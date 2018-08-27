<?php
/**
 * @file
 * cmb_paragraphs_embed_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cmb_paragraphs_embed_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_paragraphs_item__cmb_embed';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_paragraphs_item__cmb_embed'] = $strongarm;

  return $export;
}
