<?php
/**
 * @file
 * cmb_paragraphs_embed_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_paragraphs_embed_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function cmb_paragraphs_embed_features_paragraphs_info() {
  $items = array(
    'cmb_embed' => array(
      'name' => 'CMB Embed',
      'bundle' => 'cmb_embed',
      'locked' => '1',
    ),
  );
  return $items;
}
