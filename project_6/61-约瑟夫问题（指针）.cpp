#include"practice6.h"

#define LEN 21   //��������
#define OVER "exit"

typedef struct ps person;
struct ps  //�洢��Ϸ��Ա�Ľṹ��
{
	char name[LEN];  //�洢����
	int pwd;   //�洢����
	struct ps* next;  //�ṹ��ָ�룬ָ����һ����Ϸ��Ա
};

person* head = NULL;  //ָ���ڵ��ָ��
person* tail = NULL;   //ָ��ĩ�ڵ��ָ��
char choice;   //�û�ѡ��Ĳ˵���

void inputpersons();   //�����������ʼ������
void showmenu();    //��ʾ�����˵�
void displaylink();    //��ʾ������Ϣ
void resetpwd();   //��������
void countandquit();    //��ʼԼɪ����Ϸ

int num = 0;    //��¼���������

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
			displaylink();  //��ʾ������Ϣ
			_getch();
			break;
		case'2':
			resetpwd();   //��������
			_getch();
			break;
		case'3':
			countandquit();   //��ʼԼɪ����Ϸ
			_getch();
			break;
		case'0':
			exit(0);
		}
	}
}

//�����������ʼ������
void inputpersons()
{
	char name[LEN];
	person* p;   //�����ӵ���
	head = tail;   //һ��ʼ����β����NULL
	while (1)
	{
		printf("�������%d���˵���Ϣ������%s������\n", num + 1, OVER);
		printf("������<=%d���ַ���:", LEN - 1);
		scanf("%s", name);
		name[LEN - 1] = '\0';
		if (strcmp(name, OVER) == 0)
			return;
		p = (person*)malloc(sizeof(person));  //����ָ����С���ڴ�ռ��Ҳ�����ʼ��Ҫ��
		strcpy(p->name, name);

		//��������k
		printf("���루��������");
		scanf("%d", &p->pwd);
		p->next = head;  //��β�������γ�ѭ��

		//��������
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
		num++;  //��������������Ժ󣬼������ż�1
		printf("\n");
	}
}

//��ʾ�����˵�
void showmenu()
{
	while (1)
	{
		printf("\n\n��ѡ�������");
		printf("\n============================");
		printf("\n(1)��ʾ��Ϣ");
		printf("\n(2)��������ÿ���˵�����");
		printf("\n(3)��ʼ����N�˳�����Ϸ��");
		printf("\n(0)�˳�����");
		printf("\n============================");
		choice = _getche();
		if ('0' == choice)
			exit(0);
		else if (choice - '0' >= 1 && (choice - '0') <= 3)
			return;
	}
}

//��ʾ������Ϣ
void displaylink()
{
	int i = 0;
	person* p = head;  //��ͷ��㿪ʼ
	//���û�У�����ֹ
	if (NULL == p)
		return;
	printf("\n\n��ǰ������Ϣ���£�");
	printf("\n=================================");
	//�����ͷ���
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
	person* p = head;//��ͷ�ڵ㿪ʼ
	//���û�У�����ֹ
	if (NULL == p)
		return;
	printf("\n\n����������ÿ���˵����룺");
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
	int i, n, pwd;   //���ڼ������ͱ��浱ǰ����
	//�ȸ���һ������
	person* p, * c, * q;  //�ֱ�ָ����ʱ�ڵ㡢������ĵ�ǰ�ڵ㡢��ǰ�ڵ��ǰ�ڵ�
	person* head2 = NULL, * tail2 = NULL;   //�ֱ�ָ���������ͷ��β���
	c = head;
	if (NULL == head)
		return;
	p = (person*)malloc(sizeof(person));
	strcpy_s(p->name, c->name);
	p->pwd = c->pwd;
	p->next = p;
	head2 = tail2 = p;  //��һ����㣬��β��һ��
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

	//��ʼ��N�˳�
	printf("\n\n��Ϸ��������");
	printf("\n=======================");
	i = 0;
	c = head2;  //����ǰָ�루����ѭ����ָ���׽��
	q = head2;  //q��¼��ǰ����ǰһ�����
	pwd = c->pwd;   // ��¼�׽���pwd
	while (c->next != c) {
		n = 1;
		while (n < pwd) {
			q = c;
			c = c->next;
			n++;
		}
		//��ǰָ��c��ָ��Ӧ���˳�
		q->next = c->next;
		printf("\n��%2d���˳��ߣ�%s", ++i, c->name);
		pwd = c->pwd;    //�˳��ߵ�������Ϊ��һ���˳��ߵ�����
		free(c);
		c = q->next;
	}
	printf("\n��%2d���˳��ߣ�%s", ++i, c->name);
	free(c);
	printf("\n=======================");
}