#include"practice6.h"

void Practise6menu()
{
	for (;;)
	{
		system("cls");
		printf("******************实战六*****************\n");
		printf("**********1、约瑟夫游戏（指针）**********\n");
		printf("**********2、学生信息登记管理 ***********\n");
		printf("**********3、贪吃蛇 *********************\n");
		printf("**********4、拓展项目 *******************\n");
		printf("**********5、返回上一级******************\n");
		printf("*****************************************\n");
		printf("************请输入对应编号：*************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("进入约瑟夫游戏（指针） ——\n");
			joseph();
			_getch();
			break;
		case 2:
			system("cls");
			printf("进入学生信息登记管理——\n");
			shizhan6jibenxiangmu2();
			_getch();
			break;
		case 3:
			system("cls");
			printf("进入贪吃蛇——\n");
			snake();
			_getch();
			break;
		case 4:
			system("cls");
			printf("进入拓展项目——\n");
			queue();
			_getch();
			break;
		case 5:
			printf("感谢您的使用。退出实战六");
			break;
		default:
			printf("错误编号。按任意键继续......");
			break;
		}
		if (n == 5)
			break;
	}
}