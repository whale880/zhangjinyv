#include"practice5.h"
#define NUM 2
#define namelen 11
#define tellen 16

typedef struct con   //con为结构体标签 \名称    struct student{}stu; 
//                                              student为结构体名称，stu为结构体变量名称。 
{
	int code;    //编号 
	char name[namelen];    //姓名 
	char tel[tellen];     //电话号码 
}contact;     //typedef将结构体变量类型重新命名，然后可以用contact作为类型声明新的结构体变量 


void telephone()
{
	contact con[NUM];   //如果没有typedef，就要使用struct con[NUM] 
	int i = 0, n;
	for (i = 0; i < NUM; i++)
	{
		printf("请输入这个人联系人的基本信息——\n");
		printf("编号：");
		scanf("%d", &con[i].code);
		printf("姓名(不超出10个字符)：");
		scanf("%s", con[i].name);
		printf("电话号码（不超出15个字符）：");
		scanf("%s", con[i].tel);
		printf("\n");
	}

	for (i = 0; i < NUM; i++)
	{
		printf("编号：%d\t", con[i].code);
		printf("姓名：%s\t", con[i].name);
		printf("电话：%s\n", con[i].tel);
		printf("\n");
	}
}