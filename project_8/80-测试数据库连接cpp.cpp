#include"practice8.h"
//#include <WinSock.h>
//#pragma comment(lib,"libmysql.lib")

void mysqltest()
{
	char host[] = "localhost";      //MySQL������
	char dbname[] = "test";         //���ݿ���
	const char username[] = "root"; //�������ݿ�ĺϷ��û���
	const char password[] = "...haohaoxuexi123";  //����
	unsigned int port = 3306;       //���Ӷ˿ڣ�Ĭ��3306

	MYSQL* conn;          //MySQL����ָ��
	conn = mysql_init(NULL);
	if (!conn)
	{
		printf("�������ݿ�ʧ�ܣ�\n");
		exit(0);
	}
	conn = mysql_real_connect(conn, host, username, password, dbname, port, NULL, 0);
	if (conn)
	{
		printf("���ݿ����ӳɹ���\n");
	}
	else
	{
		printf("���ݿ�����ʧ�ܣ�\n");
	}
	mysql_close(conn);
	printf("Hello World!\n");
	_getch();

}