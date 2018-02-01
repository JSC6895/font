#include <stdio.h>

void main02()
{
	char buf[] = "abcdefg";
	int length = strlen(buf);
	
	char *p1 = buf;
	char *p2 = buf + length - 1;

	while(p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	printf("%s \n",buf);
	system("pause");

	return ;
}