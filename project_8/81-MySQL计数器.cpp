#include"practice8.h"

void MySQL_counter()
{
	system("cls");
	printf("===============================================\n");
	printf("******         �򵥼�������MySQL��       ******\n");
	printf("-----------------------------------------------\n");
	_getch();
	char host[] = "localhost";       //MySQL������
	char dbname[] = "test";          //���ݿ���
	const char username[] = "root";      //�û���
	const char password[] = "...haohaoxuexi123";  //����
	unsigned int port = 3306;       //���Ӷ˿ڣ�Ĭ��3306

	char szSQLTEXT[1000];

	/*getchar();
	printf("���������룺");
	gets_s(password);*/
	MYSQL* conn;          //MySQL����ָ��
	MYSQL_RES* res = NULL;       //MySQL�����
	MYSQL_ROW row = NULL;        //�б���

	conn = mysql_init(NULL);
	if (!conn)
	{
		printf("�������ݿ�ʧ�ܣ�\n");
		return;
	}
	conn = mysql_real_connect(conn, host, username, password, dbname, port, NULL, 0);
	if (conn)
	{
		printf("���ݿ����ӳɹ���\n");

		//ÿ�����У�num��һ
		mysql_query(conn, "update tbl_count set num=num+1;");
		//���ɶ�ȡSQL���
		strcpy(szSQLTEXT, "SELECT NUM FROM tbl_count LIMIT 1;");
		//���ϰ�ֵ��ȡ����
		if (mysql_query(conn, szSQLTEXT))
		{
			//�����ȡʧ��
			mysql_close(conn);
			printf("select failed!\n");
			_getch();
		}
		else
		{
			//�����ȡ�ɹ�
			res = mysql_store_result(conn);         //ȡ�������res��
			row = mysql_fetch_row(res);             //ȡ��һ�е�row��
			//printf("bababa\n");
			if (row != NULL)
			{
				//row[0]��ʾȡrow�ĵ�һ��
				printf("�������ǵ�%s������\n", row[0]);
			}
			else printf("δ��ȡ������\n");
		}

		//�ͷŽ����
		mysql_free_result(res);
	}
	else
	{
		printf("���ݿ�����ʧ�ܣ�\n");
	}
	mysql_close(conn);
	printf("\n�����˳��򵥼�������MYSQL��\n");
	printf("�밴���������������\n\n");
	_getch();
}