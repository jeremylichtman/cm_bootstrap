(function($) {
  // Controls events for panel menu.
  // We use context here on click events to compensate for a stupid bug in views ajax.
  Drupal.behaviors.menuPanelBehavior = {
    attach: function(context, settings) {
      $(document).ready(function() {
        $('body', context).click(function(e) {
          // Ignore click on search box.
          if (e.target.id == "edit-search-block-form--2") {
            return;
          } else {
            menuPanelClose();
          }
        });
        $('.menu-panel-trigger', context).click(function(e) {
          e.preventDefault();
          e.stopPropagation();
          //console.log('trigger clicked');
          menuPanelToggleMenu();
        });
        $('#menu-panel .close-menu', context).click(function(e) {
          e.preventDefault();
          //console.log('close button clicked');
          menuPanelClose();
        });
      });
      // Helper functions
      function menuPanelClose() {
        $('body').removeClass('menu-panel-expanded');
      }

      function menuPanelToggleMenu() {
        $('body').toggleClass('menu-panel-expanded');
      }
    }
  };

  Drupal.behaviors.bs3_overrides = {
    attach: function(context, settings) {
      $('.region-footer .block-menu-block li').removeClass('dropdown');

      $('.region-footer .block-menu-block li a').removeClass('dropdown-toggle');
      $('.region-footer .block-menu-block .caret').remove();


      $('.region-footer .block-menu-block li ul').removeClass('dropdown-menu');
    }
  };

  Drupal.behaviors.bs3_overrides_navigation_menu = {
    attach: function(context, settings) {
      $('.menu.nav li').hover(
        function() {
          $('.dropdown-menu', this).show();
        },
        function() {
          $('.dropdown-menu', this).hide();
        }
      );
    }
  };


  Drupal.behaviors.c_flexslider_video_carousel = {
    attach: function(context, settings) {
      $(document).ready(function() {
        custom_video_lists_flexslider_carousel();
      });
    }
  };

  // FlexSlider API: https://github.com/woothemes/FlexSlider/wiki/FlexSlider-Properties
  function custom_video_lists_flexslider_carousel(bp1, bp2, bp3, bp4) {
    //parameter defaults
    bp1 = bp1 || 1;
    bp2 = bp2 || 2;
    bp3 = bp3 || 3;
    bp4 = bp4 || 4;

    var currentBreakpoint;
    var didResize = true;

    // on window resize, set the didResize to true
    $(window).resize(function() {
      didResize = true;
    });

    // every 1/4 second, check if the browser was resized
    // we throttled this because some browsers fire the resize even continuously during resize
    // that causes excessive processing, this helps limit that
    setInterval(function() {
      if (didResize) {
        didResize = false;

        // inspect the CSS to see what breakpoint the new window width has fallen into
        var newBreakpoint = window.getComputedStyle(document.body, ':after').getPropertyValue('content');

        /* tidy up after inconsistent browsers (some include quotation marks, they shouldn't) */
        newBreakpoint = newBreakpoint.replace(/"/g, "");
        newBreakpoint = newBreakpoint.replace(/'/g, "");

        // if the new breakpoint is different to the old one, do some stuff
        if (currentBreakpoint != newBreakpoint) {

          $('.c-flexslider-video-carousel').each(function(index) {
            var raw_slider = $(this).find('.flexslider').html();

            // remove the old flexslider (which has attached event handlers and adjusted DOM nodes)
            $(this).find('.flexslider').remove();

            // now re-insert clean mark-up so flexslider can run on it properly
            $(this).append("<div class='flexslider'></div>");
            $(this).find('.flexslider').html(raw_slider);
            $window_width = $(window).width();

            switch (newBreakpoint) {
              case 'breakpoint_1':

                currentBreakpoint = 'breakpoint_1';
                // Slider with one slide
                $flex = $(this).find('.flexslider');
                $flex.flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $window_width,
                  minItems: bp1,
                  maxItems: bp1,
                  controlNav: false,
                  animationSpeed: 400
                });

                break;
              case 'breakpoint_2':

                currentBreakpoint = 'breakpoint_2';
                // Slider with one slide
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $window_width / 2,
                  minItems: bp2,
                  maxItems: bp2,
                  controlNav: false,
                  animationSpeed: 400
                });

                break;
              case 'breakpoint_3':

                currentBreakpoint = 'breakpoint_3';
                // 3 slides
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $window_width / 3,
                  minItems: bp3,
                  maxItems: bp3,
                  controlNav: false,
                  animationSpeed: 400
                });

                break;
              case 'breakpoint_4':

                currentBreakpoint = 'breakpoint_4';
                // 4 slides
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $window_width / 4,
                  minItems: bp4,
                  maxItems: bp4,
                  controlNav: false,
                  animationSpeed: 400
                });

                break;
              default:
                currentBreakpoint = 'breakpoint_4';
                // 4 slides
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $window_width / 4,
                  minItems: bp4,
                  maxItems: bp4,
                  controlNav: false,
                  animationSpeed: 400
                });
            }

          });
        }
      }
    }, 250);
  }

  // @todo code comes from SPNN -- fix this, breaks vcam's blog, but is it needed on SPNN?
  // Drupal.behaviors.bs3_archive_pg_adjust_height = {
  //   attach: function (context, settings) {
  //     $(window).on('load resize',function() {
  //       var browserWidth = $(window).width();
  //       //console.log(browserWidth);

  //       if (browserWidth > 990) {
  //         var leftHeight = $('.two-col-list li .container .left').height();
  //         //console.log(leftHeight);

  //         $('.two-col-list li .container .right').height(leftHeight);
  //       }
  //       else {
  //         $('.two-col-list li .container .right').height('auto');
  //       }

  //     });
  //   }
  // };

  // @todo move this to cm_boostrap_custom_blocks module
  Drupal.behaviors.bs3_add_item_num_to_video_block = {
    attach: function(context, settings) {
      $(window).on('load', function() {
        var i = 1;
        $('.block-cm-bootstrap-custom-blocks h2.block-title').each(function(index) {
          $(this).addClass('cb-vl-item-' + i++);
          //console.log(this);
        });
      });
    }
  };

  // Adjust height of sidebar on partner + series to match height of video.
  Drupal.behaviors.bs3_partner_and_series_sidebar = {
    attach: function(context, settings) {
      $(window).on('load resize', function() {
        var browserWidth = $(window).width();
        if (browserWidth > 768) {
          var colHeight = $('.node-type-partner .col-sm-8').height();
          //console.log(colHeight);
          $('.node-type-partner .col-sm-4').height(colHeight);
        } else {
          $('.node-type-partner .col-sm-4').height('auto');
        }
      });
      $(window).on('load resize', function() {
        var browserWidth = $(window).width();
        if (browserWidth > 768) {
          var colHeight = $('.node-type-cm-project .col-sm-8').height();
          //console.log(colHeight);
          $('.node-type-cm-project .col-sm-4').height(colHeight);
        } else {
          $('.node-type-cm-project .col-sm-4').height('auto');
        }
      });
    }
  };
  // Adjust height of sidebar on show node to match height of video.
  Drupal.behaviors.bs3_cm_show_sidebar = {
    attach: function(context, settings) {
      $(window).on('load resize', function() {
        //$(document).ready(function() {
        var browserWidth = $(window).width();
        if (browserWidth > 996) {

          var colHeight;

          // Default show images won't have this markup
          if ($('.node-type-cm-show .col-sm-8 .field-name-field-show-vod').length) {
            colHeight = $('.node-type-cm-show .col-sm-8 .field-name-field-show-vod').height();
          }
          // Account for default show images
          else {
            colHeight = $('.fluid-width-video-wrapper').height();
          }

          var metaBoxHeight = $('.node-type-cm-show .show-meta').height();
          //console.log(colHeight);
          //$('.node-type-cm-show .region-sidebar-second').hide();
          $('.node-type-cm-show .region-sidebar-second .tab-content').height(colHeight - 35);
          $('.node-type-cm-show .region-sidebar-second .tab-content').css('min-height', colHeight - 35);
          $('.node-type-cm-show .region-sidebar-second .tab-content').css('max-height', colHeight - 35);
          //$('.node-type-cm-show .region-sidebar-second').fadeIn();
        } else {
          //console.log('no min height');
          $('.node-type-cm-show .region-sidebar-second .tab-content').height('auto');

          $('.node-type-cm-show .region-sidebar-second .tab-content').css('min-height', 'initial');
          $('.node-type-cm-show .region-sidebar-second .tab-content').css('max-height', 'initial');
        }
        //});
      });
    }
  };

  // Hide certains tabs + reset active state to first remaining.
  Drupal.behaviors.cm_bootstrap_show_sidebar_mobile = {
    attach: function(context, settings) {
      $(window).on('load resize', function() {
        var browserWidth = $(window).width();
        if (browserWidth < 990) {
          $('.node-type-cm-show .region-sidebar-second ul.nav-tabs li.recent-videos').remove();
          $('.node-type-cm-show .region-sidebar-second .tab-content #recent-video').remove();
          $('.nav-tabs li:first').addClass('active');
          $('.node-type-cm-show .region-sidebar-second .tab-content .tab-pane:first').addClass('active');
        }
      });
    }
  };

  //
  // Drupal.behaviors.user_profile_ajax_load = {
  //   attach: function (context, settings) {
  //     $('ul.user-statistics li a').click(function(e) {
  //       e.preventDefault();
  //       e.stopPropagation();

  //       var href = $(this).attr('href');
  //       console.log(href);

  //       var htmlElement;

  //       switch (href) {
  //         case '/user/1/likes':
  //           htmlElement = 'ul.user-shows-likes';
  //           break;
  //         case '/user/1/followers':
  //         case '/user/1/following':
  //           htmlElement = 'ul.user-grid';
  //           break;
  //       }
  //       $('.recent-videos').load(href + ' ' + htmlElement);
  //     });
  //   }
  // };

  // Hide chapters + extract air date data for mobile.
  // wluisi 5/23/2015 -- not used for now.
  // Drupal.behaviors.cm_bootstrap_airdate_mobile = {
  //   attach: function (context, settings) {
  //     $(document).ready(function() {
  //       var browserWidth = $(window).width();
  //       //console.log(browserWidth);
  //       // Store original tabs markup
  //       var originalTabsMarkup = $('.main-container .col-sm-4').clone();
  //       if (browserWidth < 768) {
  //         var airDateHtml = $('#airdate').clone();
  //         console.log(airDateHtml);
  //         var chapterAirdateTabs = $('.region-sidebar-second div[role="tabpanel"]');
  //         // Remove chapters + tabs
  //         chapterAirdateTabs.remove();
  //         // Wrap airDateHtml in container div
  //         $(airDateHtml).wrapInner('<div class="airdate-container"></div>');
  //         // Append airDateHtml to 2nd sidebar
  //         $(airDateHtml).appendTo('.region-sidebar-second');
  //       }
  //       else {
  //         console.log(originalTabsMarkup);
  //         //$('.main-container .col-sm-4').remove();
  //         //$('.airdate-container').html(originalTabsMarkup);
  //         //console.log(originalTabsMarkup);
  //         //$('.region-sidebar-second div[role="tabpanel"]').replaceWith(originalTabsMarkup);
  //       }
  //     });
  //   }
  // };

  Drupal.behaviors.bs3_video_flexslider_fix = {
    attach: function(context, settings) {

      $(document).ready(function() {

        function flexSliderSortFix() {
          // Set section IDs we are targeting below.
          var sliderSectionId, sliderSectionIds = [
            '#block-cm-bootstrap-custom-blocks-front-pg-ls-carousel',
            '#block-cm-bootstrap-custom-blocks-cb-custom-video-lists-front',
            '#block-cm-bootstrap-custom-blocks-cmb-cb-shows-in-series'
          ];

          // Iterate over each section ID
          for (sliderSectionId in sliderSectionIds) {

            $(sliderSectionId + ' .slides').each(function() {
              var slides = $(this);
              //console.log(sliderSectionId);
              //console.log(slides);

              // Get all LI items
              var items = $(slides).find('li').get();
              //console.log(items);

              // Sort items
              items.sort(function(a, b) {
                // Set vars
                var keyA = $(a).data('slide-item');
                var keyB = $(b).data('slide-item');

                // Normal Order
                if (keyA < keyB) {
                  return -1;
                }
                if (keyA > keyB) {
                  return 1;
                }

                // Reverse Order
                //if (keyA > keyB) return -1;
                //if (keyA < keyB) return 1;
                return 0;
              });

              var ul = $(slides);

              $.each(items, function(i, li) {
                ul.append(li);
                // Last item is getting cloned and put first.
                // So just remove this
                ul.find('li.clone').hide();
              });

            });
          }
        }
        setTimeout(flexSliderSortFix, 1000)
      });
    }
  };

  Drupal.behaviors.cmb_search_overlay_toggle = {
    attach: function(context, settings) {
      $('.search-overlay-open').click(function(e) {
        e.preventDefault();
        $('#search-overlay').show();
      });

      // Close
      $('.search-overlay-close').click(function(e) {
        e.preventDefault();
        $('#search-overlay').hide();
      });
    }
  };

  Drupal.behaviors.cmb_search_default_filter_values = {
    attach: function(context, settings) {
      $('#edit-submit-solr-search').click(function(e) {
        //console.log('on document ready!');
        //$('body').data('initial', false);
        $('body').addClass('search-solr-ajax');
      });

      $(document).ready(function() {
        if (!$('body').hasClass('search-solr-ajax')) {
          $('.view-solr-search .views-exposed-form #edit-node-type-page').prop('checked', true);
          $('.view-solr-search .views-exposed-form #edit-node-type-blog').prop('checked', true);
          $('.view-solr-search .views-exposed-form #edit-node-type-cm-project').prop('checked', true);
          $('.view-solr-search .views-exposed-form #edit-node-type-cm-show').prop('checked', true);
          $('.view-solr-search .views-exposed-form #edit-node-type-genre').prop('checked', true);
          $('.view-solr-search .views-exposed-form #edit-node-type-cmbs-producer').prop('checked', true);

          // "Events"
          if ($('.view-solr-search .views-exposed-form #edit-node-type-cmbs-event').length) {
            $('.view-solr-search .views-exposed-form #edit-node-type-cmbs-event').prop('checked', true);
          }
        }
      });
    }
  };

  Drupal.behaviors.cmb_search_adv_filters_icon_toggle = {
    attach: function(context, settings) {
      $('.views-ef-fieldset-container', context).click(function(e) {
        $(this).toggleClass('active');
      });
    }
  };

  Drupal.behaviors.cmb_search_add_icon = {
    attach: function(context, settings) {
      $(document).ready(function() {
        $('.views-exposed-form #edit-search-term', context).before('<span class="search-icon"></span>');
      });
    }
  };

  // Drupal.behaviors.bs3_video_flexslider_fix = {
  //   attach: function (context, settings) {
  //     jQuery(document).ready(function($) {

  //       if (window.history && window.history.pushState) {

  //         //window.history.pushState('forward', null, './#forward');

  //         $(window).on('popstate', function() {
  //           //alert('Back button was pressed.');
  //           console.log('back button pressed!');
  //         });

  //       }
  //     });

  //   }
  // };

  Drupal.behaviors.cmb_cue_points_desrc = {
    attach: function(context, settings) {
      $('.cue-field-popcornjs a').click(function(e) {
        var description = $(this).find('.description');
        $('.video-chapters-cue-points li a span.description.active').removeClass('active');
        $(description).toggleClass('active');
      });
    }
  };

  // "Recent News" Block Set left and right col
  Drupal.behaviors.cmb_theme__recent_news_block__normalize_height = {
    attach: function (context, settings) {

      var recentNewsHeight = function () {
        var width = $(window).width();
        // Only run for certain browser widths
        if (width > 640) {
          // Get height from left col
          var colHeight = $('ul.cb-recent-news li a .left').height();
          // Set height for right col
          $('ul.cb-recent-news li a .right').height(colHeight);
        }
        else {
          colHeight = 96;
          $('ul.cb-recent-news li a .right').height(colHeight);
        }
      };

      $(document).ready(recentNewsHeight);
      $(window).resize(recentNewsHeight);

    }
  };

})(jQuery);
