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
    '#collapsed' => TRUE,
  );

  $form['global_settings']['easy_social_global_typebtn'] = array(
    '#type' => 'radios',
    '#title' => t('Type of buttons'),
    '#options' => array(
      EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
      EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
    ),
    '#default_value' => variable_get_value('easy_social_global_typebtn'),
  );

  $widgets = easy_social_get_widgets();
  $options = array();
  
  foreach ($widgets as $k => $widget) {
    $options[$k] = isset($widget['name']) ? $widget['name'] : $k;
  }
  
  $form['global_settings']['easy_social_global_social_buttons'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Social Buttons'),
    '#options' => $options,
    '#default_value' => variable_get_value('easy_social_global_social_buttons'),
  );

  /**
   * @TODO figure out how to deal with extra settings fields for widgets
   */
  
  $form['global_settings']['twitter_global_data'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter Info'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['global_settings']['twitter_global_data']['easy_social_tt_global_account_via'] = array(
    '#type' => 'textfield',
    '#title' => t('Mention account'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get_value('easy_social_tt_global_account_via'),
  );

  $form['global_settings']['twitter_global_data']['easy_social_tt_global_account_related'] = array(
    '#type' => 'textfield',
    '#title' => t('Related account'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get_value('easy_social_tt_global_account_related'),
  );

  $form['global_settings']['twitter_global_data']['easy_social_tt_global_account_description'] = array(
    '#type' => 'textfield',
    '#title' => t('Related account description'),
    '#size' => 120,
    '#maxlength' => 120,
    '#default_value' => variable_get_value('easy_social_tt_global_account_description'),
    '#description' => 'Use !title for the current page title'
  );

  $form['override_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Override Settings by Content Type'),
    '#description' => t('Custom settings per Content Type'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $node_types = node_type_get_types();

  // sometimes when dealing with feature-defined content types they appear out of order
  // since this is an admin page we prefer organization over performance so go ahead and sort it
  ksort($node_types);

  foreach ($node_types as $type => $typeobj) {

    $form['override_settings']['easy_social_settings_type_' . $type] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom Settings for %type', array('%type' => $typeobj->name)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['override_settings']['easy_social_settings_type_' . $type]['easy_social_' . $type . '_override'] = array(
      '#type' => 'checkbox',
      '#title' => t('Override'),
      '#description' => t('Check this option to override the global settings for this type'),
      '#default_value' => variable_get_value('easy_social_' . $type . '_override'),
    );

    $form['override_settings']['easy_social_settings_type_' . $type]['easy_social_' . $type . '_typebtn'] = array(
      '#type' => 'radios',
      '#title' => t('Type of buttons'),
      '#options' => array(
        EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
        EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
      ),
      '#default_value' => variable_get_value('easy_social_' . $type . '_typebtn')
    );

    $form['override_settings']['easy_social_settings_type_' . $type]['easy_social_' . $type . '_social_buttons'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Social Buttons'),
      '#options' => $options,
      '#default_value' => variable_get_value('easy_social_' . $type . '_social_buttons'),
    );
  }

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

  $form['block_settings']['override_settings_block']['easy_social_override_block_typebtn'] = array(
    '#type' => 'radios',
    '#title' => t('Type of buttons'),
    '#options' => array(
      EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
      EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
    ),
    '#default_value' => variable_get_value('easy_social_override_block_typebtn')
  );
  
  $form['block_settings']['override_settings_block']['easy_social_override_block_social_buttons'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Social Buttons'),
    '#options' => $options,
    '#default_value' => variable_get_value('easy_social_override_block_social_buttons'),
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