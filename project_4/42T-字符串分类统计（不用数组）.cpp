#include"practice4.h"

#define LEN 100
void count(char[]);

void countcount()
{
	int lc = 0, uc = 0, f = 0, s = 0, any = 0;
	printf("请输入一串字符串\n");
	char x;// = getchar();
	while (x = getchar() != '\n');
	{
		if (x >= '0' && x <= '9')   //数字条件
			f++;
		else if (x >= 'a' && x <= 'z')     //小写字母的范围
			lc++;
		else if (x >= 'A' && x <= 'Z')      //大写字母的范围
			uc++;
		else if (x == ' ')      //空格
			s++;
		else
			any++;
	}

	printf("小写字母：%d\n", lc);    //lower case小写
	printf("大写字母：%d\n", uc);     //upper case大写
	printf("0-9的数字：%d\n", f);
	printf("空格：%d\n", s);
	printf("其他字符：%d\n", any);
	printf("按任意键退出…");
}