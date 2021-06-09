#include"practice8.h"

static MYSQL* conn;        //���ݿ����Ӿ��
static char sql[1024];
static struct order1
{
    char id[20];
    char name[20];
    char address[30];
    char telenum[20];
    char ordertime[30];
    char delivertime[30];
}orders;
static struct order2
{
    int num;
    int price;
    char name[10];
}goods;

static void input2(int* i)
{
    printf("      ����Ʒ������:");
    rewind(stdin);
    *i += scanf_s("%d", &goods.price);
    printf("      ��������Ϊ:");
    rewind(stdin);
    *i += scanf_s("%d", &goods.num);
    if (*i == 2);
    else
    {
        *i = 0;
        printf("�������,��Ʒ���ۡ�������������������,����������:\n");
        input2(i);
    }
}
static void input()
{
    int i = 0;
    for (;;)
    {
        system("cls");
        printf("�����붩����(exit�˳�):");
        rewind(stdin);
        scanf_s("%s", orders.id, 20);
        if (strcmp(orders.id, "exit") == 0)
            break;
        printf("������ͻ�����:");
        rewind(stdin);
        scanf_s("%s", orders.name, 20);
        printf("������ͻ���ַ:");
        rewind(stdin);
        scanf_s("%s", orders.address, 30);
        printf("������ͻ��绰:");
        rewind(stdin);
        scanf_s("%s", orders.telenum, 20);
        printf("�����붩������:");
        rewind(stdin);
        scanf_s("%s", orders.ordertime, 30);
        printf("�����뽻������:");
        rewind(stdin);
        scanf_s("%s", orders.delivertime, 30);
        printf("      ��������Ʒ����:");
        rewind(stdin);
        scanf_s("%s", goods.name, 10);
        input2(&i);
        sprintf(sql, "insert into orders values('%s','%s','%s','%s','%s','%s')", orders.id, orders.name, orders.address, orders.telenum, orders.ordertime, orders.delivertime);
        if (mysql_query(conn, sql))
            printf("%s\n", mysql_error(conn));
        else
        {
            sprintf(sql, "insert into goods values('%s',%d,'%s',%d)", goods.name, goods.price, orders.id, goods.num);
            if (mysql_query(conn, sql))
                printf("%s\n", mysql_error(conn));
            else
                printf("��������ɹ�\n");
        }
        _getch();
    }
}
static void found()
{
    int key, i;
    char name[20], tel[20], ordertime1[20], ordertime2[20];
    MYSQL_RES* res = NULL;
    MYSQL_ROW row;
    for (;;)
    {
        system("cls");
        printf("***  1.�ݿͻ����Ʋ�ѯ   ***\n");
        printf("***  2.�ݿͻ��绰��ѯ   ***\n");
        printf("***  3.�ݶ������ڷ�Χ��ѯ   ***\n");
        printf("***  4.����           ***\n");
        printf("***********************\n");
        printf("�����빦�ܱ��:");
        fflush(stdin);
        scanf_s("%d", &key);
        switch (key)
        {
        case 1:
            printf("������ͻ�����:");
            rewind(stdin);
            gets_s(name, 20);
            sprintf(sql, "select orders.id,orders.name,orders.address,orders.telenum,orders.ordertime,orders.delivertime,goods.name,goods.price,goods.num from orders inner join goods on orders.id=goods.id where orders.name='%s'", name);
            break;
        case 2:
            printf("������ͻ��绰:");
            rewind(stdin);
            gets_s(tel, 20);
            sprintf(sql, "select orders.id,orders.name,orders.address,orders.telenum,orders.ordertime,orders.delivertime,goods.name,goods.price,goods.num from orders inner join goods on orders.id=goods.id where orders.telenum='%s'", tel);
            break;
        case 3:
            printf("�����붩�����ڷ�Χ(��������֮�任�и���):");
            rewind(stdin);
            gets_s(ordertime1, 20);
            rewind(stdin);
            gets_s(ordertime2, 20);
            sprintf(sql, "select orders.id,orders.name,orders.address,orders.telenum,orders.ordertime,orders.delivertime,goods.name,goods.price,goods.num from orders inner join goods on orders.id=goods.id where orders.ordertime between '%s' and '%s'", ordertime1, ordertime2);
            break;
        default:break;
        }
        if (key == 4)
            break;
        if (mysql_query(conn, sql))
            printf("%s\n", mysql_error(conn));
        else
            res = mysql_store_result(conn);
        i = (int)mysql_num_rows(res);            //��ȡ�������
        if (i > 0)//����ж�����Ϣ
        {
            printf("��ѯ��%d��������Ϣ��\n", i);
            printf("����ID\t�ͻ�����\t�ͻ���ַ\t�ͻ��绰\t��������\t��������\t��Ʒ����\t��������\t�����ܽ��\n");
            printf("-------------------------------------------------------------------------------------------------------- \n");
            while (1)
            {
                row = mysql_fetch_row(res);          //�������һ�и�ֵ��row
                if (row == NULL)                     //ֱ���޽��
                    break;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]);
            }
        }
        else
            printf("\n��ѯ�޽��\n");
        mysql_free_result(res);
        printf("--------------------------------------------------------------------------------------------------------\n");
        _getch();
    }
}
static void dele()
{
    char id[20];
    printf("��������Ҫɾ���Ķ�����:");
    rewind(stdin);
    gets_s(id, 20);
    sprintf(sql, "delete from orders where id='%s'", id);
    if (mysql_query(conn, sql))
        printf("%s\n", mysql_error(conn));
    else
        printf("����ɾ���ɹ���\n");
    _getch();
}
static void meau()
{
    int key;
    for (;;)
    {
        system("cls");
        printf("********��������˵�*********\n");
        printf("***  1.����¼�빦��   ***\n");
        printf("***  2.������ѯ����   ***\n");
        printf("***  3.����ɾ������   ***\n");
        printf("***  4.����           ***\n");
        printf("***********************\n");
        printf("�����빦�ܱ��:");
        fflush(stdin);
        scanf_s("%d", &key);
        switch (key)
        {
        case 1:input(); break;
        case 2:found(); break;
        case 3:dele(); break;
        default:break;
        }
        if (key == 4)
            break;
    }
}
void order8()
{
    const char* server = "localhost";   //��������
    const char* user = "root";          //�û���
    const char* password = "...haohaoxuexi123";//mysql����
    const char* database = "test";    //���ݿ���
    conn = mysql_init(NULL);            //�����ʼ��
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))  //�ж����ݿ��Ƿ����ӳɹ�
    {
        printf("����ʧ�ܣ�%s", mysql_error(conn));      //����
        _getch();
    }
    else
    {
        printf("���ӳɹ��������������");
        _getch();
        mysql_set_character_set(conn, "gbk");    //���ñ��룬��������
        meau();
    }
    mysql_close(conn);                  //�Ͽ����ݿ�
}