<?php
/**
 * @file
 * memorial_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function memorial_person_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function memorial_person_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('A person'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
