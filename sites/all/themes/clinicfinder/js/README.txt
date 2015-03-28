Add a Javascript file to all pages on your website by editing your the theme's .info file in the following manner:

    scripts[] = js/my-jquery-script.js

If the Javascript file is dependent on certain conditions, add the file using PHP code in a preprocess function:

    drupal_add_js(drupal_get_path('theme', 'THEME_NAME') . '/js/my-jquery-script.js', array('group' => JS_THEME));

Refer to http://api.drupal.org/api/function/drupal_add_js for documentation of drupal_add_js().
