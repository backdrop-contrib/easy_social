<?php
/**
 * @file
 * Variable integration for easy_social.
 * Moved here for reference, when variable support was removed.
 */

/**
 * Implements hook_variable_info().
 */
function easy_social_variable_info() {
  $variables = array();

  // Global settings.
  $variables['easy_social_ignore_paths'] = array(
    'title' => t('Easy Social Global Ignore Paths'),
    'default' => '',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_global_type'] = array(
    'title' => t('Easy Social Global Widget Type'),
    'default' => 1,
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_global_widgets'] = array(
    'title' => t('Easy Social Global Widgets'),
    'default' => array(
      'twitter' => 'twitter',
      'facebook' => 'facebook',
      'linkedin' => 'linkedin',
    ),
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_global_order'] = array(
    'title' => t('Easy Social Widget Order'),
    'default' => array('twitter', 'facebook', 'linkedin'),
    'group' => 'easy_social',
    'token' => FALSE,
  );

  // Custom settings per content type.
  $node_types = node_type_get_types();

  foreach ($node_types as $type => $typeobj) {
    $variables["easy_social_{$type}_enable"] = array(
      'title' => t('Enable Easy Social for nodes of type %type', array('%type' => $typeobj->name)),
      'default' => FALSE,
      'group' => 'easy_social',
      'token' => FALSE,
    );

    $variables["easy_social_comment_{$type}_enable"] = array(
      'title' => t('Enable Easy Social on comments for nodes of type %type', array('%type' => $typeobj->name)),
      'default' => FALSE,
      'group' => 'easy_social',
      'token' => FALSE,
    );

    $variables["easy_social_{$type}_count"] = array(
      'title' => t('Number of Easy Social fields for nodes of type %type', array('%type' => $typeobj->name)),
      'default' => 1,
      'group' => 'easy_social',
      'token' => FALSE,
    );

    $variables["easy_social_{$type}_type"] = array(
      'title' => t('Easy Social Widget type for nodes of %type', array('%type' => $typeobj->name)),
      'default' => 1,
      'group' => 'easy_social',
      'token' => FALSE,
    );

    $variables["easy_social_{$type}_widgets"] = array(
      'title' => t('Easy Social Widgets for nodes of %type', array('%type' => $typeobj->name)),
      'default' => FALSE,
      'group' => 'easy_social',
      'token' => FALSE,
    );
  }

  // Custom settings for blocks.
  $variables['easy_social_block_count'] = array(
    'title' => t('Number of Easy Social blocks'),
    'default' => 1,
    'group' => 'easy_social',
    'token' => FALSE,
  );

  // This is done like this because calling variable_get_value() inside here = WSOD.
  for ($i = 1; $i <= EASY_SOCIAL_BLOCK_MAX; ++$i) {
    $variables["easy_social_block_{$i}_title"] = array(
      'title' => t('Block title'),
      'default' => '',
      'group' => 'easy_social',
      'token' => FALSE,
    );

    $variables["easy_social_block_{$i}_override"] = array(
      'title' => t('Override settings for this block'),
      'default' => FALSE,
      'group' => 'easy_social',
      'token' => FALSE,
    );

    $variables["easy_social_block_{$i}_type"] = array(
      'title' => t('Widget Type'),
      'default' => 1,
      'group' => 'easy_social',
      'token' => FALSE,
    );

    $variables["easy_social_block_{$i}_widgets"] = array(
      'title' => t('Enabled Widgets'),
      'default' => array(),
      'group' => 'easy_social',
      'token' => FALSE,
    );
  }

  // Custom settings for Twitter.
  $variables['easy_social_twitter_account_via'] = array(
    'title' => t('Easy Social Global Mention Account'),
    'default' => '',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_twitter_account_related'] = array(
    'title' => t('Easy Social Global Related Account'),
    'default' => '',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_twitter_account_description'] = array(
    'title' => t('Easy Social Global Twitter Description'),
    'default' => 'Check it out!',
    'group' => 'easy_social',
    'token' => FALSE,
  );
  $variables['easy_social_twitter_count_show'] = array(
    'title' => t('Easy Social Global Twitter Show Count option'),
    'default' => 1,
    'group' => 'easy_social',
    'token' => FALSE,
  );

  // Custom settings for Facebook.
  $variables['easy_social_facebook_appid'] = array(
    'title' => t('Facebook Application ID'),
    'default' => '',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_widget_type'] = array(
    'title' => t('Facebook widget type'),
    'default' => 'iframe',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_send_button'] = array(
    'title' => t('Send Button (XFBML Only)'),
    'default' => FALSE,
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_width_vertical'] = array(
    'title' => t('Show faces'),
    'default' => '48',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_width_horizontal'] = array(
    'title' => t('Show faces'),
    'default' => '88',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_show_faces'] = array(
    'title' => t('Show faces'),
    'default' => TRUE,
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_verb'] = array(
    'title' => t('Verb to display'),
    'default' => 'like',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_color_scheme'] = array(
    'title' => t('Color Scheme'),
    'default' => 'light',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_facebook_font'] = array(
    'title' => t('Font'),
    'default' => 'default',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  // Custom settings for Google+.
  $variables['easy_social_googleplus_annotation'] = array(
    'title' => t('Annotation'),
    'default' => 'bubble',
    'group' => 'easy_social',
    'token' => FALSE,
  );

  $variables['easy_social_googleplus_html5'] = array(
    'title' => t('HTML5 valid syntax'),
    'default' => TRUE,
    'group' => 'easy_social',
    'token' => FALSE,
  );

  // Custom settings for LinkedIn.
  $variables['easy_social_linkedin_count_show'] = array(
    'title' => t('Easy Social Global LinkedIn Show Count option'),
    'default' => 1,
    'group' => 'easy_social',
    'token' => FALSE,
  );

  return $variables;
}
