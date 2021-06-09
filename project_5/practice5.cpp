#include"practice5.h"

void Practise5menu()
{
	for (;;)
	{
		system("cls");
		printf("******************实战五*****************\n");
		printf("*************1、学生信息管理系统*************\n");
		printf("*************2、火车订票系统***************\n");
		printf("*************3、项目拓展之电话簿*******\n");
		printf("*************4、返回上一级***************\n");
		printf("*****************************************\n");
		printf("*************请输入对应编号：************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("进入学生信息管理系统——\n");
			Sstudent();
			_getch();
			break;
		case 2:
			system("cls");
			printf("进入火车订票系统——\n");
			Practise53();
			_getch();
			break;
		case 3:
			system("cls");
			printf("进入拓展项目——\n");
			telephone();
			_getch();
			break;
		case 4:
			printf("感谢您的使用。退出实战五");
			break;
		default:
			printf("错误编号。按任意键继续......");
			break;
		}
		if (n == 4)
			break;
	}
}