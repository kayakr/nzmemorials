<?php
/**
 * @file
 * the_sorrow_and_the_pride.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function the_sorrow_and_the_pride_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tsapt_footer';
  $context->description = 'Site-wide footer';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'the_sorrow_and_the_pride-tsatp_footer' => array(
          'module' => 'the_sorrow_and_the_pride',
          'delta' => 'tsatp_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site-wide footer');
  $export['tsapt_footer'] = $context;

  return $export;
}
