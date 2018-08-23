<?php
// drush mi MemorialMultiXML --idlist='http://www.nzhistory.net.nz/media/photo/lyttelton-war-memorial'


/**
 * TIP: An example of importing from an XML feed where both the id and the
 * data to import are in the same file.  The id is a part of the data.  See
 * the file in the xml directory - producers.xml which contains all IDs and
 * producer data for this example.
 *
 * Note that, if basing a migration on an XML source, you need to derive it
 * from XMLMigration instead of Migration.
 */
class MemorialMultiXMLMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description =
      t('XML feed (multi items) of NZ Memorials');

    // There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields.
    $fields = array(
      'kml:title' => t('Title'),
      'kml:a@href' => t('URL'),
      //'authorid' => t('Numeric ID of the author'),
      //'region' => t('Name of region'),
    );

    // IMPORTANT: Do not try this at home! We have included importable files
    // with the migrate_example module so it can be very simply installed and
    // run, but you should never include any data you want to keep private
    // (especially user data like email addresses, phone numbers, etc.) in the
    // module directory. Your source data should be outside of the webroot, and
    // should not be anywhere where it may get committed into a revision control
    // system.

    // This can also be an URL instead of a file path.
    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'memorial') . '/';
    $items_url = variable_get('memorials_xml_folder', $xml_folder) . 'locations.kml'; // @todo: change to .kml when done.

    // We use the MigrateSourceMultiItems class for any source where we obtain
    // the list of IDs to process and the data for each item from the same
    // file. Examples include multiple items defined in a single xml file or a
    // single json file where in both cases the id is part of the item.

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '//kml:Placemark';
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /producers/producer/sourceid.
    //$item_ID_xpath = 'kml:name';
    // Try using href for ID, as it's easier to use on command line.
    $item_ID_xpath = 'kml:description//kml:p/kml:a/@href';
    $namespaces = array('kml' => 'http://www.opengis.net/kml/2.2');

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath, $namespaces);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('memorial');

    // The source ID here is the one retrieved from each data item in the XML
    // file, and used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'sourceid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // TIP: Note that for XML sources, in addition to the source field passed to
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to
    // retrieve the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the
    // item xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of
    // /producers/producer/name).
    $this->addFieldMapping('uid')
      ->defaultValue(0);
    $this->addFieldMapping('field_id', 'nid');
    $this->addFieldMapping('title', 'kml:name')
      ->xpath('kml:name');
    // Sometimes there are empty p tags prior to p containing a.
    $this->addFieldMapping('field_url', 'kml:a/@href')
      ->xpath('kml:description//kml:p/kml:a/@href');
    $this->addFieldMapping('field_coordinates', 'kml:Point/kml:coordinates')
      ->xpath('kml:Point/kml:coordinates')
      ->callbacks(array($this, 'coordinates'));

    $this->addFieldMapping('field_images', 'images');
    $this->addFieldMapping('field_images:file_replace')
      ->defaultValue(FILE_EXISTS_REUSE);

    //$this->addFieldMapping('field_coordinates:geo_type')
    //  ->defaultValue('point');
    //$this->addFieldMapping('field_coordinates:lat', 'kml:Point/kml:coordinates')
    //  ->xpath('kml:Point/kml:coordinates')
    //  ->callbacks(array($this, 'getLatitude'));
    //$this->addFieldMapping('field_coordinates:lon', 'kml:Point/kml:coordinates')
    //  ->xpath('kml:Point/kml:coordinates')
    //  ->callbacks(array($this, 'getLongitude'));

    //$this->addFieldMapping('migrate_example_wine_regions', 'region')
    //  ->xpath('region');
    //$this->addFieldMapping('body', 'description')
    //  ->xpath('description');

    $this->addUnmigratedDestinations(array(
      'body:summary', 'body:format',
      'changed',
      'comment',
      'created',
      'is_new',
      'language',
      'log',
      'promote',
      'revision',
      'revision_uid',
      'status',
      'sticky',
      'tnid',
      'translate',
    ));

    $destination_fields = $this->destination->fields();
    if (isset($destination_fields['path'])) {
      $this->addFieldMapping('path')
        ->issueGroup(t('DNM'));
      if (isset($destination_fields['pathauto'])) {
        $this->addFieldMapping('pathauto')
          ->issueGroup(t('DNM'));
      }
    }
    if (module_exists('statistics')) {
      $this->addUnmigratedDestinations(
        array('totalcount', 'daycount', 'timestamp'));
    }
  }

  /**
   * Fetch HEAD from nzhistory to obtain node id from Link header
   * [link] => </node/399>; rel="shortlink",</media/photo/dargaville-war-memorial-band-rotunda>; rel="canonical"
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    //$row = parent::prepareRow($row); // TODO: Change the autogenerated stub
    $a = $row->xml->xpath('kml:description/kml:p/kml:a');
    $a = current($a);
    $href = (string)$a['href'];
    watchdog('memorial', 'Detected @href.', array('@href' => $href));
    if (!empty($href)) {

      $response = drupal_http_request($href, array('method' => 'HEAD'));
      watchdog('memorial', 'HEAD @href = @code', array('@href' => $href, '@code' => $response->code));
      if ($response->code == 200) {
        // </node/399>; rel="shortlink",</media/photo/dargaville-war-memorial-band-rotunda>; rel="canonical"
        $link = $response->headers['link'];
        $pattern = '/\/node\/\d+/';
        preg_match($pattern, $link, $matches);
        if (!empty($matches)) {
          $parts = explode('/', $matches[0]);
          $nid = end($parts);
          $row->nid = $nid;
        }
      }

      // Fetch entire page so we can parse for image URLs.
      $page = drupal_http_request($href);
      if ($page->code == 200) {
        watchdog('memorial', 'Fetch @href <pre>!page</pre>', array('@href' => $href, '!page' => $response->data));

        $credit = htmlqp($page->data, '#region-credit')->text();

        $images = array();
        $primary_image = htmlqp($page->data, '.field-name-field-primary-image img')->attr('src');
        if (!empty($primary_image)) {
          $images[] = $primary_image;
        }
        else {
          watchdog('memorial', 'No primary image detected for @href.', array('@href' => $href), WATCHDOG_ERROR);
        }

        $qp_additional_images = htmlqp($page->data, '.field-name-body a.colorbox-load');
        $additional_images = array();
        foreach ($qp_additional_images as $qp_image) {
          $images[] = $qp_image->attr('href');
        }
        // Normalise URLs.
        if (!empty($images)) {
          foreach ($images as $key => $href) {
            $href_parts = parse_url($href);
            if (empty($href_parts['host'])) {
              $images[$key] = 'https://nzhistory.govt.nz' . $href;
            }
          }
        }
        $row->images = $images;
      }
      else {
        watchdog('memorial', 'Fetch @href = @code', array('@href' => $href, '@code' => $response->code), WATCHDOG_ERROR);
      }

    }
    return TRUE;
  }

  public function prepare(stdClass $entity, stdClass $row) {
    //xdebug_break();
  }

  // Return WKT from KML coordinates.
  public function coordinates($value) {
    return 'POINT(' . strtr(str_replace(' ', '', $value), array(',' => ' ')) . ')';
  }

  public function getLatitude($value) {
    $parts = explode(',', $value);
    $value = $parts[1];
    return $value;
  }

  public function getLongitude($value) {
    $parts = explode(',', $value);
    return $parts[0];
  }

}
