--TEST--
SYSCONF_POSIX_VERSION
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php 
var_dump(sysconf(SYSCONF_POSIX_VERSION));
?>
--EXPECTF--
int(%d)
