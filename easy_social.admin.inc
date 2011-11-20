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
    '#title' => t('Block Settings'),
    '#description' => t('Custom settings for Blocks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $num_blocks = variable_get_value('easy_social_block_count');
  
  $form['block_settings']['easy_social_block_count'] = array(
    '#type' => 'select',
    '#title' => t('Number of Easy Social blocks'),
    '#description' => t('You can create up to !num Easy Social blocks', array('!num' => EASY_SOCIAL_BLOCK_MAX)),
    '#options' => range(0, EASY_SOCIAL_BLOCK_MAX),
    '#default_value' => $num_blocks,
    // @TODO show/hide fieldsets for block specific settings via ajax
  );
  
  for ($i = 1; $i <= $num_blocks; ++$i) {
    $form['block_settings']["easy_social_block_{$i}"] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom Settings for Block #!num', array('!num' => $i)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['block_settings']["easy_social_block_{$i}"]["easy_social_block_{$i}_title"] = array(
      '#type' => 'textfield',
      '#title' => t('Block title'),
      '#description' => t("Leave this blank if you don't want this block to have a title."),
      '#maxlength' => 255,
      '#default_value' => variable_get_value("easy_social_block_{$i}_title"),
    );

    $form['block_settings']["easy_social_block_{$i}"]["easy_social_block_{$i}_override"] = array(
      '#type' => 'checkbox',
      '#title' => t('Override settings for this block'),
      '#description' => t('Check this option to override the global settings for this block'),
      '#default_value' => variable_get_value("easy_social_block_{$i}_override"),
    );

    $form['block_settings']["easy_social_block_{$i}"]["easy_social_block_{$i}_type"] = array(
      '#type' => 'radios',
      '#title' => t('Widget Type'),
      '#options' => array(
        EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
        EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
      ),
      '#default_value' => variable_get_value("easy_social_block_{$i}_type")
    );

    $form['block_settings']["easy_social_block_{$i}"]["easy_social_block_{$i}_widgets"] = array(
      '#type' => 'checkboxes',
      '#title' => t('Enabled Widgets'),
      '#options' => $options,
      '#default_value' => variable_get_value("easy_social_block_{$i}_widgets"),
    );
  }
  
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