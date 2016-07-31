<?php
/**
 * @file
 * memorial_task_extract_names.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function memorial_task_extract_names_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'task_extract_names';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Task: Extract names';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Extract names';
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
    'title' => 'title',
    'rendered' => 'rendered',
    'field_inscription' => 'field_inscription',
    'field_names_individual_editable' => 'field_names_individual_editable',
    'field_extract_names_complete_editable' => 'field_names_individual_editable',
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
    'title' => array(
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
    'field_inscription' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_names_individual_editable' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_extract_names_complete_editable' => array(
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
  $handler->display->display_options['header']['area']['content'] = 'Please delete non-name text from candidate name rows, and add additional name rows and text if needed. Leave names in the exact format of the inscription.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total images to assess.';
  /* Relationship: File: Content using Image */
  $handler->display->display_options['relationships']['reverse_field_images_node']['id'] = 'reverse_field_images_node';
  $handler->display->display_options['relationships']['reverse_field_images_node']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['reverse_field_images_node']['field'] = 'reverse_field_images_node';
  $handler->display->display_options['relationships']['reverse_field_images_node']['required'] = TRUE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_images_node';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: File: Rendered */
  $handler->display->display_options['fields']['rendered']['id'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['table'] = 'file_managed';
  $handler->display->display_options['fields']['rendered']['field'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['file_view_mode'] = 'memorial_large';
  /* Field: File: Inscription */
  $handler->display->display_options['fields']['field_inscription']['id'] = 'field_inscription';
  $handler->display->display_options['fields']['field_inscription']['table'] = 'field_data_field_inscription';
  $handler->display->display_options['fields']['field_inscription']['field'] = 'field_inscription';
  /* Field: File: Names (individual) (editable) */
  $handler->display->display_options['fields']['field_names_individual_editable']['id'] = 'field_names_individual_editable';
  $handler->display->display_options['fields']['field_names_individual_editable']['table'] = 'field_data_field_names_individual';
  $handler->display->display_options['fields']['field_names_individual_editable']['field'] = 'field_names_individual_editable';
  $handler->display->display_options['fields']['field_names_individual_editable']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_names_individual_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_names_individual_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_names_individual_editable']['suppress_description'] = 0;
  /* Field: File: Extract names complete (editable) */
  $handler->display->display_options['fields']['field_extract_names_complete_editable']['id'] = 'field_extract_names_complete_editable';
  $handler->display->display_options['fields']['field_extract_names_complete_editable']['table'] = 'field_data_field_extract_names_complete';
  $handler->display->display_options['fields']['field_extract_names_complete_editable']['field'] = 'field_extract_names_complete_editable';
  $handler->display->display_options['fields']['field_extract_names_complete_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_extract_names_complete_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_extract_names_complete_editable']['suppress_description'] = 0;
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
  $handler->display->display_options['filters']['field_readable_text_value']['value'] = array(
    'yes' => 'yes',
  );
  /* Filter criterion: File: Transcription complete (field_transcription_complete) */
  $handler->display->display_options['filters']['field_transcription_complete_value']['id'] = 'field_transcription_complete_value';
  $handler->display->display_options['filters']['field_transcription_complete_value']['table'] = 'field_data_field_transcription_complete';
  $handler->display->display_options['filters']['field_transcription_complete_value']['field'] = 'field_transcription_complete_value';
  $handler->display->display_options['filters']['field_transcription_complete_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: File: Extract names complete (field_extract_names_complete) */
  $handler->display->display_options['filters']['field_extract_names_complete_value']['id'] = 'field_extract_names_complete_value';
  $handler->display->display_options['filters']['field_extract_names_complete_value']['table'] = 'field_data_field_extract_names_complete';
  $handler->display->display_options['filters']['field_extract_names_complete_value']['field'] = 'field_extract_names_complete_value';
  $handler->display->display_options['filters']['field_extract_names_complete_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_extract_names_complete_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'task/extract-names';
  $export['task_extract_names'] = $view;

  return $export;
}
