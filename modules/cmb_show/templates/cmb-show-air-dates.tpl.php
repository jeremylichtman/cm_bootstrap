<div class="air-dates-list">
  <h3>Upcoming Air Dates</h3>
  <ul class="air-dates">
    <?php foreach($content as $channel => $item): ?>
      <li>
        <h3 class="channel-name">
          <?php print $item['channel_name']; ?>
        </h3>
        <ul>
          <?php foreach($item['airings'] as $airing): ?>
            <li>
              <?php
                $timestamp = strtotime($airing[0]->field_airing_date['und'][0]['value']);
                $date = date('l, F j, Y', $timestamp);
                $hour = (int)date('h', $timestamp);
                $minute = date('i', $timestamp);
                $am_pm = date('a', $timestamp);
              ?>
              <?php print $date . ' <br/>' . $hour . ':' . $minute . ' ' . $am_pm; ?>
            </li>
          <?php endforeach; ?>
        </ul>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
