<?php
/**
 * @file
 * clinicfinder_clinics.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function clinicfinder_clinics_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|clinic|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'clinic';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_nearest_mrt' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h3',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_by_bus' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h3',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|clinic|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function clinicfinder_clinics_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|clinic|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'clinic';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'field_address',
        3 => 'field_medical_scheme',
        4 => 'field_24_hours',
        5 => 'field_public_holidays',
        6 => 'field_nearest_mrt',
        7 => 'field_by_bus',
        8 => 'field_phone',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'field_address' => 'ds_content',
      'field_medical_scheme' => 'ds_content',
      'field_24_hours' => 'ds_content',
      'field_public_holidays' => 'ds_content',
      'field_nearest_mrt' => 'ds_content',
      'field_by_bus' => 'ds_content',
      'field_phone' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|clinic|default'] = $ds_layout;

  return $export;
}
