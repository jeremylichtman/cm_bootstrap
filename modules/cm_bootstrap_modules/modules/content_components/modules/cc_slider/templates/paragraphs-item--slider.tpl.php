<section class="content-component content-component--slider">
  <div class="row">
    <div class="col-md-12">
      <h2>
        <?php print $slider['title']; ?>
      </h2>
      <div class="flexslider">
        <ul class="clean-ul-list slides">
          <?php foreach($slider['s_items'] as $slider): ?>
            <li>
              <img src="<?php print $slider['placeholder_img']; ?>" data-original="<?php print $slider['data_original']; ?>"/>
            </li>
          <?php endforeach; ?>
        </ul>
      </div>
    </div>
  </div>
</section>
