<?php
/**
 * @file
 * Theme functions for easy social.
 */

/**
 * Theme callback.
 * Implements draggable table in Easy Social sort form.
 *
 * @see easy_social_admin_order()
 * @see easy_social_theme()
 */
function theme_easy_social_admin_order($variables) {
  $output = '';
  $form = $variables['form'];
  $header = array('Title', 'Weight');
  $table_id = 'easy_social_widget_order';

  foreach (element_children($form['widgets']) as $id) {
    $data = array();
    $data[] = $form['widgets'][$id]['#widget'];
    $data[] = backdrop_render($form['widgets'][$id]['weight']);
    $rows[] = array('data' => $data, 'class' => array('draggable'));
  }

  backdrop_add_tabledrag($table_id, 'order', 'sibling', 'weight_group');

  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));

  $output .= backdrop_render_children($form);
  return $output;
}
