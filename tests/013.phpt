--TEST--
SYSCONF_SYMLOOP_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_SYMLOOP_MAX));
?>
--EXPECTF--
int(%s)
