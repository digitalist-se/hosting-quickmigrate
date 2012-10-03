<?php
/**
 * Implementation of hook_hosting_feature().
 */
function quickmigrate_hosting_feature() {
  $features['quickmigrate'] = array(
  // title to display in form
    'title' => t('Quick migrate'),
  // description
    'description' => t('Migrate sites and be quick about it.'),
  // initial status ( HOSTING_FEATURE_DISABLED, HOSTING_FEATURE_ENABLED, HOSTING_FEATURE_REQUIRED )
    'status' => HOSTING_FEATURE_DISABLED,
  // module to enable/disable alongside feature
    'module' => 'quickmigrate',
  // which group to display in ( null , experimental )
    'group' => 'experimental'
  );
  return $features;
}