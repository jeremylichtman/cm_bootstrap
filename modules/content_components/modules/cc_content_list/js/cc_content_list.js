(function($) {
  Drupal.behaviors.cc_content_list = {
    attach: function (context, settings) {
      // Attach hover to overlay.
      $(".cc-cl--title-display-overlay .overlay-wrapper").hover(
        function() {
          $('.overlay', this).css("visibility", "visible");
        }, function() {
          $('.overlay', this).css("visibility", "hidden");
        }
      );
    }
  };
})(jQuery);
