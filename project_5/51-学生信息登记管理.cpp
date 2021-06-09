#include"practice5.h"
#define N 3     //学生个数
#define IDLen 20   //学号
#define NameLen 10  //姓名
#define SexLen 4    //性别
typedef struct Sco
{
	int cp;    //C语言成绩
	int en;    //英语  
	int math;  //高数成绩
}Score;
typedef struct Stu
{
	char id[IDLen + 1];   //学号
	char name[NameLen + 1];  //姓名
	char sex[SexLen + 1];  //性别
	int age;               //年龄
	Score score;            //成绩
	double avg;				//平均成绩
}Student;
//函数声明
void Line();				//画线
void InputStudent5();      //输入学生信息
void DisplayMenu51(); //菜单
void GetOrderDir5();				//排序菜单
void SortStudent5();				//排序操作（冒泡）
void OutputStudent5(Student s[]);	//输出学生信息
//全局变量
Student stu[N];  //原始输入的学生信息
Student sorted[N];	//排序操作的学生信息
char chioce = 0;    //主菜单中的选项
char dir = 0;		//排序方向选项，1升，2降

//主函数
void Sstudent()
{
	InputStudent5();
	while (1)
	{
		DisplayMenu51();
		if ('0' == chioce)
		{
			printf("\n谢谢使用，再见\n");
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
				//continue;//返回上一级
			SortStudent5();
			OutputStudent5(sorted);
		}
	}
	_getche();
}

void Line()//画虚线
{
	printf("\n----------------------------------------------------------------------------\n");
}
void InputStudent5()            //输入学生信息
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		fflush(stdin);
		printf("请输入%d/%d个学生的信息：\n", i + 1, N);
		Line();
		printf("输入学号（12个数字字符）：");
		scanf_s("%s", stu[i].id, IDLen);
		stu[i].id[IDLen] = '\0';		//强制结束符号
		fflush(stdin);
		//getchar();
		printf("输入姓名（不超出%d字符）：", NameLen);
		scanf_s("%s", stu[i].name, NameLen);
		//gets_s(stu[i].name);
		stu[i].name[NameLen] = '\0';		//强制结束符号
		printf("输入性别（不超出2字符）：");
		scanf_s("%s", stu[i].sex, SexLen);
		printf("输入年龄（整数）：");
		scanf_s("%d", &stu[i].age);

		//printf("输入成绩（整数）：\n");
		printf("输入C语言成绩：");
		scanf_s("%d", &stu[i].score.cp);
		printf("输入英语成绩：");
		scanf_s("%d", &stu[i].score.en);
		printf("输入高数成绩：");
		scanf_s("%d", &stu[i].score.math);
		//平均分
		stu[i].avg = ((double)(stu[i].score.cp + stu[i].score.en + stu[i].score.math)) / 3.0;
		Line();
	}
	//复制结构体数组(保留现场的操作）
	for (int i = 0; i < N; i++)
		sorted[i] = stu[i];
}

void DisplayMenu51()    //菜单
{
	while (1)
	{
		printf("\n请选择你的操作（排序字段或显示原始信息或退出):\n");
		Line();
		printf("(1)学号\t(2)姓名\t(3)性别\t(4)年龄\n");
		printf("(5)c语言\t(6)英语\t(7)高数\t(8)平均分\n");
		printf("(9)显示原始输入的信息\t(0)退出程序\n");
		Line();
		chioce = _getche();
		//scanf_s("%c", &chioce,1);
		if (chioce - '0' < 0 || chioce - '0' > 9)
			printf("\n输入选项错误，请重新输入!\n");
		else
			return;
	}
}
void GetOrderDir5()				//排序菜单
{
	while (1)
	{
		printf("\n请选择你的排序方向或返回:\n");
		Line();
		printf("(1)升序\t(2)降序\t(0)返回菜单\n");
		Line();
		fflush(stdin);
		dir = _getche();
		if ((dir - '0') < 0 || (dir - '0') > 2)
			printf("\n输入选项错误，请重新输入!\n");
		else
			return;
	}
}
void SortStudent5()				//排序操作（冒泡）
{
	int i = 0, j = 0, f;//f用于标记
	Student s;
	//从0-N-1升序
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			f = 0;//f=1,表示要交换
			switch (chioce)
			{
			case '1'://比较学号
				if (strcmp(sorted[j].id, sorted[j + 1].id) > 0)
					f = 1;
				break;
			case '2'://比较姓名
				if (strcmp(sorted[j].name, sorted[j + 1].name) > 0)
					f = 1;
				break;
			case '3'://比较性别
				if (strcmp(sorted[j].sex, sorted[j + 1].sex) > 0)
					f = 1;
				break;
			case '4'://比较年龄
				if (sorted[j].age > sorted[j + 1].age)
					f = 1;
			case '5'://比较C语言成绩
				if (sorted[j].score.cp > sorted[j + 1].score.cp)
					f = 1;
				break;
			case '6'://比较英语成绩
				if (sorted[j].score.en > sorted[j + 1].score.en)
					f = 1;
				break;
			case '7'://比较高数
				if (sorted[j].score.math > sorted[j + 1].score.math)
					f = 1;
				break;
			case '8'://比较平均分
				if (sorted[j].avg > sorted[j + 1].avg)
					f = 1;
				break;
			default:
				printf("未知错误！");
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
void OutputStudent5(Student s[])	//输出学生信息
{
	printf("\n学生信息如下：\n\n================================\n");
	printf("%-15s%-14s%-7s%-7s%-7s%-7s%-7s%-7s\n", "学号", "姓名", "性别", "年龄", "C语言", "英语", "高数", "平均分");
	Line();
	if ('1' == dir)//升序
	{
		for (int i = 0; i < N; i++)
		{
			printf("%-15s%-14s%-7s%-7d", s[i].id, s[i].name, s[i].sex, s[i].age);
			printf("%-7d%-7d%-7d%-7.2f\n", s[i].score.cp, s[i].score.en, s[i].score.math, s[i].avg);
		}
	}
	else    //降序
	{
		for (int i = N - 1; i >= 0; i--)
		{
			printf("%-15s%-14s%-7s%-7d", s[i].id, s[i].name, s[i].sex, s[i].age);
			printf("%-7d%-7d%-7d%-7.2f\n", s[i].score.cp, s[i].score.en, s[i].score.math, s[i].avg);
		}
	}
	dir = 0;//每次排序后将排序方向置为0
	Line();
}