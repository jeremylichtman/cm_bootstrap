<?php
/**
 * @file
 * cmb_cc_text_and_video.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cmb_cc_text_and_video_paragraphs_info() {
  $items = array(
    'text_and_video' => array(
      'name' => 'Text and Video',
      'bundle' => 'text_and_video',
      'locked' => '1',
    ),
  );
  return $items;
}
