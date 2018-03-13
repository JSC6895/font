#encoding: utf-8
import time
#记录函数定义
def logFunc(func):
	def wrapper():
		print('日志:%s' % func.__name__)
		start = time.time()
		rt = func()
		print ('日志结束:%s:%s' % (func.__name__,time.time() - start))
		return rt
	return wrapper

#定义函数执行时间统计
def time_wrapper(func):
	def wrapper():
		print('开始:%s' % func.__name__)
		start = time.time()
		rt = func()
		print ('计时结束:%s:%s' % (func.__name__,time.time() - start))
		return rt
	return wrapper
def test1():
	print('test1')
def test2():
	print ('test2')
def test3():
	print ('test3')
@logFunc
@time_wrapper
def test4():
	time.sleep(2)
	print ('test4')
test4()