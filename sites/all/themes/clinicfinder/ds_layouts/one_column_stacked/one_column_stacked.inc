<?php
function ds_one_column_stacked() {
  return array(
    'label' => t('One Column Stacked'),
    'regions' => array(
      'top' => t('Top'),
      'bottom' => t('Bottom')
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
    // Add this line if you're using DS 2.x for icon preview
    'image' => TRUE,
  );
}
