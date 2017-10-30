<?php if ($content_list['title_display_overlay'] || ($content_list['meta_display_overlay'] == 'overlay')): ?>
  <?php // Content List: Title Display Overlay ?>

  <section class="content-component cc--cl cc-cl--title-display-overlay">
    <div class="row">
      <div class="col-md-12">
        <h2>
          <?php print $content_list['title']; ?>
        </h2>
        <?php if ($content_list['description']): ?>
          <p>
            <?php print $content_list['description']; ?>
          </p>
        <?php endif; ?>
      </div>
    </div>

    <?php foreach(array_chunk($content_list['cl_items'], 3, true) as $items): ?>
      <ul class="clean-ul-list cl-items row">
        <?php foreach($items  as $cl_item): ?>
          <li class="col-md-4 col-sm-12">
            <span class="content-list-item overlay-wrapper">
              <?php if ($cl_item['link']): ?>
                <a href="<?php print $cl_item['link']['href']; ?>" target="<?php print $cl_item['link']['target']; ?>" style="background:url(<?php print $cl_item['img_src']; ?>)">
                  <span class="overlay" style="background:<?php print $content_list['overlay_color']; ?>;">
                    <?php if($content_list['title_display_overlay']): ?>
                      <h3 style="color: <?php print $content_list['overlay_text_color']; ?>;">
                        <?php print $cl_item['title']; ?>
                      </h3>
                    <?php endif; ?>
                    <?php if ($content_list['meta_display_overlay'] == 'overlay'): ?>
                      <span style="color: <?php print $content_list['overlay_text_color']; ?>;">
                        <?php print $cl_item['abstract']; ?>
                      </span>
                    <?php endif; ?>
                  </span>
                </a>
              <?php else : ?>
                <div class="no-link" style="background:url(<?php print $cl_item['img_src']; ?>)">
                  <span class="overlay" style="background:<?php print $content_list['overlay_color']; ?>;">
                    <?php if($content_list['title_display_overlay']): ?>
                      <h3 style="color: <?php print $content_list['overlay_text_color']; ?>;">
                        <?php print $cl_item['title']; ?>
                      </h3>
                    <?php endif; ?>
                    <?php if ($content_list['meta_display_overlay'] == 'overlay'): ?>
                      <span style="color: <?php print $content_list['overlay_text_color']; ?>;">
                        <?php print $cl_item['abstract']; ?>
                      </span>
                    <?php endif; ?>
                  </span>
                </div>
              <?php endif; ?>
              <?php if(!$content_list['title_display_overlay']): ?>
                <h3>
                  <?php print $cl_item['title']; ?>
                </h3>
              <?php endif; ?>
              <?php if ($content_list['meta_display_overlay'] == 'beneath'): ?>
                <p><?php print $cl_item['abstract']; ?></p>
              <?php endif; ?>
            </span>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endforeach; ?>

  </section>

<?php else: ?>
  <?php // Content List ?>

  <section class="content-component cc--cl">
    <div class="row">
      <div class="col-md-12">
        <h2>
          <?php print $content_list['title']; ?>
        </h2>
        <?php if($content_list['description']): ?>
          <p>
            <?php print $content_list['description']; ?>
          </p>
        <?php endif; ?>
      </div>
    </div>

    <?php foreach(array_chunk($content_list['cl_items'], 3, true) as $items): ?>
      <ul class="clean-ul-list cl-items row">
        <?php foreach($items  as $cl_item): ?>
          <li class="col-md-4 col-sm-12">
            <?php if ($cl_item['link']): ?>
              <a href="<?php print $cl_item['link']['href']; ?>" target="<?php print $cl_item['link']['target']; ?>">
                <img class="img-responsive" src="<?php print $cl_item['img_src']; ?>"/>
              </a>
            <?php else: ?>
              <img class="img-responsive" src="<?php print $cl_item['img_src']; ?>"/>
            <?php endif; ?>

            <?php if ($cl_item['title']): ?>
              <h3>
                <?php if ($cl_item['link']): ?>
                  <a href="<?php print $cl_item['link']['href']; ?>" target="<?php print $cl_item['link']['target']; ?>">
                    <?php print $cl_item['title']; ?>
                  </a>
                <?php else: ?>
                  <?php print $cl_item['title']; ?>
                <?php endif; ?>
              </h3>
            <?php endif; ?>

            <?php if ($content_list['meta_display_overlay'] == 'beneath'): ?>
            <?php if ($cl_item['abstract']): ?>
              <p>
                <?php print $cl_item['abstract']; ?>
              </p>
            <?php endif; ?>
            <?php endif; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endforeach; ?>

  </section>

<?php endif; ?>
