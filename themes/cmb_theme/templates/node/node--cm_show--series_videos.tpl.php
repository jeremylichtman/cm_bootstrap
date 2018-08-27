<?php
  // Series meta data
  if (isset($node->og_group_ref['und'])) {
    $series_nid = $node->og_group_ref['und'][0]['target_id'];
    $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $series_nid))->fetchField();
  }
  else {
    $series_title = '';
  }

  // Get link to the show node.
  $url = drupal_get_path_alias('node/' . $node->nid);

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
    $img_src = image_style_url('250x150_thumbnail_rounded', $image_uri);
  }
  else {
    $img_src = '';
  }

  // Strip tags
  $allowable_tags = '';
  if (isset($node->field_description['und'][0]['value'])) {
    $description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
    $description = cmb_helper_truncate($description, $length = 125, ['html' => true, 'ending' => ' . . .', 'exact' => FALSE]);
  }
  else {
    $description = '';
  }

  // Production date.
  if (!empty($node->field_show_production_date['und'][0]['value'])) {
    $production_date = $node->field_show_production_date['und'][0]['value'];
    $production_date = strtotime($production_date);
    $production_date = date('M d, Y', $production_date);
  }
  else {
    $production_date = '';
  }
?>
<div class="row">
  <section class="col-sm-3">
    <a href="<?php print $url; ?>"><img class="default-image" src="<?php print $img_src; ?>"/></a>
  </section>

  <aside class="col-sm-9" role="complementary">
    <h3><a href="<?php print $url; ?>"><?php print $node->title; ?></a></h3>

    <h4><?php print $series_title; ?></h4>

    <p><?php print $description; ?></p>

    <span><?php print $production_date; ?></span>
  </aside>
</div>