import gulp from 'gulp';
import gulpif from 'gulp-if';
import concat from 'gulp-concat';//处理文件拼接
import webpack from 'webpack';
import gulpWebpack from 'webpack-stream';
import named from 'vinyl-named'; //对文件重命名
import livereload from 'gulp-livereload'; //文件热更新
import plumber from 'gulp-plumber';//文件流
import rename from 'gulp-rename'; //文件重命名
import uglify from 'gulp-uglify'; //js压缩
import {log,colors} from 'gulp-util';//命令行颜色字体
import args from './util/args'; //对命令行解析包 

//创建脚本编译的任务
gulp.task('scripts',()=>{
	return gulp.src(['app/js/index.js'])
	//流 抛出异常进行处理
		.pipe(plumber({
			errorHandle:function(){

			}
		}))
		//重新命名
		.pipe(named())//
		.pipe()
})