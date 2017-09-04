<?php

function _node__cm_show(&$variables) {
  $node = $variables['node'];

  // Check if flag module exists
  $flag_module = FALSE;
  if (module_exists('flag')) {
    $flag_module = TRUE;
  }

  $data = [
    'nid' => $node->nid,
    'title' => $node->title,
    'flag_module' => $flag_module,
  ];

  $variables['cm_show'] = $data;
}
