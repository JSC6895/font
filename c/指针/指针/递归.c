#include <stdio.h>


//方法2:定义一个全局变量，每次递归时将指针地址传到全局变量内
/*
g_buf 是个全局变量
strncpy(g_buf,p,1); 会覆盖上个指针
strncat(g_buf,p,1); 则会追加到后面
使用全局变量有个问题，就是多线程时会出现资源争用问题 
*/
void inverse01(char *p)
{
	if(p == NULL)
	{
		return ;
	}
	if(*p == '\0') //如果是双引号的话，会找不到这个结束标识，
	{
		return ;
	}

	inverse01(p + 1);
	printf("%c",*p);
}

void inverse02(char *p,char *buf)
{
	if(p == NULL || buf == NULL)
	{
		return ;
	}
	if(*p == '\0') //如果是双引号的话，会找不到这个结束标识，
	{
		return ;
	}

	inverse02(p + 1,buf);
	strncat(buf,p,1);
}
/*
	
void main()
{
	char buf[] = "ABCDEFG";
	inverse01(buf);
	
	system("pause");
}
*/
void main03()
{
	char buf[] = "abcd";
	
	{
		char mybuf[1024] = {0};
		inverse02(buf,mybuf);
		printf("%s \n",mybuf);
	}
	system("pause");
}