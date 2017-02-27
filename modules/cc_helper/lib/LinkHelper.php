<?php

namespace ContentComponents\Helper;

class LinkHelper {
  public static function getUrl($entity, $field_name) {
    $link = FALSE;
    if (isset($entity->{$field_name}[LANGUAGE_NONE])) {
      // Get target
      $target = '_self';
      if (isset($entity->{$field_name}[LANGUAGE_NONE][0]['attributes']['target'])) {
        $target = $entity->{$field_name}[LANGUAGE_NONE][0]['attributes']['target'];
      }

      $link = [
        'href' => $entity->{$field_name}[LANGUAGE_NONE][0]['url'],
        'target' => $target,
      ];
    }

    return $link;
  }
}
