#include"practice8.h"

void Practise8menu()
{
	for (;;)
	{
		system("cls");
		printf("******************ʵս��*****************\n");
		printf("*************0���������ݿ�����**************\n");
		printf("*************1��mysql�򵥼�����*************\n");
		printf("*************2��mysqlѧ��ѧ������ϵͳ***************\n");
		printf("*************3��mysql��Ŀ��չ֮ͼ�����ϵͳ*******\n");
		printf("*************4��������һ��***************\n");
		printf("*****************************************\n");
		printf("*************�������Ӧ��ţ�************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 0:
			system("cls");
			printf("����������ݿ����ӡ���\n");
			mysqltest();
			_getch();
			break;
		case 1:
			system("cls");
			printf("����mysql�򵥼���������\n");
			MySQL_counter();
			_getch();
			break;
		case 2:
			system("cls");
			printf("����mysqlѧ��ѧ����Ϣ����ϵͳ����\n");
			MYstudent();
			_getch();
			break;
		case 3:
			system("cls");
			printf("����mysql��չ��Ŀ֮��������ϵͳ����\n");
			order8();
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