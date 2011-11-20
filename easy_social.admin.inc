<?php

/**
 * @file Easy Social administration forms
 */

/**
 * Form callback
 * Main settings form
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

  return system_settings_form($form);
}

/**
 * Form callback
 * Ignore-paths settings form
 */
function _easy_social_admin_config_ignore_paths() {
  $form = array();

  $form['easy_social_ignore_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Ignore paths'),
    '#description' => t('Every URL placed here, will not have any Social links.'),
    '#default_value' => variable_get_value('easy_social_ignore_paths'),
  );

  return system_settings_form($form);
}

/**
 * Form callback
 * Home tab for extra settings pages
 */
function _easy_social_admin_config_extra() {
  $form = array();

  $form['easy_social_extra'] = array(
    '#markup' => '<h4>' . t('Use the secondary tabs on the right to access extra settings for certain widgets') . '</h4>',
  );

  return $form;
}

/**
 * Form callback
 * Extra settings for Twitter Widget
 */
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

  return system_settings_form($form);
}

/**
 * Form callback
 * Extra settings for Facebook Widget
 */
function _easy_social_admin_config_extra_facebook() {
  $form = array();

  $form['easy_social_facebook_title'] = array(
    '#markup' => '<h4>' . t('Facebook widget settings') . '</h4>',
  );

  $form['easy_social_facebook_info'] = array(
    '#markup' => t('For more information check out the official Facebook widget <a href="!link" target="_blank">documentation</a>.', array('!link' => 'http://developers.facebook.com/docs/reference/plugins/like/')),
  );

  $form['easy_social_facebook_appid'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Application ID'),
    '#description' => t("Insert your Application ID if you want to integrate the widget with an existing Facebook application. Leave it blank if you don't know what this means."),
    '#default_value' => variable_get_value('easy_social_facebook_appid'),
    '#size' => 30,
  );
  
  $form['easy_social_facebook_widget_type'] = array(
    '#type' => 'select',
    '#title' => t('Facebook widget type'),
    '#options' => array(
      'html5' => 'HTML5',
      'xfbml' => 'XFBML',
      'iframe' => 'IFRAME',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_widget_type'),
  );

  $form['easy_social_facebook_send_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send Button (XFBML Only)'),
    '#description' => t('Include a Send Button. The Send Button is available only on sites that use the Javascript SDK.'),
    '#default_value' => variable_get_value('easy_social_facebook_send_button'),
  );

  $form['easy_social_facebook_width_vertical'] = array(
    '#type' => 'textfield',
    '#title' => t('Vertical Widget Width'),
    '#description' => t('The width of the plugin, in pixels.'),
    '#default_value' => variable_get_value('easy_social_facebook_width_vertical'),
    '#size' => 30,
  );

  $form['easy_social_facebook_width_horizontal'] = array(
    '#type' => 'textfield',
    '#title' => t('Horizontal Widget Width'),
    '#description' => t('The width of the plugin, in pixels.'),
    '#default_value' => variable_get_value('easy_social_facebook_width_horizontal'),
    '#size' => 30,
  );

  $form['easy_social_facebook_show_faces'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show faces'),
    '#description' => t('Show profile pictures below the button.'),
    '#default_value' => variable_get_value('easy_social_facebook_show_faces'),
  );

  $form['easy_social_facebook_verb'] = array(
    '#type' => 'select',
    '#title' => t('Verb to display'),
    '#description' => t("The verb to display in the button. Currently only 'like' and 'recommend' are supported."),
    '#options' => array(
      'like' => 'Like',
      'recommend' => 'Recommend',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_verb'),
  );

  $form['easy_social_facebook_color_scheme'] = array(
    '#type' => 'select',
    '#title' => t('Color Scheme'),
    '#description' => t('The color scheme of the plugin.'),
    '#options' => array(
      'light' => 'light',
      'dark' => 'dark',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_color_scheme'),
  );

  $form['easy_social_facebook_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#description' => t('The font of the plugin.'),
    '#options' => array(
      'default' => 'default',
      'arial' => 'arial',
      'lucida grande' => 'lucida grande',
      'segoe ui' => 'segoe ui',
      'tahoma' => 'tahoma',
      'trebuchet ms' => 'trebuchet ms',
      'verdana' => 'verdana',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_font'),
  );

  return system_settings_form($form);
}

/**
 * Validation callback
 * 
 * @see _easy_social_admin_config_extra_facebook().
 */
function _easy_social_admin_config_extra_facebook_validate(&$form, &$form_state) {
  if (!is_numeric($form_state['values']['easy_social_facebook_width_vertical'])) {
    form_set_error('easy_social_facebook_width_vertical', t('Vertical Widget Width must be numeric'));
  }
  else if (!is_numeric($form_state['values']['easy_social_facebook_width_horizontal'])) {
    form_set_error('easy_social_facebook_width_horizontal', t('Horizontal Widget Width must be numeric'));
  }
}

/**
 * Form callback
 * Extra settings for Google+ Widget
 */
function _easy_social_admin_config_extra_googleplus() {
  $form = array();

  $form['easy_social_googleplus_title'] = array(
    '#markup' => '<h4>' . t('Google+ widget settings') . '</h4>',
  );

  $form['easy_social_googleplus_info'] = array(
    '#markup' => t('For more information check out the official Google+ widget <a href="!link" target="_blank">documentation</a>.', array('!link' => 'http://www.google.com/intl/en/webmasters/+1/button/index.html')),
  );

  $form['easy_social_googleplus_annotation'] = array(
    '#type' => 'select',
    '#title' => t('Annotation'),
    '#description' => t('How the count will appear'),
    '#options' => array(
      'bubble' => 'bubble',
      'inline' => 'inline',
      'none' => 'none',
    ),
    '#default_value' => variable_get_value('easy_social_googleplus_annotation'),
  );

  return system_settings_form($form);
}