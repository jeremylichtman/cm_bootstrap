<?php
/**
 * @file
 * cmb_paragraphs_embed_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cmb_paragraphs_embed_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cmb_p_embed_embed'.
  $field_bases['field_cmb_p_embed_embed'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cmb_p_embed_embed',
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

  return $field_bases;
}
