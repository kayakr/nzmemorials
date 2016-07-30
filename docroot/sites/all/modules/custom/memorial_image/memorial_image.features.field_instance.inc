<?php
/**
 * @file
 * memorial_image.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function memorial_image_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'file-image-field_readable_text'.
  $field_instances['file-image-field_readable_text'] = array(
    'bundle' => 'image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'file',
    'field_name' => 'field_readable_text',
    'label' => 'Readable text',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => -1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Readable text');

  return $field_instances;
}
