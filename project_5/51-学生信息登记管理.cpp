#include"practice5.h"
#define N 3     //ѧ������
#define IDLen 20   //ѧ��
#define NameLen 10  //����
#define SexLen 4    //�Ա�
typedef struct Sco
{
	int cp;    //C���Գɼ�
	int en;    //Ӣ��  
	int math;  //�����ɼ�
}Score;
typedef struct Stu
{
	char id[IDLen + 1];   //ѧ��
	char name[NameLen + 1];  //����
	char sex[SexLen + 1];  //�Ա�
	int age;               //����
	Score score;            //�ɼ�
	double avg;				//ƽ���ɼ�
}Student;
//��������
void Line();				//����
void InputStudent5();      //����ѧ����Ϣ
void DisplayMenu51(); //�˵�
void GetOrderDir5();				//����˵�
void SortStudent5();				//���������ð�ݣ�
void OutputStudent5(Student s[]);	//���ѧ����Ϣ
//ȫ�ֱ���
Student stu[N];  //ԭʼ�����ѧ����Ϣ
Student sorted[N];	//���������ѧ����Ϣ
char chioce = 0;    //���˵��е�ѡ��
char dir = 0;		//������ѡ�1����2��

//������
void Sstudent()
{
	InputStudent5();
	while (1)
	{
		DisplayMenu51();
		if ('0' == chioce)
		{
			printf("\nллʹ�ã��ټ�\n");
			break;
		}
		else if ('9' == chioce)
		{
			//dir = 1;
			OutputStudent5(stu);
			//_getche();
		}
		else
		{
			GetOrderDir5();
			//if ('0' == dir)
				//continue;//������һ��
			SortStudent5();
			OutputStudent5(sorted);
		}
	}
	_getche();
}

void Line()//������
{
	printf("\n----------------------------------------------------------------------------\n");
}
void InputStudent5()            //����ѧ����Ϣ
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		fflush(stdin);
		printf("������%d/%d��ѧ������Ϣ��\n", i + 1, N);
		Line();
		printf("����ѧ�ţ�12�������ַ�����");
		scanf_s("%s", stu[i].id, IDLen);
		stu[i].id[IDLen] = '\0';		//ǿ�ƽ�������
		fflush(stdin);
		//getchar();
		printf("����������������%d�ַ�����", NameLen);
		scanf_s("%s", stu[i].name, NameLen);
		//gets_s(stu[i].name);
		stu[i].name[NameLen] = '\0';		//ǿ�ƽ�������
		printf("�����Ա𣨲�����2�ַ�����");
		scanf_s("%s", stu[i].sex, SexLen);
		printf("�������䣨��������");
		scanf_s("%d", &stu[i].age);

		//printf("����ɼ�����������\n");
		printf("����C���Գɼ���");
		scanf_s("%d", &stu[i].score.cp);
		printf("����Ӣ��ɼ���");
		scanf_s("%d", &stu[i].score.en);
		printf("��������ɼ���");
		scanf_s("%d", &stu[i].score.math);
		//ƽ����
		stu[i].avg = ((double)(stu[i].score.cp + stu[i].score.en + stu[i].score.math)) / 3.0;
		Line();
	}
	//���ƽṹ������(�����ֳ��Ĳ�����
	for (int i = 0; i < N; i++)
		sorted[i] = stu[i];
}

void DisplayMenu51()    //�˵�
{
	while (1)
	{
		printf("\n��ѡ����Ĳ����������ֶλ���ʾԭʼ��Ϣ���˳�):\n");
		Line();
		printf("(1)ѧ��\t(2)����\t(3)�Ա�\t(4)����\n");
		printf("(5)c����\t(6)Ӣ��\t(7)����\t(8)ƽ����\n");
		printf("(9)��ʾԭʼ�������Ϣ\t(0)�˳�����\n");
		Line();
		chioce = _getche();
		//scanf_s("%c", &chioce,1);
		if (chioce - '0' < 0 || chioce - '0' > 9)
			printf("\n����ѡ���������������!\n");
		else
			return;
	}
}
void GetOrderDir5()				//����˵�
{
	while (1)
	{
		printf("\n��ѡ�����������򷵻�:\n");
		Line();
		printf("(1)����\t(2)����\t(0)���ز˵�\n");
		Line();
		fflush(stdin);
		dir = _getche();
		if ((dir - '0') < 0 || (dir - '0') > 2)
			printf("\n����ѡ���������������!\n");
		else
			return;
	}
}
void SortStudent5()				//���������ð�ݣ�
{
	int i = 0, j = 0, f;//f���ڱ��
	Student s;
	//��0-N-1����
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			f = 0;//f=1,��ʾҪ����
			switch (chioce)
			{
			case '1'://�Ƚ�ѧ��
				if (strcmp(sorted[j].id, sorted[j + 1].id) > 0)
					f = 1;
				break;
			case '2'://�Ƚ�����
				if (strcmp(sorted[j].name, sorted[j + 1].name) > 0)
					f = 1;
				break;
			case '3'://�Ƚ��Ա�
				if (strcmp(sorted[j].sex, sorted[j + 1].sex) > 0)
					f = 1;
				break;
			case '4'://�Ƚ�����
				if (sorted[j].age > sorted[j + 1].age)
					f = 1;
			case '5'://�Ƚ�C���Գɼ�
				if (sorted[j].score.cp > sorted[j + 1].score.cp)
					f = 1;
				break;
			case '6'://�Ƚ�Ӣ��ɼ�
				if (sorted[j].score.en > sorted[j + 1].score.en)
					f = 1;
				break;
			case '7'://�Ƚϸ���
				if (sorted[j].score.math > sorted[j + 1].score.math)
					f = 1;
				break;
			case '8'://�Ƚ�ƽ����
				if (sorted[j].avg > sorted[j + 1].avg)
					f = 1;
				break;
			default:
				printf("δ֪����");
				break;
			}
			if (1 == f)
			{
				s = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = s;
			}
		}
	}
}
void OutputStudent5(Student s[])	//���ѧ����Ϣ
{
	printf("\nѧ����Ϣ���£�\n\n================================\n");
	printf("%-15s%-14s%-7s%-7s%-7s%-7s%-7s%-7s\n", "ѧ��", "����", "�Ա�", "����", "C����", "Ӣ��", "����", "ƽ����");
	Line();
	if ('1' == dir)//����
	{
		for (int i = 0; i < N; i++)
		{
			printf("%-15s%-14s%-7s%-7d", s[i].id, s[i].name, s[i].sex, s[i].age);
			printf("%-7d%-7d%-7d%-7.2f\n", s[i].score.cp, s[i].score.en, s[i].score.math, s[i].avg);
		}
	}
	else    //����
	{
		for (int i = N - 1; i >= 0; i--)
		{
			printf("%-15s%-14s%-7s%-7d", s[i].id, s[i].name, s[i].sex, s[i].age);
			printf("%-7d%-7d%-7d%-7.2f\n", s[i].score.cp, s[i].score.en, s[i].score.math, s[i].avg);
		}
	}
	dir = 0;//ÿ���������������Ϊ0
	Line();
}