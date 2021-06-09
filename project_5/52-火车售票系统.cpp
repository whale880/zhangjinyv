#include"practice5.h"

#ifndef _TICKET_H
#define _TICKET_H
#include<stdio.h>
#include<stdlib.h>//����gets_s
#include<string.h>//����strcmp����
#include<time.h>
#include<conio.h>//����system("cls")����
#define STATION_NUM 100//��վ��
#define TICKET_NUM 1000//��Ʊ��
#define STR_LEN 10//�ַ�����ĳ���
typedef struct
{
	int stationId;        //��վ��
	char from[STR_LEN];           //��Ʊ���
	char to[STR_LEN];          //��Ʊ�յ�
	int money;          //Ʊ��
	int numbers;		//Ʊ��
}StationInfo;			//��վƱ����Ϣ

typedef struct
{
	StationInfo station[STATION_NUM];		//�ṹ������
	int count;			//������
} Station;

typedef struct {
	int stationId;			//��վ��
	int seatId;			//��λ�ţ���Ʊ�����
	int ticketId;			//��Ʊ���
	char trainId[STR_LEN];			//�𳵳���
	char date[STR_LEN];			//��������
	char time[STR_LEN];   //����ʱ��
}TicketInfo;			//��Ʊ��Ϣ

typedef struct
{
	TicketInfo ticket[TICKET_NUM];
	int count;
}Ticket;

typedef struct
{
	int autoId; //������ŵĶ��ںš���Ʊʹ��
	char name[STR_LEN]; //��Ʊ������ 
	TicketInfo ticketInfo;
}Bookinfo; //��Ʊ��Ϣ

typedef struct
{
	Bookinfo book[TICKET_NUM];
	int count;
}Book;

Station station;
Ticket ticket;
Book book;
int flag = 1;

/*����ģ���ļ�doMain. c�õ��ĺ���ģ��*/
void start(int& flag);//ϵͳ��ʼ����
void initialize(Station& station, Ticket& ticket);

/*ϵͳ����ģ���ļ�systemManage. c�õ��ĺ���ģ��*/
//ϵͳ����
void systemManage(Station& station, Ticket& ticket, Book& book, int& f1ag);

/*վ�����ģ���ļ�stationManage.c�õ��ĺ���ģ��*/
void addStation(Station& station, Ticket& ticket, int i); //��ӳ�վ
void printStation(Station& station);//��ʾ��վ��Ϣ
void stationManage(Station& station, Ticket& ticket, Book& book, int& flag);//վ�����
void updateStation(Station& station, Ticket& ticket); //���³�վ��Ϣ
void updateTicketPrice(Station& s, int stationId);//���³�Ʊ�۸�
void updateTicketNum(Station& s, int stationId, Ticket& t);//���³�Ʊ����
void deleteStation(Station& s, Ticket& t);

/*Ʊ�����ģ���ļ�ticketManage. c�õ��ĺ���ģ��*/
void addTicket(int stationId, int count, Ticket& ticket);//��ӳ�Ʊ��Ϣ
void deleteTicket(int stationId, Ticket& ticket);//ɾ����վ��Ӧ�ĳ�Ʊ��Ϣ
void showOnsaleTickets(Station& station);//��ʾ���۳�Ʊ
void showSaleTickets(Book b);//��ʾ���۳�Ʊ
void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag);//Ʊ�����
void ticketWithdraw(Book& b, Ticket& t);

/*�ͻ�Ʊ�����ģ���ļ�ticketServices.c�õ�������ģ��*/
void ticketBook(Book& book, Ticket& ticket, Station s);//��Ʊ
void addBookInfo(Book& b, Ticket& t, int stationId, int bookNum);//��Ӷ�Ʊ��Ϣ
void ticketInquire(Station s, Ticket ticket);//��ѯƱ����Ϣ
void ticketServices(Station& s, Ticket& t, Book& b, int& flag);//Ʊ�����

#endif
void initialize(Station& station, Ticket& ticket)
{
	station.count = 0;
	ticket.count = 0;
	book.count = 0;
}

void start(int& flag)
{
	int option;
	if (flag)
	{
		int i = 0;						//��һ¼�복վ��Ϣ�ĸ���
		printf("\n����ϵͳ��һ�����У������վ�㼰���Ӧ��Ʊ��Ϣ��\n");
		initialize(station, ticket);
		printf("\n��������ӳ�վ��Ϣ�ĸ���:\n");
		scanf_s("%d", &i);
		if (i > 0) {
			addStation(station, ticket, i);
			flag = 1;
		}
		else start(flag);
	}
	printf("\n");
	printf("\t\t**********************************************\n");
	printf("\t\t\t��Ʊ����-----------------------1\n");
	printf("\t\t\tϵͳ����-----------------------2\n");
	printf("\t\t\t�˳�ϵͳ-----------------------0\n");
	printf("\t\t**********************************************\n");
	printf("\t\t��ѡ��");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		ticketServices(station, ticket, book, flag);
		flag = 0;
		break;
	case 2:
		systemManage(station, ticket, book, flag);
		flag = 0;
		break;
	case 0:
		printf("лл����ʹ�ã�\n");
		//exit(0);
		break;
	default:
		printf("\nѡ�����!\n");
		flag = 0;
		start(flag);
		break;
	}
}

void Practise53()
{
	srand((unsigned)time(NULL));					//�������
	while (1)start(flag);
}

//ϵͳ����˵� 
void systemManage(Station& station, Ticket& ticket, Book& book, int& flag)
{
	int option;
	printf("\t\t******************************************\n");
	printf("\t\t\tվ�����-----------------------1\n");
	printf("\t\t\tƱ�����-----------------------2\n");
	printf("\t\t\t������һ���˵�-----------------0\n");
	printf("\t\t******************************************\n");
	printf("\t\t��ѡ��");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		stationManage(station, ticket, book, flag);
		break;
	case 2:
		ticketManage(station, ticket, book, flag);
		break;
	case 0:
		start(flag);
		break;
	default:
		printf("\nѡ�����\n");
		systemManage(station, ticket, book, flag);
		break;
	}
}


//��վ���� 
void stationManage(Station& station, Ticket& ticket, Book& book, int& flag)
{
	int option, i = 0;
	printf("\t\t**********************************************\n");
	printf("\t\t\t�鿴��վ��Ϣ-----------------------1\n");
	printf("\t\t\t��ӳ�վ��Ϣ-----------------------2\n");
	printf("\t\t\t�޸ĳ�վ��Ϣ-----------------------3\n");				//Ҫ���޸�Ʊ�ۺ���Ʊ��
	printf("\t\t\tɾ����վ��Ϣ-----------------------4\n");
	printf("\t\t\t������һ���˵�---------------------0\n");
	printf("\t\t**********************************************\n");
	printf("\t\t��ѡ��");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		printStation(station);
		break;
	case 2:
		printf("\n��������ӳ�վ��Ϣ�ĸ�����");
		scanf_s("%d", &i);
		printf("%d\n", i);
		if (i > 0)
			addStation(station, ticket, i);
		break;
	case 3:
		updateStation(station, ticket);
		break;
	case 4:
		deleteStation(station, ticket);
		break;
	case 0:
		systemManage(station, ticket, book, flag);
		break;
	default:
		printf("\nѡ�����\n");
		break;
	}
}

void addStation(Station& s, Ticket& t, int snum)			//���վ�㣬snum��ӳ�վ������
{
	int i = s.count;
	int end = s.count + snum;
	printf("\n������%d����վ��Ϣ��\n", snum);
	for (; i < end; i++)
	{
		printf("----------------------------------------\n");
		printf("������%d����վ����Ϣ:\n", i + 1);
		printf("\t1.��������ʼվ���ƣ�\t");
		scanf_s("%s", s.station[i].from, STR_LEN);
		printf("\t2.�������յ�վ���ƣ�\t");
		scanf_s("%s", s.station[i].to, STR_LEN);
		printf("\t3.������Ʊ�ۣ�\t");
		scanf_s("%d", &s.station[i].money);
		printf("\t4.������Ʊ����\t");
		scanf_s("%d", &s.station[i].numbers);
		s.station[i].stationId = rand() % 1000;
		printf("\n\t5.�����Ʊ����Ϣ��\n");
		addTicket(s.station[i].stationId, s.station[i].numbers, t);
		printf("**��%d����վ��Ϣ��Ʊ����Ϣ��Ӽ�¼�ɹ���**\n", i++);
		printf("----------------------------------------\n");
		s.count++;
	}
}

void printStation(Station& s)						//��ӡվ����Ϣ
{
	int i;
	printf("\n\t\t��վ���\t��վ\t��վ\tƱ��\tʣ��Ʊ��\n");
	printf("\t\t------------------------------------\n");
	for (i = 0; i < s.count; i++)
	{
		if (!s.station[i].stationId)
		{
			printf("�޳�վ��Ϣ��\n");
			break;
		}
		printf("\t\t%d\t%s\t%s\t%d\t%d\n", s.station[i].stationId, s.station[i].from, s.station[i].to, s.station[i].money, s.station[i].numbers);
		printf("\t\t------------------------------------\n");
	}
}

void updateStation(Station& s, Ticket& t)				//���³�վ��Ϣ
{
	int stationId;
	printStation(s);
	printf("\n\t\tѡ��Ҫ�޸ĵĳ�վ��ţ�");
	scanf_s("%d", &stationId);
	updateTicketPrice(s, stationId);			//���³�Ʊ�۸�
	updateTicketNum(s, stationId, t);			//���³�Ʊ����
}
void updateTicketPrice(Station& s, int stationId)
{
	int price = 0;
	printf("-------------------------------------------\n");
	printf("�����복Ʊ�۸����Ϊ��");
	scanf_s("%d", &price);
	for (int i = 0; i < s.count; i++)
	{
		if (s.station[i].stationId == stationId)
			s.station[i].money = price;
	}
}
//���³�Ʊ���� 
void updateTicketNum(Station& s, int stationId, Ticket& t)
{
	int tic;	//�޸ĵĳ�Ʊ��
	int i;
	printf("--------------------------------------------\n");
	printf("�������޸ĺ�ĳ�Ʊ��Ϊ��");
	scanf_s("%d", &tic);
	for (i = 0; i < s.count; i++)
	{
		if (s.station[i].stationId == stationId)
			s.station[i].numbers = tic;
	}
	printf("ÿһ����վƱ�����º�Ϊ��\n");
	for (i = 0; i < s.count; i++)
		printf("%d��վ�ŵ�Ʊ��Ϊ%d\n", s.station[i].stationId, s.station[i].numbers);
	printf("---------------------------------------------\n");



}
//ɾ����վ��Ϣ 
void deleteStation(Station& s, Ticket& t)
{
	int n, i, ture = 0;//n��ʾҪɾ����վ���
	int  j = 0;
	printf("\n-----------------����վ����ɾ��վ��---------------\n");
	printf("������Ҫɾ����վ���ţ�");
	scanf_s("%d", &n);
	for (i = 0; i < s.count; i++)
	{
		if (s.station[i].stationId == n && t.ticket[i].stationId == n)
			ture = 1;
		if (i < s.count - 1)
		{
			for (j = i; j < s.count; j++)
			{
				s.station[j] = s.station[j + 1];
				t.ticket[j] = t.ticket[j + 1];
			}
			printf("----------------------------\n");
			printf("--��ɾ����վ����Ϣ--\n");
			printf("----------------------------\n");
		}
		/*if (i == s.count - 1)
		{
			s.count--;
			printf("----------------------------\n");
			printf("--��ɾ����վ����Ϣ--\n");
			printf("----------------------------\n");
		}*/
	}
	if (ture == 0)
	{
		printf("û�и�վ�㣡\n");
		deleteStation(s, t);
	}
}

//��Ʊ����
void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag)
{
	int option;
	printf("\t\t******************************************\n");
	printf("\t\t\t���۳�Ʊ-----------------------1\n");
	printf("\t\t\tʣ�೵Ʊ-----------------------2\n");
	printf("\t\t\t������һ���˵�-----------------0\n");
	printf("\t\t******************************************\n");
	printf("\t\t��ѡ��");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		showSaleTickets(book);
		break;
	case 2:
		showOnsaleTickets(station);
		break;
	case 0:
		systemManage(station, ticket, book, flag);
		break;
	default:
		printf("\nѡ�����!\n");
		ticketManage(station, ticket, book, flag);
		break;
	}
}

void addTicket(int stationId, int number, Ticket& t)
{
	int i = t.count;
	int end = t.count + number;
	char trainId[STR_LEN], date[STR_LEN], time[STR_LEN];
	printf("\t\t�г����Σ�%d���ַ����ڣ���", STR_LEN);
	scanf_s("%s", trainId, STR_LEN);
	printf("\t\t�г��������ڣ�%d���ַ����ڣ���", STR_LEN);
	scanf_s("%s", date, STR_LEN);
	printf("\t\t�г�����ʱ�䣨%d���ַ����ڣ���", STR_LEN);
	scanf_s("%s", time, STR_LEN);
	for (; i < end; i++)
	{
		t.ticket[i].stationId = stationId;
		t.ticket[i].seatId = rand() % 100;
		t.ticket[i].ticketId = rand() % 10000;
		strcpy(t.ticket[i].date, date);
		strcpy(t.ticket[i].time, time);
		strcpy(t.ticket[i].trainId, trainId);
		t.count++;
	}
}

void deleteTicket(int stationId, Ticket& t)
{
	int i, j;
	for (i = 0; i < t.count; i++)
	{
		if (t.ticket[i].stationId == stationId)
		{
			for (j = i; j < t.count; j++)
				t.ticket[j] = t.ticket[j + 1];
		}
	}
}

void showSaleTickets(Book b)
{
	int i;
	printf("\t\t��Ʊ������£�\n");
	printf("\t\t------------------------------------\n");
	printf("\n\t\t��Ʊ��\t����\t��������\t����ʱ��\t����\t��Ʊ��\n");
	printf("\t\t------------------------------------\n");
	for (i = 0; i < b.count; i++)
	{
		printf("\t\t%d\t\%s\t%s\t%s\t%d\t%s\n", b.book[i].autoId, b.book[i].ticketInfo.ticketId, b.book[i].ticketInfo.date, b.book[i].ticketInfo.time, b.book[i].ticketInfo.seatId, b.book[i].name);
		printf("\t\t------------------------------------\n");
	}
}

void showOnsaleTickets(Station& s)
{
	printStation(s);
	_getch();
}

//Ʊ�����
void ticketServices(Station& s, Ticket& t, Book& b, int& flag)
{
	int option;
	printf("\t\t******************************************\n");
	printf("\t\t\t��ѯ��Ʊ-----------------------1\n");
	printf("\t\t\tԤ����Ʊ-----------------------2\n");
	printf("\t\t\t�˶���Ʊ-----------------------3\n");
	printf("\t\t\t������һ���˵�-----------------0\n");
	printf("\t\t******************************************\n");
	printf("\t\t��ѡ��");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		ticketInquire(s, t);
		break;
	case 2:
		ticketBook(b, t, s);
		break;
	case 3:
		//��Ʊ����
		ticketWithdraw(b, t);
		break;
	case 0:
		flag = 0;
		start(flag);
		break;
	default:
		printf("\nѡ�����\n");
		ticketServices(s, t, b, flag);
		break;
	}
}

void ticketInquire(Station s, Ticket t)
{
	int i, k, j = 0;
	char from[STR_LEN], to[STR_LEN];
	char time[STR_LEN], date[STR_LEN], begin[STR_LEN], end[STR_LEN];
	int numbers = 0, money = 0, stationId = 0;
	printf("\t�������ѯ���վ���ƣ�\t");
	scanf_s("%s", from, STR_LEN);
	printf("\t�������ѯ�յ�վ���ƣ�\t");
	scanf_s("%s", to, STR_LEN);
	to[STR_LEN - 1] = '\0';
	printf("\tվ�����\t��վ\t��վ\t����\tʱ��\tƱ��\t�۸�\n");
	printf("\t\t------------------------------------\n");
	for (i = 0; i < s.count; i++)
	{
		if (strcmp(s.station[i].from, from) == 0 && strcmp(s.station[i].to, to) == 0)
		{
			stationId = s.station[i].stationId;
			numbers = s.station[i].numbers;
			money = s.station[i].money;
			strcpy(begin, from);
			strcpy(end, to);
			for (k = 0; k < t.count; k++)
			{
				if (t.ticket[i].stationId == stationId)
				{
					strcpy(time, t.ticket[i].time);
					strcpy(date, t.ticket[i].date);
					j++;
					break;
				}
			}
		}
		if (j)break;
	}
	printf("\t%d", stationId);
	printf("\t%s", begin);
	printf("\t%s", end);
	printf("\t%s", date);
	printf("\t%s", time);
	printf("\t%d", numbers);
	printf("\t%d", money);
	printf("\t-----------------------------------------\n");
}

//����stationId������Ʊ
void ticketBook(Book& b, Ticket& t, Station s)
{
	int i, stationId, bookNum;
	printStation(s);
	printf("\t\t�����붩Ʊ�ĳ�վ��ţ�");
	scanf_s("%d", &stationId);
	printf("\t\t�����붩Ʊ������");
	scanf_s("%d", &bookNum);
	for (i = 0; i < s.count; i++)
	{
		if (s.station[i].stationId == stationId && s.station[i].numbers >= bookNum)
		{
			addBookInfo(b, t, stationId, bookNum);
			s.station[i].numbers -= bookNum;		//��Ʊ�ɹ���ʣ��ĳ�Ʊ������ȥ��Ʊ������
		}
	}
}

void ticketWithdraw(Book& b, Ticket& t)     //��Ʊ����
{
	printf("---------------��Ʊ����---------------\n");
	//char na[STR_LEN];
	int tmp = 0;		//����������Ʊ�˵�autoId
	printf("��������Ʊ�˵�autoId��");
	scanf_s("%d", &tmp);
	for (int i = 0; i < b.count; i++)
	{
		if (b.book[i].autoId == tmp)
		{
			for (int j = i; j < b.count; j++)
			{
				b.book[j] = b.book[j + 1];
				t.ticket[j] = t.ticket[j + 1];
			}
			printf("-------------------------\n");
			printf("---�����Ʊ��������ɣ�--\n");
			printf("-------------------------\n");
		}

	}
}

void addBookInfo(Book& b, Ticket& t, int stationId, int bookNum)
{
	int i = b.count, j, end = b.count + bookNum;
	for (; i < end; i++)
	{
		b.book[i].autoId = rand() % 10000;
		printf("\t\t��Ʊ��������%d���ַ����ڣ�:", STR_LEN);
		scanf_s("%s", b.book[i].name, STR_LEN);
		printf("\t\t%s�Ķ�Ʊ��Ϊ%d:\n", b.book[i].name, b.book[i].autoId);
		for (j = 0; j < t.count; j++)
		{
			if (t.ticket[j].stationId == stationId)
			{
				strcpy(b.book[i].ticketInfo.date, t.ticket[j].date);
				strcpy(b.book[i].ticketInfo.time, t.ticket[j].time);
				strcpy(b.book[i].ticketInfo.trainId, t.ticket[j].trainId);
				b.book[i].ticketInfo.ticketId = t.ticket[j].ticketId;
				b.book[i].ticketInfo.seatId = t.ticket[j].seatId;
				b.book[i].ticketInfo.stationId = t.ticket[j].stationId;
			}
			b.count++;
		}
	}
}