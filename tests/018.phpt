--TEST--
SYSCONF_BC_SCALE_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_BC_SCALE_MAX));
?>
--EXPECTF--
int(%d)
