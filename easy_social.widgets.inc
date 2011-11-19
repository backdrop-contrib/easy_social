<?php

/**
 * @file Easy Social default widget markup functions
 */

/**
 * Generate the needed markup for the facebook share link
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @return string the html markup
 */
function _easy_social_widget_facebook_markup($url, $type, $title = NULL, $lang = 'en_US') {
  if ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) {
    $type_box = 'button_count';
    $markup = <<<FB
      <iframe class="fb-widget" 
      src="http://www.facebook.com/plugins/like.php?href={$url}&amp;locale={$lang}&amp;layout={$type_box}&amp;show_faces=false&amp;width=86&amp;action=like&amp;font=trebuchet+ms&amp;colorscheme=light&amp;height=21" 
      scrolling="no" 
      frameborder="0" 
      style="border:none; overflow:hidden; width:87px; height:21px;" 
      allowTransparency="true"></iframe>
FB;
  }
  else {
    $type_box = 'box_count';
    $markup = <<<FB
      <iframe class="fb-widget" 
      src="http://www.facebook.com/plugins/like.php?href={$url}&amp;locale={$lang}&amp;layout={$type_box}&amp;show_faces=false&amp;width=450&amp;action=like&amp;font=trebuchet+ms&amp;colorscheme=light&amp;height=21" 
      scrolling="no" 
      frameborder="0" 
      style="border:none; overflow:hidden; width:48px; height:60px;" 
      allowTransparency="true"></iframe>
FB;
  }
  return $markup;
}

/**
 * Generate the needed markeup for the googleplus share link
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @return string the html markup
 */
function _easy_social_widget_googleplus_markup($url, $type, $title = NULL, $lang = 'en_US') {
  $type = ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) ? 'medium' : 'tall';
  $markup = <<<GP
<g:plusone size="{$type}" href="{$url}"></g:plusone>
GP;
  return $markup;
}

/**
 * Generate the needed markeup for the linkedin share link
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @return string the html markup
 */
function _easy_social_widget_linkedin_markup($url, $type, $title = NULL, $lang = 'en_US') {
  $type = ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) ? 'right' : 'top';
  $markup = <<<LI
<script type="in/share" data-url="{$url}" data-counter="{$type}"></script>
LI;
  return $markup;
}

/**
 * Generate the needed markup for the twitter share link
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @return string the html markup
 */
function _easy_social_widget_twitter_markup($url, $type, $title = NULL, $lang = 'en') {
  $type = ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) ? 'horizontal' : 'vertical';

  $account_via = variable_get_value('easy_social_twitter_account_via');
  $account_related = variable_get_value('easy_social_twitter_account_related');
  $description = variable_get_value('easy_social_twitter_account_description');

  $markup = <<<TT
<a href="http://twitter.com/share" class="twitter-share-button" 
data-url="{$url}" 
data-count="{$type}"
data-lang = "{$lang}"
data-via="{$account_via}" 
data-related="{$account_related}:{$account_related_description}" 
data-text="{$title}">Tweet</a>
TT;
  return $markup;
}