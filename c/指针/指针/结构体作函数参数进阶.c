#include <stdio.h>

typedef struct Teacher
{
	char name[64];
	char *aliName;
	char **stuName;
	int age;
	int id;
}Teacher;

void printTeacher(Teacher *array,int num)
{
	int i;
	for(i = 0; i < num ; i ++ )
	{
		printf("age:%d\n",array[i].age);
	}
}

void sortTeacher(Teacher *array,int num)
{
	int i,j;
	Teacher tmp;
	for(i = 0;i < num ; i ++)
	{
		for(j = i+1;j < num; j++)
		{
			if(array[i].age > array[j].age)				
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}


Teacher *createTeacher01(int num)
{
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num);
	if(tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

int createTeacher02(Teacher **Tp ,int num)
{
	int i = 0;
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num);
	if(tmp == NULL)
	{
		return -1;
	}
	memset(tmp,0,sizeof(Teacher) * num);
	for(i = 0;i < num;i++)
	{
		tmp[i].aliName = (char *)malloc(60);
	}
	*Tp = tmp;
	return 0;
}

int createTeacher03(Teacher **Tp ,int num)
{
	int i = 0;
	int j;
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num);
	if(tmp == NULL)
	{
		return -1;
	}
	memset(tmp,0,sizeof(Teacher) * num);
	for(i = 0;i < num;i++)
	{
		char **p = NULL;
		tmp[i].aliName = (char *)malloc(60);

		//二级指针的第三种内存模型
		p = (char **)malloc(3 * sizeof(char *));

		for(j = 0; j < 3;j ++)
		{
			p[j] = (char *)malloc(120);
		}
		tmp[i].stuName = p;
	}
	*Tp = tmp;
	return 0;
}
void FreeTeacher(Teacher *p,int num)
{
	int i = 0;
	int j;
	if(p == NULL)
	{
		return;
	}
	for (i = 0;i < num; i ++)
	{
		if(p[i].aliName != NULL)
		{
			free(p[i].aliName);
		}
		//释放二级指针
		if(p[i].stuName != NULL)
		{
			char **myp = p[i].stuName;
			for(j=0;j<3;j++)
			{
				if(myp[j] != NULL)
				{
					free(myp[j]);
				}
			}
			free(myp);
			p[i].stuName = NULL;
		}
	}
	free(p);
}
void main()
{
	int i = 0;
	int j;
	int num = 3;
	int ret = 0 ;
	Teacher *pArray = NULL;
	ret = createTeacher03(&pArray,num);
	if (ret != 0)
	{
		printf("func create03() err:%d\n",ret);
		return;
	}
	for(i = 0;i < num;i++)
	{
		printf("\nplease enter age:");
		scanf("%d",&(pArray[i].age));
		
		printf("\nplease enter name:");
		scanf("%s",pArray[i].name);

		printf("\nplease enter aliasName:");
		scanf("%s",pArray[i].aliName);
		
		for(j=0; j < 3;j++)
		{
			printf("please enter student name:");
			scanf("%s",pArray[i].stuName[j]);
		}
	}
	printTeacher(pArray,num);

	sortTeacher(pArray,num);

	printf("排序之后\n");

	printTeacher(pArray,num);

	FreeTeacher(pArray,num);

	printf("hello >>>>\n");

	system("pause");
	return;

}