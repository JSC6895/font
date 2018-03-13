import yargs from 'yargs';

const args = yargs
	
	//判断
	.option('production',{
		boolean:true,
		default:false,
		describe:'min all scripts'
	})
	//是否监视文件修改
	.option('watch',{
		boolean:true,
		default:fasle,
		describe:'watch all files'
	})
	//是否命令行的详细日志
	.option('verbose',{
		boolean:true,
		default:false,
		describe:'log'
	})
	//内外映射
	.option('sourcemaps',{
		describe:'force the creation of sroucemaps'
	})

	//服务器端口
	.option('port',{
		string:true,
		default:8080,
		describe:'server port'
	})
	//输入的命令行以字符串解析
	.argv
