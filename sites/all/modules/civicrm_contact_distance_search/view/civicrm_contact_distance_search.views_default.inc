<?php
/**
 * @file
 * This view default view code.
 */

/**
 * Implements hook_views_default_views().
 */
function civicrm_contact_distance_search_views_default_views() {
  return civicrm_contact_distance_search_list_all_civi_contacts();
}

/**
 * The view creating function.
 */
function civicrm_contact_distance_search_list_all_civi_contacts() {
  $view = new view();
  $view->name = 'civicrm_contact_distance_search';
  $view->description = 'CiviCRM Contact Distance Search';
  $view->tag = 'default';
  $view->base_table = 'civicrm_contact';
  $view->human_name = 'CiviCRM Contact Distance Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;
  /* Edit this to true to make a default view disabled initially */
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CiviCRM Contact Distance Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';

  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';

  /* Field: CiviCRM Contacts: Contact ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['separator'] = '';

  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;

  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Distance in miles';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;

  /* Filter criterion: CiviCRM Address: Latitude */
  $handler->display->display_options['filters']['geo_code_1']['id'] = 'geo_code_1';
  $handler->display->display_options['filters']['geo_code_1']['table'] = 'civicrm_address';
  $handler->display->display_options['filters']['geo_code_1']['field'] = 'geo_code_1';
  $handler->display->display_options['filters']['geo_code_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['geo_code_1']['expose']['operator_id'] = 'geo_code_1_op';
  $handler->display->display_options['filters']['geo_code_1']['expose']['operator'] = 'geo_code_1_op';
  $handler->display->display_options['filters']['geo_code_1']['expose']['identifier'] = 'geo_code_1';
  $handler->display->display_options['filters']['geo_code_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'civicrm-contact-distance-search';
  $views[$view->name] = $view;
  return $views;
}
