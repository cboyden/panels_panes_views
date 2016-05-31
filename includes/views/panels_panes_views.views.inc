<?php

/**
 * @file
 * Views handlers for various panels tables.
 */

/**
 * Implements hook_views_data().
 */
function panels_panes_views_views_data() {

  $data = array();
  $data['panels_pane'] = array(
    'table' => array(
      'base' => array(
        'field' => 'pid',
        'title' => t('Panel panes'),
        'help' => t('A panel pane.'),
      ),
      'group' => t('Panels panes'),
    ),
    'pid' => array(
      'title' => t('Pane ID'),
      'help' => t('The internal ID of the pane.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    // Display ID field. This is the Panels display where the pane is used.
    'did' => array(
      'title' => t('Display ID'),
      'help' => t('The display unique ID.'),
      'relationship' => array(
        'title' => t('Display'),
        'base' => 'panels_display',
        'base field' => 'did',
        'label' => t('display'),
      ),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
    ),
    // The type field. Contains machine names of pane types.
    'type' => array(
      'title' => t('Pane type'),
      'help' => t('The type of pane.'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),
    // The subtype field. Contains machine names of pane subtypes. For FPPs,
    // contains the UUID.
    'subtype' => array(
      'title' => t('Pane subtype'),
      'help' => t('The subtype of pane.'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),
  );

  // The panels_display table.
  $data['panels_display'] = array(
    'table' => array(
      'base' => array(
        'field' => 'did',
        'title' => t('Panels displays'),
        'help' => t('A panels display.'),
      ),
      'group' => t('Panels displays'),
    ),
    'did' => array(
      'title' => t('Display ID'),
      'help' => t('The internal ID of the display.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    // The layout field. Contains machine names of layouts.
    'layout' => array(
      'title' => t('Layout'),
      'help' => t('The layout used by the display.'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),
  );

  // The panelizer_entity table.
  $data['panelizer_entity'] = array(
    'table' => array(
      'base' => array(
        'field' => 'entity_id',
        'title' => t('Panelizer entity'),
        'help' => t('A panelizer entity.'),
      ),
      'group' => t('Panelizer entities'),
      'join' => array(
        'panels_display' => array(
          'left_field' => 'did',
          'field' => 'did',
        ),
      ),
    ),
    'did' => array(
      'title' => t('Display ID'),
      'help' => t('The internal ID of the display.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'entity_id' => array(
      'title' => t('Entity ID'),
      'help' => t('The internal ID of the entity.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'entity_type' => array(
      'title' => t('Entity type'),
      'help' => t('The type of the entity.'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),
  );

  return $data;

}
