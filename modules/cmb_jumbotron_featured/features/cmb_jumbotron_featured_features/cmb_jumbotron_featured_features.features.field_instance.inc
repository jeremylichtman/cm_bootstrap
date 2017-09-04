<?php
/**
 * @file
 * cmb_jumbotron_featured_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cmb_jumbotron_featured_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_button_bg_color'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_button_bg_color'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'default_value' => array(
      0 => array(
        'jquery_colorpicker' => '000000',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_button_bg_color',
    'label' => 'Button Background Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(),
      'type' => 'jquery_colorpicker',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_button_link'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_button_link'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_button_link',
    'label' => 'Button Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'advanced_link',
      'settings' => array(
        'default_titles' => '',
        'urls_allowed' => 'both',
        'urls_filter' => '',
        'urls_search' => 'contains',
      ),
      'type' => 'advanced_link',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_button_txt_color'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_button_txt_color'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'default_value' => array(
      0 => array(
        'jquery_colorpicker' => 'ffffff',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_button_txt_color',
    'label' => 'Button Text Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(),
      'type' => 'jquery_colorpicker',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_image'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_image'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_image',
    'label' => 'Background Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_overlay_color'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_overlay_color'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'default_value' => array(
      0 => array(
        'jquery_colorpicker' => '050505',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_overlay_color',
    'label' => 'Overlay Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(),
      'type' => 'jquery_colorpicker',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_overlay_opacity'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_overlay_opacity'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'default_value' => array(
      0 => array(
        'value' => '.3',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_overlay_opacity',
    'label' => 'Overlay Opacity',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_subtitle'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_subtitle'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_subtitle',
    'label' => 'Sub Title',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_title'.
  $field_instances['paragraphs_item-cmb_jumbotron_featured-field_cmb_jf_title'] = array(
    'bundle' => 'cmb_jumbotron_featured',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_jf_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Image');
  t('Button Background Color');
  t('Button Link');
  t('Button Text Color');
  t('Overlay Color');
  t('Overlay Opacity');
  t('Sub Title');
  t('Title');

  return $field_instances;
}
