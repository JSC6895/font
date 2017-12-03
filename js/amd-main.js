/**
 * 支持cmd，amd
 */
define(['inc_cmd'],function(Inc){
	console.log(Inc.get());
	Inc.inc();
	console.log(Inc.get());
	Inc.inc();
	console.log(Inc.get());
});
