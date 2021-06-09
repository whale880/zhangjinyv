#include"practice7.h"

#define IDlen 13    //ID字段长度 
#define Namelen 11     //姓名字段长度 
#define Sexlen 5     //性别字段长度 
#define FilePath "student2.dat"    //数据文件的地址 
//存储学生信息的结构体 
typedef struct stu
{

	char id[IDlen];   //学号 
	char name[Namelen];     //姓名 
	char Sex[Sexlen];    //性别 
	int age;     //年龄 
	int cp;     //C语言 
	int en;     //英语 
	int math;     //高数 
	double avg;       //平均分 
}student;
//存储学生信息单链表结点类型 
typedef struct Node
{
	student stu;  //数据域 
	struct Node* next;    //指针域 
}studentnode;
int choice = 0;   //菜单选择值 

studentnode* importDate(FILE* fp);     //导入数据文件中的数据 
studentnode* initDate();       //初始化管理系统数据 
studentnode* findbyName(studentnode* head, char* name);      //按姓名查找学生 
studentnode* findbyID(studentnode* head, char* id);       //按学号查找学生 
void createnewFile(char* path);    //创建初始数据文件 
void displayMenu7();       //显示主操作菜单 
void displayMenuFind();     //显示查找子菜单 
void displayMenuModify();     //显示修改子菜单 
void displayAll(studentnode* head);     //显示所有学生信息    
void diaplayOne(studentnode* p);     //显示一个学生信息 
void modify(studentnode* head);       //修改学生信息 
void deletestudent(studentnode* head);       //删除学生信息 
void add(studentnode* head);        //增加一个学生 
void save(studentnode* head);         //保存数据到文件中 
void sort(studentnode* head);        //按学生平均分排序    *拓展项目


//主菜单 
void Studentinformation()
{
	studentnode* stuhead, * p = NULL;  //存储学生信息的单链表 
	char id[IDlen];   //临时变量，用于接收输入的学号 
	char name[Namelen];       //临时变量，用于接收输入的姓名 
	stuhead = initDate();     //初始化系统数据，导入学生信息

	while (1)
	{
		displayMenu7();      //显示主操作菜单 
		switch (choice)
		{
		case 1:
			displayAll(stuhead);      //显示所有学生信息 
			system("pause");
			break;
		case 2:
			displayMenuFind();        //显示查找子菜单 
			switch (choice)
			{
			case 1:
				printf("\n请输入要查找学生的学号：");
				scanf("%s", id);
				p = findbyID(stuhead, id);     //按学号开始查找
				break;
			case 2:
				printf("\n请输入需要查找学生的姓名");
				scanf("%s", name);
				p = findbyName(stuhead, name);      //按姓名开始查找 
				break;
			}
			diaplayOne(p);    //显示找到的学生信息 
			break;
		case 3:
			modify(stuhead);     //修改学生信息
			system("pause");
			break;
		case 4:
			deletestudent(stuhead);     //删除学生信息
			system("pause");
			break;
		case 5:
			add(stuhead);    //添加学生信息
			system("pause");
			break;
		case 6:
			save(stuhead);     //保存数据到文件
			system("pause");
			break;
		case 7:
			sort(stuhead);
			system("pause");
			break;
		case 0:
			save(stuhead);      //保存数据到文件中 
			system("pause");
			return;
		}
	}
}

//创建新的数据文件 
void createnewFile(const char* path)
{
	FILE* fp;    //定义文件指针 
	student stu;      //临时变量，用于接收学生信息 
	int i = 1;         //临时变量，用于统计学生人数 

	if ((fp = fopen(path, "w")) == NULL)     //以写的方式打开数据文件 
	{
		printf("\n无法创建新的文件！\n");
		return;
	}
	printf("\n请输入学生信息（输入学号为#时，结束输入）：\n");
	while (1)
	{
		printf("请输入第%d个学生的信息：\n", i++);
		printf("----------------------------------------\n");
		printf("学号（12个字符以内）：\t");
		scanf("%s", stu.id);
		stu.id[IDlen - 1] = '\0';      //强加结束符，防止出错 
		if (strcmp(stu.id, "#") == 0)
		{
			printf("输入信息结束：\n");
			fclose(fp);
			return;
		}
		printf("姓名（10个字符以内）：\t");
		scanf("%s", stu.name);
		stu.name[Namelen - 1] = '\0';
		printf("性别（4个字符以内）：\t");
		scanf("%s", stu.Sex);
		stu.Sex[Sexlen - 1] = '\0';
		printf("年龄：\t\t");
		scanf("%d", &stu.age);
		printf("c语言成绩：\t");
		scanf("%d", &stu.cp);
		printf("英语成绩：\t");
		scanf("%d", &stu.en);
		printf("高数成绩：\t");
		scanf("%d", &stu.math);
		stu.avg = (stu.cp + stu.en + stu.math) / 3.0;
		printf("----------------------------------------\n");
		fwrite(&stu, sizeof(student), 1, fp);//写数据到文件
	}
}

//导入数据 
studentnode* importDate(FILE* fp)     //导入数据文件中的数据
{
	studentnode* head = NULL, * p, * tail = NULL;   //头结点，新节点，尾结点
	student stu;     //存储学生信息的临时变量 

	fread(&stu, sizeof(student), 1, fp);     //从数据文件读取一个学生信息 
	while (!feof(fp))     //如果文件没有结束，继续循环 
	{
		if (head == NULL)     //单链表的第一个结点的处理 
		{
			head = (studentnode*)malloc(sizeof(studentnode));     //分配动态内存空间给新的结点 
			head->stu = stu;
			head->next = NULL;
			tail = head;
		}
		else
		{

			p = (studentnode*)malloc(sizeof(studentnode));
			p->stu = stu;
			p->next = NULL;
			tail->next = p;
			tail = p;
		}
		fread(&stu, sizeof(student), 1, fp);     //从数据文件中读取下一条记录 
	}
	return head;    //返回单链表的表头指针 
}

//初始化系统数据
studentnode* initDate()
{
	FILE* fp;
	studentnode* stuhead;
	//如果第一次使用系统，打开文件不成功 
	if ((fp = fopen(FilePath, "r")) == NULL)
	{
		//可新建一个数据文件 
		createnewFile(FilePath);     //创建一个初始的数据文件 
		if ((fp = fopen(FilePath, "rb")) == NULL)      //如果新建的数据文件不成功 
		{
			printf("\n无法初始化数据，退出系统！\n");
			exit(1);    //退出程序
		}
		stuhead = importDate(fp);     //导入新建文件的数据 
	}
	else    //如果数据文件存在，直接导入数据 
		stuhead = importDate(fp);       //导入已有文件的数据 
	fclose(fp);     //关闭文件 
	return stuhead;     //返回存储数据的单链表表头 
}

//显示主菜单操作
void displayMenu7()
{
	while (1)
	{
		system("cls");
		printf("\n请选择你的操作：\n");
		printf("------------------------------------------------\n");
		printf("(1)显示学生信息\t");
		printf("(2)查询单个学生信息\n");
		printf("(3)修改学生信息\t");
		printf("(4)删除学生信息\n");
		printf("(5)增加学生信息\t");
		printf("(6)保存修改\n");
		printf("(7)平均分排序\t");
		printf("(0)退出程序\n");
		printf("------------------------------------------------\n");
		scanf("%d", &choice);
		printf("\n");
		if (choice < 0 || choice>7)
		{
			printf("请输入正确的操作\n");
			system("pause");      //暂停 
		}
		else
			return;
	}
}

//显示子菜单查询
void displayMenuFind()
{
	while (1)
	{
		system("cls");
		printf("\n请选择你的操作：\n");
		printf("------------------------------------------------\n");
		printf("(1)按学号查询信息\t");
		printf("(2)按名字查询信息\n\n");
		printf("------------------------------------------------\n");
		scanf("%d", &choice);
		printf("\n");
		if (choice < 0 || choice>2)
		{
			printf("请输入正确的操作\n");
			system("pause");
		}
		else
			return;
	}
}

//显示修改子菜单
void displayMenuModify()
{
	while (1)
	{
		system("cls");
		printf("\n请选择x修改操作：\n");
		printf("------------------------------------------------\n");
		printf("(1)修改学生年龄\t\t");
		printf("(2)修改学生《c语言》成绩\n");
		printf("(3)修改学生《英语》成绩\t");
		printf("(4)修改学生《高数》成绩\n\n");
		printf("------------------------------------------------\n");
		scanf("%d", &choice);
		printf("\n");
		if (choice < 0 || choice>4)
		{
			printf("请输入正确的操作\n");
			system("pause");
		}
		else
			return;
	}
}

//显示所有学生信息
void displayAll(studentnode* head)
{
	studentnode* p = head;

	system("cls");
	if (head == NULL)
	{
		printf("没有学生信息!\n");
		return;
	}
	else
	{
		printf("\n所有学生信息：\n============================================\n");
		printf("学号           姓名         性别   年龄   c语言  英语   高数   平均分\n");
		printf("---------------------------------------------\n");
		while (p != NULL)
		{
			printf("%-15s%-14s%-7s%-7d", p->stu.id, p->stu.name, p->stu.Sex, p->stu.age);
			printf("%-7d%-7d%-7d%4.1f\n", p->stu.cp, p->stu.en, p->stu.math, p->stu.avg);
			p = p->next;
		}
	}
	printf("---------------------------------------------\n");
}

//显示一个学生信息
void diaplayOne(studentnode* p)
{
	system("cls");
	if (p == NULL)
	{
		printf("\n你要找的学生不存在！\n");
		system("pause");
		return;
	}
	printf("\n查找到的学生的信息！\n==========================================\n");
	printf("学号           姓名         性别   年龄   c语言  英语   高数   平均分\n");
	printf("---------------------------------------------\n");
	printf("%-15s%-14s%-7s%-7d", p->stu.id, p->stu.name, p->stu.Sex, p->stu.age);
	printf("%-7d%-7d%-7d%4.1f\n", p->stu.cp, p->stu.en, p->stu.math, p->stu.avg);
	printf("---------------------------------------------\n");
}

//按姓名查找学生 
studentnode* findbyName(studentnode* head, char* name)
{
	studentnode* p;
	p = head->next;
	while (p != NULL && strcmp(p->stu.name, name) != 0)
	{
		p = p->next;
	}
	return p;
}

//按学号查找学生 
studentnode* findbyID(studentnode* head, char* id)
{
	studentnode* p;
	p = head;
	while (p != NULL && strcmp(p->stu.id, id) != 0)
	{
		p = p->next;
	}
	return p;
}

//修改学生信息 
void modify(studentnode* head)
{
	studentnode* p;      //临时变量，用于指向要修改的结点 
	char id[IDlen];      //临时变量，用于接收要输入的学号 

	system("cls");
	printf("\n请输入要修改的学生学号：");
	scanf("%s", id);
	id[IDlen - 1] = '\0';
	p = findbyID(head, id);
	if (p == NULL)
	{
		printf("需要修改的学生不存在！\n");
		system("pause");
		return;
	}

	displayMenuModify();   //显示修改子菜单 
	switch (choice)
	{
	case 1:
		printf("\n原学生的年龄：%d\n", p->stu.age);    //改年龄 
		printf("请输入新的年龄：");
		scanf("%d", &p->stu.age);
		break;
	case 2:
		printf("\n原学生的c语言成绩：%d\n", p->stu.cp);     //改C语言成绩 
		printf("请输入新的c语言成绩：");
		scanf("%d", &p->stu.cp);
		p->stu.avg = (p->stu.en + p->stu.math + p->stu.cp) / 3.0;
		break;
	case 3:
		printf("\n原学生的英语成绩：%d\n", p->stu.en);       //改英语成绩 
		printf("请输入新的英语成绩：");
		scanf("%d", &p->stu.en);
		p->stu.avg = (p->stu.en + p->stu.math + p->stu.cp) / 3.0;
		break;
	case 4:
		printf("\n原学生的高数成绩：%d\n", p->stu.math);      //改高数成绩 
		printf("请输入新的高数成绩：");
		scanf("%d", &p->stu.math);
		p->stu.avg = (p->stu.en + p->stu.math + p->stu.cp) / 3.0;
		break;
	}
	printf("\n修改完成!\n");
}

void deletestudent(studentnode* head)//删除学生信息 
{
	studentnode* p, * q;    //p定位删除结点，q定位删除结点前一个结点 
	char id[IDlen];

	system("cls");
	printf("请输入要删除的学号：");
	scanf("%s", id);
	p = findbyID(head, id);
	if (p == NULL)
	{
		printf("要删除的学生不存在！");
		system("pause");
		return;
	}
	q = p->next;
	p->stu = q->stu;
	p->next = q->next;
	free(q);
	printf("删除成功");
}

void add(studentnode* head)//添加学生信息
{
	student stu;
	studentnode* p;
	p = head;
	char cont = 'Y';//用于判断是否要继续添加
	int i = 0;
	while (p->next != NULL)
		p = p->next;
	while (cont == 'Y')
	{
		printf("请输入学生信息：\n");
		printf("----------------------------------------\n");
		printf("学号（12个字符以内）：\t");
		scanf("%s", stu.id);
		stu.id[IDlen - 1] = '\0';
		printf("姓名（10个字符以内）：\t");
		scanf("%s", stu.name);
		stu.name[Namelen - 1] = '\0';
		printf("性别（4个字符以内）：\t");
		scanf("%s", stu.Sex);
		stu.Sex[Sexlen - 1] = '\0';
		printf("年龄：\t");
		scanf("%d", &stu.age);
		printf("c语言成绩：\t");
		scanf("%d", &stu.cp);
		printf("英语成绩：\t");
		scanf("%d", &stu.en);
		printf("高数成绩：\t");
		scanf("%d", &stu.math);
		stu.avg = (stu.cp + stu.en + stu.math) / 3.0;
		printf("----------------------------------------\n");
		p->next = (studentnode*)malloc(sizeof(studentnode));
		p = p->next;
		p->stu = stu;
		p->next = NULL;
		i++;
		printf("\n是否继续添加？（y/n 小写输入）?");
		cont = getchar();
		if (cont == 'y')
			cont = cont - 32;    //转换成大写字母 
	}
	printf("\n添加学生完成，共添加了%d个学生。\n", i);
}

//保存数据到文件
void save(studentnode* head)
{
	studentnode* p;
	p = head;
	FILE* fp;

	if ((fp = fopen(FilePath, "w")) == NULL)
	{
		printf("\n创建文件错误，无法保存修改！\n");
		return;
	}
	while (p != NULL)
	{
		fwrite(&p->stu, sizeof(student), 1, fp);
		p = p->next;
	}
	fclose(fp);
	printf("\n保存成功！\n");
}

void sort(studentnode* head)
{
	studentnode* p, * c;
	int i, j, numper = 0;
	student L;
	int ch, swap = 0;
	c = head;
	while (c != NULL)
	{
		numper++;
		c = c->next;
	}
	system("cls");
	printf("==========================================================\n");
	printf("(1)升序\t（2）降序\n");
	printf("==========================================================\n");
	scanf("%d", &ch);
	for (i = 1; i <= numper; i++)
	{
		p = head;
		for (j = 1; j <= numper - i; j++)
		{
			if (p->stu.avg < p->next->stu.avg)
				swap = 1;
			if (swap != ch)//交换
			{
				L = p->stu;
				p->stu = p->next->stu;
				p->next->stu = L;
			}
			p = p->next;
		}
	}
	printf("排序后信息如下：\n");
	displayAll(head);
}