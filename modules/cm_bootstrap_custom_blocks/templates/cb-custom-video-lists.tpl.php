<?php //dpm($content); ?>
<?php foreach($content as $item): ?>
  <h2 class="block-title"><?php print $item['collection_title']; ?>
    <p class="collection-description">
      <?php print $item['collection_desc']; ?>
    </p>
  </h3>
  <section class="c-flexslider-video-carousel">
    <div class="flexslider carousel">
      <ul class="slides">
        <?php $i = 0; ?>
        
        <?php foreach($item['video_items'] as $video_item): ?>
          <?php switch($video_item->type):
            case 'cm_show': ?>
              <?php
                // Get series title
                if (isset($video_item->og_group_ref['und'])) {
                  $nid = $video_item->og_group_ref['und'][0]['target_id'];
                  $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
                }
                else {
                  $series_title = '';
                }

                // Get the VOD thumbnail uri, if possible.
                $img_src = null;
                if (module_exists('cmb_helper')) {
                  // Get a default uri.
                  $default_image_uri = null;
                  if (isset($video_item->field_series_image[LANGUAGE_NONE])) {
                    $default_image_uri = $video_item->field_series_image[LANGUAGE_NONE][0]['uri'];
                  }

                  // Obtain the uri.
                  $image_uri = cmb_helper_vod_thumbnail_uri($video_item, $default_image_uri);

                  // Generate image style.
                  if ($image_uri !== FALSE) {
                    $img_src = image_style_url('500x281', $image_uri);
                  }
                }
              ?>          
              <?php //$i++; ?>
              <li data-slide-item="<?php print $i++; ?>">
                <a href="<?php print url('node/' . $video_item->nid); ?>">
                  <!--<span class="play-button">
                    <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
                  </span>-->
                  <?php if (isset($img_src)): ?>
                    <img src="<?php print $img_src; ?>" />
                  <?php endif; ?>
                  <span class="overlay">
                    <span class="play-button">
                      <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
                    </span>
                    <p class="title">
                      <?php print $video_item->title; ?>
                    </p>
                    <?php
                      $allowable_tags = '<i><a>';
                        
                      if (isset($video_item->field_description['und'][0]['value'])) {
                        $field_description = strip_tags($video_item->field_description['und'][0]['value'], $allowable_tags);
                      }
                      else {
                        $field_description = '';
                      }
                    ?>
                    <!--<p class="description">
                        <?php print cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)); ?>  
                      </p>-->
                    <?php if (!empty($series_title)): ?>
                      <span class="series-title" style="font-style:italic;">
                        <?php print $series_title; ?>
                      </span>
                    <?php endif; ?>
                    <span class="watch-now-mobile">Watch Now &raquo;</span>
                  </span>
                </a>
              </li>
              <?php break; ?>
            <?php case 'cm_project': ?>
              <?php 
                if (isset($video_item->field_series_image['und'][0]['uri'])) {
                  $img_src = image_style_url('500x281', $video_item->field_series_image['und'][0]['uri']);
                }
                else {
                  if (module_exists('cm_bootstrap_cp_default_images')) {
                    $file = cm_bootstrap_cp_default_images_load_image($video_item->type);
                    if ($file) {
                      $image_uri = $file->uri;
                      $img_src = image_style_url('500x281', $image_uri);
                    }
                    else {
                      $img_src = '';
                    }
                  }
                  else {
                    $img_src = '';
                  }
                }
              ?>
              <?php //$i++; ?>
              <!--<li class="cm-project" data-slide-item="id-<?php print $i++; ?>-nid-<?php print $video_item->nid; ?>">-->
              <li class="cm-project" data-slide-item="<?php print $i++; ?>">  
                <a href="<?php print url('node/' . $video_item->nid); ?>">
                  <?php if (!empty($img_src)): ?>
                    <img src="<?php print $img_src; ?>"/>
                  <?php endif; ?>
                  <!--<span class="play-button">
                    <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
                  </span>-->
                  <span class="overlay">
                    <span class="play-button">
                      <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
                    </span>
                     <p class="title">
                      <?php print $video_item->title; ?>
                     </p>
                      <?php
                        $allowable_tags = '<i>';
                        
                        if (isset($video_item->field_description['und'][0]['value'])) {
                          $field_description = strip_tags($video_item->field_description['und'][0]['value'], $allowable_tags);
                        }
                        else {
                          $field_description = '';
                        }
                      ?>
                      <p class="description">
                        <?php print cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)); ?>  
                      </p>
                    <span class="watch-now">Watch Now &raquo;</span>
                  </span>
                  <?php //if (isset($img_src)): ?>
                  <?php //endif; ?>
                </a>
              </li>              
              <?php break; ?>
          <?php endswitch; ?>
        <?php endforeach; ?>
      </ul>
    </div>
  </section>
<?php endforeach; ?>
