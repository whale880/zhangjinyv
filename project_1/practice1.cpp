#include"practice1.h"

void Practise1menu()
{
	for (;;)
	{
		system("cls");
		printf("************实战一***********\n");
		printf("***请选择你要的功能：***\n");
		printf("1、三角形相关\n");
		printf("2、四则运算器\n");
		printf("3、猴子吃桃问题\n");
		printf("4、拓展项目\n");
		printf("5、返回上一级\n");
		printf("****************************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			menu1();
			_getch();
			break;
		case 2:
			system("cls");
			yunsuanqi();
			_getch();
			break;
		case 3:
			system("cls");
			houzichitao();
			_getch();
			break;
		case 4:
			system("cls");
			tuozhanxiangmu();
			_getch();
			break;
		case 5:
			printf("感谢您的使用。退出实战一！");
			break;
		default:
			printf("错误编号。按任意键继续......\n");
		}
		if (n == 5)
			break;
	}
}

void menu1()
{
	int n;
	printf("**************三角形相关************\n");
	printf("**请选择你要的三角形判断类型：**\n");
	printf("1、三角形判断；\n");
	printf("2、判断是否是直角三角形；\n");
	printf("3、判断是否是等腰三角形；\n");
	printf("4、判断是否是等边三角形；\n");
	printf("5、返回上一级；\n");
	printf("**********************************\n");
	printf("请选择你的选项：\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:sanjiaoxing(); _getch(); break;
	case 2:zhijiao(); _getch(); break;
	case 3:dengyao(); _getch(); break;
	case 4:dengbian(); _getch(); break;
	case 5:
		printf("感谢使用。退出三角形！\n");
		Practise1menu();
		_getch();
		break;
	default:printf("你输错了。\n");
	}
}

void sanjiaoxing()
{
	printf("判断能否构成三角形\n");
	int a, b, c;
	printf("请输入三角形三条边a、b、c的数值：");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		printf("可以构成一个三角形。\n");
	}
	else { printf("不可以构成一个三角形。\n"); }
}

void zhijiao()
{
	printf("判断能否构成直角三角形\n");
	int a, b, c;
	printf("请输入三角形三条边的长度（整数）：\n");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
			printf("是直角三角形。\n");
		else
			printf("不是直角三角形。\n");
	}
	else
	{
		printf("这三条边不可以构成一个三角形，请重新输入。\n");
	}
}

void dengyao()
{
	printf("判断能否构成等腰三角形\n");
	int a, b, c;
	printf("请输入三角形三条边的长度（整数）：\n");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a == b || a == c || b == c)
			printf("是等腰三角形。\n");
		else
			printf("不是等腰三角形。\n");
	}
	else
	{
		printf("这三条边不可以构成一个三角形，请重新输入\n");
	}
}

void dengbian()
{
	printf("判断能否构成等边三角形\n");
	int a, b, c;
	printf("请输入三角形三条边的长度（整数）：\n");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a == b && b == c)
			printf("是等边三角形。\n");
		else
			printf("不是等边三角形。\n");
	}
	else
	{
		printf("这三条边不可以构成一个三角形，请重新输入\n");
	}
}

void yunsuanqi()
{
	int a, b, c;
	char op;
	int answer;
	do {
		printf("——简易运算器——");
		printf("请输入两个运算数和运算符(如1+1/2^3)：\n");
		scanf_s("%d %c %d", &a, &op, &b);
		c = zhishu(a, b);
		switch (op)
		{
		case '+':printf("%d+%d=%d\n", a, b, a + b); break;
		case '-':printf("%d-%d=%d\n", a, b, a - b); break;
		case '*':printf("%d*%d=%d\n", a, b, a * b); break;
		case '/':printf("%d/%d=%d\n", a, b, a / b); break;
		case '^':printf("%d^%d=%d\n", a, b, c); break;
		default:printf("符号错误！\n");
		}
		printf("是否要继续进行运算，如果是请输入1，不是请输入2：\n");
		scanf_s("%d", &answer);
	} while (answer == 1);
}
int zhishu(int a, int b)
{
	int i, sum = a;
	for (i = 1; i < b; i++)
	{
		sum = sum * a;
	}
	return sum;
}

void houzichitao()
{
	printf("猴子吃桃问题——\n");
	printf("有一只猴子第一天摘下了若干个桃子，当即吃掉了一半，觉得不过瘾又多吃了一个；");
	printf("第二天又将剩下的桃子吃掉一半，还不过瘾又多吃了一个；");
	printf("按照这个吃法，每天都吃掉前一天剩下的一半又多一个。到了第10天，就剩下一个桃子。");
	printf("问：这只猴子第一天摘下了多少个桃子？\n");
	int i, x, count = 1;
	printf("请输入猴子在第几天后吃得只剩下了一个桃子：\n");
	scanf_s("%d", &x);
	printf("猴子在第%d天后吃得只剩下一个桃子\n", x);
	for (i = 1; i < x; i++)
	{
		count = (count + 1) * 2;
		if ((x - i) > 1)
		{
			printf("第%d天所剰的桃子个数为%d个\n", (x - i), count);
		}
		else printf("第1天所摘的桃子个数为%d个\n", count);
	}
}

void tuozhanxiangmu()
{
	printf("判断是否是回文数且若是回文数这个数是偶数还是奇数");
	long ge, shi, qian, wan, x;
	printf("我选的是回文数问题\n");
	printf("请输入一个五位整数：\n");
	scanf_s("%ld", &x);
	wan = x / 10000;
	qian = (x % 10000) / 1000;
	shi = (x % 100) / 10;
	ge = x % 10;
	if (ge == wan && shi == qian)
	{
		if (x % 2 == 0)
			printf("这个数是回文数且是偶数\n");
		else
			printf("这个数是回文数且是奇数\n");
	}
	else
		printf("这个数不是回文数\n");
}
