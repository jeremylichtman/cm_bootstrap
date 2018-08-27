<style>
  .default-image {
    max-width: 770px;
    width:100%;
    height:auto;
  }
</style>

<div class="row series">

  <section class="col-sm-7">

    <?php
      if (module_exists('cm_bootstrap_cp_default_images')) {
        $file = cm_bootstrap_cp_default_images_load_image($node->type);
        $image_uri = $file->uri;
        $default_image = image_style_url('cm_bootstrap_cp_default_images_cm_show_video', $image_uri);
      }
    ?>
    <div class="fluid-width-video-wrapper">
      <img class="default-image" src="<?php print $default_image; ?>"/>
    </div>

  </section>

  <aside class="col-sm-5" role="complementary">
    <h1><?php print $node->title; ?></h1>

    <?php print render($content['field_executive_producer']); ?>

    <?php hide($content['links']['print_html']); ?>
    <?php hide($content['field_series_paragraphs']); ?>

    <?php print render($content); ?>

    <div class="row social-row">
      <div class="col-sm-5">
        <?php print render($content['links']['print_html']); ?>
      </div>

      <div class="col-sm-7">
        <!-- START: Social Media Block -->
        <?php $social_media_block = module_invoke('widgets', 'block_view', 's_socialmedia_share-default'); ?>
        <?php if (isset($social_media_block)): ?>
          <?php print render($social_media_block['content']); ?>
        <?php endif; ?>
        <!-- END: Social Media Block -->
      </div>
    </div>
  </aside>

</div>

<?php if (isset($content['field_series_paragraphs'])): ?>
<div class="row">
  <section class="col-sm-12">
    <?php print render($content['field_series_paragraphs']); ?>
  </section>
</div>
<?php endif; ?>
