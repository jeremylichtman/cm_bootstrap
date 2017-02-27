<section class="content-component cc-cmb-jumbotron">
  <div class="flexslider">
    <ul class="clean-ul-list slides">
      <?php foreach($cmb_jumbotron['items'] as $item): ?>
        <li>

          <div class="overlay-wrapper">

            <div class="overlay-content">
              <h2>
                <?php print $item['title']; ?>
              </h2>
              <div class="short-description">
                <?php print $item['short_description']; ?>
              </div>
            </div>

          </div>

          <img src="<?php print $item['placeholder_img']; ?>" data-original="<?php print $item['image']['src']; ?>"/>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
