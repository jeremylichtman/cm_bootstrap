<style>
.jumbotron-featured__overlay-right > a:hover {
  text-decoration: none;
  cursor: auto;
}
</style>

<section class="content-component cc-cmb-jumbotron <?php print $cmb_jumbotron['extra_classes']; ?>">
  <div class="flexslider">
    <ul class="clean-ul-list slides">
      <?php foreach($cmb_jumbotron['items'] as $item): ?>

        <?php if ($item['published']): ?>
          <li>
            <a target="<?php print $item['link']['target']; ?>" href="<?php print $item['link']['href']; ?>">
              <div class="overlay-wrapper" style="background:rgba(<?php print $item['overlay_color'];?>, <?php print $item['overlay_opacity'];?>);">

                <?php if ($cmb_jumbotron['featured_content_display']): ?>
                  <div class="overlay-content">

                    <div class="jumbotron-featured__overlay-left sm-100 md-60">
                      <h2>
                        <?php print $item['title']; ?>
                      </h2>
                      <div class="short-description">
                        <?php print $item['short_description']; ?>
                      </div>
                      <?php if ($item['cta_toggle']): ?>
                        <?php if ($item['link']['title']): ?>
                          <div class="button-wrapper">
                            <button style="background-color:<?php print $cmb_jumbotron['cta_bg_color']; ?>; color:<?php print $cmb_jumbotron['cta_color']; ?>;">
                              <?php print $item['link']['title']; ?>
                            </button>
                          </div>
                        <?php endif; ?>
                      <?php endif; ?>
                    </div>

                    <div class="jumbotron-featured__overlay-right sm-100 md-40 bg-white">
                      <h2 class="jumbotron-featured__items-title center">
                        <?php print $cmb_jumbotron['featured_content_title']; ?>
                      </h2>
                      <ul class="jumbotron-featured__items">
                        <?php foreach($cmb_jumbotron['featured_items'] as $featured_item): ?>
                          <li class="jumbotron-featured__item">
                            <a href="<?php print $featured_item['link']; ?>" target="_blank">
                              <span class="jumbotron-featured__item-icon vertical-center">
                                <i class="icon icon-calendar"></i>
                              </span>
                              <div class="jumbotron-featured__item-right">
                                <h3 class="jumbotron-featured__item-title">
                                  <?php print $featured_item['title']; ?>
                                </h3>
                                <div class="jumbotron-featured__item-datetime">
                                  <?php print $featured_item['date']; ?>
                                </div>
                              </div>
                            </a>
                          </li>
                        <?php endforeach; ?>
                      </ul>

                      <div class="jumbotron-featured__items-button">
                        <a style="background: <?php print $cmb_jumbotron['cta_bg_color']; ?>; color:#FFF;" href="<?php print $cmb_jumbotron['featured_content_btn_link']['href']; ?>" target="_blank">
                          <?php print $cmb_jumbotron['featured_content_btn_link']['title']; ?>
                        </a>
                      </div>
                    </div>

                  </div>

                <?php else: ?>

                  <div class="overlay-content">
                    <h2>
                      <?php print $item['title']; ?>
                    </h2>
                    <div class="short-description">
                      <?php print $item['short_description']; ?>
                    </div>
                    <?php if ($item['cta_toggle']): ?>
                      <?php if ($item['link']['title']): ?>
                        <div class="button-wrapper">
                          <button style="background-color:<?php print $cmb_jumbotron['cta_bg_color']; ?>; color:<?php print $cmb_jumbotron['cta_color']; ?>;">
                            <?php print $item['link']['title']; ?>
                          </button>
                        </div>
                      <?php endif; ?>
                    <?php endif; ?>
                  </div>
                <?php endif; ?>

              </div>
              <img src="<?php print $item['placeholder_img']; ?>" data-original="<?php print $item['image']['src']; ?>"/>
            </a>
          </li>
        <?php endif; ?>

      <?php endforeach; ?>
    </ul>
  </div>
</section>
