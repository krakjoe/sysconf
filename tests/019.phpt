--TEST--
SYSCONF_COLL_WEIGHTS_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_COLL_WEIGHTS_MAX));
?>
--EXPECTF--
int(%d)
