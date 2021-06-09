#include"practice4.h"

void mima()
{
	int N, M, pwd;    //N为总人数，M为第一个人出队的决定数
	int i, mark, count;   //mart为数数计数器，count为出圈人计数器
	int r[31], out[31];     //限定最多为30人，其中数组r[]用以存放每个人的密码，数组out[]用以记录出圈人序号
	printf("\n请输入总人数（<=30）及开始的M（正整数）值：如5,3\n");
	scanf("%d%d", &N, &M);
	printf("请分别输入每个人的密码（用空格分开）；\n");
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &pwd);
		r[i] = pwd;
	}
	mark = 0;    //数数计数器初始化
	count = 0;     //出队总人数初始化
	while (1)
	{
		for (i = 1; i <= N; i++)
		{
			if (r[i] > 0)
			{
				mark++;
				if (mark == M)    //到了标记的数就执行交换密码操作
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
	printf("出列的先后序号为：\n");     //输出结果
	for (i = 1; i <= N; i++)
		printf("%d", out[i]);
}