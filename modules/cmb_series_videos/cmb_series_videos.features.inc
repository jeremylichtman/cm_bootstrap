<?php
/**
 * @file
 * cmb_series_videos.features.inc
 */

/**
 * Implements hook_views_api().
 */
function cmb_series_videos_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_paragraphs_info().
 */
function cmb_series_videos_paragraphs_info() {
  $items = array(
    'series_videos' => array(
      'name' => 'Series Videos',
      'bundle' => 'series_videos',
      'locked' => '1',
    ),
  );
  return $items;
}
