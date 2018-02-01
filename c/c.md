![c结构体高级特性-偏移量](./img/c.png)

###### 错误	1	error LNK2019: 无法解析的外部符号 _WinMain@16，该符号在函数 ___tmainCRTStartup 中被引用	C:\Users\Administrator\Documents\Visual Studio 2012\Projects\namespace\namespace\MSVCRTD.lib(crtexew.obj)	namespace

此类错误是入口函数main() ,WinMain()调用错误

控制台是main()函数,win32是winmain()函数,在ide中项目菜单栏中选中当前项目的属性修改c/c++和link的属性将”_WINDOWS“改为"_CONSOLE"

