#include<stdio.h>
void main()
#define N 10
{
	int array[N],i,n;
	printf("请输入十个数字:\n");
	for(i=0;i<N;i++)
	scanf_s("%d", &array[i]);
	printf("请问您要查找哪一个数字呢:\n");
	scanf_s("%d", &n);
	for (i = 0; i < N; i++)
	{
		if (n == array[i])
			break;
	}
	if (i < N)
		printf("找到了这个数字位于第%d个呢\n", i+1);
	else printf("不好意思哦但是实在是没有找到这个数字呢\n");
}