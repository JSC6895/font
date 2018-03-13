<body ng-app="lesson">
	<div>
		<b>指令</b>
	</div>
	<div>
		<b>今天天</b>
	</div>
	<ul div>
		<li></li>
		<li></li>
		<li></li>
	</ul>
	<script src="scripts/angular-1.4.6.min.js"></script>
	<script>
	var app = angular.module("lesson",[]);
	app.controller('MainCtrl',function($scope){

	});
	app.directive('div',function(){
		var direction = {};
		direction.restrict = 'A';
		direction.template = '第一个指令';
		direction.templateUrl = './append.js';
		return direction;
	});
	</script>