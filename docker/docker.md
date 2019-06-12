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


### Docker命令（mysql）
```bash
 docker run -it --link some-mysql:mysql --rm mysql sh -c 'exec mysql -h"$MYSQL_PORT_3306_TCP_ADDR" -P"$MYSQL_PORT_3306_TCP_PORT" -uroot -p"$MYSQL_ENV_MYSQL_ROOT_PASSWORD"' //some-mysql为原先开启的容器
```

### 服务器设置加速镜像
```bash
$ docker run -d -p 5000:5000 \
-e STANDALONE=false \
-e MIRROR_SOURCE=https://registry-1.docker.io \ 
-e MIRROR_SOURCE_INDEX=https://index.docker.io \
registry[]
```

###挂载数据卷容器
```bash
$ docker run -d -v /volume:/var/lib/mysql --name=mysql_volume mysql /bin/true
#启动其他容器并挂载数据卷容器
$ docker run -d --volume-from mysql_volume --name mysql1 mysql
$ docker run -d --volume-from mysql_volume --name mysql2 mysql
# -v /vol:/vol:ro 表示/vol只读不可写 rw表示可读可写
```

###docker网路模式

```bash
$ PID=$(docker inspect -f '{{.State.Pid}}' mynetwork) //?不支持了
$ sudo mkdir -p /var/run/netns
$ sudo ln -s /proc/$PID/ns/net /var/run/netns/$PID

//接着创建veth接口 A和B
$ sudo ip link add A type veth peer name B
$ sudo brctl addif br0 A
$ sudo ip link set A up

//最后将B放入容器 命名为eth0
$ sudo ip link set B netns $PID
$ sudo ip netns exec $PID ip link set dev B name eth0
$ sudo ip netns exec $PID ip link set eth0 up
$ sudo ip netns exec $PID ip addr add 10.10.10.25/24 dev eth0 
$ sudo ip netns exec $PID ip route add default via 10.10.10.10.1
```

####container模式
```bash
$ docker run -itd --dns 8.8.8.8 -h testhost --name nginx nginx:alpine
//在启动一个容器 使用上个容器的网络
$ docker run --rm -net=contaienr:nginx -it nginx;alpine
$ docker run --rm -h testhost --name hostname nginx:alpine
```

####host模式
```bash
$ docker run --rm  --net=host -it nginx:alpine //可以操作宿主机网络配置

```
###compose实战
```yaml
version: '3'
services:
    db:
      image: mysql:5.7
      volumes:
        - "./.data/db:/var/lib/mysql"
      restart: always
      environment:
        MYSQL_ROOT_PASSWORD: wordpress
        MYSQL_DATABASE: wordpress
        MYSQL_USER: word
        MYSQL_PASSWORD: word
    
    wordpress:
      depends_on:
        - db
      image: wordpress:latest
      links:
        - db
      ports:
        - "8000:80"
      restart: always
      environment:
        WORDPRESS_DB_ROOT: db:3306
        WORdPRESS_DB_PASSWORD: wordpress
```

####docker-machine
```bash
$ docker-machine create --driver virtualbox manager1
$ eval $(docker-machine env manager1)
$ docker-machine create --driver virtualbox worker1

//联系两虚拟机 实际只需docker swarm
$ docker-machine ssh manager1 docker swarm init --listen-addr 192.168.99.100:2377 --advertise-addr 192.168.99.100

$ docker-machine ssh worker1 docker swarm join --token SWMTKN-1-0pbln2t8rmqnvibfgx4f6gfgklad0gbfw3yzlbf2jwm562i5ro-4qs2ltybf5m3ux3qbpmgt9v83 192.168.99.100:2377

$ docker-machine ssh manager1 docker swarm join-token manager //获取manager的token

//chuanjian chuz
```
