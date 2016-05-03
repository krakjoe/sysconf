/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
*/
/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_sysconf.h"

#ifdef HAVE_SPL
#	include <ext/spl/spl_exceptions.h>
#else
	zend_class_entry *spl_ce_RuntimeException;
#endif

#ifndef PHP_WIN32
#	include <unistd.h>
#endif

#if PHP_VERSION_ID < 70000
#	define zend_long       long
#	define ZEND_LONG_FMT   "%ld"
#endif

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(sysconf)
{
	REGISTER_LONG_CONSTANT("SYSCONF_POSIX_VERSION", _SC_VERSION, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_POSIX2_VERSION", _SC_2_VERSION, CONST_CS|CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("SYSCONF_ARG_MAX", _SC_ARG_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_CHILD_MAX", _SC_CHILD_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_HOST_NAME_MAX", _SC_HOST_NAME_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_LOGIN_NAME_MAX", _SC_LOGIN_NAME_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_NGROUPS_MAX", _SC_NGROUPS_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_CLK_TCK", _SC_CLK_TCK, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_OPEN_MAX", _SC_OPEN_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_PAGESIZE", _SC_PAGESIZE, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_RE_DUP_MAX", _SC_RE_DUP_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_STREAM_MAX", _SC_STREAM_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_SYMLOOP_MAX", _SC_SYMLOOP_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_TTY_NAME_MAX", _SC_TTY_NAME_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_TZNAME_MAX", _SC_TZNAME_MAX, CONST_CS|CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("SYSCONF_BC_BASE_MAX", _SC_BC_BASE_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_BC_DIM_MAX", _SC_BC_DIM_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_BC_SCALE_MAX", _SC_BC_SCALE_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_COLL_WEIGHTS_MAX", _SC_COLL_WEIGHTS_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_EXPR_NEST_MAX", _SC_EXPR_NEST_MAX, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SYSCONF_LINE_MAX", _SC_LINE_MAX, CONST_CS|CONST_PERSISTENT);

#ifdef _SC_PHYS_PAGES
	REGISTER_LONG_CONSTANT("SYSCONF_PHYS_PAGES", _SC_PHYS_PAGES, CONST_CS|CONST_PERSISTENT);
#endif

#ifdef _SC_AVPHYS_PAGES
	REGISTER_LONG_CONSTANT("SYSCONF_AVPHYS_PAGES", _SC_AVPHYS_PAGES, CONST_CS|CONST_PERSISTENT);
#endif

#ifdef _SC_NPROCESSORS_CONF
	REGISTER_LONG_CONSTANT("SYSCONF_NPROCESSORS_CONF", _SC_NPROCESSORS_CONF, CONST_CS|CONST_PERSISTENT);
#endif

#ifdef _SC_NPROCESSORS_ONLN
	REGISTER_LONG_CONSTANT("SYSCONF_NPROCESSORS_ONLN", _SC_NPROCESSORS_ONLN, CONST_CS|CONST_PERSISTENT);
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(sysconf)
{
#if defined(COMPILE_DL_SYSCONF) && defined(ZTS)
#	if PHP_VERSION_ID >= 70000
	ZEND_TSRMLS_CACHE_UPDATE();
#	endif
#endif

#ifndef HAVE_SPL
	spl_ce_RuntimeException = zend_exception_get_default();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(sysconf)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "sysconf support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ */
#if PHP_VERSION_ID >= 70000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(php_sysconf_arginfo, 0, 1, IS_LONG, NULL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(php_sysconf_arginfo, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ proto int sysconf(int name) */
PHP_FUNCTION(sysconf)
{
	zend_long name = 0;
	zend_long result = 0;
	int _errno = errno;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &name) != SUCCESS) {
		return;
	}

	result = sysconf(name);

	if (errno != _errno && errno == EINVAL) {
		zend_throw_exception_ex(spl_ce_RuntimeException, name,
			"the name provided("ZEND_LONG_FMT") is not valid", name);
		return;
	}

	RETURN_LONG(result);
} 
/* }}} */

/* {{{ sysconf_functions[]
 */
const zend_function_entry sysconf_functions[] = {
	PHP_FE(sysconf,	php_sysconf_arginfo)
	PHP_FE_END
};
/* }}} */

/* {{{ sysconf_module_entry
 */
zend_module_entry sysconf_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SYSCONF_EXTNAME,
	sysconf_functions,
	PHP_MINIT(sysconf),
	NULL,
	PHP_RINIT(sysconf),
	NULL,
	PHP_MINFO(sysconf),
	PHP_SYSCONF_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SYSCONF
#ifdef ZTS
#if PHP_VERSION_ID >= 70000
	ZEND_TSRMLS_CACHE_DEFINE()
#endif
#endif
ZEND_GET_MODULE(sysconf)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
