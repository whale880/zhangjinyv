#include<stdio.h>
void main()
#define N 10
{
	int array[N],i,n;
	printf("������ʮ������:\n");
	for(i=0;i<N;i++)
	scanf_s("%d", &array[i]);
	printf("������Ҫ������һ��������:\n");
	scanf_s("%d", &n);
	for (i = 0; i < N; i++)
	{
		if (n == array[i])
			break;
	}
	if (i < N)
		printf("�ҵ����������λ�ڵ�%d����\n", i+1);
	else printf("������˼Ŷ����ʵ����û���ҵ����������\n");
}