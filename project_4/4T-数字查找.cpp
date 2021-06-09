#include"practice4.h"
#define N 10

void wordselect()
{
	printf("输入10个数，保存在一个数组中，在数组中查找某个数，给出是否找到的信息。");
	printf("如果找到了，要求输出该数在数组中所处的位置；如果找不到，输出“没有找到！”\n");
	int num[N], i, key, answer;
	do
	{
		printf("请输入10个数：\n");  //输入十个数
		for (i = 0; i < N; i++)
			scanf_s("%d", &num[i]);
		printf("请输入你要找的数：\n");
		scanf_s("%d", &key);   //输入关键数：你要找的数
		for (i = 0; i < N; i++)
		{
			if (num[i] == key)
			{
				printf("\n在数组的第%d个位置找到了数字%d\n", i + 1, key);
				break;
			}
		}
		if (i == N)
			printf("\n没有找到这个数\n");
		printf("\n是否继续进行数字查找，继续请输1，不是请输0：\n"); //do while继续循环
		scanf("%d", &answer);
		printf("\n\n");
	} while (answer == 1);
}