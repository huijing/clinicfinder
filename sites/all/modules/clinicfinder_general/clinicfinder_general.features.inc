<?php
/**
 * @file
 * clinicfinder_general.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function clinicfinder_general_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
