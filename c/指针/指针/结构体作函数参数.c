//#include <stdio.h>
//
//typedef struct Teacher
//{
//	char name[64];
//	int age;
//	int id;
//}Teacher;
//
//void printTeacher(Teacher *array,int num)
//{
//	int i;
//	for(i = 0; i < num ; i ++ )
//	{
//		printf("age:%d\n",array[i].age);
//	}
//}
//
//void sortTeacher(Teacher *array,int num)
//{
//	int i,j;
//	Teacher tmp;
//	for(i = 0;i < num ; i ++)
//	{
//		for(j = i+1;j < num; j++)
//		{
//			if(array[i].age > array[j].age)				
//			{
//				tmp = array[i];
//				array[i] = array[j];
//				array[j] = tmp;
//			}
//		}
//	}
//}
//
//
//Teacher *createTeacher(int num)
//{
//	Teacher * tmp = NULL;
//	tmp = (Teacher *)malloc(sizeof(Teacher) * num);
//	if(tmp == NULL)
//	{
//		return NULL;
//	}
//}
//
//void FreeTeacher(Teacher *p)
//{
//	if(p != NULL)
//	{
//		free(p);
//	}
//}
//void main()
//{
//	int i = 0;
//	int num = 3;
//	Teacher *pArray = NULL;
//	pArray = createTeacher(num);
//
//	for(i = 0;i < num;i++)
//	{
//		printf("\nplease enter age:");
//		scanf("%d",&(pArray[i].age));
//	}
//	printTeacher(pArray,num);
//
//	sortTeacher(pArray,num);
//
//	printf("ÅÅÐòÖ®ºó\n");
//
//	printTeacher(pArray,num);
//
//	FreeTeacher(pArray);
//
//	printf("hello >>>>\n");
//
//	system("pause");
//	return;
//
//}