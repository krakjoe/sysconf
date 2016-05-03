--TEST--
SYSCONF_NGROUPS_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_NGROUPS_MAX));
?>
--EXPECTF--
int(%d)
