--TEST--
SYSCONF_NPROCESSORS_ONLN
--XFAIL--
Not always available
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_NPROCESSORS_ONLN));
?>
--EXPECTF--
int(%d)
