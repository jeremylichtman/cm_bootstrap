<?php
/**
 * @file
 * Admin form for CMB Dropdown menu.
 *
 * Has admin form for dropdown menu and CSS color file writing also in this file.
 */

/**
 * Builds the dropdown menu settings form.
 */
function cmb_dropdown_menu_settings_form($form, &$form_state) {

  $form = [];

  // Get dropdown menu name.
  $dropdown_menu = variable_get('cmb_dropdown_menu_menu', 'main-menu');

  // Set menu being used, fires ajax callback to update the menu items.
  $form['cmb_dropdown_menu']['cmb_dropdown_menu_menu'] = [
    '#type' => 'select',
    '#title' => t('Drupal Menu'),
    '#default_value' => $dropdown_menu,
    '#description' => 'Select the Drupal menu for this dropdown menu. This is usually the Main Menu.',
    '#options' => _cmb_dropdown_menu_get_custom_menus_options(),
    '#ajax' => array(
      'callback' => 'cmb_dropdown_menu_color_form_ajax_callback',
      'wrapper' => 'cmb_dropdown_menu_color_form_ajax_wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  ];

  // Ajax wrapper and start of complete colors fieldset.
  $form['cmb_dropdown_menu']['colors'] = array(
    '#type' => 'fieldset',
    '#title' => 'Color Settings',
    '#description' => 'Below you will find the color settings for the dropdown menu.',
    '#prefix' => '<div id="cmb_dropdown_menu_color_form_ajax_wrapper">',
    '#suffix' => '</div>',
  );

  // Run this with ajax change to get new dropdown menu that was selected.
  if (isset($form_state['triggering_element']['#type'])) {

    // Change dropdown menu variable to the currently selected menu.
    $dropdown_menu = !empty($form_state['values']['cmb_dropdown_menu_menu']) ? $form_state['values']['cmb_dropdown_menu_menu'] : variable_get('cmb_dropdown_menu_menu', 'main-menu');
  }

  // Load menu tree from selected menu at page load or ajax load.
  $menu_tree = menu_tree_all_data($dropdown_menu, $link = NULL, $max_depth = 3);

  $i = 1;

  // Loop through and make form items.
  foreach($menu_tree as $item) {
    $link_title = $item['link']['link_title'];
    $link_id = $item['link']['mlid'];

    // Start color settings.
    // Level 1 fieldset for current link tree.
    $form['cmb_dropdown_menu']['colors'][$link_title] = array(
      '#type' => 'fieldset',
      '#title' => $link_title,
      '#description' => 'Level 1 dropdown menu settings for background color, text color, and hover color.',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    // Level 1, Item $i, Background Color
    $form['cmb_dropdown_menu']['colors'][$link_title]['cmb_dropdown_menu_l1_i' . $i . '_bg_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Background Color',
      '#size' => 90,
      '#required' => TRUE,
      '#default_value' => variable_get('cmb_dropdown_menu_l1_i' . $i . '_bg_color', '01a7da'),
    ];

    // Level 1, Item $i, Text Color
    $form['cmb_dropdown_menu']['colors'][$link_title]['cmb_dropdown_menu_l1_i' . $i . '_text_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Text Color',
      '#size' => 90,
      '#required' => TRUE,
      '#default_value' => variable_get('cmb_dropdown_menu_l1_i' . $i . '_text_color', 'FFFFFF'),
    ];

    // Level 1, Item $i, Hover Background Color
    $form['cmb_dropdown_menu']['colors'][$link_title]['cmb_dropdown_menu_l1_i' . $i . '_hover_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Hover Color',
      '#size' => 90,
      '#required' => TRUE,
      '#default_value' => variable_get('cmb_dropdown_menu_l1_i' . $i . '_hover_color', 'e06126'),
    ];

    // Level 1, Item $i, Hover Text Color
    $form['cmb_dropdown_menu']['colors'][$link_title]['cmb_dropdown_menu_l1_i' . $i . '_hover_text_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Hover Text Color',
      '#size' => 90,
      '#required' => TRUE,
      '#default_value' => variable_get('cmb_dropdown_menu_l1_i' . $i . '_hover_text_color', 'FFFFFF'),
    ];

    // Level 2 fieldset for current link tree.
    $form['cmb_dropdown_menu']['colors'][$link_title]['l2'] = array(
      '#type' => 'fieldset',
      '#title' => $link_title . ' Level 2',
      '#description' => 'If no colors are chosen (all colors are white or #FFFFFF) then the colors will inherited from the root menu item.',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    // Level 2, Item $i, Background Color.
    $form['cmb_dropdown_menu']['colors'][$link_title]['l2']['cmb_dropdown_menu_l2_i' . $i . '_bg_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Level 2 Background Color',
      '#size' => 90,
      '#default_value' => variable_get('cmb_dropdown_menu_l2_i' . $i . '_bg_color', 'FFFFFF'),
    ];

    // Level 2, Item $i, Text Color.
    $form['cmb_dropdown_menu']['colors'][$link_title]['l2']['cmb_dropdown_menu_l2_i' . $i . '_text_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Level 2 Text Color',
      '#size' => 90,
      '#default_value' => variable_get('cmb_dropdown_menu_l2_i' . $i . '_text_color', 'FFFFFF'),
    ];

    // Level 3 fieldset for current link tree.
    $form['cmb_dropdown_menu']['colors'][$link_title]['l3'] = array(
      '#type' => 'fieldset',
      '#title' => $link_title . ' Level 3',
      '#description' => 'If no colors are chosen (all colors are white or #FFFFFF) then the colors will inherited from the root menu item or level 2 if present.',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    // Level 3, Item $i, Background Color.
    $form['cmb_dropdown_menu']['colors'][$link_title]['l3']['cmb_dropdown_menu_l3_i' . $i . '_bg_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Level 3 Background Color',
      '#size' => 90,
      '#default_value' => variable_get('cmb_dropdown_menu_l3_i' . $i . '_bg_color', 'FFFFFF'),
    ];

    // Level 3, Item $i, Text Color.
    $form['cmb_dropdown_menu']['colors'][$link_title]['l3']['cmb_dropdown_menu_l3_i' . $i . '_text_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Level 3 Text Color',
      '#size' => 90,
      '#default_value' => variable_get('cmb_dropdown_menu_l3_i' . $i . '_text_color', 'FFFFFF'),
    ];

    // Level 3, Item $i, Hover Color.
    $form['cmb_dropdown_menu']['colors'][$link_title]['l3']['cmb_dropdown_menu_l3_i' . $i . '_hover_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Level 3 Hover Color',
      '#size' => 90,
      '#default_value' => variable_get('cmb_dropdown_menu_l3_i' . $i . '_hover_color', 'FFFFFF'),
    ];

    // Level 3, Item $i, Hover Text Color
    $form['cmb_dropdown_menu']['colors'][$link_title]['l3']['cmb_dropdown_menu_l3_i' . $i . '_hover_text_color'] = [
      '#type' => 'jquery_colorpicker',
      '#title' => $link_title . ' Level 3 Hover Text Color',
      '#size' => 90,
      '#default_value' => variable_get('cmb_dropdown_menu_l3_i' . $i . '_hover_text_color', 'FFFFFF'),
    ];

    $i++;
  }

  // Custom submit to mainly fire off the generate function for the CSS file.
  $form['#submit'][] = 'cmb_dropdown_menu_settings_form_submit';

  // Validate handler to set the level2/level3 items if they arent set.
  $form['#validate'][] = 'cmb_dropdown_menu_settings_form_validate';

  return system_settings_form($form);
}

/**
 * Ajax callback for system settings form color settings.
 */
function cmb_dropdown_menu_color_form_ajax_callback($form, $form_state) {
  // Return portion that is being rebuilt.
  return $form['cmb_dropdown_menu']['colors'];
}

/**
 * Custom Submit handler.
 */
function cmb_dropdown_menu_settings_form_submit($form, &$form_state) {

  // Generate CSS for colors.
  $css = _cmb_dropdown_menu_generate_css($form_state);

  // Directory for CSS file.
  $directory = 'public://cmb-dropdown-menu/css';

  if (!file_prepare_directory($directory, FILE_MODIFY_PERMISSIONS | FILE_CREATE_DIRECTORY)) {
    drupal_set_message(t('Failed to create %directory.', array('%directory' => $directory)), 'error');
  }
  else {
    // URI for file now that the directory has been made or checked.
    $uri = $directory . '/cmb_dropdown_menu_colors.css';
  }

  // Drupal save CSS file data and replace any file that was saved before.
  $file_object = file_save_data($css, $uri, FILE_EXISTS_REPLACE);

  // Set status to perm.
  $file_object->status = FILE_STATUS_PERMANENT;
  // Set file type to CSS (that filetype is added by this module in the module file).
  $file_object->type = 'css';
  // We add usage so cron doesn't delete it, assigned to user 1 b/c it has no node.
  file_usage_add($file_object, 'cmb_dropdown_menu', 'user', 1);
  // Save changes from above.
  file_save($file_object);

  if (!empty($file_object)) {

    $url = file_create_url($file_object->uri);

    drupal_set_message(
      t('Generated CSS file for colors: %file to destination %destination',
        array(
          '%file' => $file_object->filename,
          '%destination' => $uri, '@uri' => $file_object->uri,
        )
      )
    );
  }
  else {
    drupal_set_message(t('Failed to save the managed file'), 'error');
  }

}

/**
 * Form validate handler for dropdown menu system settings form.
 */
function cmb_dropdown_menu_settings_form_validate($form, &$form_state) {

  // Change dropdown menu variable to the currently selected menu.
  $dropdown_menu = !empty($form_state['values']['cmb_dropdown_menu_menu']) ? $form_state['values']['cmb_dropdown_menu_menu'] : variable_get('cmb_dropdown_menu_menu', 'main-menu');

  // Load menu tree from selected menu at page load or ajax load.
  $menu_tree = menu_tree_all_data($dropdown_menu, $link = NULL, $max_depth = 3);

  $i = 1;

  // Loop through and make form items.
  foreach($menu_tree as $item) {
    $link_title = $item['link']['link_title'];
    $link_id = $item['link']['mlid'];

    // Level 1 vars so we can set the other levels if needed.
    $level1_bg_color = $form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_bg_color'];
    $level1_text_color = $form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_text_color'];
    $level1_hover_color = $form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_hover_color'];
    $level1_hover_text_color = $form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_hover_text_color'];

    // Level 2 and level 3 bg color so we can check if it's set.
    // Set to upper b/c some were set to lower and some were set to upper for some reason?
    $level2_bg_color = strtoupper($form_state['values']['cmb_dropdown_menu_l2_i' . $i . '_bg_color']);
    $level2_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l2_i' . $i . '_text_color']);

    // If all are white then we can use the level1 colors.
    if ($level2_bg_color == 'FFFFFF' && $level2_text_color == 'FFFFFF' ) {
      $form_state['values']['cmb_dropdown_menu_l2_i' . $i . '_bg_color'] = $level1_bg_color;
      $form_state['values']['cmb_dropdown_menu_l2_i' . $i . '_text_color'] = $level1_text_color;
    }

    // Level 3 settings.
    $level3_bg_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_bg_color']);
    $level3_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_text_color']);
    $level3_hover_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_hover_color']);
    $level3_hover_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_hover_text_color']);

    // If all are white then we can use the level1 colors.
    if ($level3_bg_color == 'FFFFFF' && $level3_text_color == 'FFFFFF' && $level3_hover_color == 'FFFFFF' && $level3_hover_text_color == 'FFFFFF') {
      // Set these backwards when inheriting so it will flow correctly.
      $form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_bg_color'] = $level1_hover_color;
      $form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_text_color'] = $level1_hover_text_color;
      $form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_hover_color'] = $level1_bg_color;
      $form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_hover_text_color'] = $level1_text_color;
    }

    $i++;
  }

}

/**
 * Helper function to generate CSS file.
 */
function _cmb_dropdown_menu_generate_css(&$form_state) {

  // Change dropdown menu variable to the currently selected menu.
  $dropdown_menu = !empty($form_state['values']['cmb_dropdown_menu_menu']) ? $form_state['values']['cmb_dropdown_menu_menu'] : variable_get('cmb_dropdown_menu_menu', 'main-menu');

  // Load menu tree from selected menu at page load or ajax load.
  $menu_tree = menu_tree_all_data($dropdown_menu, $link = NULL, $max_depth = 3);

  $i = 1;
  $output = '';

  // Loop through and make form items.
  foreach($menu_tree as $item) {
    $link_item_class = strtolower($item['link']['link_title']);
    $link_id = $item['link']['mlid'];

    // Level 1 Settings.
    $level1_bg_color = strtoupper($form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_bg_color']);
    $level1_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_text_color']);
    $level1_hover_color = strtoupper($form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_hover_color']);
    $level1_hover_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l1_i' . $i . '_hover_text_color']);

    // Level 2 Settings.
    $level2_bg_color = strtoupper($form_state['values']['cmb_dropdown_menu_l2_i' . $i . '_bg_color']);
    $level2_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l2_i' . $i . '_text_color']);

    // Level 3 settings.
    $level3_bg_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_bg_color']);
    $level3_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_text_color']);
    $level3_hover_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_hover_color']);
    $level3_hover_text_color = strtoupper($form_state['values']['cmb_dropdown_menu_l3_i' . $i . '_hover_text_color']);

    $output .= <<<EOF
/* Main li element bg color. */
#cmb-dropdown-menu ul li.$link_item_class {
  background-color: #$level1_bg_color;
}

/* Main li text color. */
#cmb-dropdown-menu ul li.$link_item_class a {
  color: #$level1_text_color;
}

/* Main li element hover bg color. When hovering over lower li. */
#cmb-dropdown-menu ul li.$link_item_class:hover {
  background-color: #$level1_hover_color;
}

/* Main li element hover bg color. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li {
  background-color: #$level1_hover_color;
}

/* Main li element hover text color */
#cmb-dropdown-menu ul li.$link_item_class:hover a {
  color: #$level1_hover_text_color;
}

/* Main li element hover text color. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li a {
  color: #$level1_hover_text_color;
}

/* Hover on level 1 li - bg for level 2. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover {
  background-color: #$level2_bg_color !important;
}

/* Main li level 2 bg color. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li {
  background-color: #$level2_bg_color;
}

/* Main level 2 li element hover text color */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover a {
  color: #$level2_text_color;
}

/* Main level 2 li element hover text color. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li a {
  color: #$level2_text_color;
}

/* Hover on level 2 li - bg for level 3. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li:hover {
  background-color: #$level3_bg_color !important;
}

/* Main li level 3 bg color. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li:hover ul li {
  background-color: #$level3_bg_color;
}

/* Main level 3 li element text color */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li:hover a {
  color: #$level3_text_color;
}

/* Main level 3 li element text color. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li:hover ul li a {
  color: #$level3_text_color;
}

/* Main li level 3 hover colors. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li:hover ul li:hover {
  background-color: #$level3_hover_color !important;
}

/* Main li level 3 hover text colors. */
#cmb-dropdown-menu ul li.$link_item_class:hover ul li:hover ul li:hover ul li:hover a {
  color: #$level3_hover_text_color !important;
}

EOF;

    $i++;
  }

  return $output;
}

/**
 * Helper function to get menus for form options.
 */
function _cmb_dropdown_menu_get_custom_menus_options() {
  $result = db_query('SELECT menu_name, title FROM {menu_custom} ORDER BY title ASC;')->fetchAll();

  if (isset($result)) {
    foreach ($result as $option) {
      $options[$option->menu_name] = $option->title;
    }
    return $options;
  }
}
