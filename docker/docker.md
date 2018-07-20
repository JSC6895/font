### docker常用命令
```bash
docker build ./ #当前目录封装成一个image
docker commit -m="提交信息" -a="什么人传的" 已有的镜像[id] 新镜像名称:版本 
docker build -t 自定义镜像名:版本 . 
docker image ls #显示镜像
docker run [params] #params eg: --restart=always “一直使用该环境,docker重启后丢失” 
docker run -it -p 

```

### Dockerfile
```bash
FROM  镜像名
RUN 执行sh命令
COPY 宿主机 docker主机
WORKDIR ~/ #与cd命令类似
EXPOSE 80 #暴露的端口
CMD ["/bin/echo","this is running"]#容器开启后执行
```
