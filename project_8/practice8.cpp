#include"practice8.h"

void Practise8menu()
{
	for (;;)
	{
		system("cls");
		printf("******************实战八*****************\n");
		printf("*************0、测试数据库连接**************\n");
		printf("*************1、mysql简单计数器*************\n");
		printf("*************2、mysql学生学籍管理系统***************\n");
		printf("*************3、mysql项目拓展之图书管理系统*******\n");
		printf("*************4、返回上一级***************\n");
		printf("*****************************************\n");
		printf("*************请输入对应编号：************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 0:
			system("cls");
			printf("进入测试数据库连接——\n");
			mysqltest();
			_getch();
			break;
		case 1:
			system("cls");
			printf("进入mysql简单计数器——\n");
			MySQL_counter();
			_getch();
			break;
		case 2:
			system("cls");
			printf("进入mysql学生学籍信息管理系统——\n");
			MYstudent();
			_getch();
			break;
		case 3:
			system("cls");
			printf("进入mysql拓展项目之订单管理系统——\n");
			order8();
			_getch();
			break;
		case 4:
			printf("感谢您的使用。退出实战八");
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