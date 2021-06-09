#include "practice7.h"

void Practise7menu()
{
	printf("************实战七***********\n");
	for (;;)
	{
		system("cls");
		printf("******************实战七*****************\n");
		printf("*************1、简单计数器*************\n");
		printf("*************2、学生学籍管理系统***************\n");
		printf("*************3、项目拓展之图书管理系统*******\n");
		printf("*************4、返回上一级***************\n");
		printf("*****************************************\n");
		printf("*************请输入对应编号：************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("进入简单计数器——\n");
			counter();
			_getch();
			break;
		case 2:
			system("cls");
			printf("进入学生学籍信息管理系统——\n");
			Studentinformation();
			_getch();
			break;
		case 3:
			system("cls");
			printf("进入拓展项目之图书管理系统——\n");
			library();
			_getch();
			break;
		case 4:
			printf("感谢您的使用。退出实战七");
			break;
		default:
			printf("错误编号。按任意键继续......");
			break;
		}
		if (n == 4)
			break;
	}
	_getch();
}