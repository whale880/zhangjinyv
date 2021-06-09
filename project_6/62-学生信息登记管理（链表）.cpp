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
		printf("\n�����������......\n");
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
		printf("\n�������%d��ѧ������Ϣ��\n", ++numm);
		p = (Node*)malloc(sizeof(Node));
		p->order = numm;
		printf("-----------------------------------------------\n");
		printf("ѧ�ţ�12���ַ����ڣ���\t");
		gets_s(p->stu.id);
		p->stu.id[IDLen - 1] = '\0';
		printf("������10���ַ����ڣ���\t");
		gets_s(p->stu.name);
		p->stu.name[NameLen - 1] = '\0';
		printf("�Ա�4���ַ����ڣ���\t");
		gets_s(p->stu.sex);
		p->stu.sex[SexLen - 1] = '\0';
		printf("���䣨��������\t\t");
		scanf_s("%d", &p->stu.age);
		printf("��C���ԡ��ɼ�����������\t");
		scanf_s("%d", &p->stu.score.cp);
		printf("��Ӣ��ɼ�����������\t");
		scanf_s("%d", &p->stu.score.en);
		printf("���������ɼ�����������\t");
		scanf_s("%d", &p->stu.score.math);
		getchar();
		p->stu.avg = (p->stu.score.cp + p->stu.score.en + p->stu.score.math) / 3.0;
		printf("--------------------------------------------\n");
		p->next = taill;
		p->prev = taill->prev;
		taill->prev->next = p;
		taill->prev = p;
		printf("\n��ѡ�������\n");
		printf("��0���������\t\t�����������������������\n");
		printf("---------------------------------------------\n");
		if (_getch() == '0')
			return;
	}
}

void SortStudent() {
	Node* m;          //��ȽϽڵ��ǰһ���ڵ�
	Node* p;                   //��߲μӱȽϵĽڵ�
	Node* q;               //�ұ߲μӱȽϵĽڵ�
	Node* n;               //�ұȽϽ��ĺ�һ���ڵ�

	int f;               //��С��־��0ǰ�ߴ�1���ߴ�
	int swap;         //�Ƿ񽻻���1������0������
	//���ֻ��һ���ڵ㣬���ò���
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
			//������������
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
				printf("�����š�");
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
				//���ڵ�p�Ƴ�
				m->next = p->next;
				p->next->prev = m;
				//�Ҳ���q�Ƴ�
				q->prev->next = n;
				n->prev = q->prev;
				//��q���뵽ԭ��p����λ��
				q->next = m->next;
				q->prev = m;
				m->next->prev = q;
				m->next = q;
				//��p���뵽ԭ��q����λ��
				p->next = n;
				p->prev = n->prev;
				n->prev->next = p;
				n->prev = p;
				//�ָ�p��qԭ����λ��
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

//���ѧ����Ϣ
void OutputStudent() {
	int i = 1;
	Node* p;
	if (9 == choicee) {
		printf("\nԭʼ�����ѧ����Ϣ��\n===================\n");
	}
	else {
		printf("\n������ѧ����Ϣ��\n===================\n");
	}
	printf("ѧ��\t����\t�Ա�\t����\tC����\tӢ��\t����\tƽ����\n");
	printf("---------------------------------------\n");

	//�����������ȫ����Ϣ
	p = headd->next;
	do {
		printf("%-15s%-14s%-7s%-7d%-7d%-7d%-7d%4.lf\n", p->stu.id, p->stu.name, p->stu.sex, p->stu.age, p->stu.score.cp, p->stu.score.en, p->stu.score.math, p->stu.avg);
		p = p->next;
	} while (p != taill);
	printf("------------------------------------------------\n");
}

void GetOrderDir() {
	printf("��ѡ������ʽ��\n");
	printf("===========================================\n");
	printf("��1������\t��2������\t��0��������һ��\n");
	printf("===========================================\n");
	scanf_s("%d", &dir);
}

void DisplayMenu() {
	printf("��ѡ��ʲô����\n");
	printf("===========================================\n");
	printf("��1��ѧ��\t��2������\t��3���Ա�\t��4������\n");
	printf("��5��C���Գɼ�\t��6��Ӣ��ɼ�\t��7�������ɼ�\t��8��ƽ���ɼ�\n");
	printf("��9����ʾԭʼ����\t\t��0���˳�����\n");
	printf("===========================================\n");
	scanf_s("%d", &choicee);
}