#include"practice4.h"

#define LEN 100
void count(char[]);

int lc = 0, uc = 0, f = 0, s = 0, any = 0;
void countmain()
{
	char a[LEN + 1];      //字符串末尾存放‘\0’
	printf("请输入100以内任意字符\n");
	printf("程序将按大小写字母、数字、空格和其他字符进行统计。\n");
	gets_s(a);        //scanf_s("%s", a,LEN+1);(但是scanf不能读空格)
	count(a);         //调用函数
	printf("小写字母：%d\n", lc);    //lower case
	printf("大写字母：%d\n", uc);     //upper case
	printf("0-9的数字：%d\n", f);
	printf("空格：%d\n", s);
	printf("其他字符：%d\n", any);
	printf("按任意键退出…");
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