<?php

/**
 * Implements hook_css_alter().
 */
// function THEME_NAME_css_alter(&$css) { 

//   $exclude = array(

//   //exclude core stylesheets
//     'modules/system/SYSTEM_STYLESHEET.css' => FALSE,

//   //remove contrib module CSS
//     drupal_get_path('module','MODULE_NAME').'/PATH_TO_STYLESHEET.css' => FALSE,

//   //remove contrib module CSS from libraries
//     libraries_get_path('LIBRARY_NAME').'/PATH_TO_STYLESHEET.css' => FALSE,
//   );

//   $css = array_diff_key($css, $exclude);
// }