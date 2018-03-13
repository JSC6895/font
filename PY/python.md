###python的三元运算符
```python
a=1 if a > b else a=2
#a=1作为条件符合执行代码
#__name__:如果是以脚本启动 则为__main__，如果是以包/模块导入,则是包名/模块名
```
####Flask Web框架
导入
```python
app = Flask(__name__) #实例化一个flask实例
```
启动
```python
app.run()
#host:监听指定IP
#port:监听指定端口 int
#debug:开启调试模式 boolean
```

####session
flask 的session要生成一个secret_key
eg:
```python
import os
app.secret_key = os.urandom(32)
```

####python装饰器
应用场景:每个函数都获取session时
```python
'''
在每个函数之前执行一段代码
在每个函数之后执行一段代码
=================================
@funcname 修饰器的写法
如果出现多个修饰器，会出现bug，调用函数名紊乱
解决：from functools import wraps

'''

```
####python操作mysql

```python
'''
pip install mysql-python 安装mysql的python库
import MySQLdb
conn = MySQLdb.connect(host='localhost',port=3306,user='cheng',passwd='123456',db='test',charset='utf8')
#只连接到库还不够，要想操作数据库，就要建立一个游标
cur = conn.cursor()
cur.execute('insert into user(username,password,age) values ("kk",md5("123456"),29)')
conn.commit()


元组表示（'a','b'）

元组转字典dist(zip((x,y),tuple)) ===> {'x':'x','y':'b'}
'''
```



### python调用C C++

包裹函数

实现包裹，主要有四步

1. 包含Python.h头文件
2. 为每个函数增加一个PyObject  * Module_func() 的包裹函数
3. 为模块增加一个PymMethod DefModuleMethods[]的数组
4. 增加模块的初始化函数void initModule()