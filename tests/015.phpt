--TEST--
SYSCONF_TZNAME_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_TZNAME_MAX));
?>
--EXPECTF--
int(%d)
