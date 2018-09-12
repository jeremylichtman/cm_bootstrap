<section class="cc--custom-video-list-context paragraph-<?php print $custom_video_list_context['id'];?>">
  <h2 class="title" style="background-color:<?php print $custom_video_list_context['bg_color']; ?>; color:<?php print $custom_video_list_context['text_color']; ?>;">
    <span class="<?php print $custom_video_list_context['title_align']; ?>">
      <?php print $custom_video_list_context['title']; ?>
    </span>
  </h2>

  <div class="flexslider carousel">
    <ul class="slides">
      <?php foreach($custom_video_list_context['items'] as $item): ?>
        <li>
          <a href="<?php print $item['url']; ?>">
            <img src="<?php print $item['placeholder_img']; ?>" data-original="<?php print $item['img_src']; ?>"/>

            <span class="overlay">
              <span class="play-button">
                <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
              </span>

              <h4 class="title" style="color:<?php print $custom_video_list_context['overlay_text_color']; ?> !important;">
                <?php print $item['title']; ?>
              </h4>

              <?php if ($item['series_title']): ?>
                <p class="series-title" style="color:<?php print $custom_video_list_context['overlay_text_color']; ?>;">
                  <?php print $item['series_title']; ?>
                </p>
              <?php endif; ?>

              <?php if ($item['description']): ?>
                <p class="description" style="color:<?php print $custom_video_list_context['overlay_text_color']; ?>;">
                  <?php print $item['description']; ?>
                </p>
              <?php endif; ?>

              <span class="watch-now" style="color:<?php print $custom_video_list_context['overlay_text_color']; ?>;">Watch Now &raquo;</span>
            </span>
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
