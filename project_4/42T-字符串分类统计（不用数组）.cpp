#include"practice4.h"

#define LEN 100
void count(char[]);

void countcount()
{
	int lc = 0, uc = 0, f = 0, s = 0, any = 0;
	printf("������һ���ַ���\n");
	char x;// = getchar();
	while (x = getchar() != '\n');
	{
		if (x >= '0' && x <= '9')   //��������
			f++;
		else if (x >= 'a' && x <= 'z')     //Сд��ĸ�ķ�Χ
			lc++;
		else if (x >= 'A' && x <= 'Z')      //��д��ĸ�ķ�Χ
			uc++;
		else if (x == ' ')      //�ո�
			s++;
		else
			any++;
	}

	printf("Сд��ĸ��%d\n", lc);    //lower caseСд
	printf("��д��ĸ��%d\n", uc);     //upper case��д
	printf("0-9�����֣�%d\n", f);
	printf("�ո�%d\n", s);
	printf("�����ַ���%d\n", any);
	printf("��������˳���");
}