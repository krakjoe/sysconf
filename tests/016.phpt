--TEST--
SYSCONF_BC_BASE_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_BC_BASE_MAX));
?>
--EXPECTF--
int(%d)
