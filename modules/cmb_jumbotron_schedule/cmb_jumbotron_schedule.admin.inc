<?php
/**
 * @file
 * Admin form for CMB Jumbotron Schedule.
 */

/**
 * Builds the settings form.
 */
function cmb_jumbotron_schedule_settings_form($form, &$form_state) {
  // How many items in total to display (default 6).
  $form['cmb_jumbotron_schedule_count'] = [
    '#type' => 'textfield',
    '#title' => t('Schedule count'),
    '#description' => t('Number of items from the TV schedule to show on the jumbotron overlay (if schedule is configured).'),
    '#size' => 10,
    '#maxlength' => 2,
    '#required' => TRUE,
    '#default_value' => variable_get('cmb_jumbotron_schedule_count', 6),
  ];

  return system_settings_form($form);
}
