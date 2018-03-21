<div class="block-custom-block">
<?php //dpm($content);?>
<h2 class="block-title">Shows In This Series</h3>

<section class="c-flexslider-video-carousel">
  <div class="flexslider carousel">
    <?php $i=0; ?>
    <ul class="slides">
      <?php foreach($content as $node): ?>
        <li data-slide-item="<?php print $i++; ?>">
          <a href="<?php print url('node/' . $node['nid']); ?>">
            <img src="<?php print $node['placeholder_img']; ?>" data-original="<?php print $node['img_src']; ?>"/>
            <span class="overlay" style="background-color:<?php //print $node['bg-color'];?>;" data-accent-color="<?php //print $node['accent-color'];?>">
              <span class="play-button">
                <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
              </span>
              <p class="title">
                <?php print $node['title']; ?>
              </p>
              <?php //print $node['sub_title']; ?>
              <p class="description">
                <?php print $node['description']; ?>
              </p>
              <?php if (isset($node['series_title'])): ?>
                <span class="series-title" style="font-style:italic;"><?php print $node['series_title']; ?></span>
              <?php endif; ?>
              <span class="watch-now-mobile">Watch Now &raquo;</span>
            </span>
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
</div>
