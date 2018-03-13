# tip

设置1px的分割线移动端不兼容

在common>stylus下添加一个mixin.styl

```scss
border-1px($color)
	position:relative
	&:after
		display:block
		position:absolute
		left: 0
		bottom: 0
		
		border-top: 1px solid $color
		content: ''
```



### 弹出层动画

弹出层底部模糊效果(ios)

```css
backdrop-filter:blur(10px)
```

### vue动画过渡

```css
transition="fade"
&.fade-transition //最终状态
&.fade-enter,&.fade-leave
	option
```

