# 命令

```bash
$ cd - //表示返回上一次目录，相当于cd $OLDPWD
```

```bash
$ scp server1.py root@123.123.132.123://home/document
//拷贝某个文件到另一个服务器 
$ netstat -apn | grep 8080 //看看8080端口是否占用	
```

:vsp 1.c vim开启左右双屏

```bash
$ nm xx.c //显示函数
```

```bash
netstat an | grep 8080 //查看8080端口是否被监听
```

设置软链接权限

```bash
$ setfacl -m u:www:rwx -R web/
```

=======
```bash
$ chattr -i 目录 //表示使原先不能修改删除文件可以
```

## 命令行输出

在linux中运行命令行时，会输出一些日志信息，特别典型的是启用WebLogic命令时，输出一些信息，当启用demon模式运行时，又想收集这些信息咋办？

解决的办法就是使用输出重定向，如下面的命令：

nohup ./startWebLogic.sh  >  app.log    2>&1     & 

这是什么意思呢？

其中app.log是保存输出的文件名称；

2>&1 表示不仅命令行正常的输出保存到app.log中，产生错误信息的输出也保存到app.log文件中；

& 表示该进程在后台运行；
