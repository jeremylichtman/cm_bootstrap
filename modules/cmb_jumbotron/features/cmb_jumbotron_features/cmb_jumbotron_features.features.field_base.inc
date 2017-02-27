<?php
/**
 * @file
 * cmb_jumbotron_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cmb_jumbotron_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cc_cmbj_items'.
  $field_bases['field_cc_cmbj_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cc_cmbj_items',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  // Exported field_base: 'field_cc_cmbji_image'.
  $field_bases['field_cc_cmbji_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cc_cmbji_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_cc_cmbji_short_description'.
  $field_bases['field_cc_cmbji_short_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cc_cmbji_short_description',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_cc_cmbji_title'.
  $field_bases['field_cc_cmbji_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cc_cmbji_title',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
