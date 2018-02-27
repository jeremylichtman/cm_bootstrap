<?php

function cm_bootstrap_metatag_cm_show_image() {
  if ($node = menu_get_object()) {
    // Use show custom thumbnail field if avail
    if (isset($node->field_show_custom_thumbnail[LANGUAGE_NONE])) {
      $image_uri = $node->field_show_custom_thumbnail[LANGUAGE_NONE][0]['uri'];
    }
    // Switch to account for cloudcast, vimeo, youtube, etc.
    else if (module_exists('cmb_helper')) {
      $image_uri = cmb_helper_vod_thumbnail_uri($node);
    }

    // Generate image style.
    if (isset($image_uri) && ($image_uri !== FALSE)) {
      $img_src = image_style_url('500x281', $image_uri);
    }
    else {
      $img_src = '';
    }

    $og_image = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image',
        'content' => $img_src,
      ),
    );
    drupal_add_html_head($og_image, 'og:image');

    $og_image_width = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image:width',
        'content' => '500',
      ),
    );
    drupal_add_html_head($og_image_width, 'og:image:width');

    $og_image_height = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image:height',
        'content' => '281',
      ),
    );
    drupal_add_html_head($og_image_height, 'og:image:height');
  }
}
