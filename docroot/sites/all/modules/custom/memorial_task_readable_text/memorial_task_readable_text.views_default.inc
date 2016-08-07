<?php
/**
 * @file
 * memorial_task_readable_text.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function memorial_task_readable_text_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'images_have_text';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Images have text';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Which photos have readable text?';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'filename' => 'filename',
    'field_contains_text' => 'field_contains_text',
    'rendered' => 'rendered',
    'title' => 'title',
    'field_contains_text_editable' => 'field_contains_text_editable',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'filename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contains_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contains_text_editable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['batch_size'] = '10';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'If memorial photos have readable text, especially with names of people, please set the field to Yes. If there is definitely no text or text that is unreadable, set field to No.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total photos to assess.';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<em>[filename]</em> from [title].';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  /* Relationship: File: Content using Image */
  $handler->display->display_options['relationships']['reverse_field_images_node']['id'] = 'reverse_field_images_node';
  $handler->display->display_options['relationships']['reverse_field_images_node']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['reverse_field_images_node']['field'] = 'reverse_field_images_node';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['relationship'] = 'reverse_field_images_node';
  $handler->display->display_options['fields']['field_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_images_node';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_url]';
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: File: Rendered */
  $handler->display->display_options['fields']['rendered']['id'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['table'] = 'file_managed';
  $handler->display->display_options['fields']['rendered']['field'] = 'rendered';
  /* Field: File: Readable text (editable) */
  $handler->display->display_options['fields']['field_readable_text_editable']['id'] = 'field_readable_text_editable';
  $handler->display->display_options['fields']['field_readable_text_editable']['table'] = 'field_data_field_readable_text';
  $handler->display->display_options['fields']['field_readable_text_editable']['field'] = 'field_readable_text_editable';
  $handler->display->display_options['fields']['field_readable_text_editable']['widget_type'] = 'options_buttons';
  $handler->display->display_options['fields']['field_readable_text_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_readable_text_editable']['suppress_description'] = 0;
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  /* Filter criterion: File: Readable text (field_readable_text) */
  $handler->display->display_options['filters']['field_readable_text_value']['id'] = 'field_readable_text_value';
  $handler->display->display_options['filters']['field_readable_text_value']['table'] = 'field_data_field_readable_text';
  $handler->display->display_options['filters']['field_readable_text_value']['field'] = 'field_readable_text_value';
  $handler->display->display_options['filters']['field_readable_text_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_readable_text_value']['value'] = array(
    'yes' => 'yes',
    'no' => 'no',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'task/readable-text';
  $export['images_have_text'] = $view;

  return $export;
}
