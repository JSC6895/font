###gulp方法

-  src:引入文件可以是string,array,配置文件
```javascript
gulp.task('css',function(argument){
	gulp.src('src/**/*.css')	  
		.pipe(concat('merge.min.css')//合并到css
		.pipe(minifycss())//进行压缩；js的压缩用uglify()
		.pipe(gulp.dest('dist/css/'));
}
```
-  concat:合并文件

```javascript
var browserSync = require('browser-sync').create();
var scp = require('gulp-scp2');
var fs = require('fs');
gulp.task('server',function(){
  browserSync.init({
    server:{
     baseDir:"./src"	
    }
  }); //开启一个服务器
  gulp.watch(['**/*.css','**/*.js','**/*.html'],['reload','scp']);
  //监控第一个参数的内容，发生改变后执行后一个参数操作	
})
gulp.task('scp',function(){
  
})
```
###jQuery解析
```javascript
/*
	jquery源码分析
*/
//步骤1
(function(){
  var hQuery = function(selector,context){
    return new hQuery.prototype.init(selector,context){
      
    }
  };
  hQuery.prototype = {
    init:function(selector,context){
      
    },
    sayHello:function(){
      console.log('hello,world');
    }
  };
  
  hQuery.prototype.init.prototype = hQuery.prototype;
  window.hQuery = window.$ = hQuery;
})(window,undefined)

//写法
$().sayhello() //新对象的属性 
$.ajax()//静态方法上的属性

//jquery的extend方法
hQuery.extend = hQuery.prototype.extend = function(obj){
  for(var key in obj){
    this[key] = obj[key];
  }
};
hQuery.extend({
  isArray:Array.isArray(),
  ajax:function(){}
});
hQuery.prototype.extend({
  addClass:function(){console.log('add class')},
  sayHello:function(){
    console.log('hello '+this.selector);
  }
});

/***
遗漏的小知识点：代码调试可以用debugger；加断点
*****/
/**
generator示例
返回的是个对象，value返回值,done表示是否迭代完毕

**/
var gen = function* (n){
  for (var i = 0;i < 3; i ++){
    n ++;
    yield n
  }
}
var genObj = gen(2)

console.log(genObj.next()) //输出3
console.log(genObj.next()) //输出4
console.log(genObj.next()) //输出5
console.log(genObj.next()) //输出undefined
//generator演化过程
request(url,function(err,res.body){
  if(err) handleError(err)
  
  fs.writeFile('1.txt',body,function(err){
    if (err) handleError(err)
   	
    request(url2,function(err,res,body){
      if (err) handleError(err)
    })
  })
})
======================================================
request(url)
  .then(function(result){
  return writeFileAsync('1.txt',result)
})
  .then(function(result){
  return request(url2)
})
  .catch(function(e){
  handleError(e)
})
=======================================================
var result = yield request(url)
yield writeFileAsync('1.txt',result)
yield request(url2)
//generator演化过程end

request

/*

*/
```