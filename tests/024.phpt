--TEST--
SYSCONF_NPROCESSORS_CONF
--XFAIL--
Not always available
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_NPROCESSORS_CONF));
?>
--EXPECTF--
int(%d)
