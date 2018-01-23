module.exports = {
    // entry: './app.js',
    entry: {
    	first:'./first_entry.js',
    	second:'./second_entry.js'
    },
    /*
	入口文件:可以是相对路径，
	'__dirname'表示webpack.config.js所在的路径
	'./src/index.js' 相对执行shell命令的文件路径
	出口文件必须写绝对路（不允许相对路径)
    */
    output: {
        filename: './dist/[name].js'
    }
    /**
     * [name] 代表entry中的key-'first'
     * [hash] 该值来解决缓存的问题 [hash:10]来限制长度（默认20）
     * [chunkhash]代替[hash] 文件没改变不更新
     */
    /**
     * webpack自动引入带hash值的文件
     *先在当前文件夹安装webpack:npm install --save webpack
     *再安装一个webpack插件:npm install --save-dev html-webpack-plugin
     *配置一下webpack配置文件
     *const HtmlWebpackPlugin = require('html-webpack-plugin');
     *module.exports = {
     *  entry:'./app.js',
     *  outoput:{
     *      path:__dirname + '/dist',
     *      filename:'dist.chunkhash=[chunkhash:10].name=[name].id=[id].js'
     *  },
     *  plugins:[
     *      new HtmlWebpackPlugin({
     *          title:'my html'
     *      })
     *  ]
     *}
     *npm run test 
     *dist文件夹下就出现一个html文件
     *==================================================================================================
     * 以某个html文件为模版，额外加入打包好的js文件
     * plugins: [
     *     new HtmlWebpackPlugin({
     *         title:'title',
     *         filename:'index.html', //重写后的html文件名，默认是index.html
     *         template:'./demo.html',// 这个就是那个模板文件，不会改动原有的内容，而是在原来html文件的末尾，将打包编译好的文件添加进去
     *     })
     * ]
     */
    
    
    
}