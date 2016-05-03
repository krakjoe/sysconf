--TEST--
SYSCONF_ARG_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php 
var_dump(sysconf(SYSCONF_ARG_MAX));
?>
--EXPECTF--
int(%d)
