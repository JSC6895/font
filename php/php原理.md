





**scanning**

lex是LEXical compiler的缩写，主要功能是此法分析器（scanner），描述规则采用正则表达式，在php源码中是zend/zend_language_scanner.c,去根据zend/zend_language_scanner.l（lex规则文件），来对需要执行php文件进行此法分析，从而得到一个个的“词”（token）,执行规则（也就是切分的方式）还是用正则表达式做的







如何让php网站运行更快

- 压缩代码，去除无用的注释后空白
- 尽量使用php内置函数或扩展函数
- 用apc/xcache/opcache等缓存php的opcode
- 使用多线程，多进程优化程序逻辑
- 缓存复杂的和耗时的结果
- 能异步处理的任务不要马上处理，如发邮件
- 依据资源情况对FastCGI配置合适的参数

##### php垃圾回收机制

第一步，从所有变量中找到垃圾，所有的变量get_defined_vars函数能看到所有已经定义的变量，那意味着php本身能存储所有变量或已开辟的内存空间，具体在zend_globals.h中struct_zend_excutor_globals中看到struct_zend_executor_globals｛

HashTable  *active_symbol_table; //局部变量的和符号表

HashTable symbol_table; //全局变量的符号表

}

第二步，如何找到垃圾？在这个垃圾变量上面打个标签，这个是垃圾，可以清理了，这个标签在哪里呢？

看看变量本身的定义Zend/zend.h中，我们可以看到zval的定义zend_uinit refcoun__gc;//这个用来标记有多少个变量指向他

zend_uchar is_ref__gc;//这个用来标记用引用的方式指向他

看看是否是垃圾就看refcount__gc是不是为0

看xdebug.php代码