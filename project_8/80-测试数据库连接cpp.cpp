#include"practice8.h"
//#include <WinSock.h>
//#pragma comment(lib,"libmysql.lib")

void mysqltest()
{
	char host[] = "localhost";      //MySQL主机名
	char dbname[] = "test";         //数据库名
	const char username[] = "root"; //连接数据库的合法用户名
	const char password[] = "...haohaoxuexi123";  //密码
	unsigned int port = 3306;       //连接端口，默认3306

	MYSQL* conn;          //MySQL连接指针
	conn = mysql_init(NULL);
	if (!conn)
	{
		printf("连接数据库失败！\n");
		exit(0);
	}
	conn = mysql_real_connect(conn, host, username, password, dbname, port, NULL, 0);
	if (conn)
	{
		printf("数据库连接成功！\n");
	}
	else
	{
		printf("数据库连接失败！\n");
	}
	mysql_close(conn);
	printf("Hello World!\n");
	_getch();

}