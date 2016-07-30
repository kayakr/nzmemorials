<?php
/**
 * @file
 * memorial_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function memorial_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function memorial_image_image_default_styles() {
  $styles = array();

  // Exported image style: memorial_large.
  $styles['memorial_large'] = array(
    'label' => 'Memorial Large',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 1200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
