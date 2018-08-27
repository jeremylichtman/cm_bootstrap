<?php
/**
 * Data
 */
function _front_pg_featured_videos_carousel_data() {
  $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'cm_show')
    ->propertyCondition('status', 1)
    ->propertyCondition('promote', 1)
    ->range(0, 25);  
  $result = $query->execute();
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    foreach ($nodes as $node) { 
      if (module_exists('cmb_helper')) {
        $image_uri = cmb_helper_vod_thumbnail_uri($node);
      }

      // Generate image style.
      if (!is_null($image_uri) && ($image_uri !== FALSE)) {
        $cm_show_image = image_style_url('500x281', $image_uri);
      }
      else {
        $cm_show_image = '';
      }
 
      // field_description
      //$allowable_tags = '<i><a>';
      //$field_description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
      if (isset($node->og_group_ref['und'][0]['target_id'])) {
        $nid = $node->og_group_ref['und'][0]['target_id'];
        $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
      }
      else {
        $series_title = '';
      }
      // Build data array.     
      $items[$node->nid] = array(
        'nid' => $node->nid,
        'title' => $node->title,      
        //'description' => custom_block_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
        'img' => $cm_show_image,
        'series_title' => $series_title,
      );
    }
    // Send to theme layer.
    return theme('front_pg_fv_carousel', 
      array (
        'content' => $items,
      )
    );
  }
}
