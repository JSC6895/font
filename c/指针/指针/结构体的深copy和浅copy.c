#include <stdio.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char *aliName2;
}Teacher

void copyTeacher(Teacher *to,Teacher *from)
{
	*to = *from; //浅copy
	//memcpy(to,from,sizeof(Teacher)) //与上一个类似

	//深copy
	to->aliName2 = (char *)malloc(100);
	strcpy(to->aliName2,from->aliName2);
}
void main()		
{
	Teacher t1;
	Teacher t2;

	printf("hello >>>> \n");
	system("pause);
	return;
}
