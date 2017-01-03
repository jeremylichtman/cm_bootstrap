(function($) {
  Drupal.behaviors.cc_slider__flexslider = {
    attach: function (context, settings) {
      $(window).load(function() {
        $('.flexslider').flexslider({
          animation: "slide",
          controlNav: true,
          slideshow: false,
          start: function(slider) {
            $.flexloader(slider);
          },
          after: function(slider) {
            $.flexloader(slider);
          }
        });
      });
    }
  };
})(jQuery);
