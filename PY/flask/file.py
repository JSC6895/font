#encoding:utf-8

def loganalysis(logfile,dstpath,topen=10):

	fhandler = open(logfile,'r')

	rt_dict = {}

	#统计
	while True:
		line = fhandler.readline()
		if line = '':
			break

		nodes = line.split()
		ip,url,code = node[0],node[6],node[8]
		key = (ip,url,code)
		if key not in rt_dict:
			rc_dict[key] = 1
		else:
			rt_dict[key] = rc_dict[key] + 1

	fhanlder.close()
	#print 

	#排序
	rt_list = rt_dict.items()
	#[(key,value),(key,value)]

	for j  in range(0,topen):
		for i in range(0,len(rt_list) - 1):
			if rt_list[i][1] > rt_list[i + 1][1]:
				temp = rt_list[i]
				rt_list[i] = rt_list[i + 1]
				rt_list[i + 1 ] = temp
	#fhadler = open('result.txt','w')

	for node in rt_list[-1: -topen - 1:-1]:
		fhandler = open('result.txt','a')
		fhandler.write('%s %s %s %s\n' %(node[1],node[0][0],node[0][1],node[0][2]))
		fhandler.close()

	page_tpl = '''
	<!DOCTYPE html>
	<html>
	 	<head>
	 		<meta charset = "utf-8"/>
	 		<title>{title}</title>
	 	</head>
	</html>
	‘’‘

	title = 'TOP %s '
