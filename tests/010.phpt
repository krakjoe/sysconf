--TEST--
SYSCONF_PAGESIZE
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_PAGESIZE));
?>
--EXPECTF--
int(%d)
