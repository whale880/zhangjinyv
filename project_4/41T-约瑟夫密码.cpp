#include"practice4.h"

void mima()
{
	int N, M, pwd;    //NΪ��������MΪ��һ���˳��ӵľ�����
	int i, mark, count;   //martΪ������������countΪ��Ȧ�˼�����
	int r[31], out[31];     //�޶����Ϊ30�ˣ���������r[]���Դ��ÿ���˵����룬����out[]���Լ�¼��Ȧ�����
	printf("\n��������������<=30������ʼ��M����������ֵ����5,3\n");
	scanf("%d%d", &N, &M);
	printf("��ֱ�����ÿ���˵����루�ÿո�ֿ�����\n");
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &pwd);
		r[i] = pwd;
	}
	mark = 0;    //������������ʼ��
	count = 0;     //������������ʼ��
	while (1)
	{
		for (i = 1; i <= N; i++)
		{
			if (r[i] > 0)
			{
				mark++;
				if (mark == M)    //���˱�ǵ�����ִ�н����������
				{
					count++;
					out[count] = i;
					M = r[i];
					r[i] = 0;
					mark = 0;
				}
			}
		}
		if (count == N)
			break;
	}
	printf("���е��Ⱥ����Ϊ��\n");     //������
	for (i = 1; i <= N; i++)
		printf("%d", out[i]);
}