<?php
/**
 * @file
 * Custom, non-secure, settings for The Sorrow and the Pride.
 */

$conf['locale_custom_strings_en'][''] = array(
  // Kiwi English
  'You are not authorized to access this page.' => 'You are not authorised to access this page.<br/><br/>If you have an account, please login. If you do not have an account, you can <a href="/user/register">register an account</a>.<br/><br/>If you have received this message in error, please <a href="/contact">contact us</a>.',
  // contact form.
  'Your e-mail address' => 'Your email address',
);

// Force SSL when available.
if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
  $_SERVER['HTTPS'] = 'on';
}

// if we don't have environment from settings.php, determine from host.
if (!isset($conf['environment']) || !is_array($conf['environment'])) {
  switch ($_SERVER['HTTP_HOST']) {
    case 'beta.thesorrowandthepride.nz':
      $conf['environment'] = array('default' => 'staging-sitehost');
      break;

    // New Catalyst Small Clients cluster https://wiki.wgtn.cat-it.co.nz/wiki/ChcSmallClients
    case 'thesorrowandthepride.catalystdemo.net.nz':
      $conf['environment'] = array('default' => 'staging');
      break;

    case 'thesorrowandthepride.local':
      $conf['environment'] = array('default' => 'development');
      break;

    default:
    //case 'thesorrowandthepride.nz':
      $conf['environment'] = array('default' => 'production-sitehost');
      break;
  }
}

// The environment module uses a lowercase variable.
//$conf['environment']['default'] = $environment;
//define('ENVIRONMENT', $environment);

switch ($conf['environment']['default']) {

  case 'production':
    ini_set('error_reporting', E_ALL ^E_NOTICE);
    ini_set('display_errors', FALSE);

    // File system
    $conf['file_directory_path'] = 'sites/default/files';
    $conf['file_public_path'] = $conf['file_directory_path'];
    $conf['file_downloads'] = 1; // Public.

    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_file'] = 'drupal-df8f663eedb7f7a78b5d992d600bb65b5a37e9ae.log';

    /* If this Drupal installation operates
    * behind a reverse proxy, this setting should be enabled so that correct
    * IP address information is captured in Drupal's session management,
    * logging, statistics and access management systems
    */
    $conf['reverse_proxy'] = true;

    /*When Varnish is used, "page_cache_invoke_hooks" must be set as "false". While static files
    * (JS, CSS, images, etc.) all show the proper cache lifetime, the nodes themselves
    * will send back "max-age=0", causing a reverse proxy cache miss on eminently-cacheable content.
    * Without the last variable, anonymous users will get nodes/pages with the max-age=0
    * and the proxy won’t cache it. Setting it to false allows the node to be sent with the max-age set
    * to the cache lifetime set in the admin UI.
    */
    //$conf['page_cache_invoke_hooks'] = false;
    //$conf['cache'] = 1;
    //$conf['cache_lifetime'] = 0;
    //$conf['page_cache_maximum_age'] = 21600;

    /**
     * Set this value if your proxy server sends the client IP in a header other
     * than X-Forwarded-For.
     */
    $conf['reverse_proxy_header'] = 'HTTP_X_FORWARDED_FOR';

    /* Each element of this array is the IP address of any of your reverse
    * proxies.
    */
    $conf['reverse_proxy_addresses'] = array('127.0.0.1');

    // Connection details for Catalyst Squid proxies.
    $conf['proxy_server'] = 'ext-proxy-prod.catalyst.net.nz';
    $conf['proxy_port'] = '3128';
    $conf['proxy_exceptions'] = array('cat-chcsc-staging-solr.servers.catalyst.net.nz', 'nzhistory.govt.nz');
    //$conf['proxy_exceptions'] = array('cat-chcsc-prod-solr1.servers.catalyst.net.nz');

    /**
     * Page caching:
     *
     * By default, Drupal sends a "Vary: Cookie" HTTP header for anonymous page
     * views. This tells a HTTP proxy that it may return a page from its local
     * cache without contacting the web server, if the user sends the same Cookie
     * header as the user who originally requested the cached page. Without "Vary:
     * Cookie", authenticated users would also be served the anonymous page from
     * the cache. If the site has mostly anonymous users except a few known
     * editors/administrators, the Vary header can be omitted. This allows for
     * better caching in HTTP proxies (including reverse proxies), i.e. even if
     * clients send different cookies, they still get content served from the cache
     * if aggressive caching is enabled and the minimum cache time is non-zero.
     * However, authenticated users should access the site directly (i.e. not use an
     * HTTP proxy, and bypass the reverse proxy if one is used) in order to avoid
     * getting cached pages from the proxy.
     */
    $conf['omit_vary_cookie'] = true;

    break;

  case 'production-sitehost':
  case 'staging-sitehost':
    $conf['environment_indicator_text'] = 'STAGING';

    ini_set('error_reporting', E_ALL);
    ini_set('display_errors', TRUE);

    // c/- PreviousNext
    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'admin') === 0 || strpos($_GET['q'], 'en/admin') === 0)) {
      ini_set('memory_limit', '196M');
    }
    // Node edit pages are memory heavy too.
    if (isset($_GET['q']) && preg_match('@^node\/([0-9]+)\/edit$@', $_GET['q'])) {
      ini_set('memory_limit', '196M');
    }

    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'batch') === 0)) {
      ini_set('memory_limit', '196M');
    }

    // File system
    $conf['file_directory_path'] = 'sites/default/files';
    $conf['file_public_path'] = $conf['file_directory_path'];
    //$conf['file_private_path'] = '/var/lib/sitedata/drupal/steelandtube/files_private';
    $conf['file_downloads'] = 1; // Public.

    $conf['reverse_proxy'] = false;
    break;

  case 'staging':
    $conf['environment_indicator_text'] = 'STAGING';

    ini_set('error_reporting', E_ALL);
    ini_set('display_errors', TRUE);

    // c/- PreviousNext
    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'admin') === 0 || strpos($_GET['q'], 'en/admin') === 0)) {
      ini_set('memory_limit', '196M');
    }
    // Node edit pages are memory heavy too.
    if (isset($_GET['q']) && preg_match('@^node\/([0-9]+)\/edit$@', $_GET['q'])) {
      ini_set('memory_limit', '196M');
    }

    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'batch') === 0)) {
      ini_set('memory_limit', '196M');
    }

    // File system
    $conf['file_directory_path'] = 'sites/default/files';
    $conf['file_public_path'] = $conf['file_directory_path'];
    //$conf['file_private_path'] = '/var/lib/sitedata/drupal/steelandtube/files_private';
    $conf['file_downloads'] = 1; // Public.

    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_file'] = 'drupal-df8f663eedb7f7a78b5d992d600bb65b5a37e9ae.log';

    // Each element of this array is the IP address of any of your reverse proxies.
    $conf['reverse_proxy'] = true;
    $conf['reverse_proxy_header'] = 'HTTP_X_FORWARDED_FOR';
    $conf['reverse_proxy_addresses'] = array('127.0.0.1');

    // Connection details for Catalyst Squid proxies.
    $conf['proxy_server'] = 'ext-proxy-staging.catalyst.net.nz';
    $conf['proxy_port'] = '3128';
    $conf['proxy_exceptions'] = array('cat-chcsc-staging-solr.servers.catalyst.net.nz', 'nzhistory.govt.nz');
    //$conf['proxy_exceptions'] = array('cat-chcsc-staging-solr.servers.catalyst.net.nz');

    $conf['omit_vary_cookie'] = true;
    break;

  case 'development':
    ini_set('error_reporting', E_ALL);
    ini_set('display_errors', TRUE);

    $conf['file_directory_path'] = 'sites/default/files';
    $conf['file_public_path'] = $conf['file_directory_path'];

    $conf['flog_enabled'] = TRUE;
    $conf['flog_path'] = 'sites/default/files';

    $conf['environment_indicator_text'] = 'DEVELOPMENT';

    $conf['gmap_marker_custom_dir'] =  $conf['file_public_path'] . '/st_markers';

    // Disable performance config.
    $conf['page_compression'] = FALSE;
    $conf['preprocess_css'] = FALSE;
    $conf['preprocess_js'] = FALSE;
    break;
}
