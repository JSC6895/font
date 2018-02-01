#include <stdio.h>

void main01 ()
{
	char a[] = "i am a student";
	char b[64];
	int i = 0;
	for (i = 0; *(a+i) != '\0';i++)
	{
		*(b+i) = *(a+i);
	}
	
	b[i] = '\0';
	printf("a:%s \n",a);
	printf("b:%s \n",b);

	system("pause");
	return ;
	
}
