#include"practice4.h"

#define N 5
#define LEN 10
void Josephproblem(char[][LEN], int);//声明二维数组

void ysf()
{
	char name[N][LEN];
	int i, k;    //k表示数到第k时即该人退出
	printf("请依次输入%d个人名（每个人名不超出10个字符）：\n", N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%s", name[i], sizeof(name[i]));
	}
	printf("请输入数到第几人时退出");
	scanf_s("%d", &k);
	Josephproblem(name, k);
	//_getch();
}

void Josephproblem(char a[][LEN], int k)
{
	int out = 0;   //出列人数统计，out=N时循环结束
	int counter = 0;   //数数器，当counter为k时，该人退出，counter重置为0
	int idx = -1;    //idx为数组下标，即索引
	while (out < N)
	{
		idx++;
		if (idx == N)
			idx = 0;
		else if (strcmp(a[idx], "\0") == 0)    //字符串比较函数，等于零代表两者相等，当检测到这个字符串结束符时
			continue;
		else
		{
			counter++;
			if (counter == k)
			{
				out++;
				printf("第%3d个退出者：%s\n", out, a[idx]);
				strcpy_s(a[idx], "0");  //复制函数
				counter = 0;
			}
		}
	}
}