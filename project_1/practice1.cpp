#include"practice1.h"

void Practise1menu()
{
	for (;;)
	{
		system("cls");
		printf("************ʵսһ***********\n");
		printf("***��ѡ����Ҫ�Ĺ��ܣ�***\n");
		printf("1�����������\n");
		printf("2������������\n");
		printf("3�����ӳ�������\n");
		printf("4����չ��Ŀ\n");
		printf("5��������һ��\n");
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
			printf("��л����ʹ�á��˳�ʵսһ��");
			break;
		default:
			printf("�����š������������......\n");
		}
		if (n == 5)
			break;
	}
}

void menu1()
{
	int n;
	printf("**************���������************\n");
	printf("**��ѡ����Ҫ���������ж����ͣ�**\n");
	printf("1���������жϣ�\n");
	printf("2���ж��Ƿ���ֱ�������Σ�\n");
	printf("3���ж��Ƿ��ǵ��������Σ�\n");
	printf("4���ж��Ƿ��ǵȱ������Σ�\n");
	printf("5��������һ����\n");
	printf("**********************************\n");
	printf("��ѡ�����ѡ�\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:sanjiaoxing(); _getch(); break;
	case 2:zhijiao(); _getch(); break;
	case 3:dengyao(); _getch(); break;
	case 4:dengbian(); _getch(); break;
	case 5:
		printf("��лʹ�á��˳������Σ�\n");
		Practise1menu();
		_getch();
		break;
	default:printf("������ˡ�\n");
	}
}

void sanjiaoxing()
{
	printf("�ж��ܷ񹹳�������\n");
	int a, b, c;
	printf("������������������a��b��c����ֵ��");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		printf("���Թ���һ�������Ρ�\n");
	}
	else { printf("�����Թ���һ�������Ρ�\n"); }
}

void zhijiao()
{
	printf("�ж��ܷ񹹳�ֱ��������\n");
	int a, b, c;
	printf("�����������������ߵĳ��ȣ���������\n");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
			printf("��ֱ�������Ρ�\n");
		else
			printf("����ֱ�������Ρ�\n");
	}
	else
	{
		printf("�������߲����Թ���һ�������Σ����������롣\n");
	}
}

void dengyao()
{
	printf("�ж��ܷ񹹳ɵ���������\n");
	int a, b, c;
	printf("�����������������ߵĳ��ȣ���������\n");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a == b || a == c || b == c)
			printf("�ǵ��������Ρ�\n");
		else
			printf("���ǵ��������Ρ�\n");
	}
	else
	{
		printf("�������߲����Թ���һ�������Σ�����������\n");
	}
}

void dengbian()
{
	printf("�ж��ܷ񹹳ɵȱ�������\n");
	int a, b, c;
	printf("�����������������ߵĳ��ȣ���������\n");
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a == b && b == c)
			printf("�ǵȱ������Ρ�\n");
		else
			printf("���ǵȱ������Ρ�\n");
	}
	else
	{
		printf("�������߲����Թ���һ�������Σ�����������\n");
	}
}

void yunsuanqi()
{
	int a, b, c;
	char op;
	int answer;
	do {
		printf("������������������");
		printf("�����������������������(��1+1/2^3)��\n");
		scanf_s("%d %c %d", &a, &op, &b);
		c = zhishu(a, b);
		switch (op)
		{
		case '+':printf("%d+%d=%d\n", a, b, a + b); break;
		case '-':printf("%d-%d=%d\n", a, b, a - b); break;
		case '*':printf("%d*%d=%d\n", a, b, a * b); break;
		case '/':printf("%d/%d=%d\n", a, b, a / b); break;
		case '^':printf("%d^%d=%d\n", a, b, c); break;
		default:printf("���Ŵ���\n");
		}
		printf("�Ƿ�Ҫ�����������㣬�����������1������������2��\n");
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
	printf("���ӳ������⡪��\n");
	printf("��һֻ���ӵ�һ��ժ�������ɸ����ӣ������Ե���һ�룬���ò�����ֶ����һ����");
	printf("�ڶ����ֽ�ʣ�µ����ӳԵ�һ�룬��������ֶ����һ����");
	printf("��������Է���ÿ�춼�Ե�ǰһ��ʣ�µ�һ���ֶ�һ�������˵�10�죬��ʣ��һ�����ӡ�");
	printf("�ʣ���ֻ���ӵ�һ��ժ���˶��ٸ����ӣ�\n");
	int i, x, count = 1;
	printf("����������ڵڼ����Ե�ֻʣ����һ�����ӣ�\n");
	scanf_s("%d", &x);
	printf("�����ڵ�%d���Ե�ֻʣ��һ������\n", x);
	for (i = 1; i < x; i++)
	{
		count = (count + 1) * 2;
		if ((x - i) > 1)
		{
			printf("��%d�����������Ӹ���Ϊ%d��\n", (x - i), count);
		}
		else printf("��1����ժ�����Ӹ���Ϊ%d��\n", count);
	}
}

void tuozhanxiangmu()
{
	printf("�ж��Ƿ��ǻ����������ǻ������������ż����������");
	long ge, shi, qian, wan, x;
	printf("��ѡ���ǻ���������\n");
	printf("������һ����λ������\n");
	scanf_s("%ld", &x);
	wan = x / 10000;
	qian = (x % 10000) / 1000;
	shi = (x % 100) / 10;
	ge = x % 10;
	if (ge == wan && shi == qian)
	{
		if (x % 2 == 0)
			printf("������ǻ���������ż��\n");
		else
			printf("������ǻ�������������\n");
	}
	else
		printf("��������ǻ�����\n");
}
