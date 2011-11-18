<?php
/**
 * @file Easy Social default widget markup functions
 */

/**
 * Generate the needed markup for the facebook share link
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $data Actually not used
 * @return the html markup
 */
function _easysocial_widget_facebook_markup($url, $type, $data = NULL, $lang = 'en_US'){
  if($type == 0){
    $type_box = 'button_count';
    $markup = <<<FB
      <iframe class="fb-widget" 
      src="http://www.facebook.com/plugins/like.php?href={$url}&amp;locale={$lang}&amp;layout={$type_box}&amp;show_faces=false&amp;width=86&amp;action=like&amp;font=trebuchet+ms&amp;colorscheme=light&amp;height=21" 
      scrolling="no" 
      frameborder="0" 
      style="border:none; overflow:hidden; width:87px; height:21px;" 
      allowTransparency="true"></iframe>
FB;
  } else {
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
 * @param $data Actually not used
 * @return the html markup
 */
function _easysocial_widget_googleplus_markup($url, $type, $data = NULL, $lang = 'en_US'){
  $type = ($type == 0) ? 'medium' : 'tall';
  $markup = <<<GP
    <g:plusone size="{$type}" href="{$url}"></g:plusone>
GP;
    return $markup;
}

/**
 * Generate the needed markeup for the linkedin share link
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $data Actually not used
 * @return the html markup
 */
function _easysocial_widget_linkedin_markup($url, $type, $data = NULL, $lang = 'en_US'){
  $type = ($type == 0) ? 'right' : 'top';
  $markup = <<<LI
    <script type="in/share" data-url="{$url}" data-counter="{$type}"></script>
LI;
    return $markup;
}

/**
 * Generate the needed markup for the twitter share link
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $data Assoc array with info for the tweet
 * @return the html markup
 */
function _easysocial_widget_twitter_markup($url, $type, $data = NULL, $lang = 'en'){
  $type = ($type == 0) ? 'horizontal' : 'vertical';
  
  $account_via = variable_get_value('easysocial_tt_global_account_via');
  $account_related = variable_get_value('easysocial_tt_global_account_related');
  $description = variable_get_value('easysocial_tt_global_account_description');
  $description = str_replace('!title', $data['title'], $description);
  
  $markup = <<<TT
    <a href="http://twitter.com/share" 
    class="twitter-share-button" 
    data-url="{$url}" 
    data-count="{$type}"
    data-lang = "{$lang}"
    data-via="{$account_via}" 
    data-related="{$account_related}" 
    data-text="{$description}">Tweet</a>
TT;
  return $markup;
}