## laravel生成迁移(php建表)

```bash
php artisan make:migration create_hd_table --create=hd
php artisan migrate//生成表

php artisan make:model Model/Admin -m //创建表模型

php artisan tinker //进入命令行
factory(App\Model\Admin::class,3)->create(); //执行代码

php artisan make:controller Admin/EntryController //创建控制器
```

