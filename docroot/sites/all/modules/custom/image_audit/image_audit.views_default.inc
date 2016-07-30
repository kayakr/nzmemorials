<?php
/**
 * @file
 * image_audit.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function image_audit_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'image_audit';
  $view->description = 'Table of all images';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Image audit';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Image audit';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: File: Content using Image */
  $handler->display->display_options['relationships']['reverse_field_images_node']['id'] = 'reverse_field_images_node';
  $handler->display->display_options['relationships']['reverse_field_images_node']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['reverse_field_images_node']['field'] = 'reverse_field_images_node';
  $handler->display->display_options['relationships']['reverse_field_images_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_images_node';
  $handler->display->display_options['fields']['title']['label'] = 'Memorial';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: Rendered */
  $handler->display->display_options['fields']['rendered']['id'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['table'] = 'file_managed';
  $handler->display->display_options['fields']['rendered']['field'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['file_view_mode'] = 'image_audit';
  /* Field: File: Readable text */
  $handler->display->display_options['fields']['field_readable_text']['id'] = 'field_readable_text';
  $handler->display->display_options['fields']['field_readable_text']['table'] = 'field_data_field_readable_text';
  $handler->display->display_options['fields']['field_readable_text']['field'] = 'field_readable_text';
  /* Field: File: Inscription */
  $handler->display->display_options['fields']['field_inscription']['id'] = 'field_inscription';
  $handler->display->display_options['fields']['field_inscription']['table'] = 'field_data_field_inscription';
  $handler->display->display_options['fields']['field_inscription']['field'] = 'field_inscription';
  /* Field: File: Transcription complete */
  $handler->display->display_options['fields']['field_transcription_complete']['id'] = 'field_transcription_complete';
  $handler->display->display_options['fields']['field_transcription_complete']['table'] = 'field_data_field_transcription_complete';
  $handler->display->display_options['fields']['field_transcription_complete']['field'] = 'field_transcription_complete';
  $handler->display->display_options['fields']['field_transcription_complete']['type'] = 'list_key';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'reverse_field_images_node';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Memorial name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: File: Readable text (field_readable_text) */
  $handler->display->display_options['filters']['field_readable_text_value']['id'] = 'field_readable_text_value';
  $handler->display->display_options['filters']['field_readable_text_value']['table'] = 'field_data_field_readable_text';
  $handler->display->display_options['filters']['field_readable_text_value']['field'] = 'field_readable_text_value';
  $handler->display->display_options['filters']['field_readable_text_value']['group'] = 1;
  $handler->display->display_options['filters']['field_readable_text_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_readable_text_value']['expose']['operator_id'] = 'field_readable_text_value_op';
  $handler->display->display_options['filters']['field_readable_text_value']['expose']['label'] = 'Readable text';
  $handler->display->display_options['filters']['field_readable_text_value']['expose']['operator'] = 'field_readable_text_value_op';
  $handler->display->display_options['filters']['field_readable_text_value']['expose']['identifier'] = 'field_readable_text_value';
  $handler->display->display_options['filters']['field_readable_text_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: File: Transcription complete (field_transcription_complete) */
  $handler->display->display_options['filters']['field_transcription_complete_value']['id'] = 'field_transcription_complete_value';
  $handler->display->display_options['filters']['field_transcription_complete_value']['table'] = 'field_data_field_transcription_complete';
  $handler->display->display_options['filters']['field_transcription_complete_value']['field'] = 'field_transcription_complete_value';
  $handler->display->display_options['filters']['field_transcription_complete_value']['group'] = 1;
  $handler->display->display_options['filters']['field_transcription_complete_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_transcription_complete_value']['expose']['operator_id'] = 'field_transcription_complete_value_op';
  $handler->display->display_options['filters']['field_transcription_complete_value']['expose']['label'] = 'Transcription complete';
  $handler->display->display_options['filters']['field_transcription_complete_value']['expose']['operator'] = 'field_transcription_complete_value_op';
  $handler->display->display_options['filters']['field_transcription_complete_value']['expose']['identifier'] = 'field_transcription_complete_value';
  $handler->display->display_options['filters']['field_transcription_complete_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'audit/image';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Audit Images';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['image_audit'] = $view;

  return $export;
}
