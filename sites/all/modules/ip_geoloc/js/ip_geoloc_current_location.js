(function ($) {

  Drupal.behaviors.addCurrentLocation = {
    attach: function (context, settings) {
      ip_geoloc_getCurrentPosition(
        settings.ip_geoloc_menu_callback,
        settings.ip_geoloc_reverse_geocode,
        settings.ip_geoloc_refresh_page
      );
    }
  }

})(jQuery);

function ip_geoloc_getCurrentPosition(callbackUrl, reverseGeocode, refreshPage) {

  if (typeof(getCurrentPositionCalled) !== 'undefined') {
    // Been here, done that (can happen in AJAX context).
    return;
  }

  if (navigator.geolocation) {
    var startTime = (new Date()).getTime();
    navigator.geolocation.getCurrentPosition(getLocation, handleLocationError, {enableHighAccuracy: true, timeout: 20000});
    getCurrentPositionCalled = true;
  }
  else {
    var data = new Object;
    data['error'] = Drupal.t('IPGV&M: device does not support W3C API.');
    callbackServer(callbackUrl, data, false);
  }

  function getLocation(position) {

    if (window.console && window.console.log) { // Does not work on IE8
      var elapsedTime = (new Date()).getTime() - startTime;
      window.console.log(elapsedTime/1000 + ' s to locate visitor');
    }
    var ip_geoloc_address = new Object;
    ip_geoloc_address['latitude']  = position.coords.latitude;
    ip_geoloc_address['longitude'] = position.coords.longitude;
    ip_geoloc_address['accuracy']  = position.coords.accuracy;

    if (!reverseGeocode) {
      // Pass lat/long back to Drupal without street address.
      callbackServer(callbackUrl, ip_geoloc_address, refreshPage);
      return;
    }
    // Reverse-geocoding of lat/lon requested.
    startTime = (new Date()).getTime();
    var location = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
    new google.maps.Geocoder().geocode({'latLng': location }, function(response, status) {

      if (status === google.maps.GeocoderStatus.OK) {
        var google_address = response[0];
        ip_geoloc_address['formatted_address'] = google_address.formatted_address;
        for (var i = 0; i < google_address.address_components.length; i++) {
          var component = google_address.address_components[i];
          if (component.long_name !== null) {
            var type = component.types[0];
            ip_geoloc_address[type] = component.long_name;
            if (type === 'country' && component.short_name !== null) {
              ip_geoloc_address['country_code'] = component.short_name;
            }
          }
        }
      }
      else {
        //alert(Drupal.t('IPGV&M: Google Geocoder returned error !code.', { '!code': status }));
        ip_geoloc_address['error'] = Drupal.t('getLocation(): Google Geocoder address lookup failed with status code !code.', { '!code': status });
        refreshPage = false;
      }
      if (window.console && window.console.log) {
        var elapsedTime = (new Date()).getTime() - startTime;
        window.console.log(elapsedTime/1000 + ' s to reverse-geocode to address');
      }

      // Pass lat/long, accuracy and address back to Drupal
      callbackServer(callbackUrl, ip_geoloc_address, refreshPage);
    });
  }

  function handleLocationError(error) {
    var data = new Object;
    data['error'] = Drupal.t('getCurrentPosition() returned error !code: !text. Browser: @browser',
      {'!code': error.code, '!text': error.message, '@browser': navigator.userAgent});
    // Pass error back to PHP rather than alert();
    callbackServer(callbackUrl, data, false);
  }

  function callbackServer(callbackUrl, data, refresh_page) {
    jQuery.ajax({
      url: callbackUrl,
      type: 'POST',
      dataType: 'json',
      data: data,
      success: function () {
      },
      error: function (http) {
        if (http.status > 0 && http.status !== 200 && http.status !== 404 && http.status !== 503) {
          // 404 may happen intermittently and when Clean URLs isn't enabled
          // 503 may happen intermittently, see [#2158847]
          alert(Drupal.t('IPGV&M: an HTTP error @status occurred.', { '@status': http.status }));
        }
      },
      complete: function() {
        if (refresh_page) {
          window.location.reload();
        }
      }
    });
  }
}
