#include"practice4.h"

#define N 5
#define M 26
void Wordsort(char word[][M], int);
void print(const char word[][M], int);

void Wordsortmain()
{
	char word[N][M];   //����һ����ά����
	int m = M - 1;
	int count = N;
	int n = 0, i;
	for (int i = 0; i < n; i++)
	{
		printf("�������㽫Ҫ����ĵ���������1-%d)\n", count);
		scanf_s("%d", &n);
	}
	printf("������%d�����ʣ��Կո�ֿ�\n�����ʳ��Ȳ�����%d�ģ���������������Զ����Գ������֣�\n", n, m);
	//����n������
	for (i = 0; i < n; i++)
	{
		scanf_s("%s", &word[i], N);
		word[i][M - 1] = '0';
	}
	Wordsort(word, n);    //���ú������в���
	printf("�������");
}


void Wordsort(char word[][M], int n)    //��������
{
	char key[M];
	int i, j;
	for (i = 1; i < n; i++)
	{
		strcpy_s(key, word[i]);
		j = 1;
		while (j >= 1 && strcmp(word[j - 1], key) > 0)  //�ַ����ȽϺ���
		{
			strcpy_s(word[j], word[j - 1]);
			j--;
		}
		strcpy_s(word[j], key);    //���ƺ�������key��ֵ����word
	}
}

void print(const char word[][M], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", word[i]);  //������
	}
}