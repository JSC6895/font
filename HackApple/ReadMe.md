
### clover配置
```bash
ioreg -l | grep ig-platform-id #显示核显id

```
### alc声卡驱动
- 确保applehda为原版并已加载
- boot启动参数里去掉alcoff
- 下载最新release版本的applealc+lilu
- 去掉了CodecCommander.kext，用的是黑果小兵的整合镜像，因为里面可能含有别人ssdt注入文件
