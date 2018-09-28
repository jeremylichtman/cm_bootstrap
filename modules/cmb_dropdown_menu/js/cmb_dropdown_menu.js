(function($) {

  Drupal.behaviors.cmb_dropdown_menu__menu = {
    attach: function(context, settings) {
      var windowWidth = $(window).width();
      // Touch screens
      if (windowWidth <= 768) {

        /*$('#cmb-dropdown-menu ul li > a').click(function(e) {
          e.preventDefault();
        });
        */
        $('#cmb-dropdown-menu li:has(ul)').doubleTapToGo();

        /*$('#cmb-dropdown-menu ul li > a').toggle(function(e) {
          e.preventDefault();
          console.log('click 1');

          // Remove class
          $('#cmb-dropdown-menu ul.is-open').removeClass('is-open');

          // Add open class
          $(this).closest('li').children('ul').addClass('is-open');
        }, function() {
          console.log('click 2');

          // Remove class
          //$('#cmb-dropdown-menu ul.is-open').removeClass('is-open');
          $(this).closest('ul.is-open').removeClass('is-open');

          // Add open class
          $(this).closest('li').children('ul').addClass('is-open');
        });*/
      }
    }
  };

})(jQuery);
