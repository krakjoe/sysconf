--TEST--
SYSCONF_OPEN_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_OPEN_MAX));
?>
--EXPECTF--
int(%d)
