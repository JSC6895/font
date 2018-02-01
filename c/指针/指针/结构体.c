//#include <stdio.h>
//
////定义一个结构体类型
////struct Teacher 
////{
////	char name[64];
////	int age;
////	int id;
////};
//
////类型的重定义
////可以省略struct
//typedef struct Teacher 
//{
//	char name[64];
//	int age;
//	int id;
//}Teacher;
//
////用类型定义变量的三种方法
//
//struct Student
//{
//	char name[64];
//	int age;
//}s1,s2;//定义类型的同时 定义变量
//
//struct
//{
//	char name[64];
//	int age;
//}s3,s4; //匿名类型 定义变量
//
//
////初始化变量的三种方法
////定义变量，然后初始化
//struct Student2 
//{
//	char name[64];
//	int age;
//}s5 = {"name",23};
//
//struct
//{
//	char name[64];
//	int age;
//}s6 = {"name",23};
//
//
//void main04()
//{
//	Teacher t1; //告诉c编译器给我分配内存
//	t1.age = 23; //"."操作符的含义是寻址操作，age相对于t1的偏移量 =》 计算 美与欧操作内存
//	Teacher t2 = {"aa",24,02};
//
//
//	//通过指针的方式操作 内存空间
//	{
//		Teacher *p =NULL;
//		p = &t2;
//		printf("p->age:%d\n",p->age);
//		printf("p->name:%s\n",p->name);
//	}
//
//	printf("hello.....\n");
//	system( "pause");
//	return;
//}