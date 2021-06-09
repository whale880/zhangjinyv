#include"practice8.h"

#define IDLens 13
#define NameLens 11
#define SexLens 5
#pragma comment(lib,"libmysql.lib")
struct Score
{
	int cp;
	int en;
	int math;
};
typedef struct Stu
{
	char id[IDLens];
	char name[NameLens];
	char sex[SexLens];
	int age;
	struct Score score;
	double avg;
}Student;
MYSQL* conn;
char szSqlTexts[1000] = "";    //SQL语句
char sortField[100];
Student stu;

void OutputStudenta()
{

	int i;
	MYSQL_RES* res;
	MYSQL_ROW row;
	sprintf(szSqlTexts, "select id,name,sex,age,score_cp,score_en,score_math,(score_cp + score_en + score_math) / 3 score_avg from tbl_student order by ");
	strcat(szSqlTexts, sortField);
	if (mysql_query(conn, szSqlTexts))
	{
		printf("select failed.\n");
		return;
	}
	else
	{
		res = mysql_store_result(conn);
		i = (int)mysql_num_rows(res);
		if (i > 0)
		{
			printf("\n共有%d个学生信息：\n==========\n", i);
			printf("学号            姓名        性别   年龄   C语言   英语   高数   平均分\n");
			printf("----------------------------\n");
			while (1)
			{
				row = mysql_fetch_row(res);
				if (row == NULL)
					break;
				printf("%-15s%-14s%-7s%-7s", row[0], row[1], row[2], row[3]);
				printf("%-7s%-7s%-7s%-7.1f\n", row[4], row[5], row[6], atof(row[7]));
			}
		}
		else
			printf("\n没有学生信息\n===================\n");
		mysql_free_result(res);
	}
	printf("-----------------------------------");
}

bool ExistsStudenta(char* id)
{
	int i = 0;
	MYSQL_RES* res;
	sprintf(szSqlTexts, "select id from tbl_student where id='%s'", id);
	if (mysql_query(conn, szSqlTexts))
	{
		printf("select failed.\n");
		return false;
	}
	else
	{
		res = mysql_store_result(conn);
		i = (int)mysql_num_rows(res);
		mysql_free_result(res);
	}
	return i > 0;
}

void InsertStudenta()
{
	sprintf(szSqlTexts, "insert into tbl_student(id,name,sex,age,score_cp,score_en,score_math) values('%s','%s','%s',%d,%d,%d,%d)", stu.id, stu.name, stu.sex, stu.age, stu.score.cp, stu.score.en, stu.score.math);
	if (mysql_query(conn, szSqlTexts))
	{
		printf("inserted failed.\n");
	}
}

void UpdateStudenta()
{
	sprintf(szSqlTexts, "update tbl_student set name='%s',sex='%s',age=%d,score_cp=%d,score_en=%d,score_math=%d where id='%s'", stu.name, stu.sex, stu.age, stu.score.cp, stu.score.en, stu.score.math, stu.id);
	if (mysql_query(conn, szSqlTexts))
	{
		printf("inserted failed.\n");
	}
}

void DeleteStudenta()
{
	sprintf(szSqlTexts, "delete from tbl_student where id='%s'", stu.id);
	if (mysql_query(conn, szSqlTexts))
	{
		printf("inserted failed.\n");
	}
}

bool InputStudenta(int mode, bool OnlyID)
{
	bool b;
	if (OnlyID == false)
		printf("\n请输入学生信息：");
	printf("\n---------------------------\n");
	do
	{
		printf("学号（12个字符以内，q!表示放弃本次操作）:\t");
		scanf("%s", stu.id);
		stu.id[IDLens - 1] = 0;
		if (strcmp(stu.id, "q!") == 0)
			return false;
		b = ExistsStudenta(stu.id);
		if (mode == 1 && b == false)
			printf("学号%s不存在，重新输入学号。\n", stu.id);
		else if (mode == 2 && b == true)
			printf("学号%s存在，重新输入学号。\n", stu.id);
		else
			break;
	} while (1);
	if (OnlyID)
		return true;
	printf("姓名(10个字符以内）：\t");
	scanf("%s", stu.name);
	stu.name[NameLens - 1] = 0;
	printf("性别(4个字符以内）：\t");
	scanf("%s", stu.sex);
	stu.sex[SexLens - 1] = 0;
	printf("年龄(整数）：\t");
	scanf("%d", &stu.age);
	printf("《C语言》成绩（整数）：\t");
	scanf("%d", &stu.score.cp);
	printf("《英语》成绩（整数）：\t");
	scanf("%d", &stu.score.en);
	printf("《高数》成绩（整数）：\t");
	scanf("%d", &stu.score.math);
	stu.avg = (stu.score.cp + stu.score.en + stu.score.math) / 3.0;
	printf("---------------------------\n");
	return true;
}

void DisplaySortMenua()
{
	system("cls");
	int i;
	do
	{
		printf("\n请选择排序的字段：\n");
		printf("---------------------------\n");
		printf("(1)学号\t(2)姓名\t(3)性别\t(4)年龄\n");
		printf("(5)C语言\t(6)英语\t(7)高数\t(8)平均分\n");
		printf("---------------------------\n");
		i = _getche() - '0';
		strcpy(sortField, "");
		switch (i)
		{
		case 1:
			strcpy(sortField, "id");
			break;
		case 2:
			strcpy(sortField, "name");
			break;
		case 3:
			strcpy(sortField, "sex");
			break;
		case 4:
			strcpy(sortField, "age");
			break;
		case 5:
			strcpy(sortField, "score_cp");
			break;
		case 6:
			strcpy(sortField, "score_en");
			break;
		case 7:
			strcpy(sortField, "score_math");
			break;
		case 8:
			strcpy(sortField, "score_cp+score_en+score_math");
			break;
		default:
			printf("\n请选择正确的操作！");
			break;
		}
	} while (i < 1 || i>8);

	do
	{
		system("cls");
		printf("\n请选择排序方向：\n");
		printf("---------------------------\n");
		printf("(1)升序\t(2)降序\t\n");
		printf("---------------------------\n");
		i = _getche() - '0';
		switch (i)
		{
		case 1:
			break;
		case 2:
			strcat(sortField, " desc");
			break;
		default:
			printf("\n请选择正确的操作！");
			break;
		}
	} while (i < 1 || i>2);
}

void DisplayMainMenua()
{
	int i;
	while (1)
	{
		system("cls");
		printf("\n系统主菜单，请选择：\n");
		printf("---------------------------\n");
		printf("(1)增加学生及成绩\n");
		printf("(2)删除学生及成绩\n");
		printf("(3)修改学生及成绩\n");
		printf("(4)显示所有记录\n");
		printf("(0)退出程序\n");
		printf("---------------------------\n");
		i = _getche() - '0';
		switch (i)
		{
		case 1:
			if (InputStudenta(2, false))
				InsertStudenta();
			_getch();
			break;
		case 2:
			if (InputStudenta(1, true))
				DeleteStudenta();
			_getch();
			break;
		case 3:
			if (InputStudenta(1, false))
				UpdateStudenta();
			_getch();
			break;
		case 4:
			DisplaySortMenua();
			OutputStudenta();
			_getch();
			break;
		case 0:
			return;
		default:
			printf("\n请选择正确的操作！");
			break;
		}
	}
}

void MYstudent()
{
	char host[] = "localhost";
	char szTargetDSN[] = "test";
	const char username[] = "root";
	const char password[] = "...haohaoxuexi123";
	unsigned int port = 3306;
	if ((conn = mysql_init((MYSQL*)0)) && (mysql_options(conn, MYSQL_SET_CHARSET_NAME, "gbk") == 0) && mysql_real_connect(conn, host, username, password, szTargetDSN, port, NULL, 0))
	{
		printf("数据库连接成功！\n");
		_getch();
		DisplayMainMenua();
		mysql_close(conn);
	}
	else
	{
		printf("\n链接数据库失败。\n");
		_getch();
		mysql_close(conn);
	}
	printf("hahaha···\n");
	_getch();
}