#include"practice4.h"

#define N 5
#define M 26
void Wordsort(char word[][M], int);
void print(const char word[][M], int);

void Wordsortmain()
{
	char word[N][M];   //定义一个二维数组
	int m = M - 1;
	int count = N;
	int n = 0, i;
	for (int i = 0; i < n; i++)
	{
		printf("请输入你将要输入的单词数：（1-%d)\n", count);
		scanf_s("%d", &n);
	}
	printf("请输入%d个单词，以空格分开\n（单词长度不超过%d的，若超出，程序会自动忽略超出部分）\n", n, m);
	//输入n个单词
	for (i = 0; i < n; i++)
	{
		scanf_s("%s", &word[i], N);
		word[i][M - 1] = '0';
	}
	Wordsort(word, n);    //调用函数进行操作
	printf("程序结束");
}


void Wordsort(char word[][M], int n)    //插入排序
{
	char key[M];
	int i, j;
	for (i = 1; i < n; i++)
	{
		strcpy_s(key, word[i]);
		j = 1;
		while (j >= 1 && strcmp(word[j - 1], key) > 0)  //字符串比较函数
		{
			strcpy_s(word[j], word[j - 1]);
			j--;
		}
		strcpy_s(word[j], key);    //复制函数，将key的值赋给word
	}
}

void print(const char word[][M], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", word[i]);  //输出结果
	}
}