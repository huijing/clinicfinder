<?php
/**
 * @file
 * clinicfinder_clinics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function clinicfinder_clinics_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function clinicfinder_clinics_node_info() {
  $items = array(
    'clinic' => array(
      'name' => t('Clinic'),
      'base' => 'node_content',
      'description' => t('Used for clinic information'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
