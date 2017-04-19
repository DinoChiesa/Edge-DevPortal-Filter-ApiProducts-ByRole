<?php
/**
 * @file
 * Apigee API Product list filter - included functions
 *
 * Supporting functions used in the module and the .install
 *
 */

function apigee_filter_apiprod_byrole_all_environments() {
  $available_environments = array("prod", "test"); /* default */
  try {
    $dca = new Apigee\ManagementAPI\DeveloperAppAnalytics(devconnect_default_org_config());
    $available_environments = $dca->getAllEnvironments();

    // the following did not work for me. :(
    /* $org = new Apigee\ManagementAPI\Organization(devconnect_default_org_config()); */
    /*  */
    /* $available_environments = $org->getEnvironments(); */
  }
  catch (Apigee\Exceptions\ResponseException $e) {
    watchdog('apiprods_filter',
             "Exception while retrieving environments: !exc",
             array('!exc' => $e),
             WATCHDOG_WARNING);
  }
  return $available_environments;
}


