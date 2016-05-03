--TEST--
SYSCONF_UNKNOWN
--SKIPIF--
<?php if (!extension_loaded("sysconf")) print "skip"; ?>
--FILE--
<?php
try {
	sysconf(-1);
} catch (Exception $e) {
	var_dump($e->getMessage());
}
?>
--EXPECT--
string(34) "the name provided(-1) is not valid"

