<?php
/**
 * @file Easy Social links template
 * 
 * Variables available:
 * - $social_links: Assoc array with my share buttons html markup.
 *
 */
?>
<div id="easy_social_box">
  <?php foreach ($social_links as $name => $markup): ?>
    <span class="easy_social-widget easy_social-widget-<?php echo $name; ?>"><?php echo $markup; ?></span>
  <?php endforeach; ?>
</div><!-- /#easy_social_box -->