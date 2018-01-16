module.exports = {
	entry:'./app.js',
	output: {
		path:__dirname + '/dist',
		filename:'./dist.js'
	},
	module:{
		rules: [
		//将loader放在rules这个数组中
		/*
		loader的作用：对模块的源代码进行编码
		eg:输入一个css文件，拿到的是一个字符串，进行处理，再返回处理后的内容作为css文件
		 */
		]
	}
}