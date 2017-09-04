/*(function ($, Drupal, drupalSettings) {

  // Header menu icon
  Drupal.behaviors.ftnm__header_menu_icon = {
    attach: function (context, settings) {

      $(document).ready(function(){
      	$('#header-menu__icon').click(function(){
      		$(this).toggleClass('open');
      	});
      });

    }
  };

})(jQuery, Drupal, drupalSettings);
*/

$(document).ready(function(){
  $('#header__menu').click(function(){
    $(this).toggleClass('is-open');

    // Show header menu overlay
    $('#header__menu-overlay').toggleClass('is-open');
  });
});
