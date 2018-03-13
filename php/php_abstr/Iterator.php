<?php 

	class Languages implements IteratorAggregate{
		private $names;

		public function __construct(){
			$this->names = explode(",","PHP,JS,Java,Go");
		}

		/*
		IteratorAggregate中定义的，必须实现
		 */
		public function getIterator(){
			return new ArrayIterator($this->names);
		}


	}

	$langs = new Languages();
	foreach($langs as $lang){
		echo "$lang\n";
	}
 ?>