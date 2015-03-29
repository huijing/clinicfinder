/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

(function ($) {
  // Toggle for more clinic information
  $(document).ready(function() {
    $('.view-display-id-clinics .ds-bottom').hide();
    $( ".view-display-id-clinics .ds-top" ).append( "<p id='toggle'>More</p>" );

    $('#toggle').bind('click',function(){
      $(this).parent().next().toggleClass('reveal');
    });
  });
})(jQuery);
