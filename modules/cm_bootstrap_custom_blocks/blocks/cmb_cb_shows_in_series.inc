<?php

// Placeholder image
define("CMB_SHOWS_IN_SERIES_PLACEHOLDER", "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAfQAAAEZCAQAAADLBR9dAAACbUlEQVR42u3TQQ0AAAjEMM6/ZgIq+JBWwpKlp4DnYnQwOmB0wOiA0QGjA0YHjA4YHYwOGB0wOmB0wOiA0QGjA0YHowNGB4wOGB0wOmB0wOiA0cHoRgejA0YHjA4YHTA6YHTA6IDRweiA0QGjA0YHjA4YHTA6YHQwOmB0wOiA0QGjA0YHjA4YHYwuAhgdMDpgdMDogNEBowNGB4wORgeMDhgdMDpgdMDogNEBo4PRAaMDRgeMDhgdMDpgdMDoYHTA6IDRAaMDRgeMDhgdMDpgdDA6YHTA6IDRAaMDRgeMDhgdjA4YHTA6YHTA6IDRAaMDRgejA0YHjA4YHTA6YHTA6IDRAaOD0QGjA0YHjA4YHTA6YHTA6GB0wOiA0QGjA0YHjA4YHTA6GB0wOmB0wOiA0QGjA0YHjA4YHYwOGB0wOmB0wOiA0QGjA0YHowNGB4wOGB0wOmB0wOiA0cHogNEBowNGB4wOGB0wOmB0wOhgdMDogNEBowNGB4wOGB0wOhgdMDpgdMDogNEBowNGB4wORgeMDhgdMDpgdMDogNEBowNGB6MDRgeMDhgdMDpgdMDogNHB6IDRAaMDRgeMDhgdMDpgdDA6YHTA6IDRAaMDRgeMDhgdMDoYHTA6YHTA6IDRAaMDRgeMDkYHjA4YHTA6YHTA6IDRAaOD0QGjA0YHjA4YHTA6YHTA6IDRweiA0QGjA0YHjA4YHTA6YHQwOmB0wOiA0QGjA0YHjA4YHYwOGB0wOmB0wOiA0QGjA0YHoxsdjA4YHTA6YHTA6IDRAaMDRgejA0YHjA4YHTA6YHTA6IDRweiA0QGjA0YHjA4cWp9PLtR3ly0mAAAAAElFTkSuQmCC");

function _cmb_cb_shows_in_series() {
  // Sort
  $sort = variable_get('cmb_latest_shows_production_date', FALSE);
  // Unlimited range
  $unlimited_range = variable_get('cmb_unlimited_range', FALSE);

  if ($current_node = menu_get_object()) {
    switch($current_node->type) {
      case 'cm_show':
        if (isset($current_node->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
          $nid = $current_node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        }
        break;
      case 'cm_project':
        $nid = $current_node->nid;
        break;
    }
    // Data query
    $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'cm_show');
      $query->propertyCondition('status', 1);

      // Unlimited range
      if (!$unlimited_range) {
        $query->range(0, 100);
      }
      if ($sort) {
        $query->fieldOrderBy('field_show_production_date', 'value', 'DESC');
      }
      else {
        $query->propertyOrderBy('created', 'DESC');
      }
      $query->fieldCondition('og_group_ref', 'target_id', $nid, '=');
    $result = $query->execute();
    //
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $nodes = entity_load('node', $nids);
      foreach($nodes as $node) {
        // Use show custom thumbnail field if avail
        if (isset($node->field_show_custom_thumbnail[LANGUAGE_NONE])) {
          $image_uri = $node->field_show_custom_thumbnail[LANGUAGE_NONE][0]['uri'];
        }
        // Get field_show_vod thumbnail
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

        // Strip tags
        $allowable_tags = '';
        if (isset($node->field_description['und'][0]['value'])) {
          $field_description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
        }
        else {
          $field_description = '';
        }

        // Build data array for TPL
        $items[$node->nid] = array(
          'nid' => $node->nid,
          'title' => $node->title,
          'description' => cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
          'img_src' => $img_src,
          'placeholder_img' => CMB_SHOWS_IN_SERIES_PLACEHOLDER,
        );
      }
      // Send $items array to TPL.
      return theme('cmb_cb_shows_in_series',
        array (
          'content' => $items,
        )
      );
    }
  }
}
