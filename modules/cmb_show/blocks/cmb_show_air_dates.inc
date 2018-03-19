<?php

function _cmb_show_air_dates() {
  if ($node = menu_get_object()) {
    // RETN uses node_reference field for airings.
    // VCAM uses entity_reference field for airings.
    // So we grab the field info first and do a switch
    // to account for both types of fields.
    if (module_exists('cm_airing')) {
      $field_airing_show_ref = field_info_field('field_airing_show_ref');

      switch($field_airing_show_ref['type']) {
        case 'node_reference':
          $column = 'nid';
          break;
        case 'entity_reference':
          $column = 'target_id';
          break;
        case 'entityreference':
          $column = 'target_id';
          break;
      }

      // Get all airings related to current show
      $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'airing');
        $query->fieldCondition('field_airing_show_ref', $column, $node->nid, '=');
        $query->fieldOrderBy('field_airing_date', 'value', 'DESC');
        $query->fieldCondition('field_airing_date', 'value', strtotime('today'), '>=');
        $query->range(0, 5);
      $result = $query->execute();

      if (isset($result['airing'])) {
        $aids = array_keys($result['airing']);
        $airings = entity_load('airing', $aids);

        foreach ($airings as $airing) {
          $tid = $airing->field_airing_channel[LANGUAGE_NONE][0]['tid'];

          // Get channel name/term name
          $term = taxonomy_term_load($tid);
          $channel_name = $term->name;
          $items[$tid]['channel_name'] = $channel_name;

          // Build array of airings
          $items[$tid]['airings'][] = array(
            $airing,
          );
        }

        // Send $items array to TPL.
        return theme('cmb_show_air_dates',
          array (
            'content' => $items,
          )
        );
      }
    }
  }
}
