<?php

/**
 * Implements hook_css_alter().
 */
function clinicfinder_css_alter(&$css) { 

  $exclude = array(

  //exclude core stylesheets
    // 'modules/system/SYSTEM_STYLESHEET.css' => FALSE,

  //remove contrib module CSS
    // drupal_get_path('module','MODULE_NAME').'/PATH_TO_STYLESHEET.css' => FALSE,

  //remove contrib module CSS from libraries
    libraries_get_path('DropKick') . '/css/dropkick.css' => FALSE,
  );

  $css = array_diff_key($css, $exclude);
}

/*
 * Implements template_preprocess_field()
 */
function clinicfinder_preprocess_field(&$vars) {
  //check to see if the field is a boolean
  if ($vars['element']['#field_type'] == 'list_boolean') {
    //check to see if the value is TRUE
    if ($vars['element']['#items'][0]['value'] == '1') {
      //add the class .is-true
      $vars['classes_array'][] = 'is-true';
    } else {
      //add the class .is-false
      $vars['classes_array'][] = 'is-false';
    }
  }
}
