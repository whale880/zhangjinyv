#include "practice7.h"

void Practise7menu()
{
	printf("************ʵս��***********\n");
	for (;;)
	{
		system("cls");
		printf("******************ʵս��*****************\n");
		printf("*************1���򵥼�����*************\n");
		printf("*************2��ѧ��ѧ������ϵͳ***************\n");
		printf("*************3����Ŀ��չ֮ͼ�����ϵͳ*******\n");
		printf("*************4��������һ��***************\n");
		printf("*****************************************\n");
		printf("*************�������Ӧ��ţ�************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("����򵥼���������\n");
			counter();
			_getch();
			break;
		case 2:
			system("cls");
			printf("����ѧ��ѧ����Ϣ����ϵͳ����\n");
			Studentinformation();
			_getch();
			break;
		case 3:
			system("cls");
			printf("������չ��Ŀ֮ͼ�����ϵͳ����\n");
			library();
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
	_getch();
}