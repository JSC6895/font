###HTML5页面资源预加载(Link prefetch)写法

```html
<!-- 预加载整个页面 -->
<link rel="prefetch" href="http://www.webhek.com/misc/3d-album/" />

<!-- 预加载一个图片 -->
<link rel="prefetch" href=" http://www.webhek.com/wordpress/
wp-content/uploads/2014/04/b-334x193.jpg " />
```

HTML5页面资源预加载/预读取(Link prefetch)功能是通过`Link`标记实现的，将`rel属性`指定为“prefetch”，在`href属性`里指定要加载资源的地址。火狐浏览器里还提供了一种额外的属性支持：

```html
<link rel="prefetch alternate stylesheet" 
title="Designed for Mozilla" href="mozspecific.css" />
<link rel="next" href="2.html" />
```
HTTPS协议资源下也可以使用prefetch。
###什么情况下应该预加载页面资源
在你的页面里加载什么样的资源，什么时候加载，这完全取决于你。下面是一些建议：
-  当页面有幻灯片类似的服务时，预加载/预读取接下来的1-3页和之前的1-3页。
-  预加载那些整个网站通用的图片。
-  预加载网站上搜索结果的下一页。
###禁止页面资源预加载(Link prefetch)
火狐浏览器里有一个选项可以禁止任何的页面资源预加载(Link prefetch)功能，你可以这样设置：
```html
user_pref("network.prefetch-next", false);
```
###页面资源预加载(Link prefetch)注意事项
下面是一些关于页面资源预加载(Link prefetch)的注意事项：
-  预加载(Link prefetch)不能跨域工作，包括跨域拉取cookies
-  预加载(Link prefetch)会污染你的网站访问量统计，因为有些预加载到浏览器的页面用户可能并未真正访问
-  火狐浏览器从2003年开始就已经提供了对这项预加载(Link prefetch)技术的支持