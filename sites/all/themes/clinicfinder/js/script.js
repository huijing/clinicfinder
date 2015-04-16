/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

(function ($) {
  
  $(document).ready(function() {
    // Move open/close indicator up the DOM
    $('.view-display-id-clinics').find('.views-row').each(function(index, el) {
      var appendLocation = $(el).find(".addressfield-container-inline");
      $(el).find('.oh-current-open, .oh-current-closed').appendTo( appendLocation);
    });

    // Move home page text above the search bar
    $('#views-exposed-form-clincs-clinics').appendTo('.panel-display');

    // Toggle for more clinic information
    $('.view-display-id-clinics .ds-bottom').hide();
    $( ".view-display-id-clinics .ds-top" ).append( "<p class='toggle'>More</p>" );

    $('.toggle').bind('click',function(){
      $(this).parent().next().slideToggle();
    });
  });
})(jQuery);
