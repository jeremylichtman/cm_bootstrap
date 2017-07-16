(function($) {
  Drupal.behaviors.cm_bootstrap_jumbotron_flexslider = {
    attach: function(context, settings) {
      $(document).ready(function() {
        $('.flexslider').flexslider({
          animation: "slide",
          controlNav: false,
          slideshow: true
        });
      });
    }
  };
})(jQuery);
