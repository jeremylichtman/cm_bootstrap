<style>
  #block-system-main {
    padding-top:25px;
  }
</style>

<?php
  $following = _cm_bootstrap_community_get_following($account['user']->uid);
  $follows = _cm_bootstrap_community_get_follows($account['user']->uid);
  $likes = _cm_bootstrap_community_get_likes($account['user']->uid);
  $recent_videos = _cm_bootstrap_community_get_recent_videos($account['user']->uid);
  $video_count = _cm_bootstrap_community_get_user_video_count($account['user']->uid);
?>


<?php //dpm($account); ?>
<?php $uid = $account['user']->uid; ?>

<?php //dpm($account); ?>

<h1><?php echo $account['user']->name ?></h1>
<div class="col-lg-3 col-md-3 col-xs-4 user-profile-left-col no-padding">
  <?php //dpm($account); ?>
  <?php 
    if (isset($account['user']->picture->uri)) {
      $user_img_src = image_style_url('user_avatar_large', $account['user']->picture->uri);
    }
    else {
      $user_img_src = $GLOBALS['base_url'] . '/' . path_to_theme() . '/images/user-avatar-large-placeholder.png';
    }
  ?>
  <img class="user-avatar-large" src="<?php print $user_img_src; ?>"/>
  <div class="user-details">
    <div class="btn btn-default">        
      <?php if ($account['user']->uid === $GLOBALS['user']->uid): ?>
        <a href="/user/<?php print $GLOBALS['user']->uid; ?>/edit">Edit Profile</a>
      <?php else: ?>
        <?php print flag_create_link('cf_follow_user', $account['user']->uid); ?>
      <?php endif; ?>
    </div>
  </div>
</div>
<div class="col-lg-9 col-md-9 col-xs-8 user-profile-right-col">
  <?php $cf_user_statistics_blocks = module_invoke('cm_bootstrap_community', 'block_view', 'cf_user_statistics'); ?>
  <?php //dpm($cf_user_statistics_blocks); ?>
  <?php print render($cf_user_statistics_blocks['content']); ?>
  <div class="clearfix"></div>
</div>
<div class="col-lg-9 col-md-9 col-xs-12 user-profile-third-col">
  <h2><?php echo $account['user']->name ?> Likes</h2>
  <div class="user-shows-likes-container">
    <?php $flags = flag_get_user_flags('node', null, $account['user']->uid); ?>
    <?php if (!empty($flags)): ?>
      <ul class="user-shows-likes">
        <?php foreach ($flags['cf_like_show'] as $flag): ?>
          <?php $node = node_load($flag->entity_id); ?>
          <?php 
            // Get show images, accounting for variations.     
            if (module_exists('cmb_helper')) {
              $image_uri = cmb_helper_vod_thumbnail_uri($node);
            }

            // Generate image style.
            if (isset($image_uri) && ($image_uri !== FALSE)) {
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
              <?php if (!empty($img_src)): ?>
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
    <?php endif; ?>
  </div>

</div>


