#include"practice4.h"

#define LEN 100
void count(char[]);

int lc = 0, uc = 0, f = 0, s = 0, any = 0;
void countmain()
{
	char a[LEN + 1];      //�ַ���ĩβ��š�\0��
	printf("������100���������ַ�\n");
	printf("���򽫰���Сд��ĸ�����֡��ո�������ַ�����ͳ�ơ�\n");
	gets_s(a);        //scanf_s("%s", a,LEN+1);(����scanf���ܶ��ո�)
	count(a);         //���ú���
	printf("Сд��ĸ��%d\n", lc);    //lower case
	printf("��д��ĸ��%d\n", uc);     //upper case
	printf("0-9�����֣�%d\n", f);
	printf("�ո�%d\n", s);
	printf("�����ַ���%d\n", any);
	printf("��������˳���");
}

void count(char a[])
{
	int i = 0;
	while (a[i] != 0)
	{
		if (a[i] >= '0' && a[i] <= '9')
			f++;
		else if (a[i] >= 'a' && a[i] <= 'z')
			lc++;
		else if (a[i] >= 'A' && a[i] <= 'Z')
			uc++;
		else if (a[i] == ' ')
			s++;
		else
			any++;
		i++;
	}
}