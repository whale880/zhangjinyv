#include"practice5.h"

void Practise5menu()
{
	for (;;)
	{
		system("cls");
		printf("******************ʵս��*****************\n");
		printf("*************1��ѧ����Ϣ����ϵͳ*************\n");
		printf("*************2���𳵶�Ʊϵͳ***************\n");
		printf("*************3����Ŀ��չ֮�绰��*******\n");
		printf("*************4��������һ��***************\n");
		printf("*****************************************\n");
		printf("*************�������Ӧ��ţ�************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("����ѧ����Ϣ����ϵͳ����\n");
			Sstudent();
			_getch();
			break;
		case 2:
			system("cls");
			printf("����𳵶�Ʊϵͳ����\n");
			Practise53();
			_getch();
			break;
		case 3:
			system("cls");
			printf("������չ��Ŀ����\n");
			telephone();
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