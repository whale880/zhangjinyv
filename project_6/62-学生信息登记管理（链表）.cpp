#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <WinBase.h>

#define IDLen 13
#define NameLen 11
#define SexLen 5

typedef struct {
	int cp;
	int en;
	int math;
}Score;

typedef struct {
	char id[IDLen];
	char name[NameLen];
	char sex[SexLen];
	int age;
	Score score;
	double avg;
}Student;

typedef struct theNode {
	theNode* prev;
	int order;
	Student stu;
	theNode* next;
}Node;

extern Node* headd;
extern Node* taill;
extern int dir;
extern int choicee;
extern int numm;

void InputStudent();
void DisplayMenu();
void GetOrderDir();
void SortStudent();
static void OutputStudent();


Node* headd = NULL;
Node* taill = NULL;
int dir = 0;
int choicee = 0;
int numm = 0;

void shizhan6jibenxiangmu2() {
	InputStudent();
	system("cls");
	while (1) {
		DisplayMenu();
		system("cls");
		if (0 == choicee) {
			exit(0);
		}
		else if (9 == choicee) {
			dir = 1;
		}
		else {
			GetOrderDir();
			system("cls");
		}
		SortStudent();
		OutputStudent();
		printf("\n按任意键继续......\n");
		_getch();
		system("cls");
	}
}

void InputStudent() {
	Node* p = NULL;
	headd = (Node*)malloc(sizeof(Node));
	taill = (Node*)malloc(sizeof(Node));
	headd->prev = NULL;
	headd->next = taill;
	taill->prev = headd;
	taill->next = NULL;
	while (1) {
		printf("\n请输入第%d个学生的信息：\n", ++numm);
		p = (Node*)malloc(sizeof(Node));
		p->order = numm;
		printf("-----------------------------------------------\n");
		printf("学号（12个字符以内）：\t");
		gets_s(p->stu.id);
		p->stu.id[IDLen - 1] = '\0';
		printf("姓名（10个字符以内）：\t");
		gets_s(p->stu.name);
		p->stu.name[NameLen - 1] = '\0';
		printf("性别（4个字符以内）：\t");
		gets_s(p->stu.sex);
		p->stu.sex[SexLen - 1] = '\0';
		printf("年龄（整数）：\t\t");
		scanf_s("%d", &p->stu.age);
		printf("《C语言》成绩（整数）：\t");
		scanf_s("%d", &p->stu.score.cp);
		printf("《英语》成绩（整数）：\t");
		scanf_s("%d", &p->stu.score.en);
		printf("《高数》成绩（整数）：\t");
		scanf_s("%d", &p->stu.score.math);
		getchar();
		p->stu.avg = (p->stu.score.cp + p->stu.score.en + p->stu.score.math) / 3.0;
		printf("--------------------------------------------\n");
		p->next = taill;
		p->prev = taill->prev;
		taill->prev->next = p;
		taill->prev = p;
		printf("\n请选择操作：\n");
		printf("（0）输入完成\t\t（其他任意键）：继续输入\n");
		printf("---------------------------------------------\n");
		if (_getch() == '0')
			return;
	}
}

void SortStudent() {
	Node* m;          //左比较节点的前一个节点
	Node* p;                   //左边参加比较的节点
	Node* q;               //右边参加比较的节点
	Node* n;               //右比较结点的后一个节点

	int f;               //大小标志：0前者大，1后者大
	int swap;         //是否交换：1交换，0不交换
	//如果只有一个节点，不用操作
	if (1 == numm) {
		return;
	}
	m = headd;
	p = m->next;
	while (p->next != taill) {
		q = p->next;
		n = q->next;
		while (q != taill) {
			f = 0;
			//交换相邻两个
			switch (choicee) {
			case 1:
				if (strcmp(p->stu.id, q->stu.id) < 0) {
					f = 1;
					break;
				}
			case 2:
				if (strcmp(p->stu.name, q->stu.name) < 0) {
					f = 1;
					break;
				}
			case 3:
				if (strcmp(p->stu.sex, q->stu.sex) < 0) {
					f = 1;
					break;
				}
			case 4:
				if (p->stu.age < q->stu.age) {
					f = 1;
					break;
			case 5:
				if (p->stu.score.cp < q->stu.score.cp) {
					f = 1;
					break;
				}
			case 6:
				if (p->stu.score.en < q->stu.score.en) {
					f = 1;
					break;
				}
			case 7:
				if (p->stu.score.math < q->stu.score.math) {
					f = 1;
					break;
				}
			case 8:
				if (p->stu.avg < q->stu.avg) {
					f = 1;
					break;
				}
			case 9:
				if (p->order < q->order) {
					f = 1;
					break;
				}
			default:
				printf("错误编号。");
				break;
				}
			}
			swap = 0;
			if (1 == f && 2 == dir) {
				swap = 1;
			}
			if (0 == f && 1 == dir) {
				swap = 1;
			}
			if (1 == swap) {
				//左侧节点p移出
				m->next = p->next;
				p->next->prev = m;
				//右侧结点q移出
				q->prev->next = n;
				n->prev = q->prev;
				//将q插入到原来p所在位置
				q->next = m->next;
				q->prev = m;
				m->next->prev = q;
				m->next = q;
				//将p插入到原来q所在位置
				p->next = n;
				p->prev = n->prev;
				n->prev->next = p;
				n->prev = p;
				//恢复p、q原来的位置
				p = m->next;
				q = n->prev;
			}
			q = n;
			n = q->next;
			m = p;
			p = p->next;
		}
	}
}

//输出学生信息
void OutputStudent() {
	int i = 1;
	Node* p;
	if (9 == choicee) {
		printf("\n原始输入的学生信息：\n===================\n");
	}
	else {
		printf("\n排序后的学生信息：\n===================\n");
	}
	printf("学号\t姓名\t性别\t年龄\tC语言\t英语\t高数\t平均分\n");
	printf("---------------------------------------\n");

	//遍历链表，输出全部信息
	p = headd->next;
	do {
		printf("%-15s%-14s%-7s%-7d%-7d%-7d%-7d%4.lf\n", p->stu.id, p->stu.name, p->stu.sex, p->stu.age, p->stu.score.cp, p->stu.score.en, p->stu.score.math, p->stu.avg);
		p = p->next;
	} while (p != taill);
	printf("------------------------------------------------\n");
}

void GetOrderDir() {
	printf("请选择排序方式：\n");
	printf("===========================================\n");
	printf("（1）升序\t（2）降序\t（0）返回上一级\n");
	printf("===========================================\n");
	scanf_s("%d", &dir);
}

void DisplayMenu() {
	printf("请选择按什么排序：\n");
	printf("===========================================\n");
	printf("（1）学号\t（2）姓名\t（3）性别\t（4）年龄\n");
	printf("（5）C语言成绩\t（6）英语成绩\t（7）高数成绩\t（8）平均成绩\n");
	printf("（9）显示原始数据\t\t（0）退出程序\n");
	printf("===========================================\n");
	scanf_s("%d", &choicee);
}