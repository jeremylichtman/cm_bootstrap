<?php //dpm($content); ?>
<div class="video-grid-container">
  <?php foreach($content as $item): ?>
    <?php //dpm($item); ?>
    
    <div class="video-grid-column">
      <div class="top-details">
        <h3 class="video-grid-title">
          <?php print $item['title']; ?>
        </h3>
        <div class="description">
          <?php print $item['description']; ?>
        </div>
      </div>
      <ul class="video-grid-shows">
        <?php foreach($item['shows'] as $show_node): ?>        
          <?php 
            // Get show images, accounting for variations.
            if (module_exists('cmb_helper')) {
              $image_uri = cmb_helper_vod_thumbnail_uri($show_node);

              // Generate image style.
              if ($image_uri !== FALSE) {
                $img_src = image_style_url('500x281', $image_uri);
              }
            }

            // Description
            if (isset($show_node->field_description['und'][0]['value'])) {
              $show_description = $show_node->field_description['und'][0]['value'];
            }
            else {
              $show_description = '';
            }
            
            // Get series title
            if (isset($show_node->og_group_ref['und'][0]['target_id'])) {
              $nid = $show_node->og_group_ref['und'][0]['target_id'];
              $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
            }
            else {
              $series_title = '';
            }
          ?>  
          <?php // Don't show video grid item if no image ?> 
          <?php if (isset($img_src)): ?> 
            <li>
              <a href="<?php print url('node/' . $show_node->nid); ?>">
                <?php //print drupal_render($img_src); ?>
                
                <img src="<?php print $img_src; ?>" />
                <span class="overlay">
                  <!--<span class="play-button">
                    <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
                  </span>-->
                  <p class="title">
                    <?php print cmb_helper_truncate($show_node->title, $length = 45, array('html' => false, 'ending' => ' . . .', 'exact' => FALSE)); ?>                  
                  </p>
                  <p class="description">
                    <?php //print $show_description; ?>
                  </p>
                  <span class="series-title" style="font-style:italic;"><?php print $series_title; ?></span>
                  <span class="watch-now-mobile">Watch Now &raquo;</span>
                </span>
              </a>
            </li>
          <?php endif; ?>
          
          
        <?php endforeach; ?>
      </ul>
      
    </div>
  <?php endforeach; ?>
</div>
