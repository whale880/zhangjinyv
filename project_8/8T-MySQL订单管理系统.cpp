#include"practice8.h"

static MYSQL* conn;        //数据库连接句柄
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
    printf("      该商品单价是:");
    rewind(stdin);
    *i += scanf_s("%d", &goods.price);
    printf("      购买数量为:");
    rewind(stdin);
    *i += scanf_s("%d", &goods.num);
    if (*i == 2);
    else
    {
        *i = 0;
        printf("输入错误,商品单价、购买数量请输入数字,请重新输入:\n");
        input2(i);
    }
}
static void input()
{
    int i = 0;
    for (;;)
    {
        system("cls");
        printf("请输入订单号(exit退出):");
        rewind(stdin);
        scanf_s("%s", orders.id, 20);
        if (strcmp(orders.id, "exit") == 0)
            break;
        printf("请输入客户名称:");
        rewind(stdin);
        scanf_s("%s", orders.name, 20);
        printf("请输入客户地址:");
        rewind(stdin);
        scanf_s("%s", orders.address, 30);
        printf("请输入客户电话:");
        rewind(stdin);
        scanf_s("%s", orders.telenum, 20);
        printf("请输入订货日期:");
        rewind(stdin);
        scanf_s("%s", orders.ordertime, 30);
        printf("请输入交货日期:");
        rewind(stdin);
        scanf_s("%s", orders.delivertime, 30);
        printf("      请输入商品名称:");
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
                printf("订单输入成功\n");
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
        printf("***  1.据客户名称查询   ***\n");
        printf("***  2.据客户电话查询   ***\n");
        printf("***  3.据订货日期范围查询   ***\n");
        printf("***  4.返回           ***\n");
        printf("***********************\n");
        printf("请输入功能编号:");
        fflush(stdin);
        scanf_s("%d", &key);
        switch (key)
        {
        case 1:
            printf("请输入客户名称:");
            rewind(stdin);
            gets_s(name, 20);
            sprintf(sql, "select orders.id,orders.name,orders.address,orders.telenum,orders.ordertime,orders.delivertime,goods.name,goods.price,goods.num from orders inner join goods on orders.id=goods.id where orders.name='%s'", name);
            break;
        case 2:
            printf("请输入客户电话:");
            rewind(stdin);
            gets_s(tel, 20);
            sprintf(sql, "select orders.id,orders.name,orders.address,orders.telenum,orders.ordertime,orders.delivertime,goods.name,goods.price,goods.num from orders inner join goods on orders.id=goods.id where orders.telenum='%s'", tel);
            break;
        case 3:
            printf("请输入订货日期范围(两个日期之间换行隔开):");
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
        i = (int)mysql_num_rows(res);            //获取结果行数
        if (i > 0)//如果有订单信息
        {
            printf("查询到%d个订单信息：\n", i);
            printf("订单ID\t客户名称\t客户地址\t客户电话\t订货日期\t交货日期\t商品名称\t销售数量\t销售总金额\n");
            printf("-------------------------------------------------------------------------------------------------------- \n");
            while (1)
            {
                row = mysql_fetch_row(res);          //检索结果一行赋值给row
                if (row == NULL)                     //直到无结果
                    break;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]);
            }
        }
        else
            printf("\n查询无结果\n");
        mysql_free_result(res);
        printf("--------------------------------------------------------------------------------------------------------\n");
        _getch();
    }
}
static void dele()
{
    char id[20];
    printf("请输入你要删除的订单号:");
    rewind(stdin);
    gets_s(id, 20);
    sprintf(sql, "delete from orders where id='%s'", id);
    if (mysql_query(conn, sql))
        printf("%s\n", mysql_error(conn));
    else
        printf("订单删除成功！\n");
    _getch();
}
static void meau()
{
    int key;
    for (;;)
    {
        system("cls");
        printf("********订单管理菜单*********\n");
        printf("***  1.订单录入功能   ***\n");
        printf("***  2.订单查询功能   ***\n");
        printf("***  3.订单删除功能   ***\n");
        printf("***  4.返回           ***\n");
        printf("***********************\n");
        printf("请输入功能编号:");
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
    const char* server = "localhost";   //本地连接
    const char* user = "root";          //用户名
    const char* password = "...haohaoxuexi123";//mysql密码
    const char* database = "test";    //数据库名
    conn = mysql_init(NULL);            //句柄初始化
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))  //判断数据库是否连接成功
    {
        printf("连接失败：%s", mysql_error(conn));      //报错
        _getch();
    }
    else
    {
        printf("连接成功！按任意键继续");
        _getch();
        mysql_set_character_set(conn, "gbk");    //设置编码，避免乱码
        meau();
    }
    mysql_close(conn);                  //断开数据库
}