(function($) {

  Drupal.behaviors.cmb_custom_video_list_context__flexslider = {
    attach: function(context, settings) {

      //console.log('cmb_custom_video_list__flexslider');

      // Breakpoint vars defaults
      var bp1 = bp1 || 1;
      var bp2 = bp2 || 2;
      var bp3 = bp3 || 3;
      var bp4 = bp4 || 4;

      var currentBreakpoint;
      var didResize = true;

      // on window resize, set the didResize to true
      $(window).resize(function() {
        didResize = true;
      });

      $(window).load(function() {

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

              $('.cc--custom-video-list-context').each(function(index) {
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
                        animationSpeed: 400,
                        start: function(slider) {
                          $.flexloader(slider);
                        },
                        after: function(slider) {
                          $.flexloader(slider);
                        }
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
                        animationSpeed: 400,
                        start: function(slider) {
                          $.flexloader(slider);
                        },
                        after: function(slider) {
                          $.flexloader(slider);
                        }
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
                        animationSpeed: 400,
                        start: function(slider) {
                          $.flexloader(slider);
                        },
                        after: function(slider) {
                          $.flexloader(slider);
                        }
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
                        animationSpeed: 400,
                        start: function(slider) {
                          $.flexloader(slider);
                        },
                        after: function(slider) {
                          $.flexloader(slider);
                        }
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
                        animationSpeed: 400,
                        start: function(slider) {
                          $.flexloader(slider);
                        },
                        after: function(slider) {
                          $.flexloader(slider);
                        }
                      });
                  }

              });
            }
          }
        }, 250);

      });

    }
  };

})(jQuery);
