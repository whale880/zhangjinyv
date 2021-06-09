#include"practice5.h"

#ifndef _TICKET_H
#define _TICKET_H
#include<stdio.h>
#include<stdlib.h>//用于gets_s
#include<string.h>//用于strcmp函数
#include<time.h>
#include<conio.h>//用于system("cls")清屏
#define STATION_NUM 100//车站数
#define TICKET_NUM 1000//车票数
#define STR_LEN 10//字符数组的长度
typedef struct
{
	int stationId;        //车站号
	char from[STR_LEN];           //车票起点
	char to[STR_LEN];          //车票终点
	int money;          //票价
	int numbers;		//票数
}StationInfo;			//车站票务信息

typedef struct
{
	StationInfo station[STATION_NUM];		//结构体数组
	int count;			//计数器
} Station;

typedef struct {
	int stationId;			//车站号
	int seatId;			//座位号，与票数相关
	int ticketId;			//车票编号
	char trainId[STR_LEN];			//火车车次
	char date[STR_LEN];			//出发日期
	char time[STR_LEN];   //出发时间
}TicketInfo;			//车票信息

typedef struct
{
	TicketInfo ticket[TICKET_NUM];
	int count;
}Ticket;

typedef struct
{
	int autoId; //随机生放的订期号。退票使用
	char name[STR_LEN]; //订票人姓名 
	TicketInfo ticketInfo;
}Bookinfo; //定票信息

typedef struct
{
	Bookinfo book[TICKET_NUM];
	int count;
}Book;

Station station;
Ticket ticket;
Book book;
int flag = 1;

/*主调模块文件doMain. c用到的函数模块*/
void start(int& flag);//系统开始函数
void initialize(Station& station, Ticket& ticket);

/*系统管理模块文件systemManage. c用到的函数模块*/
//系统管理
void systemManage(Station& station, Ticket& ticket, Book& book, int& f1ag);

/*站点管理模块文件stationManage.c用到的函数模块*/
void addStation(Station& station, Ticket& ticket, int i); //添加车站
void printStation(Station& station);//显示车站信息
void stationManage(Station& station, Ticket& ticket, Book& book, int& flag);//站点管理
void updateStation(Station& station, Ticket& ticket); //更新车站信息
void updateTicketPrice(Station& s, int stationId);//更新车票价格
void updateTicketNum(Station& s, int stationId, Ticket& t);//更新车票数量
void deleteStation(Station& s, Ticket& t);

/*票务管理模块文件ticketManage. c用到的函数模块*/
void addTicket(int stationId, int count, Ticket& ticket);//添加车票信息
void deleteTicket(int stationId, Ticket& ticket);//删除车站对应的车票信息
void showOnsaleTickets(Station& station);//显示待售车票
void showSaleTickets(Book b);//显示已售车票
void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag);//票务管理
void ticketWithdraw(Book& b, Ticket& t);

/*客户票务服务模块文件ticketServices.c用到的两数模块*/
void ticketBook(Book& book, Ticket& ticket, Station s);//订票
void addBookInfo(Book& b, Ticket& t, int stationId, int bookNum);//添加订票信息
void ticketInquire(Station s, Ticket ticket);//查询票务信息
void ticketServices(Station& s, Ticket& t, Book& b, int& flag);//票务服务

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
		int i = 0;						//第一录入车站信息的个数
		printf("\n本次系统第一次运行，请添加站点及其对应车票信息！\n");
		initialize(station, ticket);
		printf("\n请输入添加车站信息的个数:\n");
		scanf_s("%d", &i);
		if (i > 0) {
			addStation(station, ticket, i);
			flag = 1;
		}
		else start(flag);
	}
	printf("\n");
	printf("\t\t**********************************************\n");
	printf("\t\t\t售票服务-----------------------1\n");
	printf("\t\t\t系统管理-----------------------2\n");
	printf("\t\t\t退出系统-----------------------0\n");
	printf("\t\t**********************************************\n");
	printf("\t\t请选择：");
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
		printf("谢谢您的使用！\n");
		//exit(0);
		break;
	default:
		printf("\n选择出错!\n");
		flag = 0;
		start(flag);
		break;
	}
}

void Practise53()
{
	srand((unsigned)time(NULL));					//随机种子
	while (1)start(flag);
}

//系统管理菜单 
void systemManage(Station& station, Ticket& ticket, Book& book, int& flag)
{
	int option;
	printf("\t\t******************************************\n");
	printf("\t\t\t站点操作-----------------------1\n");
	printf("\t\t\t票务操作-----------------------2\n");
	printf("\t\t\t返回上一级菜单-----------------0\n");
	printf("\t\t******************************************\n");
	printf("\t\t请选择：");
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
		printf("\n选择出错\n");
		systemManage(station, ticket, book, flag);
		break;
	}
}


//车站管理 
void stationManage(Station& station, Ticket& ticket, Book& book, int& flag)
{
	int option, i = 0;
	printf("\t\t**********************************************\n");
	printf("\t\t\t查看车站信息-----------------------1\n");
	printf("\t\t\t添加车站信息-----------------------2\n");
	printf("\t\t\t修改车站信息-----------------------3\n");				//要求修改票价和余票量
	printf("\t\t\t删除车站信息-----------------------4\n");
	printf("\t\t\t返回上一级菜单---------------------0\n");
	printf("\t\t**********************************************\n");
	printf("\t\t请选择：");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		printStation(station);
		break;
	case 2:
		printf("\n请输入添加车站信息的个数：");
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
		printf("\n选择错误\n");
		break;
	}
}

void addStation(Station& s, Ticket& t, int snum)			//添加站点，snum添加车站的数量
{
	int i = s.count;
	int end = s.count + snum;
	printf("\n请输入%d个车站信息：\n", snum);
	for (; i < end; i++)
	{
		printf("----------------------------------------\n");
		printf("请输入%d个车站的信息:\n", i + 1);
		printf("\t1.请输入起始站名称：\t");
		scanf_s("%s", s.station[i].from, STR_LEN);
		printf("\t2.请输入终点站名称：\t");
		scanf_s("%s", s.station[i].to, STR_LEN);
		printf("\t3.请输入票价：\t");
		scanf_s("%d", &s.station[i].money);
		printf("\t4.请输入票数：\t");
		scanf_s("%d", &s.station[i].numbers);
		s.station[i].stationId = rand() % 1000;
		printf("\n\t5.请添加票务信息：\n");
		addTicket(s.station[i].stationId, s.station[i].numbers, t);
		printf("**第%d个车站信息和票务信息添加记录成功！**\n", i++);
		printf("----------------------------------------\n");
		s.count++;
	}
}

void printStation(Station& s)						//打印站点信息
{
	int i;
	printf("\n\t\t车站编号\t起站\t终站\t票价\t剩余票数\n");
	printf("\t\t------------------------------------\n");
	for (i = 0; i < s.count; i++)
	{
		if (!s.station[i].stationId)
		{
			printf("无车站信息！\n");
			break;
		}
		printf("\t\t%d\t%s\t%s\t%d\t%d\n", s.station[i].stationId, s.station[i].from, s.station[i].to, s.station[i].money, s.station[i].numbers);
		printf("\t\t------------------------------------\n");
	}
}

void updateStation(Station& s, Ticket& t)				//更新车站信息
{
	int stationId;
	printStation(s);
	printf("\n\t\t选择要修改的车站序号：");
	scanf_s("%d", &stationId);
	updateTicketPrice(s, stationId);			//更新车票价格
	updateTicketNum(s, stationId, t);			//更新车票数量
}
void updateTicketPrice(Station& s, int stationId)
{
	int price = 0;
	printf("-------------------------------------------\n");
	printf("请输入车票价格更改为：");
	scanf_s("%d", &price);
	for (int i = 0; i < s.count; i++)
	{
		if (s.station[i].stationId == stationId)
			s.station[i].money = price;
	}
}
//更新车票数量 
void updateTicketNum(Station& s, int stationId, Ticket& t)
{
	int tic;	//修改的车票数
	int i;
	printf("--------------------------------------------\n");
	printf("请输入修改后的车票数为：");
	scanf_s("%d", &tic);
	for (i = 0; i < s.count; i++)
	{
		if (s.station[i].stationId == stationId)
			s.station[i].numbers = tic;
	}
	printf("每一个车站票数更新后为：\n");
	for (i = 0; i < s.count; i++)
		printf("%d车站号的票数为%d\n", s.station[i].stationId, s.station[i].numbers);
	printf("---------------------------------------------\n");



}
//删除车站信息 
void deleteStation(Station& s, Ticket& t)
{
	int n, i, ture = 0;//n表示要删除的站点号
	int  j = 0;
	printf("\n-----------------按照站点编号删除站点---------------\n");
	printf("请输入要删除的站点编号：");
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
			printf("--已删除该站点信息--\n");
			printf("----------------------------\n");
		}
		/*if (i == s.count - 1)
		{
			s.count--;
			printf("----------------------------\n");
			printf("--已删除该站点信息--\n");
			printf("----------------------------\n");
		}*/
	}
	if (ture == 0)
	{
		printf("没有该站点！\n");
		deleteStation(s, t);
	}
}

//车票管理
void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag)
{
	int option;
	printf("\t\t******************************************\n");
	printf("\t\t\t已售车票-----------------------1\n");
	printf("\t\t\t剩余车票-----------------------2\n");
	printf("\t\t\t返回上一级菜单-----------------0\n");
	printf("\t\t******************************************\n");
	printf("\t\t请选择：");
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
		printf("\n选择出错!\n");
		ticketManage(station, ticket, book, flag);
		break;
	}
}

void addTicket(int stationId, int number, Ticket& t)
{
	int i = t.count;
	int end = t.count + number;
	char trainId[STR_LEN], date[STR_LEN], time[STR_LEN];
	printf("\t\t列车车次（%d个字符以内）：", STR_LEN);
	scanf_s("%s", trainId, STR_LEN);
	printf("\t\t列车出发日期（%d个字符以内）：", STR_LEN);
	scanf_s("%s", date, STR_LEN);
	printf("\t\t列车出发时间（%d个字符以内）：", STR_LEN);
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
	printf("\t\t售票情况如下：\n");
	printf("\t\t------------------------------------\n");
	printf("\n\t\t订票号\t车次\t出发日期\t出发时间\t座号\t订票人\n");
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

//票务服务
void ticketServices(Station& s, Ticket& t, Book& b, int& flag)
{
	int option;
	printf("\t\t******************************************\n");
	printf("\t\t\t查询车票-----------------------1\n");
	printf("\t\t\t预定车票-----------------------2\n");
	printf("\t\t\t退订车票-----------------------3\n");
	printf("\t\t\t返回上一级菜单-----------------0\n");
	printf("\t\t******************************************\n");
	printf("\t\t请选择：");
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
		//退票服务
		ticketWithdraw(b, t);
		break;
	case 0:
		flag = 0;
		start(flag);
		break;
	default:
		printf("\n选择出错！\n");
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
	printf("\t请输入查询起点站名称：\t");
	scanf_s("%s", from, STR_LEN);
	printf("\t请输入查询终点站名称：\t");
	scanf_s("%s", to, STR_LEN);
	to[STR_LEN - 1] = '\0';
	printf("\t站点序号\t起站\t终站\t日期\t时间\t票数\t价格\n");
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

//根据stationId订购车票
void ticketBook(Book& b, Ticket& t, Station s)
{
	int i, stationId, bookNum;
	printStation(s);
	printf("\t\t请输入订票的车站编号：");
	scanf_s("%d", &stationId);
	printf("\t\t请输入订票数量：");
	scanf_s("%d", &bookNum);
	for (i = 0; i < s.count; i++)
	{
		if (s.station[i].stationId == stationId && s.station[i].numbers >= bookNum)
		{
			addBookInfo(b, t, stationId, bookNum);
			s.station[i].numbers -= bookNum;		//订票成功后剩余的车票数量减去订票的数量
		}
	}
}

void ticketWithdraw(Book& b, Ticket& t)     //退票服务
{
	printf("---------------退票服务---------------\n");
	//char na[STR_LEN];
	int tmp = 0;		//用于输入退票人的autoId
	printf("请输入退票人的autoId：");
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
			printf("---你的退票服务已完成！--\n");
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
		printf("\t\t订票人姓名（%d个字符以内）:", STR_LEN);
		scanf_s("%s", b.book[i].name, STR_LEN);
		printf("\t\t%s的订票号为%d:\n", b.book[i].name, b.book[i].autoId);
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