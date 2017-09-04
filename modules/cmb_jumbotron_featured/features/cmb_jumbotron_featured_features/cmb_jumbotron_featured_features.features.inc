<?php
/**
 * @file
 * cmb_jumbotron_featured_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_jumbotron_featured_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function cmb_jumbotron_featured_features_paragraphs_info() {
  $items = array(
    'cmb_jumbotron_featured' => array(
      'name' => 'Jumbotron Featured Content',
      'bundle' => 'cmb_jumbotron_featured',
      'locked' => '1',
    ),
  );
  return $items;
}
