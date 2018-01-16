###webpack

#### 中间件容器webpack-dev-middleware



先安装express和webpack-dev-middleware

```javasscript
npm install --save express webpack-dev-middleware
然后在webpack.config.js中的output添加publicPath:'/'属性,如：
output: {
  path:__dirname + '/../dist',
  filename:'[name].[chunkhash].js',
  publicPath:'/'
},

```
在build目录下的新建server.js
```
const express = require('express');
const webpack = require('webpack');
const webpackDevMiddleware = require('webpack-dev-middleware');
var opn = require('opn')

const app = express();
const config = require('./webpack.config.js');
const compiler = webpack(config);

app.use(webpackDevMiddleware(compiler,{
	publicPath:config.output.publicPath
}));
app.listen(3000,function(){
  console.log('example app listening on port 3000!\n');
})
opn('http://localhost:3000/login.html')
```
在package.json文件了里添加一条scripts:

```
"server":"node build/server.js"
```

   注意因为是在根目录下执行命令，server.js 在 build 文件夹下，所以需要是 `build/server.js`。

**举个例子：**

1. 直接对比 watch 模式和 webpack-dev-server 模式吧：
2. 也带服务器功能，不过 webpack-dev-server 用的是一个简单的web服务器，而这个用的是 express 的服务器；
3. 跟 watch 模式类似，只使用这个的话（没任何配置），需要手动刷新页面，才能获取修改后的代码；

**优点：**

1. 比 watch 模式多一个服务器。相较说，不需要从文件路径来访问，或者需要自己额外搭建一个服务器来访问；
2. 是 HMR （模块热替换）的基础；

**缺点：**

1. 单纯使用这个，并不能实现 HMR，还需要额外配置；

#### HMR

单纯的使用 开发中 Server(DevServer)，并不能达到我们预期的效果——修改代码后无需刷新页面，即可在页面上体现出变化。

因此还需要启用 HMR，参照下一篇博客。

