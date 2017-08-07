<?php
/**
 * @file
 * Module admin page settings.
 */

/**
 * Implements hook_permission().
 */
function civicrm_contact_distance_search_permission() {
  return array(
    'administer civicrm_contact_distance_search settings' => array(
      'title' => t('Access google api setting of civicrm_contact_distance'),
    ),
  );
}

/**
 * Implements hook_admin().
 */
function civicrm_contact_distance_search_admin() {
  $form = array();
  $form['civicrm_contact_distance_search_googleapi'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API Key'),
    '#default_value' => variable_get('civicrm_contact_distance_search_googleapi'),
    '#size' => 100,
    '#description' => t("Add the Google Maps API Key here for civicrm contact distance search"),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
