#include"practice7.h"

#define IDlen 13    //ID�ֶγ��� 
#define Namelen 11     //�����ֶγ��� 
#define Sexlen 5     //�Ա��ֶγ��� 
#define FilePath "student2.dat"    //�����ļ��ĵ�ַ 
//�洢ѧ����Ϣ�Ľṹ�� 
typedef struct stu
{

	char id[IDlen];   //ѧ�� 
	char name[Namelen];     //���� 
	char Sex[Sexlen];    //�Ա� 
	int age;     //���� 
	int cp;     //C���� 
	int en;     //Ӣ�� 
	int math;     //���� 
	double avg;       //ƽ���� 
}student;
//�洢ѧ����Ϣ������������ 
typedef struct Node
{
	student stu;  //������ 
	struct Node* next;    //ָ���� 
}studentnode;
int choice = 0;   //�˵�ѡ��ֵ 

studentnode* importDate(FILE* fp);     //���������ļ��е����� 
studentnode* initDate();       //��ʼ������ϵͳ���� 
studentnode* findbyName(studentnode* head, char* name);      //����������ѧ�� 
studentnode* findbyID(studentnode* head, char* id);       //��ѧ�Ų���ѧ�� 
void createnewFile(char* path);    //������ʼ�����ļ� 
void displayMenu7();       //��ʾ�������˵� 
void displayMenuFind();     //��ʾ�����Ӳ˵� 
void displayMenuModify();     //��ʾ�޸��Ӳ˵� 
void displayAll(studentnode* head);     //��ʾ����ѧ����Ϣ    
void diaplayOne(studentnode* p);     //��ʾһ��ѧ����Ϣ 
void modify(studentnode* head);       //�޸�ѧ����Ϣ 
void deletestudent(studentnode* head);       //ɾ��ѧ����Ϣ 
void add(studentnode* head);        //����һ��ѧ�� 
void save(studentnode* head);         //�������ݵ��ļ��� 
void sort(studentnode* head);        //��ѧ��ƽ��������    *��չ��Ŀ


//���˵� 
void Studentinformation()
{
	studentnode* stuhead, * p = NULL;  //�洢ѧ����Ϣ�ĵ����� 
	char id[IDlen];   //��ʱ���������ڽ��������ѧ�� 
	char name[Namelen];       //��ʱ���������ڽ������������ 
	stuhead = initDate();     //��ʼ��ϵͳ���ݣ�����ѧ����Ϣ

	while (1)
	{
		displayMenu7();      //��ʾ�������˵� 
		switch (choice)
		{
		case 1:
			displayAll(stuhead);      //��ʾ����ѧ����Ϣ 
			system("pause");
			break;
		case 2:
			displayMenuFind();        //��ʾ�����Ӳ˵� 
			switch (choice)
			{
			case 1:
				printf("\n������Ҫ����ѧ����ѧ�ţ�");
				scanf("%s", id);
				p = findbyID(stuhead, id);     //��ѧ�ſ�ʼ����
				break;
			case 2:
				printf("\n��������Ҫ����ѧ��������");
				scanf("%s", name);
				p = findbyName(stuhead, name);      //��������ʼ���� 
				break;
			}
			diaplayOne(p);    //��ʾ�ҵ���ѧ����Ϣ 
			break;
		case 3:
			modify(stuhead);     //�޸�ѧ����Ϣ
			system("pause");
			break;
		case 4:
			deletestudent(stuhead);     //ɾ��ѧ����Ϣ
			system("pause");
			break;
		case 5:
			add(stuhead);    //���ѧ����Ϣ
			system("pause");
			break;
		case 6:
			save(stuhead);     //�������ݵ��ļ�
			system("pause");
			break;
		case 7:
			sort(stuhead);
			system("pause");
			break;
		case 0:
			save(stuhead);      //�������ݵ��ļ��� 
			system("pause");
			return;
		}
	}
}

//�����µ������ļ� 
void createnewFile(const char* path)
{
	FILE* fp;    //�����ļ�ָ�� 
	student stu;      //��ʱ���������ڽ���ѧ����Ϣ 
	int i = 1;         //��ʱ����������ͳ��ѧ������ 

	if ((fp = fopen(path, "w")) == NULL)     //��д�ķ�ʽ�������ļ� 
	{
		printf("\n�޷������µ��ļ���\n");
		return;
	}
	printf("\n������ѧ����Ϣ������ѧ��Ϊ#ʱ���������룩��\n");
	while (1)
	{
		printf("�������%d��ѧ������Ϣ��\n", i++);
		printf("----------------------------------------\n");
		printf("ѧ�ţ�12���ַ����ڣ���\t");
		scanf("%s", stu.id);
		stu.id[IDlen - 1] = '\0';      //ǿ�ӽ���������ֹ���� 
		if (strcmp(stu.id, "#") == 0)
		{
			printf("������Ϣ������\n");
			fclose(fp);
			return;
		}
		printf("������10���ַ����ڣ���\t");
		scanf("%s", stu.name);
		stu.name[Namelen - 1] = '\0';
		printf("�Ա�4���ַ����ڣ���\t");
		scanf("%s", stu.Sex);
		stu.Sex[Sexlen - 1] = '\0';
		printf("���䣺\t\t");
		scanf("%d", &stu.age);
		printf("c���Գɼ���\t");
		scanf("%d", &stu.cp);
		printf("Ӣ��ɼ���\t");
		scanf("%d", &stu.en);
		printf("�����ɼ���\t");
		scanf("%d", &stu.math);
		stu.avg = (stu.cp + stu.en + stu.math) / 3.0;
		printf("----------------------------------------\n");
		fwrite(&stu, sizeof(student), 1, fp);//д���ݵ��ļ�
	}
}

//�������� 
studentnode* importDate(FILE* fp)     //���������ļ��е�����
{
	studentnode* head = NULL, * p, * tail = NULL;   //ͷ��㣬�½ڵ㣬β���
	student stu;     //�洢ѧ����Ϣ����ʱ���� 

	fread(&stu, sizeof(student), 1, fp);     //�������ļ���ȡһ��ѧ����Ϣ 
	while (!feof(fp))     //����ļ�û�н���������ѭ�� 
	{
		if (head == NULL)     //������ĵ�һ�����Ĵ��� 
		{
			head = (studentnode*)malloc(sizeof(studentnode));     //���䶯̬�ڴ�ռ���µĽ�� 
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
		fread(&stu, sizeof(student), 1, fp);     //�������ļ��ж�ȡ��һ����¼ 
	}
	return head;    //���ص�����ı�ͷָ�� 
}

//��ʼ��ϵͳ����
studentnode* initDate()
{
	FILE* fp;
	studentnode* stuhead;
	//�����һ��ʹ��ϵͳ�����ļ����ɹ� 
	if ((fp = fopen(FilePath, "r")) == NULL)
	{
		//���½�һ�������ļ� 
		createnewFile(FilePath);     //����һ����ʼ�������ļ� 
		if ((fp = fopen(FilePath, "rb")) == NULL)      //����½��������ļ����ɹ� 
		{
			printf("\n�޷���ʼ�����ݣ��˳�ϵͳ��\n");
			exit(1);    //�˳�����
		}
		stuhead = importDate(fp);     //�����½��ļ������� 
	}
	else    //��������ļ����ڣ�ֱ�ӵ������� 
		stuhead = importDate(fp);       //���������ļ������� 
	fclose(fp);     //�ر��ļ� 
	return stuhead;     //���ش洢���ݵĵ������ͷ 
}

//��ʾ���˵�����
void displayMenu7()
{
	while (1)
	{
		system("cls");
		printf("\n��ѡ����Ĳ�����\n");
		printf("------------------------------------------------\n");
		printf("(1)��ʾѧ����Ϣ\t");
		printf("(2)��ѯ����ѧ����Ϣ\n");
		printf("(3)�޸�ѧ����Ϣ\t");
		printf("(4)ɾ��ѧ����Ϣ\n");
		printf("(5)����ѧ����Ϣ\t");
		printf("(6)�����޸�\n");
		printf("(7)ƽ��������\t");
		printf("(0)�˳�����\n");
		printf("------------------------------------------------\n");
		scanf("%d", &choice);
		printf("\n");
		if (choice < 0 || choice>7)
		{
			printf("��������ȷ�Ĳ���\n");
			system("pause");      //��ͣ 
		}
		else
			return;
	}
}

//��ʾ�Ӳ˵���ѯ
void displayMenuFind()
{
	while (1)
	{
		system("cls");
		printf("\n��ѡ����Ĳ�����\n");
		printf("------------------------------------------------\n");
		printf("(1)��ѧ�Ų�ѯ��Ϣ\t");
		printf("(2)�����ֲ�ѯ��Ϣ\n\n");
		printf("------------------------------------------------\n");
		scanf("%d", &choice);
		printf("\n");
		if (choice < 0 || choice>2)
		{
			printf("��������ȷ�Ĳ���\n");
			system("pause");
		}
		else
			return;
	}
}

//��ʾ�޸��Ӳ˵�
void displayMenuModify()
{
	while (1)
	{
		system("cls");
		printf("\n��ѡ��x�޸Ĳ�����\n");
		printf("------------------------------------------------\n");
		printf("(1)�޸�ѧ������\t\t");
		printf("(2)�޸�ѧ����c���ԡ��ɼ�\n");
		printf("(3)�޸�ѧ����Ӣ��ɼ�\t");
		printf("(4)�޸�ѧ�����������ɼ�\n\n");
		printf("------------------------------------------------\n");
		scanf("%d", &choice);
		printf("\n");
		if (choice < 0 || choice>4)
		{
			printf("��������ȷ�Ĳ���\n");
			system("pause");
		}
		else
			return;
	}
}

//��ʾ����ѧ����Ϣ
void displayAll(studentnode* head)
{
	studentnode* p = head;

	system("cls");
	if (head == NULL)
	{
		printf("û��ѧ����Ϣ!\n");
		return;
	}
	else
	{
		printf("\n����ѧ����Ϣ��\n============================================\n");
		printf("ѧ��           ����         �Ա�   ����   c����  Ӣ��   ����   ƽ����\n");
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

//��ʾһ��ѧ����Ϣ
void diaplayOne(studentnode* p)
{
	system("cls");
	if (p == NULL)
	{
		printf("\n��Ҫ�ҵ�ѧ�������ڣ�\n");
		system("pause");
		return;
	}
	printf("\n���ҵ���ѧ������Ϣ��\n==========================================\n");
	printf("ѧ��           ����         �Ա�   ����   c����  Ӣ��   ����   ƽ����\n");
	printf("---------------------------------------------\n");
	printf("%-15s%-14s%-7s%-7d", p->stu.id, p->stu.name, p->stu.Sex, p->stu.age);
	printf("%-7d%-7d%-7d%4.1f\n", p->stu.cp, p->stu.en, p->stu.math, p->stu.avg);
	printf("---------------------------------------------\n");
}

//����������ѧ�� 
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

//��ѧ�Ų���ѧ�� 
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

//�޸�ѧ����Ϣ 
void modify(studentnode* head)
{
	studentnode* p;      //��ʱ����������ָ��Ҫ�޸ĵĽ�� 
	char id[IDlen];      //��ʱ���������ڽ���Ҫ�����ѧ�� 

	system("cls");
	printf("\n������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%s", id);
	id[IDlen - 1] = '\0';
	p = findbyID(head, id);
	if (p == NULL)
	{
		printf("��Ҫ�޸ĵ�ѧ�������ڣ�\n");
		system("pause");
		return;
	}

	displayMenuModify();   //��ʾ�޸��Ӳ˵� 
	switch (choice)
	{
	case 1:
		printf("\nԭѧ�������䣺%d\n", p->stu.age);    //������ 
		printf("�������µ����䣺");
		scanf("%d", &p->stu.age);
		break;
	case 2:
		printf("\nԭѧ����c���Գɼ���%d\n", p->stu.cp);     //��C���Գɼ� 
		printf("�������µ�c���Գɼ���");
		scanf("%d", &p->stu.cp);
		p->stu.avg = (p->stu.en + p->stu.math + p->stu.cp) / 3.0;
		break;
	case 3:
		printf("\nԭѧ����Ӣ��ɼ���%d\n", p->stu.en);       //��Ӣ��ɼ� 
		printf("�������µ�Ӣ��ɼ���");
		scanf("%d", &p->stu.en);
		p->stu.avg = (p->stu.en + p->stu.math + p->stu.cp) / 3.0;
		break;
	case 4:
		printf("\nԭѧ���ĸ����ɼ���%d\n", p->stu.math);      //�ĸ����ɼ� 
		printf("�������µĸ����ɼ���");
		scanf("%d", &p->stu.math);
		p->stu.avg = (p->stu.en + p->stu.math + p->stu.cp) / 3.0;
		break;
	}
	printf("\n�޸����!\n");
}

void deletestudent(studentnode* head)//ɾ��ѧ����Ϣ 
{
	studentnode* p, * q;    //p��λɾ����㣬q��λɾ�����ǰһ����� 
	char id[IDlen];

	system("cls");
	printf("������Ҫɾ����ѧ�ţ�");
	scanf("%s", id);
	p = findbyID(head, id);
	if (p == NULL)
	{
		printf("Ҫɾ����ѧ�������ڣ�");
		system("pause");
		return;
	}
	q = p->next;
	p->stu = q->stu;
	p->next = q->next;
	free(q);
	printf("ɾ���ɹ�");
}

void add(studentnode* head)//���ѧ����Ϣ
{
	student stu;
	studentnode* p;
	p = head;
	char cont = 'Y';//�����ж��Ƿ�Ҫ�������
	int i = 0;
	while (p->next != NULL)
		p = p->next;
	while (cont == 'Y')
	{
		printf("������ѧ����Ϣ��\n");
		printf("----------------------------------------\n");
		printf("ѧ�ţ�12���ַ����ڣ���\t");
		scanf("%s", stu.id);
		stu.id[IDlen - 1] = '\0';
		printf("������10���ַ����ڣ���\t");
		scanf("%s", stu.name);
		stu.name[Namelen - 1] = '\0';
		printf("�Ա�4���ַ����ڣ���\t");
		scanf("%s", stu.Sex);
		stu.Sex[Sexlen - 1] = '\0';
		printf("���䣺\t");
		scanf("%d", &stu.age);
		printf("c���Գɼ���\t");
		scanf("%d", &stu.cp);
		printf("Ӣ��ɼ���\t");
		scanf("%d", &stu.en);
		printf("�����ɼ���\t");
		scanf("%d", &stu.math);
		stu.avg = (stu.cp + stu.en + stu.math) / 3.0;
		printf("----------------------------------------\n");
		p->next = (studentnode*)malloc(sizeof(studentnode));
		p = p->next;
		p->stu = stu;
		p->next = NULL;
		i++;
		printf("\n�Ƿ������ӣ���y/n Сд���룩?");
		cont = getchar();
		if (cont == 'y')
			cont = cont - 32;    //ת���ɴ�д��ĸ 
	}
	printf("\n���ѧ����ɣ��������%d��ѧ����\n", i);
}

//�������ݵ��ļ�
void save(studentnode* head)
{
	studentnode* p;
	p = head;
	FILE* fp;

	if ((fp = fopen(FilePath, "w")) == NULL)
	{
		printf("\n�����ļ������޷������޸ģ�\n");
		return;
	}
	while (p != NULL)
	{
		fwrite(&p->stu, sizeof(student), 1, fp);
		p = p->next;
	}
	fclose(fp);
	printf("\n����ɹ���\n");
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
	printf("(1)����\t��2������\n");
	printf("==========================================================\n");
	scanf("%d", &ch);
	for (i = 1; i <= numper; i++)
	{
		p = head;
		for (j = 1; j <= numper - i; j++)
		{
			if (p->stu.avg < p->next->stu.avg)
				swap = 1;
			if (swap != ch)//����
			{
				L = p->stu;
				p->stu = p->next->stu;
				p->next->stu = L;
			}
			p = p->next;
		}
	}
	printf("�������Ϣ���£�\n");
	displayAll(head);
}