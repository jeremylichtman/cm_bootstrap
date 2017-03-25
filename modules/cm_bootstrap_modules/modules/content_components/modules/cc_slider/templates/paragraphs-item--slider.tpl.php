<section class="content-component content-component--slider">
  <div class="row">
    <div class="col-md-12">
      <?php if ($slider['title']): ?>
        <h2>
          <?php print $slider['title']; ?>
        </h2>
      <?php endif; ?>

      <div id="flexslider-slider" class="flexslider">
        <ul class="clean-ul-list slides">
          <?php foreach($slider['s_items'] as $item): ?>
            <li>
              <img src="<?php print $item['placeholder_img']; ?>" data-original="<?php print $item['data_original']; ?>"/>
            </li>
          <?php endforeach; ?>
        </ul>
      </div>

      <?php if ($slider['thumbnails']): ?>
        <div id="flexslider-thumbnails" class="flexslider">
          <ul class="clean-ul-list slides">
            <?php foreach($slider['s_items_thumbnails'] as $thumbnail_item): ?>
              <li>
                <img src="<?php print $thumbnail_item['thumbnail']; ?>"/>
              </li>
            <?php endforeach; ?>
          </ul>
        </div>
      <?php endif; ?>

    </div>
  </div>
</section>
