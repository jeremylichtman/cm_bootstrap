<section class="playlist playlist-infinite-scroll series-id-<?php print $series_videos['series_nid']; ?>">
  <div class="row">
    <h2>Episodes</h2>

    <?php if (!empty($series_videos['items'])): ?>
      <?php print $series_videos['items']; ?>
    <?php endif; ?>

  </div>
</section>
