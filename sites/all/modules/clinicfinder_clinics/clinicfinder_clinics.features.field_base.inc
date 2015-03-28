<?php
/**
 * @file
 * clinicfinder_clinics.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function clinicfinder_clinics_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_phone'
  $field_bases['field_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_phone',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'phone',
    'settings' => array(
      'country' => 'sg',
    ),
    'translatable' => 0,
    'type' => 'phone',
  );

  return $field_bases;
}
