#include"practice4.h"
#define N 10

void wordselect()
{
	printf("����10������������һ�������У��������в���ĳ�����������Ƿ��ҵ�����Ϣ��");
	printf("����ҵ��ˣ�Ҫ�����������������������λ�ã�����Ҳ����������û���ҵ�����\n");
	int num[N], i, key, answer;
	do
	{
		printf("������10������\n");  //����ʮ����
		for (i = 0; i < N; i++)
			scanf_s("%d", &num[i]);
		printf("��������Ҫ�ҵ�����\n");
		scanf_s("%d", &key);   //����ؼ�������Ҫ�ҵ���
		for (i = 0; i < N; i++)
		{
			if (num[i] == key)
			{
				printf("\n������ĵ�%d��λ���ҵ�������%d\n", i + 1, key);
				break;
			}
		}
		if (i == N)
			printf("\nû���ҵ������\n");
		printf("\n�Ƿ�����������ֲ��ң���������1����������0��\n"); //do while����ѭ��
		scanf("%d", &answer);
		printf("\n\n");
	} while (answer == 1);
}