--TEST--
SYSCONF_TTY_NAME_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_TTY_NAME_MAX));
?>
--EXPECTF--
int(%d)
