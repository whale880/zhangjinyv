#include"practice4.h"

void Practise4menu()
{
	for (;;)
	{
		system("cls");
		printf("************ʵս��***********\n");
		printf("*** ��ѡ����Ҫ�Ĺ��ܣ�***\n");
		printf("1��Լɪ��ϵ��\n");
		printf("2������ͳ�������ַ����и����ַ�����\n");
		printf("3���������N����������\n");
		printf("4����չ��Ŀ\n");
		printf("5��������һ��\n");
		printf("****************************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("\n����Լɪ��ϵ�С���\n");
			p4menu1();
			_getch();
			break;
		case 2:
			system("cls");
			printf("\n�������ͳ��ϵ�С���\n");
			p4menu2();
			_getch();
			break;
		case 3:
			system("cls");
			printf("\n���뵥������ϵ�С���\n");
			p4menu3();
			_getch();
			break;
		case 4:
			system("cls");
			printf("\n������չ��Ŀ֮���ֲ��ҡ���\n");
			p4tuozhanxiangmu();
			_getch();
			break;
		case 5:
			printf("��л����ʹ�á��˳�ʵս�ģ�");
			break;
		default:
			printf("�����š������������......\n");
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
		printf("\n����Լɪ�򻷡���\n");
		ysf();
		_getch();
		break;
	case 2:
		system("cls");
		printf("\n����Լɪ���������⡪��\n");
		mima();
		_getch();
		break;
	case 3:
		system("cls");
		printf("\n��л���ʹ�á��˳�\n");
		Practise4menu();
		_getch();
		break;
	default:
		printf("\n�����š������������......\n");
		break;
	}
	_getch();
}

void p4menu2()
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
		printf("\n�������ͳ���ַ�����\n");
		countmain();
		_getch();
		break;
	case 2:
		system("cls");
		printf("\n�������ͳ���ַ�����������ʵ�ֶ��룩����\n");
		countcount();
		_getch();
		break;
	case 3:
		system("cls");
		printf("\n��л���ʹ�á��˳�\n");
		Practise4menu();
		_getch();
		break;
	default:
		printf("\n�����š������������......\n");
		break;
	}
}



void p4menu3()
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
		printf("\n���뵥�����򣨲������򷨣�����\n");
		Wordsortmain();
		_getch();
		break;
	case 2:
		system("cls");
		printf("\n���뵥������ð�����򷨣�����\n");
		maopaosort();
		_getch();
		break;
	case 3:
		system("cls");
		printf("\n��л���ʹ�á��˳�\n");
		Practise4menu();
		_getch();
		break;
	default:
		printf("\n�����š������������......\n");
		break;
	}
}

void p4tuozhanxiangmu()
{
	system("cls");
	printf("\n�������ֲ��ҡ���\n");
	wordselect();
	_getch();
}