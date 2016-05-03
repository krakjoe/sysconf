--TEST--
SYSCONF_LINE_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_LINE_MAX));
?>
--EXPECTF--
int(%d)
