<style>
  @media only screen {
    .img-align-right,
    .img-align-left {
      float: none;
      width: 100%;
      height: auto;
      margin: 0 0 20px 0;
    }
  }
  @media only screen and (min-width : 768px) {
    .img-align-right {
      width: 100%;
      height: auto;
      margin: 0 0 20px 0;
      padding: 0 0 0 20px;
    }
    .img-align-left {
      width: 100%;
      height: auto;
      margin: 0;
      padding: 0 20px 0 0;
    }
  }
</style>
<section class="paragraphs--text-and-image">
  <div class="row">
    <div class="col-md-12">
      <?php if ($text_and_image['alignment'] == 'left'): ?>

        <div class="row">
          <div class="col-md-6">
            <?php if ($text_and_image['link']): ?>
              <a target="<?php print $text_and_image['link']['target']; ?>" href="<?php print $text_and_image['link']['href']; ?>">
                <img class="<?php print $text_and_image['image_alignment_class']; ?>" src="<?php print $text_and_image['img_src']; ?>"/>
              </a>
            <?php else: ?>
              <img class="<?php print $text_and_image['image_alignment_class']; ?>" src="<?php print $text_and_image['img_src']; ?>"/>
            <?php endif; ?>
          </div>
          <div class="col-md-6">
            <?php print $text_and_image['field_cc_tai_text']; ?>
          </div>
        </div>

      <?php else: ?>

        <div class="row">
          <div class="col-md-6">
            <?php print $text_and_image['field_cc_tai_text']; ?>
          </div>
          <div class="col-md-6">
            <?php if ($text_and_image['link']): ?>
              <a target="<?php print $text_and_image['link']['target']; ?>" href="<?php print $text_and_image['link']['href']; ?>">
                <img class="<?php print $text_and_image['image_alignment_class']; ?>" src="<?php print $text_and_image['img_src']; ?>"/>
              </a>
            <?php else: ?>
              <img class="<?php print $text_and_image['image_alignment_class']; ?>" src="<?php print $text_and_image['img_src']; ?>"/>
            <?php endif; ?>
          </div>
        </div>

      <?php endif; ?>

    </div>
  </div>
</section>
