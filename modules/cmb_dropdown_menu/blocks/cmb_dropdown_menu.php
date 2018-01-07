<?php

function _cmb_dropdown_menu() {
  // Get menu variable
  $custom_menu = variable_get('cmb_dropdown_menu_menu', 'main-menu');

  // Get and render menu
  $menu_data = menu_tree_output(menu_tree_all_data($custom_menu));

  // Loop through menu tree.
  foreach($menu_data as $index => $item) {

    // Index has cruft but we need root menu items which are keyed to mlid.
    if(is_numeric($index)) {
      // Add lowercase title to class array to use in styling.
      $menu_data[$index]['#attributes']['class'][] = strtolower($item['#title']);
    }
  }

	$menu_render = drupal_render($menu_data);

  // Build data array for TPL
  $data = [
    'menu' => $menu_render,
  ];

  // Send data to TPL
  return theme('cmb_dropdown_menu',
    array (
      'cmb_dm' => $data,
    )
  );
}
