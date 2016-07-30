<?php
/**
 * @file
 * memorial.features.inc
 */

/**
 * Implements hook_node_info().
 */
function memorial_node_info() {
  $items = array(
    'memorial' => array(
      'name' => t('Memorial'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
