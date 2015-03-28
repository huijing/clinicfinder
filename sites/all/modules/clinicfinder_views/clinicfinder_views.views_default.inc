<?php
/**
 * @file
 * clinicfinder_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function clinicfinder_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clincs';
  $view->description = 'All views related to the Clinic content type';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clinics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_geofield_distance' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '25',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_medical_scheme_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_24_hours_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_public_holidays_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_position']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_position']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Sort criterion: Content: Position (field_position) - proximity */
  $handler->display->display_options['sorts']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['table'] = 'field_data_field_position';
  $handler->display->display_options['sorts']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['source'] = 'exposed_geofield_filter';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_position';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_position';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clinic' => 'clinic',
  );
  /* Filter criterion: Content: Position (field_position) - proximity */
  $handler->display->display_options['filters']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['table'] = 'field_data_field_position';
  $handler->display->display_options['filters']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['operator'] = '<=';
  $handler->display->display_options['filters']['field_geofield_distance']['value'] = array(
    'distance' => '2',
    'distance2' => 200,
    'unit' => '6371',
    'origin' => '',
  );
  $handler->display->display_options['filters']['field_geofield_distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator_id'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['identifier'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_geofield_distance']['source'] = 'geocoder';
  $handler->display->display_options['filters']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_position';
  $handler->display->display_options['filters']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_position';
  /* Filter criterion: Content: Medical scheme (field_medical_scheme) */
  $handler->display->display_options['filters']['field_medical_scheme_tid']['id'] = 'field_medical_scheme_tid';
  $handler->display->display_options['filters']['field_medical_scheme_tid']['table'] = 'field_data_field_medical_scheme';
  $handler->display->display_options['filters']['field_medical_scheme_tid']['field'] = 'field_medical_scheme_tid';
  $handler->display->display_options['filters']['field_medical_scheme_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_medical_scheme_tid']['expose']['operator_id'] = 'field_medical_scheme_tid_op';
  $handler->display->display_options['filters']['field_medical_scheme_tid']['expose']['operator'] = 'field_medical_scheme_tid_op';
  $handler->display->display_options['filters']['field_medical_scheme_tid']['expose']['identifier'] = 'field_medical_scheme_tid';
  $handler->display->display_options['filters']['field_medical_scheme_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_medical_scheme_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_medical_scheme_tid']['vocabulary'] = 'medical_schemes';
  /* Filter criterion: Content: Open 24 hours? (field_24_hours) */
  $handler->display->display_options['filters']['field_24_hours_value']['id'] = 'field_24_hours_value';
  $handler->display->display_options['filters']['field_24_hours_value']['table'] = 'field_data_field_24_hours';
  $handler->display->display_options['filters']['field_24_hours_value']['field'] = 'field_24_hours_value';
  $handler->display->display_options['filters']['field_24_hours_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_24_hours_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_24_hours_value']['expose']['operator_id'] = 'field_24_hours_value_op';
  $handler->display->display_options['filters']['field_24_hours_value']['expose']['operator'] = 'field_24_hours_value_op';
  $handler->display->display_options['filters']['field_24_hours_value']['expose']['identifier'] = 'field_24_hours_value';
  $handler->display->display_options['filters']['field_24_hours_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_24_hours_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_24_hours_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Open on Public Holidays? (field_public_holidays) */
  $handler->display->display_options['filters']['field_public_holidays_value']['id'] = 'field_public_holidays_value';
  $handler->display->display_options['filters']['field_public_holidays_value']['table'] = 'field_data_field_public_holidays';
  $handler->display->display_options['filters']['field_public_holidays_value']['field'] = 'field_public_holidays_value';
  $handler->display->display_options['filters']['field_public_holidays_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_public_holidays_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_public_holidays_value']['expose']['operator_id'] = 'field_public_holidays_value_op';
  $handler->display->display_options['filters']['field_public_holidays_value']['expose']['operator'] = 'field_public_holidays_value_op';
  $handler->display->display_options['filters']['field_public_holidays_value']['expose']['identifier'] = 'field_public_holidays_value';
  $handler->display->display_options['filters']['field_public_holidays_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_public_holidays_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_public_holidays_value']['expose']['reduce'] = TRUE;

  /* Display: Clinic map */
  $handler = $view->new_display('attachment', 'Clinic map', 'clinic_map');
  $handler->display->display_options['display_description'] = 'Map view of all clinics';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => '',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['map_height'] = '600';
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = array(
    'field_position' => 'field_position',
  );
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = '';
  $handler->display->display_options['style_options']['default_marker']['default_marker_color'] = 'green';
  $handler->display->display_options['style_options']['center_option'] = '2';
  $handler->display->display_options['style_options']['mini_map']['height'] = '100';
  $handler->display->display_options['style_options']['mini_map']['width'] = '150';
  $handler->display->display_options['style_options']['cluster_differentiator']['cluster_differentiator_fields'] = array(
    '' => '',
  );
  $handler->display->display_options['style_options']['cluster_differentiator']['zoom_ranges'] = array(
    1 => '',
  );
  $handler->display->display_options['style_options']['cluster_differentiator']['cluster_tooltips'] = 1;
  $handler->display->display_options['style_options']['cluster_differentiator']['cluster_outline'] = '0';
  $handler->display->display_options['style_options']['cluster_aggregation']['aggregation_function'] = 'average';
  $handler->display->display_options['style_options']['cluster_aggregation']['ranges']['small'] = '10';
  $handler->display->display_options['style_options']['cluster_aggregation']['ranges']['medium'] = '100';
  $handler->display->display_options['style_options']['cluster_aggregation']['ranges']['large'] = '1000';
  $handler->display->display_options['style_options']['empty_map_center'] = 'visitor';
  $handler->display->display_options['style_options']['map_options']['maxzoom'] = '18';
  $handler->display->display_options['style_options']['map_options']['zoom'] = '15';
  $handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
  $handler->display->display_options['style_options']['map_options']['dragging'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'clinics' => 'clinics',
    'default' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Clinics page */
  $handler = $view->new_display('page', 'Clinics page', 'clinics');
  $handler->display->display_options['display_description'] = 'Main display for clinic information';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'clinics';
  $export['clincs'] = $view;

  return $export;
}
