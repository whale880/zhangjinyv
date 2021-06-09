#include"practice4.h"

void Practise4menu()
{
	for (;;)
	{
		system("cls");
		printf("************实战四***********\n");
		printf("*** 请选择你要的功能：***\n");
		printf("1、约瑟夫系列\n");
		printf("2、分类统计输入字符串中各类字符个数\n");
		printf("3、对输入的N个单词排序\n");
		printf("4、拓展项目\n");
		printf("5、返回上一级\n");
		printf("****************************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("\n进入约瑟夫系列——\n");
			p4menu1();
			_getch();
			break;
		case 2:
			system("cls");
			printf("\n进入分类统计系列——\n");
			p4menu2();
			_getch();
			break;
		case 3:
			system("cls");
			printf("\n进入单词排序系列——\n");
			p4menu3();
			_getch();
			break;
		case 4:
			system("cls");
			printf("\n进入拓展项目之数字查找——\n");
			p4tuozhanxiangmu();
			_getch();
			break;
		case 5:
			printf("感谢您的使用。退出实战四！");
			break;
		default:
			printf("错误编号。按任意键继续......\n");
			break;
		}
		if (n == 5)
			break;
	}
}

void p4menu1()
{
	int n;
	printf("******************************************\n");
	printf("******1、基本项目************************\n");
	printf("******2、项目拓展************************\n");
	printf("******3、返回上一级**********************\n");
	printf("******************************************\n");
	printf("******请输入对应编号：*******************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");
		printf("\n进入约瑟夫环——\n");
		ysf();
		_getch();
		break;
	case 2:
		system("cls");
		printf("\n进入约瑟夫密码问题——\n");
		mima();
		_getch();
		break;
	case 3:
		system("cls");
		printf("\n感谢你的使用。退出\n");
		Practise4menu();
		_getch();
		break;
	default:
		printf("\n错误编号。按任意键继续......\n");
		break;
	}
	_getch();
}

void p4menu2()
{
	int n;
	printf("******************************************\n");
	printf("******1、基本项目************************\n");
	printf("******2、项目拓展************************\n");
	printf("******3、返回上一级**********************\n");
	printf("******************************************\n");
	printf("******请输入对应编号：*******************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");
		printf("\n进入分类统计字符——\n");
		countmain();
		_getch();
		break;
	case 2:
		system("cls");
		printf("\n进入分类统计字符（不用数组实现读入）——\n");
		countcount();
		_getch();
		break;
	case 3:
		system("cls");
		printf("\n感谢你的使用。退出\n");
		Practise4menu();
		_getch();
		break;
	default:
		printf("\n错误编号。按任意键继续......\n");
		break;
	}
}



void p4menu3()
{
	int n;
	printf("******************************************\n");
	printf("******1、基本项目************************\n");
	printf("******2、项目拓展************************\n");
	printf("******3、返回上一级**********************\n");
	printf("******************************************\n");
	printf("******请输入对应编号：*******************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");
		printf("\n进入单词排序（插入排序法）——\n");
		Wordsortmain();
		_getch();
		break;
	case 2:
		system("cls");
		printf("\n进入单词排序（冒泡排序法）——\n");
		maopaosort();
		_getch();
		break;
	case 3:
		system("cls");
		printf("\n感谢你的使用。退出\n");
		Practise4menu();
		_getch();
		break;
	default:
		printf("\n错误编号。按任意键继续......\n");
		break;
	}
}

void p4tuozhanxiangmu()
{
	system("cls");
	printf("\n进入数字查找——\n");
	wordselect();
	_getch();
}