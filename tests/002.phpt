--TEST--
SYSCONF_POSIX2_VERSION
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php 
var_dump(sysconf(SYSCONF_POSIX2_VERSION));
?>
--EXPECTF--
int(%d)
