#include"practice5.h"
#define NUM 2
#define namelen 11
#define tellen 16

typedef struct con   //conΪ�ṹ���ǩ \����    struct student{}stu; 
//                                              studentΪ�ṹ�����ƣ�stuΪ�ṹ��������ơ� 
{
	int code;    //��� 
	char name[namelen];    //���� 
	char tel[tellen];     //�绰���� 
}contact;     //typedef���ṹ�������������������Ȼ�������contact��Ϊ���������µĽṹ����� 


void telephone()
{
	contact con[NUM];   //���û��typedef����Ҫʹ��struct con[NUM] 
	int i = 0, n;
	for (i = 0; i < NUM; i++)
	{
		printf("�������������ϵ�˵Ļ�����Ϣ����\n");
		printf("��ţ�");
		scanf("%d", &con[i].code);
		printf("����(������10���ַ�)��");
		scanf("%s", con[i].name);
		printf("�绰���루������15���ַ�����");
		scanf("%s", con[i].tel);
		printf("\n");
	}

	for (i = 0; i < NUM; i++)
	{
		printf("��ţ�%d\t", con[i].code);
		printf("������%s\t", con[i].name);
		printf("�绰��%s\n", con[i].tel);
		printf("\n");
	}
}