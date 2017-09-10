<a href="<?php print url('node/' . $search_result['nid']); ?>">
  <div class="row">

    <?php if($search_result['img_src']): ?>

      <div class="col-md-3 col-lg-3 col-sm-12 left-column">
        <?php if($search_result['img_src']): ?>
          <img src="<?php print $search_result['img_src']; ?>"/>
        <?php endif; ?>
      </div>

      <div class="col-md-9 col-lg-9 col-sm-12 right-column">
        <div class="col-md-12 col-lg-12 col-sm-12 no-padding">
          <h3><?php print $search_result['title']; ?></h3>
          <p class="description"><?php print $search_result['description']; ?></p>

          <?php if(!empty($search_result['post_date'])): ?>
            <p class="date">
              <label>Post Date:</label>
              <?php print $search_result['post_date']; ?>
            </p>
          <?php endif; ?>

          <p class="node-type">
            <label>Type:</label>
            <?php print $search_result['type']; ?>
          </p>
        </div>
      </div>

    <?php else: ?>

      <div class="col-md-12 col-lg-12 col-sm-12 no-padding">
        <h3><?php print $search_result['title']; ?></h3>
        <p class="description"><?php print $search_result['description']; ?></p>

        <?php if(!empty($search_result['post_date'])): ?>
          <p class="date">
            <label>Post Date:</label>
            <?php print $search_result['post_date']; ?>
          </p>
        <?php endif; ?>

        <p class="node-type">
          <label>Type:</label>
          <?php print $search_result['type']; ?>
        </p>
      </div>

    <?php endif; ?>

  </div>
</a>
