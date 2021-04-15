//restar
//对N个单词进行排序 利用strcmp和strcpy函数
#include<stdio.h>
#include<string.h>
#define N 50//单词数上限
#define M 26//单词长度上限
#pragma warning(disable:4996)
void wordsort(char word[][M], int n)//形式函数以及数组相关概念☆
{
	char key[M];
	int i, j;
	for (i = 1; i < n; i++)
	{
		strcpy(key, word[i]);
		j = i;
		while (j >= 1 && strcmp(word[j - 1], key) > 0)
		{
			strcpy(word[j], word[j - 1]);
			j--;
		}
		strcpy(word[i], key);
	}
}
void print(const char word[][M], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", word[i]);
	}
}

void main()
{
	char word[N][M];
	int m = M - 1;
	int count = N;
	int n = 0, i;
	while (n < 1 || n>50)
	{
		printf("请输入你将要输入的单词数:(1-%d)\n", count);
		scanf_s("%d", &n);
	}
	printf("请输入%d个单词并且以空格分开\n", n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", &word[i]);
		word[i][M - 1] = '\0';
	}
	wordsort(word, n);
	print(word, n);
}