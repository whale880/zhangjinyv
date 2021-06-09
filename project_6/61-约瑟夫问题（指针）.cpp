#include"practice6.h"

#define LEN 21   //姓名长度
#define OVER "exit"

typedef struct ps person;
struct ps  //存储游戏人员的结构体
{
	char name[LEN];  //存储姓名
	int pwd;   //存储密码
	struct ps* next;  //结构体指针，指向下一个游戏人员
};

person* head = NULL;  //指向表节点的指针
person* tail = NULL;   //指向末节点的指针
char choice;   //用户选择的菜单项

void inputpersons();   //输入操作，初始化链表
void showmenu();    //显示操作菜单
void displaylink();    //显示链表信息
void resetpwd();   //重输密码
void countandquit();    //开始约瑟夫游戏

int num = 0;    //记录输入的人数

void joseph()
{
	inputpersons();
	while (1)
	{
		system("cls");
		showmenu();
		switch (choice)
		{
		case'1':
			displaylink();  //显示链表信息
			_getch();
			break;
		case'2':
			resetpwd();   //重输密码
			_getch();
			break;
		case'3':
			countandquit();   //开始约瑟夫游戏
			_getch();
			break;
		case'0':
			exit(0);
		}
	}
}

//输入操作，初始化链表
void inputpersons()
{
	char name[LEN];
	person* p;   //新增加的人
	head = tail;   //一开始，首尾都是NULL
	while (1)
	{
		printf("请输入第%d个人的信息，输入%s结束：\n", num + 1, OVER);
		printf("人名（<=%d个字符）:", LEN - 1);
		scanf("%s", name);
		name[LEN - 1] = '\0';
		if (strcmp(name, OVER) == 0)
			return;
		p = (person*)malloc(sizeof(person));  //分配指定大小的内存空间且不做初始化要求
		strcpy(p->name, name);

		//输入密码k
		printf("密码（整数）：");
		scanf("%d", &p->pwd);
		p->next = head;  //首尾相连，形成循环

		//创建链表
		if (NULL == head)
		{
			head = tail = p;
			p->next = head;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
		num++;  //新人添加链表中以后，计数器才加1
		printf("\n");
	}
}

//显示操作菜单
void showmenu()
{
	while (1)
	{
		printf("\n\n请选择操作：");
		printf("\n============================");
		printf("\n(1)显示信息");
		printf("\n(2)重新输入每个人的密码");
		printf("\n(3)开始“数N退出‘游戏’");
		printf("\n(0)退出程序");
		printf("\n============================");
		choice = _getche();
		if ('0' == choice)
			exit(0);
		else if (choice - '0' >= 1 && (choice - '0') <= 3)
			return;
	}
}

//显示链表信息
void displaylink()
{
	int i = 0;
	person* p = head;  //从头结点开始
	//如果没有，就终止
	if (NULL == p)
		return;
	printf("\n\n当前链表信息如下：");
	printf("\n=================================");
	//先输出头结点
	printf("\n%2d:\t%s\t%d", ++i, p->name, p->pwd);
	p = p->next;
	while (p != head)
	{
		printf("\n%2d:\t%s\t%d", ++i, p->name, p->pwd);
		p = p->next;
	}
	printf("\n=================================");
}

void resetpwd() {
	person* p = head;//从头节点开始
	//如果没有，就终止
	if (NULL == p)
		return;
	printf("\n\n请重新输入每个人的密码：");
	printf("\n========================\n");
	printf("%s:", p->name);
	scanf_s("%d", &p->pwd);
	p = p->next;
	while (p != head) {
		printf("%s:", p->name);
		scanf_s("%d", &p->pwd);
		p = p->next;
	}
	printf("\n========================\n");
}

void countandquit()
{
	int i, n, pwd;   //用于计数，和保存当前密码
	//先复制一个链表
	person* p, * c, * q;  //分别指向临时节点、新链表的当前节点、当前节点的前节点
	person* head2 = NULL, * tail2 = NULL;   //分别指向新链表的头、尾结点
	c = head;
	if (NULL == head)
		return;
	p = (person*)malloc(sizeof(person));
	strcpy_s(p->name, c->name);
	p->pwd = c->pwd;
	p->next = p;
	head2 = tail2 = p;  //第一个结点，首尾在一起
	c = c->next;
	while (c != head) {
		p = (person*)malloc(sizeof(person));
		strcpy_s(p->name, c->name);
		p->pwd = c->pwd;
		p->next = head2;
		tail2->next = p;
		tail2 = p;
		c = c->next;
	}

	//开始数N退出
	printf("\n\n游戏处理结果：");
	printf("\n=======================");
	i = 0;
	c = head2;  //将当前指针（用于循环）指向首结点
	q = head2;  //q记录当前结点的前一个结点
	pwd = c->pwd;   // 记录首结点的pwd
	while (c->next != c) {
		n = 1;
		while (n < pwd) {
			q = c;
			c = c->next;
			n++;
		}
		//当前指针c所指的应该退出
		q->next = c->next;
		printf("\n第%2d个退出者：%s", ++i, c->name);
		pwd = c->pwd;    //退出者的密码作为下一个退出者的依据
		free(c);
		c = q->next;
	}
	printf("\n第%2d个退出者：%s", ++i, c->name);
	free(c);
	printf("\n=======================");
}