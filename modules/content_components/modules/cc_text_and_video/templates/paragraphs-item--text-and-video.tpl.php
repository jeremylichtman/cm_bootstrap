<section class="paragraphs--text-and-video">
  <div class="row">
    <div class="col-md-12">
      <?php if ($text_and_video['alignment'] == 'left'): ?>

        <div class="row">
          <div class="col-md-6">
            <div class="cmb--responsive-video-wrapper">
              <?php print render($text_and_video['field_cc_tav_video']); ?>
            </div>
          </div>
          <div class="col-md-6">
            <?php print $text_and_video['field_cc_tav_text']; ?>
          </div>
        </div>

      <?php else: ?>

        <div class="row">
          <div class="col-md-6">
            <?php print $text_and_video['field_cc_tav_text']; ?>
          </div>
          <div class="col-md-6">
            <div class="cmb--responsive-video-wrapper">
              <?php print render($content['field_cc_tav_video']); ?>
            </div>            
          </div>
        </div>

      <?php endif; ?>

    </div>
  </div>
</section>
