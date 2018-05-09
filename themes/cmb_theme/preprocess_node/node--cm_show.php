<?php

function _node__cm_show(&$variables) {
  $node = $variables['node'];

  // Set to false, will get value if avail below
  $default_image = FALSE;

  // Use show custom thumbnail field if avail
  if (isset($node->field_show_custom_thumbnail[LANGUAGE_NONE])) {
    $image_uri = $node->field_show_custom_thumbnail[LANGUAGE_NONE][0]['uri'];
    $default_image = image_style_url('cm_bootstrap_cp_default_images_cm_show_video', $image_uri);
  }
  // Otherwise, use default image if avail
  else if (module_exists('cm_bootstrap_cp_default_images')) {
    $file = cm_bootstrap_cp_default_images_load_image($node->type);
    if ($file) {
      $image_uri = $file->uri;
      $default_image = image_style_url('cm_bootstrap_cp_default_images_cm_show_video', $image_uri);
    }
  }

  // Build data array for tpl
  $data = [
    'nid' => $node->nid,
    'title' => $node->title,
    'default_image' => $default_image,
  ];

  $variables['cm_show'] = $data;
}
