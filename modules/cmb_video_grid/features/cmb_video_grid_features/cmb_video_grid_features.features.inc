<?php
/**
 * @file
 * cmb_video_grid_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cmb_video_grid_features_paragraphs_info() {
  $items = array(
    'cmb_video_grid' => array(
      'name' => 'CMB Video Grid',
      'bundle' => 'cmb_video_grid',
      'locked' => '1',
    ),
  );
  return $items;
}
