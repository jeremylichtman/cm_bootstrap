<?php

/**
 * Callback for module settings page.
 */
function cm_bootstrap_custom_blocks_config($form, &$form_state) {
  $form = array();

  $form['cm_bootstrap_custom_blocks']['cmb_latest_shows_production_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sort Video List by Production Date'),
    '#default_value' => variable_get('cmb_latest_shows_production_date', ''),
    '#size' => 120,
  );

  $form['cm_bootstrap_custom_blocks']['cmb_unlimited_range'] = array(
    '#type' => 'checkbox',
    '#title' => t('Unlimited Range'),
    '#description' => t('Checking this box is almost always a bad idea and has performance impact. If checked, CVLs will not have a range limit.'),
    '#default_value' => variable_get('cmb_unlimited_range', ''),
    '#size' => 120,
  );

  return system_settings_form($form);
}
