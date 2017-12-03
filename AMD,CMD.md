AMD,CMD规范
=====
AMD
-----
```javascript
define('model',['jQuery','dialog'],function($,Dialog){
	$('.model').show();
	Dialog.open();
})
```
实现AMD的库有RequireJS、curl、Dojo等
CMD
----
```javascript
define(function(require,exports,module){
  var inc = require('increment').increment;
  var a = 1;
  inc(a);
  
  module.id = "program";
})
export.add
```
### require的简洁写法
用data-main放置在script标签（引入require.js文件）中指定入口文件的位置
require中的paths配置项用于将目录较深的js文件作一个映射

```javascript
define(['jquery','com/gotop',],function($,GoTop){
  //引入jqury和gotop当引入成功后执行以下代码
})
```

###baseUrl失效的情况

* 以".js"结束
* 以"/"开始
* 包含URL协议，如“http”

###gulp
gulp可以对css进行压缩,还可以对图片的清晰度进行处理
```javascript
//build.js中的配置参数
({
  baseUrl:"./src/js",
  paths:{
    'jquery':'/lib/'
  },
  name:"main",//入口文件 全名baseUrl+main.js
  out:"dist/js/XX.js"//压缩后文件路径
})
node r.js -o build.js optimize=none //对文件名进行替换 并不进行压缩
```


###设计方式
```javascript
//构造函数模式
function Person(name,age){
  this.name = name;
  this.age = age;
}
Person.prototype.sayName = function(){
  return this.name;
}
var student = new Person('cheng',30);
console.log(student);
//混合方式
function Person(name,age){
  this.name = name;
  this.age = age;
}
Person.prototype.sayName = function(){
  console.log(this.name);
}
var Student = function(name,age,score){
  Person.call(this,name,age);
  this.score = score;
};
Student.prototype = create(Person.prototype);

function create(parentObj){
  function F(){}
  F.prototype = parentObj;
  return new F();
};

Student.prototype.sayScore = function(){
  console.log(this.score);
}
var student = new Student('cheng',34,99);
console.log(student);
//模块方式
var Person = (function(){
  var name = "hunger";
  return {
    changeName:function(newName){
      name = newName;
    },
    sayName:function(){
      console.log(name);
    }
  };
})();
Person.sayName();
Person.changeName("cheng");
Person.sayName();
//封装，继承，多态
```