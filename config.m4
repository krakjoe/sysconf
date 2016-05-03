dnl $Id$
dnl config.m4 for extension sysconf

PHP_ARG_ENABLE(sysconf, whether to enable sysconf support,
[  --enable-sysconf           Enable sysconf support])

if test "$PHP_SYSCONF" != "no"; then
  PHP_NEW_EXTENSION(sysconf, sysconf.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
