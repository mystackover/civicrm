/**
 * @file
 * Javascript for postcode search.
 */

jQuery(document).ready(function() {
  jQuery("#mtl-find-location").click(function(event){
    event.preventDefault();
    jQuery("#mtl-find-location").find("#mtl-loading-span").remove();
    jQuery("#mtl-find-location").find("img").after('<span id="mtl-loading-span">Loading..</span>');
    if (navigator.geolocation) {
      function GeoSuccess(position) {
        mylocation = {latitude:'',longitude:''};
        mylocation.latitude = position.coords.latitude;
        mylocation.longitude = position.coords.longitude;
        var geocoder = new google.maps.Geocoder();
        var latLng = new google.maps.LatLng(mylocation.latitude, mylocation.longitude);
        if (geocoder) {
          geocoder.geocode({ 'latLng': latLng}, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK) {
              var found = false;
              for (var i = 0; i < results.length; i++) {
                if (results[i].types[0] == 'postal_code') {
                  if (results[i].address_components[0].long_name != '') {
                     jQuery('#edit-postcode-from').val(results[i].address_components[0].long_name);
                     found = true;
                  }
                }
              }
              /* If postcode not found */
              if (!found) {
                jQuery("#mtl-find-location").find("#mtl-loading-span").remove();
                jQuery("#mtl-find-location").find("img").after('<span id="mtl-loading-span">Postcode not found !</span>');
              }
              else {
                jQuery("#mtl-find-location").find("#mtl-loading-span").remove();
              }
            }
            /* If geocode not functioned */
            else {
              jQuery('#edit-postcode-from').val('');
              jQuery("#mtl-find-location").find("#mtl-loading-span").remove();
              jQuery("#mtl-find-location").find("img").after('<span id="mtl-loading-span">Postcode not found !</span>');
            }
          });
        }
      }
      function GeoFailure() {
        alert('There was an error.');
      }
      navigator.geolocation.getCurrentPosition(GeoSuccess, GeoFailure);
    }
  });
});
