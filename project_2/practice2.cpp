#include"practice2.h"

void Practise2menu()
{
	for (;;)
	{
		system("cls");
		printf("******************实战二*****************\n");
		printf("*************1、猴子摘桃系列*************\n");
		printf("*************2、汉诺塔系列***************\n");
		printf("*************3、项目拓展之兔子*******\n");
		printf("*************4、返回上一级***************\n");
		printf("*****************************************\n");
		printf("*************请输入对应编号：************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("进入猴子摘桃系列——\n");
			p2menu1();
			_getch();
			break;
		case 2:
			system("cls");
			printf("进入汉诺塔系列——\n");
			p2menu2();
			_getch();
			break;
		case 3:
			system("cls");
			printf("进入拓展项目——\n");
			rabbit();
			_getch();
			break;
		case 4:
			printf("感谢您的使用。退出实战二");
			break;
		default:
			printf("错误编号。按任意键继续......");
			break;
		}
		if (n == 4)
			break;
	}
}

void p2menu1()
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
		monkeypeach1();
		_getch();
		break;
	case 2:
		system("cls");
		monkeypeach2();
		_getch();
		break;
	case 3:
		system("cls");
		printf("感谢你的使用。退出猴子吃桃系列\n");
		Practise2menu();
		_getch();
		break;
	default:
		printf("错误编号。按任意键继续......\n");
		break;
	}
	_getch();
}

void p2menu2()
{
	int n, num;
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
		hanoi1();
		_getch();
		break;
	case 2:
		system("cls");
		hanoi2();
		_getch();
		break;
	case 3:
		system("cls");
		printf("感谢你的使用。退出汉诺塔系列\n");
		Practise2menu();
		_getch();
		break;
	default:
		printf("\n错误编号。按任意键继续......");
		break;
	}
}

void monkeypeach1()
{
	printf("有一只猴子第一天摘下了若干个桃子，当即吃掉了一半，觉得不过瘾又多吃了一个；");
	printf("第二天又将剩下的桃子吃掉一半，还不过瘾又多吃了一个；");
	printf("按照这个吃法，每天都吃掉前一天剩下的一半又多一个。到了第10天，就剩下一个桃子。");
	printf("问：这只猴子第一天摘下了多少个桃子？\n");

	int k = 10, sum = 0;
	printf("请输入猴子吃桃子的天数，默认为10\n请输入k=");
	fflush(stdin);
	scanf_s("%d,", &k);
	sum = monkey1(1, k);
	printf("猴子第一天摘桃子个数为%d", sum);
}

int monkey1(int n, int k)
{
	int sum;
	if (n == k)
		sum = 4;
	else
		sum = 2 * (monkey1(n + 1, k) + 1);
	return sum;
}

void monkeypeach2()
{
	printf("如果改变游戏的玩法：猴子第一天摘了x个桃子，当即吃掉了一些，剩下（根号x）个，还不过瘾又多吃了一个剩下y个；");
	printf("第二天又吃掉了一些，剩下(根号y）个，又多吃一个；按照这样的吃法，到了第n天只剩下了一个桃子。");
	printf("问：猴子第一天摘下了几个桃子？\n");
	int k, sum;
	printf("请输入猴子吃桃子的天数，默认为10\n请输入k=");
	fflush(stdin);
	scanf_s("%d", &k);
	sum = monkey2(1, k);
	printf("猴子第一天摘的桃子个数为%d\n", sum);
}

int monkey2(int n, int k)
{
	int sum;
	if (n == k)
		sum = 4;
	else
		sum = (monkey2(n + 1, k) + 1) * (monkey2(n + 1, k) + 1);
	return sum;
}

void hanoi1()
{
	printf("塔内有A，B，C共3个座，座A上有n个大小不等的盘子，大的在下，小的在上。");
	printf("要把这些盘子从座A全部移到座C，在移动过程中可以借用座A，座B或座C.");
	printf("但每次只允许移动一个盘子，并且不允许大盘放在小盘的上面\n");
	int a = 0, b = 0, c = 0;
	int num;
	printf("请输入盘子个数：\n");
	scanf_s("%d", &num);
	han1(num, 'A', 'B', 'C');
}

void han1(int num, char a, char b, char c)
{
	int n = 0;
	if (num == 1)
	{
		printf("第%3d步,%c->%c\n", ++n, a, c);
	}
	else
	{
		han1(num - 1, a, c, b);
		printf("第%3d步,%c->%c\n", ++n, a, c);
		han1(num - 1, b, a, c);
	}
}

void hanoi2()
{
	int num;
	printf("如果改变游戏的玩法：不允许直接从最左（右）边移到最右（左）边。");
	printf("即每次移动一定是移到中间杆或从中间移出），也不允许大盘放到小盘的上面。\n");
	printf("请输入盘子个数:\n");
	scanf_s("%d", &num);
	han2(num, 'A', 'B', 'C');
}

void han2(int num, char A, char B, char C)
{
	int n = 0;
	if (num == 1)
	{
		if (abs(A - C) == 1)
		{
			printf("第%d步:%c->%c\n", ++n, A, C);
		}
		if (abs(A - C) == 2)
		{
			printf("第%d步:%c->%c\n", ++n, A, B);
			printf("第%d步:%c->%c\n", ++n, B, C);
		}
	}
	else
	{
		han2(num - 1, A, B, C);
		han2(1, A, C, B);
		han2(num - 1, A, B, C);
		han2(1, B, A, C);
		han2(num - 1, A, B, C);
	}
}

void rabbit()
{
	int n, x;
	printf("兔子出生两个月后就有繁殖能力，此后每个月能生出一对小兔子来。如果所有兔子都不死，那么n个月后有多少对兔子？\n");
	printf("请输入n：\n");
	scanf_s("%d", &n);
	x = rab(n);
	printf("%d个月后有%d对兔子\n", n, x);
}

int rab(int n)
{
	if (n < 3)
		return n;
	else
		return rab(n - 1) + rab(n - 2);
}

