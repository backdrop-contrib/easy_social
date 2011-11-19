<?php
/**
 * @file Easy Social administration forms
 */

function _easy_social_admin_config_main() {
  $form = array();

  $form['global_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global Settings'),
    '#description' => t('Global settings for all widgets'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['global_settings']['easy_social_global_type'] = array(
    '#type' => 'radios',
    '#title' => t('Type of buttons'),
    '#options' => array(
      EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
      EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
    ),
    '#default_value' => variable_get_value('easy_social_global_type'),
  );

  $options = _easy_social_get_options();
  
  $form['global_settings']['easy_social_global_widgets'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Social Buttons'),
    '#options' => $options,
    '#default_value' => variable_get_value('easy_social_global_widgets'),
  );

  // block settings
  
  $form['block_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Blocks'),
    '#description' => t('Custom settings for Blocks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['block_settings']['easy_social_block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Block title'),
    '#description' => t("Leave this blank if you don't want the block to have a title"),
    '#maxlength' => 255,
    '#default_value' => variable_get_value('easy_social_block_title'),
  );
  
  $form['block_settings']['override_settings_block'] = array(
    '#type' => 'fieldset',
    '#title' => t('Override Settings for Blocks'),
    '#description' => t('Override settings for Blocks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['block_settings']['override_settings_block']['easy_social_override_block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override'),
    '#description' => t('Check this option to override the global settings for blocks'),
    '#default_value' => variable_get_value('easy_social_override_block'),
  );

  $form['block_settings']['override_settings_block']['easy_social_override_block_type'] = array(
    '#type' => 'radios',
    '#title' => t('Type of buttons'),
    '#options' => array(
      EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
      EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
    ),
    '#default_value' => variable_get_value('easy_social_override_block_type')
  );
  
  $form['block_settings']['override_settings_block']['easy_social_override_block_widgets'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Social Buttons'),
    '#options' => $options,
    '#default_value' => variable_get_value('easy_social_override_block_widgets'),
  );
  
  $form = system_settings_form($form);

  return $form;
}

/**
 * Form callback
 * Return settings form for ignore-paths
 */
function _easy_social_admin_config_ignore_paths() {
  $form = array();

  $form['easy_social_ignore_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Ignore paths'),
    '#description' => t('Every URL placed here, will not have any Social links.'),
    '#default_value' => variable_get_value('easy_social_ignore_paths'),
  );

  $form = system_settings_form($form);

  return $form;
}

function _easy_social_admin_config_extra() {
  $form = array();
  
  $form['easy_social_extra'] = array(
    '#markup' => '<h4>' . t('Use the secondary tabs on the right to access extra settings for certain widgets') . '</h4>',
  );
  
  return $form;
}

function _easy_social_admin_config_extra_twitter() {
  $form = array();

  $form['easy_social_twitter_title'] = array(
    '#markup' => '<h4>' . t('Twitter widget settings') . '</h4>',
  );

  $form['easy_social_twitter_info'] = array(
    '#markup' => t('For more information check out the official Twitter widget <a href="!link" target="_blank">documentation</a>.', array('!link' => 'https://twitter.com/about/resources/tweetbutton')),
  );
  
  $form['easy_social_twitter_account_via'] = array(
    '#type' => 'textfield',
    '#title' => t('Mention account'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get_value('easy_social_twitter_account_via'),
  );

  $form['easy_social_twitter_account_related'] = array(
    '#type' => 'textfield',
    '#title' => t('Related account'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get_value('easy_social_twitter_account_related'),
  );

  $form['easy_social_twitter_account_description'] = array(
    '#type' => 'textfield',
    '#title' => t('Related account description'),
    '#size' => 120,
    '#maxlength' => 120,
    '#default_value' => variable_get_value('easy_social_twitter_account_description'),
  );
  
  return $form;
}