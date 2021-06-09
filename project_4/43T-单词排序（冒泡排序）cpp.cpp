#include"practice4.h"
#define N 4 //固定四个单词
#define LEN 26  //单次最大长度
void bubblesort(char w[N][LEN + 1]);

void maopaosort()
{
	int i = 0;
	char w[N][LEN + 1];
	printf("请输入%d个单词（注：每个单词长度不超出%d个字符\n", N, LEN);
	for (i = 0; i < N; i++)
	{
		scanf("%s", w[i]);
		w[i][LEN] = '\0';
	}
	bubblesort(w);     //调用函数
	printf("按照升序排序后的结果\n");
	for (i = 0; i < N; i++)
	{
		printf("%s\n", w[i]);    //输出结果
	}
}

void bubblesort(char w[N][LEN + 1])  //冒泡排序
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