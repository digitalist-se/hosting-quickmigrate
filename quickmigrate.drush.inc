<?php

/**
 * @file
 * This file provides drush integration for quickmigrate.
 * It communiciates with the vnodectrl drush backend and provides
 * it with information it needs.
 */

/* function drush_quickmigrate_pre_hosting_task() { */
/*   $task =& drush_get_context('HOSTING_TASK'); */
/*   if ($task->ref->type == 'server' && ($task->task_type == 'create-server' || $task->task_type == 'delete-server' || $task->task_type == 'server-info')) { */
/*     drush_log(print_r($task->ref, TRUE), 'ok'); */
/*     $task->options['provider'] = $task->ref->provider; */
/*     $task->options['image'] = $task->ref->image; */
/*     $task->options['name'] = $task->ref->title; */
/*     $task->options['size'] = $task->ref->size; */
/*     $task->options['instance_id'] = $task->ref->instance_id; */
/*     $task->options['additional'] = implode('|', $task->ref->additional); */
/*   } */
/*   else { */
/*     drush_log("something went wrong", 'error'); */
/*   } */
/* } */

/* function drush_quickmigrate_post_hosting_task() { */
/*   $task = & drush_get_context('HOSTING_TASK'); */
/*   if ($task->ref->type == 'server' && $task->task_type == 'create-server') { */
/*     $output =& drush_get_context('HOSTING_DRUSH_OUTPUT'); */
/*     drush_log(print_r($output['object'], TRUE), 'ok'); */
/*     if (isset($output['object']['node']['id'])) { */
/*       // Save the machine ID so we can operate on it. */
/*       $task->ref->instance_id = $output['object']['node']['id']; */
/*       node_save($task->ref); */
/*     } */
/*   } */
/*   elseif ($task->ref->type == 'server' && $task->task_type == 'delete-server') { */
/*     // Remove the machine ID since it is now removed. */
/*     $task->ref->instance_id = ''; */
/*     $task->ref->ip_addresses = array(); */
/*     node_save($task->ref); */
/*   } */
/*   elseif ($task->ref->type == 'server' && $task->task_type == 'server-info') { */
/*     // Fill in relevant information about the server. */
/*     $output =& drush_get_context('HOSTING_DRUSH_OUTPUT'); */
/*     drush_log(print_r($output['object'], TRUE), 'ok'); */
/*     if (isset($output['object']['node']['public_ips'])) { */
/*       drush_log('yeah'); */
/*       $task->ref->ip_addresses = $output['object']['node']['public_ips']; */
/*       node_save($task->ref); */
/*     } */
/*   } */
/* } */
