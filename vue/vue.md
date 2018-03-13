### Vue

##### 生命周期(1.0)

- created :实例已经创建
- beforeCompile:编译之前
- compiled:编译之后
- ready:插入到文档中
- beforeDestroy:销毁前
- destroyed:销毁后

 v-cloak:花括号刷新时不显示

```css
[v-cloak]{
  display:none;
}
/*
属性选择器
*/


```

```javascript
var vm = new Vue({
  el:'#box',
  data:{
    a:1
  },
  //计算属性
  computed:{
    b:function(){
      return 1;
    }
    /*完整的形式
    b:{
     get:function(){},//莫忘return
     set:function(){}
    }
    */
  }
});

```

#### vue实例简单方法

vm.$el  -> 就是元素

vm.$data -> 就是data

vm.$mount -> 手动挂载指定dom （el:'#XXX'）

vm.$options -> 自定义属性对象

vm.$destroy -> 销毁对象

vm.$log(); ->查看现在的数据的状态

```html
<div id="box">
	<input type="button" value="添加" @click="add">
  	<ul>
  		<li v-for="val in arr" track-by="$index">
          {{val}}
      	</li>
  	</ul>
</div>
<script>
  var vm = new Vue({
    data:{arr:['apple','pear','orange']},
    methods:{
      add:function(){
        this.arr.push('tomato');
      }
    }
  }).$mount('#box');
</script>
```

#### 过滤器(capitalize,uppercase,currency,debounce)

 debounce：配合事件，延迟执行  	

limitBy:限制几个, 取几个时需要两个参数，第一个表示从第几个开始，参数2表示取几个

filterBy:过滤数据

orderBy:  1 ,-1 正反序

Vue.filter(name,function(input){



});

#### 双向过滤器

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title></title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <style>

    </style>
    <script src="vue.js"></script>
    <script>
        //<h2>welcome</h2>
        Vue.filter('filterHtml',{
            read:function(input){ //model-view
                alert(1);
                return input.replace(/<[^<]+>/g,'');
            },
            write:function(val){ //view -> model
                console.log(val);
                return val;
            }
        });
        window.onload=function(){
            var vm=new Vue({
                data:{
                    msg:'<strong>welcome</strong>'
                }
            }).$mount('#box');
        };

    </script>
</head>
<body>
    <div id="box">
        <input type="text" v-model="msg | filterHtml">
        <br>
        {{{msg}}}
    </div>
</body>
</html>
```

指令（v-for,v-html,v-text）

自定义指令

```javascript
Vue.directive('red',function(){
  this.el//this代表vue实例
})

<span v-red></span>
#自定义指令必须以v开头 v-red="param"可以带参数
```

###### 自定义元素

```javascript
Vue.elementDirective('zdy-read'{
   bind:function(){
  this.el
}
})
```

###### 自定义键盘信息

@keydown.up获取键盘按下

@keydown.enter

Vue.directive('on').keyCodes.ctrl = 17;

###### 监听数据变化

```
vm.$el/$mount/$options
vm.$watch(name,fnCb);//浅度
vm.$watch(name,fnCb,{deep:true});//深度监视
```

### Vue动画

```html	
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
	<script src="bower_components/vue/dist/vue.js"></script>
	<style>
		#div1{
			width:100px;
			height:100px;
			background: red;
		}

		.fade-transition{
			transition: 1s all ease;	
		}
		.fade-enter{
			opacity: 0;
		}
		.fade-leave{
			opacity: 0;
			transform: translateX(200px);
		}
	</style>
</head>
<body>
	<div id="box">
		<input type="button" value="按钮" @click="toggle">
		<div id="div1" v-show="bSign" transition="fade"></div>
	</div>

	<script>
		new Vue({
			el:'#box',
			data:{
				bSign:true
			},
			methods:{
				/*toggle:function(){
					alert(1);
				}*/
				toggle(){
					this.bSign=!this.bSign;
				}
			}
		});
	</script>
</body>
</html>
```

### Vue组件

组件：一个对象

###### 全局组件

 ```html
<div>
  <aaa></aaa>
</div>
<script>
var Aaa = Vue.extend({
template:'<h3>
  h3标题
</h3>'
});
Vue.component('aaa',Aaa);
</script>

<!--还有一种方法-->
<script>
  var Aaa = Vue.extend({
    data(){
      return {
        msg:'xxx's
      };
    }
    method:{
      change(){
      this.msg = 'changed'
      }
  	},
    template:"<h3 @click='change'>{{msg}}</h3>"
  });
  Vue.component('aaa',Aaa);
</script>
 ```

###### 局部组件

```html
var vm = new Vue(){
  el:'#box',
  data:{

  },
  components:{
    //放置组件
    'my-aaa':{
     template:"<h2>XXX</h2>"
    }
  }
}
```
######配合模版
- 方式1： template:"<h2 @click="change">{{msg}}</h2>"
- 方式2：
```javascript
<script type="x-template" id="aaa"> 
  <h2></h2>

</script>
template:"#aaa"
```
- 方式3：
```html
<template id="aaa">
  <h1></h1>
  <ul>
    <li v-for="val in arr">
    {{val}}
    </li>
  </ul>
</template>
```
######动态组件
```html
```
<component :is="组件名称"></component>

Vue({
  components:{
  'aaa':{
    template:'<h1></h1>'
  }
  'bbb':{
    template:'<h1></h1>'
  }
  }
})

######组件继承
在父组件中
<bbb :m="数据"></bbb>

子组件内：
props:['m','myMsg']
props:{
  'm':String,
  'myMsg':Number
}
- 父组件获取子组件
vm.$emit(事件名,数据)
v-on: @

###Vue-router
vue-resouce 交互
vue-router 路由 spa应用

<a v-link="{path:'/home'}">主页</a> 跳转链接
展示内容
<route-view></route-view>

######跳转
router.redirect({
  '/':'/home',
})


###vue项目构建
package.json -> npm init --yes

npm run dev ->取决于package.json中script dev为键名 build也可作键名'build':'webpack -p'

npm install vue-loader@8.X.X --save-dev  -> --save-dev 意思是将配置文本写进package.jso n


###Vue脚手架
####vue-cli
- npm install vue-cli -g 安装vue命令环境
  
- 生成项目模版
  vue init <模版名称> 本地文件夹名

###Vue2.0
####变化
- 在每个组件模板，不在支持片段代码
    组件中模板：
```javascript 

<template id="aaa">
  <h3>ss</h3><strong>dsss</strong>//1.0可以显示strong内容
  //2.0必须加个根元素
  <div>
    <h2></h2>
    <strong></strong>
  </div>

</template>
```

- 组件
var Home = {
  template:"" ->Vue.extend()//2.0  -> 1.0
}

- 生命周期
之前:
    init
    created
    deforeCompile
    compiled
    ready
    beforeDestroy
    de
 现在：
    beforeCreate组件实例刚刚被创建，属性都没有
    created 实例已经创建完成 
    beforeMount 模板编译之前
    mounted 模板编译完成 
    beforeUpdate  组件更新之前
    updated 组件更新完毕
    beforeDestroy 组件销毁前
    destroyed 组件销毁后
- 2.0循环
  v-for="(val,index) in array"
- 循环中提升性能trace-by 变为 :key = "index"

- 自定义键盘指令
  之前:Vue.directive('on').keyCodes.f1 = 17;
  现在: Vue.config.keyCodes.ctrl = 17
- 过滤器
  2.0,内置过滤器，全部删除
- 组件通讯

可以单一通讯
  var Event = new Vue();
  Event.$emit(事件名称,数据)
  Event.$on(事件名称,function(data){

  }.bind(this));


###transition
class定义
.fade-enter{} //初始化状态
.fade-enter-active{} //变化成什么样 -> 当元素出来

.fade-leave{}
.fade-leave-active{}


```javascript
<transition name="fade">
  @before-enter = "beforeEnter"
  @enter = "enter"
  @after-enter = "afterEnter"

  @before-leave = "beforeLeave"
  @leave = "leave"
  @after-leave = "afterLeave" //后跟方法名afterLeave(el)
  
  <p v-show="show"></p>
</transition>
```
####配合animate.css
<transition enter-active-class="animated zoomInLeft">
  <p v-show="show" class="animated"></p>
</transition>

#####多个元素
<transition-group enter-active-class="animated zoomInLeft">
  <p v-show="show" class="animated" :key="1"></p>
  <p v-show="show" class="animated" :key="2"></p>
</transition-group>


###vue2.0 脚手架

new Vue({
  el:'#app',
  render: h => h(app)
})

webpack css-loader 先style后css