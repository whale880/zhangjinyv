#include"practice8.h"

void MySQL_counter()
{
	system("cls");
	printf("===============================================\n");
	printf("******         简单计数器（MySQL）       ******\n");
	printf("-----------------------------------------------\n");
	_getch();
	char host[] = "localhost";       //MySQL主机名
	char dbname[] = "test";          //数据库名
	const char username[] = "root";      //用户名
	const char password[] = "...haohaoxuexi123";  //密码
	unsigned int port = 3306;       //连接端口，默认3306

	char szSQLTEXT[1000];

	/*getchar();
	printf("请输入密码：");
	gets_s(password);*/
	MYSQL* conn;          //MySQL连接指针
	MYSQL_RES* res = NULL;       //MySQL结果集
	MYSQL_ROW row = NULL;        //行变量

	conn = mysql_init(NULL);
	if (!conn)
	{
		printf("连接数据库失败！\n");
		return;
	}
	conn = mysql_real_connect(conn, host, username, password, dbname, port, NULL, 0);
	if (conn)
	{
		printf("数据库连接成功！\n");

		//每次运行，num加一
		mysql_query(conn, "update tbl_count set num=num+1;");
		//生成读取SQL语句
		strcpy(szSQLTEXT, "SELECT NUM FROM tbl_count LIMIT 1;");
		//马上把值读取出来
		if (mysql_query(conn, szSQLTEXT))
		{
			//如果读取失败
			mysql_close(conn);
			printf("select failed!\n");
			_getch();
		}
		else
		{
			//如果读取成功
			res = mysql_store_result(conn);         //取结果集到res中
			row = mysql_fetch_row(res);             //取第一行到row中
			//printf("bababa\n");
			if (row != NULL)
			{
				//row[0]表示取row的第一列
				printf("本程序是第%s次运行\n", row[0]);
			}
			else printf("未获取行数！\n");
		}

		//释放结果集
		mysql_free_result(res);
	}
	else
	{
		printf("数据库连接失败！\n");
	}
	mysql_close(conn);
	printf("\n即将退出简单计数器（MYSQL）\n");
	printf("请按任意键继续···\n\n");
	_getch();
}