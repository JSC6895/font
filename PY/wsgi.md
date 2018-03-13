# wsgi协议 

web框架和服务之间通讯

web框架（flask，django）只适用 开发，生产环境还遵循wsgi协议

# 常见的wsgi容器

wsgi是同步接口，所以Tornado的wsgi容器是无法实现异步的，主流选择Gunicorn和uWSGI

# Gunicorn安装使用

```bash
pip install gunicorn
gunicorn --wokers=3 chapter6.section1.app:app =b 0.0.0.0:9000
//chapter5.section1是模块的名字，第一个app是模块文件的名字，第二个app是flask的实例
//wokers的数量不是越多越好，一般为cpu数量*2+1
//查看cpu数量
python -c 'import multiprocessing;print multiprocessing.cpu_count()'

```



