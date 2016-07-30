<?php
/**
 * @file
 * the_sorrow_and_the_pride.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function the_sorrow_and_the_pride_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
