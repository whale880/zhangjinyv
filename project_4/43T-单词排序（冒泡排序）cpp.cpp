#include"practice4.h"
#define N 4 //�̶��ĸ�����
#define LEN 26  //������󳤶�
void bubblesort(char w[N][LEN + 1]);

void maopaosort()
{
	int i = 0;
	char w[N][LEN + 1];
	printf("������%d�����ʣ�ע��ÿ�����ʳ��Ȳ�����%d���ַ�\n", N, LEN);
	for (i = 0; i < N; i++)
	{
		scanf("%s", w[i]);
		w[i][LEN] = '\0';
	}
	bubblesort(w);     //���ú���
	printf("�������������Ľ��\n");
	for (i = 0; i < N; i++)
	{
		printf("%s\n", w[i]);    //������
	}
}

void bubblesort(char w[N][LEN + 1])  //ð������
{
	int i = 0, j = 0;
	char tmp[LEN + 1];
	for (j = 0; j < N - 1; j++)
	{
		for (i = 0; i < N - 1; i++)
		{
			if (strcmp(w[i], w[i + 1]) > 0)
			{
				strcpy(tmp, w[i + 1]);
				strcpy(w[i], w[i + 1]);
				strcpy(w[i + 1], tmp);
			}
		}
	}
}