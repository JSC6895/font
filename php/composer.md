## composer的安装

通过命令行安装

```bash
php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');"
php -r "if (hash_file('SHA384', 'composer-setup.php') === '544e09ee996cdf60ece3804abc52599c22b1f40f4323403c44d44fdfdd586475ca9813a858088ffbc1f233e9b180f061') { echo 'Installer verified'; } else { echo 'Installer corrupt'; unlink('composer-setup.php'); } echo PHP_EOL;"
php composer-setup.php
php -r "unlink('composer-setup.php');"
```

安装后目录下会生成一个".phar"为后缀的文件

```bash
echo @php "%~dp0composer.phar" %*>composer.bat
//将composer添加到当前环境变量里
```



composer配置文件

```bash
composer install 
//执行安装插件
```

