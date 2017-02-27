<?php
/**
 * @file
 * cmb_jumbotron_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cmb_jumbotron_features_paragraphs_info() {
  $items = array(
    'cmb_jumbotron' => array(
      'name' => 'CMB Jumbotron',
      'bundle' => 'cmb_jumbotron',
      'locked' => '1',
    ),
    'cmb_jumbotron_item' => array(
      'name' => 'Jumbotron Item',
      'bundle' => 'cmb_jumbotron_item',
      'locked' => '1',
    ),
  );
  return $items;
}
