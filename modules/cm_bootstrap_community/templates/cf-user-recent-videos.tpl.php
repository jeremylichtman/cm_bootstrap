<ul class="user-shows-likes">
<?php foreach($content as $node): ?>
  <?php
    // Use show custom thumbnail field if avail
    if (isset($node->field_show_custom_thumbnail[LANGUAGE_NONE])) {
      $image_uri = $node->field_show_custom_thumbnail[LANGUAGE_NONE][0]['uri'];
    }
    // Get show images, accounting for variations.
    else if (module_exists('cmb_helper')) {
      $image_uri = cmb_helper_vod_thumbnail_uri($node);
    }

    // Generate image style.
    if (!is_null($image_uri) && ($image_uri !== FALSE)) {
      $img_src = image_style_url('250x150', $image_uri);
    }

    // Description
    if (isset($node->field_description['und'][0]['value'])) {
      $show_description = $node->field_description['und'][0]['value'];
    }
    else {
      $show_description = '';
    }
    // Series title
    if (isset($node->og_group_ref['und'][0]['target_id'])) {
      $nid = $node->og_group_ref['und'][0]['target_id'];
      $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
    }
    else {
      $series_title = '';
    }
  ?>
  <li>
    <a href="<?php print url('node/' . $node->nid); ?>">
      <?php if (isset($img_src)): ?>
      <img src="<?php print $img_src; ?>" />
      <?php endif; ?>
      <span class="overlay">
        <p class="title">
          <?php print $node->title; ?>
        </p>
        <p class="description">
          <?php //print $show_description; ?>
        </p>
        <span class="series-title" style="font-style:italic;"><?php print $series_title; ?></span>
        <span class="watch-now-mobile">Watch Now &raquo;</span>
      </span>
    </a>
  </li>
<?php endforeach; ?>
</ul>

<?php if ($pager['pager_total'][0] > 1): ?>
  <?php print render($pager); ?>
<?php endif; ?>
