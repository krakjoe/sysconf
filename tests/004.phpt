--TEST--
SYSCONF_CHILD_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_CHILD_MAX));
?>
--EXPECTF--
int(%d)
