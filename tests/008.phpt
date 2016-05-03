--TEST--
SYSCONF_CLK_TCK
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_CLK_TCK));
?>
--EXPECTF--
int(%d)
