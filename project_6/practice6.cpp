#include"practice6.h"

void Practise6menu()
{
	for (;;)
	{
		system("cls");
		printf("******************ʵս��*****************\n");
		printf("**********1��Լɪ����Ϸ��ָ�룩**********\n");
		printf("**********2��ѧ����Ϣ�Ǽǹ��� ***********\n");
		printf("**********3��̰���� *********************\n");
		printf("**********4����չ��Ŀ *******************\n");
		printf("**********5��������һ��******************\n");
		printf("*****************************************\n");
		printf("************�������Ӧ��ţ�*************\n");
		int n;
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("����Լɪ����Ϸ��ָ�룩 ����\n");
			joseph();
			_getch();
			break;
		case 2:
			system("cls");
			printf("����ѧ����Ϣ�Ǽǹ�����\n");
			shizhan6jibenxiangmu2();
			_getch();
			break;
		case 3:
			system("cls");
			printf("����̰���ߡ���\n");
			snake();
			_getch();
			break;
		case 4:
			system("cls");
			printf("������չ��Ŀ����\n");
			queue();
			_getch();
			break;
		case 5:
			printf("��л����ʹ�á��˳�ʵս��");
			break;
		default:
			printf("�����š������������......");
			break;
		}
		if (n == 5)
			break;
	}
}