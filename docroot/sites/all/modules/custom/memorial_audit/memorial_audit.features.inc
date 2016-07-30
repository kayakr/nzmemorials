<?php
/**
 * @file
 * memorial_audit.features.inc
 */

/**
 * Implements hook_views_api().
 */
function memorial_audit_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function memorial_audit_image_default_styles() {
  $styles = array();

  // Exported image style: tiny_thumb_square.
  $styles['tiny_thumb_square'] = array(
    'label' => 'tiny thumb square',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
