<?php

/**
 * Generates field: field_archive_node_ref
 */
function cm_bootstrap_archive_field_archive_node_ref($bundle) {
  // Create field
  $field = array(
    'field_name' => 'field_archive_node_ref',
    'label' => t('Archive Node Ref'),
    'description' => t('Archive Node Ref'),
    'type' => 'entityreference',
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'required' => TRUE,
    'settings' => array(
      'handler_settings' => array(
        'target_type' => 'node',
        'target_bundles' => array('page'),
      ),
    ),
  );
  $field = field_create_field($field);
  
  // Attach field instance to content type
  $instance = array(
    'field_name' => $field['field_name'],
    'label' => t('Archive Node Ref'),
    'entity_type' => 'node',
    'bundle' => $bundle,
    'required' => TRUE,    
    'widget' => array(
      'weight' => '1',
      'type' => 'entityreference_autocomplete',
      'module' => 'entityreference',
      'active' => 1,
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'match_operator' => 'CONTAINS',
          'size' => 60
        ),
      ),
    ),
  );
  field_create_instance($instance);
}

/**
 * Generates field: field_archive_more_copy
 */
function cm_bootstrap_archive_field_archive_more_copyFCF() {
  // Create field
  $field = array(
    'field_name' => 'field_archive_more_copy',
    'label' => t('Archive More Copy'),
    'description' => t('Used for more link.'),
    'type' => 'text',
    'required' => TRUE,
  );
  field_create_field($field);
}

/**
 * Generates field: field_archive_more_copy
 */
function cm_bootstrap_archive_field_archive_more_copyFCI($bundle) {  
  // Attach field instance to content type
  $field_instance = array(
    'field_name' => 'field_archive_more_copy',
    'entity_type' => 'node',
    'label' => t('Archive More Copy'),
    'description' => t('Used for more link.'),
    'bundle' => $bundle,
    'required' => TRUE,
    'widget' => array(
      'weight' => '2',
    ),
  );
  field_create_instance($field_instance);
}

/**
 * Generates field: field_archive_content_type
 */
function cm_bootstrap_archive_field_archive_content_type($bundle) {
  // Create field
  $field = array(
    'field_name' => 'field_archive_more_copy',
    'label' => t('Content Type'),
    'description' => t('Reference a content type create list'),
    'type' => 'list_text',
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'required' => TRUE,
  );
  field_create_field($field);
  
  // Attach field instance to content type
  $field_instance = array(
    'field_name' => $field['field_name'],
    'entity_type' => 'node',
    'label' => t('Content Type'),
    'description' => t('Reference a content type create list'),
    'bundle' => $bundle,
    'required' => TRUE,
    'widget' => array(
      'weight' => '2',
    ),
  );
  field_create_instance($field_instance);
}