--TEST--
SYSCONF_RE_DUP_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_RE_DUP_MAX));
?>
--EXPECTF--
int(%d)
