--TEST--
SYSCONF_STREAM_MAX
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
var_dump(sysconf(SYSCONF_STREAM_MAX));
?>
--EXPECTF--
int(%d)
