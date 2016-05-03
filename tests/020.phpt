--TEST--
SYSCONF_EXPR_NEST_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_EXPR_NEST_MAX));
?>
--EXPECTF--
int(%d)
