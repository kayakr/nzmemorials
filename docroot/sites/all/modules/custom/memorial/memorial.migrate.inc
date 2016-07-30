<?php


/**
 * Implements hook_migrate_api().
 * @return array
 */
function memorial_migrate_api() {
  // Usually field mappings are established by code in the migration constructor -
  // a call to addFieldMapping(). They may also be passed as arguments when
  // registering a migration - in this case, they are stored in the database
  // and override any mappings for the same field in the code. To do this,
  // construct the field mapping object and configure it similarly to when
  // you call addFieldMapping, and pass your mappings as an array below.
  $translate_mapping = new MigrateFieldMapping('translate', NULL);
  $translate_mapping->defaultValue(0);
  $ignore_mapping = new MigrateFieldMapping('migrate_example_beer_styles:ignore_case', NULL);
  $ignore_mapping->defaultValue(1);

  $api = array(
    // Required - tells the Migrate module that you are implementing version 2
    // of the Migrate API.
    'api' => 2,
    // Migrations can be organized into groups. The key used here will be the
    // machine name of the group, which can be used in Drush:
    //  drush migrate-import --group=wine
    // The title is a required argument which is displayed for the group in the
    // UI. You may also have additional arguments for any other data which is
    // common to all migrations in the group.
    'groups' => array(
      'memorial' => array(
        'title' => t('Memorial Imports'),
      ),
    ),

    // Here we register the individual migrations. The keys (BeerTerm, BeerUser,
    // etc.) are the machine names of the migrations, and the class_name
    // argument is required. The group_name is optional (defaulting to 'default')
    // but specifying it is a best practice.
    'migrations' => array(

      'MemorialMultiXML' => array(
        'class_name' => 'MemorialMultiXMLMigration',
        'group_name' => 'memorial',
      ),
//      'MemorialXMLPull' => array(
//        'class_name' => 'MemorialXMLPullMigration',
//        'group_name' => 'memorial',
//      ),
/*      'WineProducerNamespaceXMLPull' => array(
        'class_name' => 'WineProducerNamespaceXMLPullMigration',
        'group_name' => 'wine',
        'dependencies' => array(
          'WineRegion',
          'WineUser',
        ),
      ),*/

    ),
  );
  return $api;
}
