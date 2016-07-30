<?php
/**
 * @file
 * memorial_image.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function memorial_image_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_readable_text'.
  $field_bases['field_readable_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_readable_text',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'yes' => 'Yes',
        'no' => 'No',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
