<style>
  .main-container {
    background-color: #E8E6E1;
  }
  .main-container-inner {
    max-width: 1170px;
    margin: 0 auto;
  }
</style>

<!-- ** START: Search Overlay ** -->
<?php
  if (module_exists('cm_bootstrap_search')) {
    $search_overlay_tpl = drupal_get_path('theme', 'cmb_theme') . '/templates/cm_bootstrap_search/search-overlay.php';
    include_once $search_overlay_tpl;
  }
?>
<!-- ** END: Search Overlay ** -->

<div id="main">
  <div class="container-fluid navigation">
    <div class="row">

      <!-- ** START: Search Trigger ** -->
      <?php
        if (module_exists('cm_bootstrap_search')) {
          $search_trigger_tpl = drupal_get_path('theme', 'cmb_theme') . '/templates/cm_bootstrap_search/search-trigger.php';
          include_once $search_trigger_tpl;
        }
      ?>
      <!-- ** END: Search Trigger ** -->

      <?php if (!empty($page['navigation'])): ?>
        <?php print render($page['navigation']); ?>
      <?php endif; ?>

    </div>
  </div>

  <div id="menu-panel">
    <?php if (!empty($page['jpanel_region'])): ?>
      <?php print render($page['jpanel_region']); ?>
    <?php endif; ?>
  </div>

  <div class="container below-navigation">
    <div class="row">
      <?php print render($page['below_navigation']); ?>
    </div>
  </div>

  <!-- START -->
  <div class="main-container container-fluid">
    <div class="main-container-inner">
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>

      <?php if (!empty($page['above_content'])): ?>
        <div class="row">
          <?php print render($page['above_content']); ?>
        </div>
      <?php endif; ?>

      <div class="row">
        <?php if (!empty($page['sidebar_first'])): ?>
          <aside class="col-sm-3" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside>  <!-- /#sidebar-first -->
        <?php endif; ?>

        <?php
          if (!empty($page['sidebar_second'])) {
            $col_class = 'col-sm-8';
          }
          else {
            $col_class = 'col-sm-12';
          }
        ?>

        <section class="<?php print $col_class; ?>">
          <?php if (!empty($page['highlighted'])): ?>
            <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
          <?php endif; ?>
          <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
          <a id="main-content"></a>
          <?php if (!empty($page['help'])): ?>
            <?php print render($page['help']); ?>
          <?php endif; ?>
          <?php if (!empty($action_links)): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>
        </section>

        <?php if (!empty($page['sidebar_second'])): ?>
          <aside class="col-sm-4" role="complementary">
            <?php print render($page['sidebar_second']); ?>
          </aside>  <!-- /#sidebar-second -->
        <?php endif; ?>
      </div>
    </div>
  </div>
  <!-- END -->

  <div class="main-container-below-content container">
    <div class="row">
      <section class="col-md-12 no-padding top-section">
        <h1 class="page-header">
          <?php print $page__cm_show['title']; ?>
        </h1>
      </section>
    </div>

    <div class="row">
      <section class="col-sm-12">
        <?php if ($page__cm_show['social_media_block']): ?>
          <?php print render($page__cm_show['social_media_block']); ?>
        <?php endif; ?>
      </section>
    </div>

    <div class="row">
      <section class="col-sm-8">
        <?php print $page__cm_show['cmb_show_meta_left']; ?>
      </section>

      <aside class="col-sm-4" role="complementary">
        <?php print $page__cm_show['cmb_show_meta_right']; ?>
      </aside>
    </div>

    <?php if ($page['below_content_fwidth']): ?>
      <div class="row">
        <section class="col-md-12 no-padding">
          <?php print render($page['below_content_fwidth']); ?>
        </section>
      </div>
    <?php endif; ?>
  </div>

  <?php if ($page['below_content']): ?>
    <div class="main-container-below-content container-fluid">
      <div class="row">
        <?php print render($page['below_content']); ?>
      </div>
    </div>
  <?php endif; ?>

  <footer class="footer container-fluid">
    <div class="row">
      <?php print render($page['footer']); ?>
    </div>
  </footer>

  <footer class="footer-bottom container-fluid">
    <div class="container">
      <div class="row">
        <div class="contact-info-container col-md-12">
          <?php print render($page['footer_bottom']); ?>
        </div>
      </div>
  </footer>
</div>

<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>
