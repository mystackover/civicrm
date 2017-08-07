INTRODUCTION
------------
CiviCRM contact distance search module enable the facility to search
CiviCRM contacts based on distance from perticular UK,CA,US post codes

This will create a new drupal view for CiviCRM contacts
that view can be extendable.


INSTALLATION
------------
Follow the steps below to install.

1. Conatct's primary address and Latitude, Longitude information needed 
   to be filled for search CiviCRM contacts based on distance.
   Latitude, Longitude information can be filled by 
   executing "Geocode and Parse Addresses" sheduled job 
   ( www.yourdomain.com/civicrm/admin/job?reset=1 )

2. Install the module as normal drupal module.
   more info 
   ( https://www.drupal.org/documentation/install/modules-themes/modules-7 )

3. clear all cache

4. Export and save the view civicrm_contact_distance_search for backup
   purpose before you add extra filters on view.

4. admin/config/development/google_api_key
   Add the google map api key to get advanced searching counts per day
   To get api key
   --------------
   * Login in to https://console.developers.google.com
   * Create project for api (also able to use exisitng one)
   * Click on project
   * Navigate to APIs & auth >> APIs
   * Under the Google Maps APIs section enable
     Google Maps JavaScript API v3 & Geocoding API
   * Navigate to APIs & auth >> Credentials
   * Under the Key for browser applications section you can find the API key 
 
5. Access the url www.yourdomain.com/civicrm-contact-distance-search 
   to get the view page
   (default searching miles 2500)
