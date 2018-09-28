<?php

function _cb_genres_show_series_carousels() {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
    if (isset($node)) {
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node');
        $query->entityCondition('bundle', 'cm_show');
        $query->propertyCondition('status', 1);
        $query->range(0, 25);
        $query->propertyOrderBy('created', 'DESC');
        //$query->fieldCondition('og_group_ref', 'target_id', $cvl_bssc_nid, '=');

        if (db_table_exists('field_data_field_genres')) {
          $query->fieldCondition('field_genres', 'target_id', $node->nid, '=');
        }
      $result = $query->execute();
      if (isset($result['node'])) {
        $nids = array_keys($result['node']);
        $nodes = entity_load('node', $nids);
        foreach($nodes as $node) {
          if (module_exists('cmb_helper')) {
            $image_uri = cmb_helper_vod_thumbnail_uri($node);
          }

          // Generate image style.
          if ($image_uri !== FALSE) {
            $img_src = image_style_url('500x281', $image_uri);
          }
          else {
            $img_src = '';
          }

          // field_description
          $allowable_tags = '';
          if (isset($node->field_description['und'][0]['value'])) {
            $field_description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
          }
          else {
            $field_description = '';
          }
          // Build data array
          $items[$node->nid] = array(
            'nid' => $node->nid,
            'title' => $node->title,
            'description' => cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
            'img' => $img_src,
          );
        }

        // Send $items array to TPL.
        return theme('cb_genres_show_series_carousels',
          array (
            'content' => $items,
          )
        );
      }
    }
  }
  //return 'cb_genres_show_series_carousels';
}
