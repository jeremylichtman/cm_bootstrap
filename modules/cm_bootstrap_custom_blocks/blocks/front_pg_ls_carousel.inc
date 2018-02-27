<?php

/**
 *
 */
function _front_pg_latest_shows_carousel_data() {
  $sort = variable_get('cmb_latest_shows_production_date', FALSE);

  $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'cm_show');
    $query->propertyCondition('status', 1);
    $query->range(0, 25);

    if ($sort) {
      $query->fieldOrderBy('field_show_production_date', 'value', 'DESC');
    }
    else {
      $query->propertyOrderBy('created', 'DESC');
    }

    // Make sure node has an image to display.
    $query->fieldCondition('field_show_vod', 'fid', 'NULL', '!=');

  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);

    foreach ($nodes as $node) {
      // Use show custom thumbnail field if avail
      if (isset($node->field_show_custom_thumbnail[LANGUAGE_NONE])) {
        $image_uri = $node->field_show_custom_thumbnail[LANGUAGE_NONE][0]['uri'];
      }
      // Switch to account for cloudcast, vimeo, youtube, etc.
      else if (module_exists('cmb_helper')) {
        $image_uri = cmb_helper_vod_thumbnail_uri($node);
      }

      // Generate image style.
      if (!is_null($image_uri) && ($image_uri !== FALSE)) {
        $img_src = image_style_url('500x281', $image_uri);
      }
      else {
        $img_src = '';
      }

      // field_description
      if (isset($node->field_description['und'][0]['value'])) {
        $allowable_tags = '<i><a>';
        $field_description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
      }
      else {
        $allowable_tags = '';
        $field_description = '';
      }

      // field_topic
      if (isset($node->field_topic['und'][0]['tid'])) {
        $field_topic_term = taxonomy_term_load($node->field_topic['und'][0]['tid']);
        $field_topic_term_name = $field_topic_term->name;
      }
      else {
        $field_topic_term_name = '';
      }

      if (isset($node->og_group_ref['und'][0]['target_id'])) {
        $nid = $node->og_group_ref['und'][0]['target_id'];
        $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
      }
      else {
        $series_title = '';
      }

      $items[$node->nid] = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'description' => cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
        'series' => $field_topic_term_name,
        'series_title' => $series_title,
        'img' => $img_src,
        //'bg-color' => $node->field_background_color['und'][0]['value'],
        //'text-color' => $node->field_text_color['und'][0]['value'],
        //'accent-color' => $node->field_accent_color['und'][0]['value'],
      );
    }
  }

  //dpm($items);

  //theme
  return theme('front_pg_ls_carousel',
    array (
      'content' => $items,
    )
  );

}
