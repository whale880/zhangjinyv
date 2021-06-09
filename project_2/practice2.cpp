#include"practice2.h"

void Practise2menu()
{
	for (;;)
	{
		system("cls");
		printf("******************ʵս��*****************\n");
		printf("*************1������ժ��ϵ��*************\n");
		printf("*************2����ŵ��ϵ��***************\n");
		printf("*************3����Ŀ��չ֮����*******\n");
		printf("*************4��������һ��***************\n");
		printf("*****************************************\n");
		printf("*************�������Ӧ��ţ�************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("�������ժ��ϵ�С���\n");
			p2menu1();
			_getch();
			break;
		case 2:
			system("cls");
			printf("���뺺ŵ��ϵ�С���\n");
			p2menu2();
			_getch();
			break;
		case 3:
			system("cls");
			printf("������չ��Ŀ����\n");
			rabbit();
			_getch();
			break;
		case 4:
			printf("��л����ʹ�á��˳�ʵս��");
			break;
		default:
			printf("�����š������������......");
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
	printf("******1��������Ŀ************************\n");
	printf("******2����Ŀ��չ************************\n");
	printf("******3��������һ��**********************\n");
	printf("******************************************\n");
	printf("******�������Ӧ��ţ�*******************\n");
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
		printf("��л���ʹ�á��˳����ӳ���ϵ��\n");
		Practise2menu();
		_getch();
		break;
	default:
		printf("�����š������������......\n");
		break;
	}
	_getch();
}

void p2menu2()
{
	int n, num;
	printf("******************************************\n");
	printf("******1��������Ŀ************************\n");
	printf("******2����Ŀ��չ************************\n");
	printf("******3��������һ��**********************\n");
	printf("******************************************\n");
	printf("******�������Ӧ��ţ�*******************\n");
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
		printf("��л���ʹ�á��˳���ŵ��ϵ��\n");
		Practise2menu();
		_getch();
		break;
	default:
		printf("\n�����š������������......");
		break;
	}
}

void monkeypeach1()
{
	printf("��һֻ���ӵ�һ��ժ�������ɸ����ӣ������Ե���һ�룬���ò�����ֶ����һ����");
	printf("�ڶ����ֽ�ʣ�µ����ӳԵ�һ�룬��������ֶ����һ����");
	printf("��������Է���ÿ�춼�Ե�ǰһ��ʣ�µ�һ���ֶ�һ�������˵�10�죬��ʣ��һ�����ӡ�");
	printf("�ʣ���ֻ���ӵ�һ��ժ���˶��ٸ����ӣ�\n");

	int k = 10, sum = 0;
	printf("��������ӳ����ӵ�������Ĭ��Ϊ10\n������k=");
	fflush(stdin);
	scanf_s("%d,", &k);
	sum = monkey1(1, k);
	printf("���ӵ�һ��ժ���Ӹ���Ϊ%d", sum);
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
	printf("����ı���Ϸ���淨�����ӵ�һ��ժ��x�����ӣ������Ե���һЩ��ʣ�£�����x��������������ֶ����һ��ʣ��y����");
	printf("�ڶ����ֳԵ���һЩ��ʣ��(����y�������ֶ��һ�������������ĳԷ������˵�n��ֻʣ����һ�����ӡ�");
	printf("�ʣ����ӵ�һ��ժ���˼������ӣ�\n");
	int k, sum;
	printf("��������ӳ����ӵ�������Ĭ��Ϊ10\n������k=");
	fflush(stdin);
	scanf_s("%d", &k);
	sum = monkey2(1, k);
	printf("���ӵ�һ��ժ�����Ӹ���Ϊ%d\n", sum);
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
	printf("������A��B��C��3��������A����n����С���ȵ����ӣ�������£�С�����ϡ�");
	printf("Ҫ����Щ���Ӵ���Aȫ���Ƶ���C�����ƶ������п��Խ�����A����B����C.");
	printf("��ÿ��ֻ�����ƶ�һ�����ӣ����Ҳ�������̷���С�̵�����\n");
	int a = 0, b = 0, c = 0;
	int num;
	printf("���������Ӹ�����\n");
	scanf_s("%d", &num);
	han1(num, 'A', 'B', 'C');
}

void han1(int num, char a, char b, char c)
{
	int n = 0;
	if (num == 1)
	{
		printf("��%3d��,%c->%c\n", ++n, a, c);
	}
	else
	{
		han1(num - 1, a, c, b);
		printf("��%3d��,%c->%c\n", ++n, a, c);
		han1(num - 1, b, a, c);
	}
}

void hanoi2()
{
	int num;
	printf("����ı���Ϸ���淨��������ֱ�Ӵ������ң����Ƶ����ң��󣩱ߡ�");
	printf("��ÿ���ƶ�һ�����Ƶ��м�˻���м��Ƴ�����Ҳ��������̷ŵ�С�̵����档\n");
	printf("���������Ӹ���:\n");
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
			printf("��%d��:%c->%c\n", ++n, A, C);
		}
		if (abs(A - C) == 2)
		{
			printf("��%d��:%c->%c\n", ++n, A, B);
			printf("��%d��:%c->%c\n", ++n, B, C);
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
	printf("���ӳ��������º���з�ֳ�������˺�ÿ����������һ��С������������������Ӷ���������ôn���º��ж��ٶ����ӣ�\n");
	printf("������n��\n");
	scanf_s("%d", &n);
	x = rab(n);
	printf("%d���º���%d������\n", n, x);
}

int rab(int n)
{
	if (n < 3)
		return n;
	else
		return rab(n - 1) + rab(n - 2);
}

