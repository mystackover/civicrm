<?php
/**
 * @file
 * Module custom functions.
 */

/**
 * This function is used to validate UK,Canada,US postcodes.
 */
function civicrm_contact_distance_search_ispostcode($postcode) {
  $postcode = strtoupper(str_replace(' ', '', $postcode));
  if (preg_match("/^[A-Z]{1,2}[0-9]{2,3}[A-Z]{2}$/", $postcode) || preg_match("/^[A-Z]{1,2}[0-9]{1}[A-Z]{1}[0-9]{1}[A-Z]{2}$/", $postcode) || preg_match("/^GIR0[A-Z]{2}$/", $postcode)) {
    return TRUE;
  }
  elseif (preg_match("/^[^dfioquwz][0-9][^dfioqu][0-9][^dfioqu][0-9]$/i", $postcode)) {
    return TRUE;
  }
  elseif (preg_match("/^([0-9]{5})(-[0-9]{4})?$/i", $postcode)) {
    return TRUE;
  }
  return FALSE;
}
