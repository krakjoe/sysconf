--TEST--
SYSCONF_AVPHYS_PAGES
--XFAIL--
Not always available
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_AVPHYS_PAGES));
?>
--EXPECTF--
int(%d)
