#include"practice4.h"

#define N 5
#define LEN 10
void Josephproblem(char[][LEN], int);//������ά����

void ysf()
{
	char name[N][LEN];
	int i, k;    //k��ʾ������kʱ�������˳�
	printf("����������%d��������ÿ������������10���ַ�����\n", N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%s", name[i], sizeof(name[i]));
	}
	printf("�����������ڼ���ʱ�˳�");
	scanf_s("%d", &k);
	Josephproblem(name, k);
	//_getch();
}

void Josephproblem(char a[][LEN], int k)
{
	int out = 0;   //��������ͳ�ƣ�out=Nʱѭ������
	int counter = 0;   //����������counterΪkʱ�������˳���counter����Ϊ0
	int idx = -1;    //idxΪ�����±꣬������
	while (out < N)
	{
		idx++;
		if (idx == N)
			idx = 0;
		else if (strcmp(a[idx], "\0") == 0)    //�ַ����ȽϺ��������������������ȣ�����⵽����ַ���������ʱ
			continue;
		else
		{
			counter++;
			if (counter == k)
			{
				out++;
				printf("��%3d���˳��ߣ�%s\n", out, a[idx]);
				strcpy_s(a[idx], "0");  //���ƺ���
				counter = 0;
			}
		}
	}
}