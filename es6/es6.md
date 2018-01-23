###ES6
###### ES5中顶层对象的属性赋值与全局变量的赋值,是一回事

###### 顶层对象在浏览器是window对象，在Node指的是golbal对象

###### 顶层对象的属性与全局变量挂钩，被认为是 JavaScript 语言最大的设计败笔之一。这样的设计带来了几个很大的问题，首先是没法在编译时就报出变量未声明的错误，只有运行时才能知道（因为全局变量可能是顶层对象的属性创造的，而属性的创造是动态的）；其次，程序员很容易不知不觉地就创建了全局变量（比如打字出错）；最后，顶层对象的属性是到处可以读写的，这非常不利于模块化编程。另一方面，window对象有实体含义，指的是浏览器的窗口对象，顶层对象是一个有实体含义的对象，也是不合适的。

ES6为了改变这一点,一方面规定:为了保持兼容性，var和function命令声明的全局变量，依旧是顶层对象的属性;另一方面规定，let、const、class声明的全局变量，不属于顶层对象的属性。也就是说，从es6开始，全局变量将逐步与顶层对象脱钩

##### global对象

ES5 的顶层对象，本身也是一个问题，因为它在各种实现里面是不统一的。

- 浏览器里面，顶层对象是`window`，但 Node 和 Web Worker 没有`window`。
- 浏览器和 Web Worker 里面，`self`也指向顶层对象，但是 Node 没有`self`。
- Node 里面，顶层对象是`global`，但其他环境都不支持。

同一段代码为了能够在各种环境，都能取到顶层对象，现在一般是使用`this`变量，但是有局限性。

- 全局环境中，`this`会返回顶层对象。但是，Node 模块和 ES6 模块中，`this`返回的是当前模块。
- 函数里面的`this`，如果函数不是作为对象的方法运行，而是单纯作为函数运行，`this`会指向顶层对象。但是，严格模式下，这时`this`会返回`undefined`。
- 不管是严格模式，还是普通模式，`new Function('return this')()`，总是会返回全局对象。但是，如果浏览器用了 CSP（Content Security Policy，内容安全政策），那么`eval`、`new Function`这些方法都可能无法使用。

综上所述，很难找到一种方法，可以在所有情况下，都取到顶层对象。下面是两种勉强可以使用的方法。

```javascript
(typeof window !== 'undefined'
	?window
 	:(typeof process === 'object' &&
      typeof require === 'function' &&
      typeof global === 'object')
 		?global
 		:this);
//方法二
var getGlobal = function(){
  if(typeof self !== 'undefined'){return self;}
  if(typeof window !== 'undefined'){return window;}
  if(typeof global !== 'undefined'){return global;}
  throw new Error('unable to locats global object');
};
```

现在有一个[提案](https://github.com/tc39/proposal-global)，在语言标准的层面，引入`global`作为顶层对象。也就是说，在所有环境下，`global`都是存在的，都可以从它拿到顶层对象。

垫片库[`system.global`](https://github.com/ljharb/System.global)模拟了这个提案，可以在所有环境拿到`global`。

```javascript
//commonJs写法
require('system.global/shim')();
//es6模块的写法
import shim from 'system.global/shim';shim();
```



### 数组的解构赋值

#### 基本用法

ES6 允许按照一定模式，从数组和对象中提取值，对变量进行赋值，这被称为解构（Destructuring）。



error:如果等号的右边不是数组（或者严格地说，不是可遍历的结构，参见《Iterator》一章），那么将会报错。

```javascript
// 报错
let [foo] = 1;
let [foo] = false;
let [foo] = NaN;
let [foo] = undefined;
let [foo] = null;
let [foo] = {};
```

上面的语句都会报错，因为等号右边的值，要么转为对象以后不具备 Iterator 接口（前五个表达式），要么本身就不具备 Iterator 接口（最后一个表达式）。