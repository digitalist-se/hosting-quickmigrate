<?php

/**
 * @file
 * This file provides drush integration for quickmigrate.
 * It communiciates with the vnodectrl drush backend and provides
 * it with information it needs.
 */

/**
 * Implementation of hook_pre_hosting_task().
 */
function drush_hosting_quickmigrate_pre_hosting_task($task) {
  $task = & drush_get_context('HOSTING_TASK');
  if ($task->ref->type == 'site' && $task->task_type == 'quickmigrate') {
    $platform = node_load($task->task_args['target_platform']);
    $task->args[2] = hosting_context_name($platform->nid);

    $site = $task->ref;
    if (strtolower(trim($site->title)) != strtolower(trim($task->task_args['new_uri']))) {
      $task->args[3] = '@' . strtolower(trim($task->task_args['new_uri']));
    }

    $profile_instance = _hosting_migrate_get_target_profile_name($task);
    if (sizeof($profile_instance)) {
      $task->options['profile'] = $profile_instance->short_name;
    }
    else {
      drush_set_error("HOSTING_NO_VALID_PROFILE", dt("There are no valid install profiles on the target platform to migrate to"));
    }
  }
}
