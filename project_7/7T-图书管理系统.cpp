#include"practice7.h"

//借书证信息
struct student
{
	char stu_num[10];
	char stu_name[20];
	char borrow_book[50];
	struct student* next;
}*stu1, * stu2;
//书籍信息
struct book
{
	char book_num[10];
	char book_name[60];
	char book_writer[20];
	int book_price;
	int here;
	char borrow_book_man[20];
	struct book* next;
}*book1, * book2;

int creat_ka(struct student* head1, int n);
int add_book(struct book* head, int n);
int del_book(struct book* head, int n);
int del_ka(struct student* head, int n);
int search_book_1(struct book* head);
int search_book_2(struct book* head);
int search_book_3(struct book* head);
int search_ka_1(struct student* head);
int search_ka_2(struct student* head);
int search_ka_3(struct student* head);
int search_ka(struct student* head);
int search_book(struct book* head);
int borrow_book(struct student* head1, struct book* head2);
int back_book(struct student* head, struct book* head2);
void printf_book(struct book* head);
void printf_ka(struct student* head);
int change_1(struct book* head);
int change_2(struct student* head);

//主程序
void library()
{
	int a[5], i = 0, k = 0;
	struct student* s1;
	struct book* b1;
	FILE* fp1, * fp2;
	s1 = (struct student*)malloc(sizeof(struct student));
	b1 = (struct book*)malloc(sizeof(struct book));
	s1->next = NULL;
	b1->next = NULL;
	stu1 = s1;
	book1 = b1;
	stu2 = (struct student*)malloc(sizeof(struct student));
	book2 = (struct book*)malloc(sizeof(struct book));
	fp1 = fopen("ka.txt", "a+");
	fp2 = fopen("book.txt", "a+");
	while (fread(stu2, sizeof(struct student), 1, fp1) != 0)
	{
		stu2->next = NULL;
		stu1->next = stu2;
		stu1 = stu2;
		stu2 = (struct student*)malloc(sizeof(struct student));
		i++;
	}
	fclose(fp1);
	while (fread(book2, sizeof(struct book), 1, fp2) != 0)
	{
		book1->next = book2;
		book1 = book2;
		book2 = (struct book*)malloc(sizeof(struct book));
		k++;
	}
	fclose(fp2);
	printf("\t\t目前系统内已存储了：%d本书%d个借书证\n", k, i);
shuru_3:
	printf("\t********************第1级页面_超级图书管理系统******************\n");
	printf("【1】 借书\n【2】 还书\n【3】 图书查询\n【4】 借书证信息查询\n【5】 系统管理\n【0】 关闭系统\n");
	printf("请选择功能0-5:");
	scanf("%d", &a[0]);
	switch (a[0])
	{
	case 0:printf("\t**************[成功关闭系统]*****************");
		return;
	case 1:
		printf("\t***************第2级页面_借书系统**************\n");
		borrow_book(s1, b1); goto shuru_3;
	case 2:
		printf("\t***************第2级页面_还书系统**************\n");
		back_book(s1, b1); goto shuru_3;
	case 3:
		printf("\t***************第2级页面_图书查询**************\n");
		search_book(b1);
		goto shuru_3;
	case 4:
		printf("\t***************第2级页面_借书证信息查询**************\n");
		search_ka(s1); goto shuru_3;
	case 5:
	second_1:
		system("cls");
	second_11:
		printf("\t***************第2级页面_系统管理**************\n");
		printf("【1】 新办借书证\n【2】 注销借书证\n【3】 新增图书\n【4】 删除图书\n【5】 修改旧书信息\n【6】 显示书库中所有书籍\n【7】  显示所有借书证信息\n【0】 返回上一级\n");
		printf("请选择功能0-5:");
		scanf("%d", &a[1]);
		switch (a[1])
		{
		case 1:i = creat_ka(s1, i); goto second_11;
		case 2:i = del_ka(s1, i); goto second_11;
		case 3:k = add_book(b1, k); goto second_11;
		case 4:k = del_book(b1, k); goto second_11;
		case 5:change_1(b1); goto second_11;
		case 6:printf_book(b1); goto second_11;
		case 7:printf_ka(s1); goto second_11;
		case 8:change_2(s1); goto second_1;
		case 0:system("cls"); goto shuru_3;
		default:goto second_1;
		}
	default:printf("***********输入错误***************\n"); goto shuru_3;
	}
}

//创建卡，也就是新的借书证，有了新读者
int creat_ka(struct student* head1, int n)
{
	FILE* fp;
	int i;
	struct student* tail, * pnew;
	tail = head1;
	system("cls");
	for (i = 0; i < n; i++)
	{
		tail = tail->next;
	}
	pnew = (struct student*)malloc(sizeof(struct student));
	printf("输入新办的借书证号：");
	scanf("%s", &pnew->stu_num);
	printf("输入新的读者名：");
	scanf("%s", pnew->stu_name);
	strcpy(pnew->borrow_book, "无");
	pnew->next = NULL;
	tail->next = pnew;
	fp = fopen("ka.txt", "a");
	fwrite(pnew, sizeof(struct student), 1, fp);
	fclose(fp);
	system("cls");
	printf("***************************[操作成功]*****************************\n\n");
	return ++n;
}
//增加书
int add_book(struct book* head, int n)
{
	FILE* fp;
	struct book* tail, * pnew;
	int i;
	tail = head;
	system("cls");
	for (i = 0; i < n; i++)
	{
		tail = tail->next;
	}
	pnew = (struct book*)malloc(sizeof(struct book));
	printf("新书的书号:\n");
	scanf("%s", pnew->book_num);
	printf("新书的书名:\n");
	scanf("%s", pnew->book_name);
	printf("新书作者:\n");
	scanf("%s", pnew->book_writer);
	printf("单价:\n");
	scanf("%d", &pnew->book_price);
	printf("请你设定书的状态(1在架/0不在):\n");
	scanf("%d", &pnew->here);
	pnew->next = NULL;
	tail->next = pnew;
	fp = fopen("book.txt", "a");
	fwrite(pnew, sizeof(struct book), 1, fp);
	fclose(fp);
	printf("***************************[操作成功]*****************************\n\n");
	return ++n;
}
//删除书
int del_book(struct book* head, int n)
{
	FILE* fp;
	struct book* tail, * pnew1, * pnew2;
	char booknum[10];
	int i, j, biaozhi_1;
	tail = head->next;
	pnew1 = head;
	pnew2 = head->next;
	system("cls");
	printf("输入要删除的书的书号:\n");
	scanf("%s", booknum);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->book_num, booknum) == 0)
		{
			i++;
			biaozhi_1 = 0;
			break;
		}
		tail = tail->next;
	}
	if (biaozhi_1)
	{
		printf("不存在这个书号\n");
		return 0;
	}
	for (j = 1; j < i; j++)
	{
		pnew1 = pnew1->next;
	}
	pnew1->next = tail->next;
	free(tail);
	fp = fopen("book.txt", "w");
	if (pnew1->next)
	{
		while (pnew2->next);
		{
			fwrite(pnew2, sizeof(struct book), 1, fp);
			pnew2 = pnew2->next;
		}
	}
	else
	{
		fwrite(NULL, 0, 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("***************************[操作成功]*****************************\n\n");
	return --n;
}
//注销借书证
int del_ka(struct student* head, int n)
{
	FILE* fp;
	struct student* tail, * pnew1, * pnew2;
	char ka_num[10];
	int i, j, biaozhi_2;
	tail = head->next;
	pnew1 = head;
	pnew2 = head->next;
	system("cls");
	printf("要删除的卡号:\n");
	scanf("%s", ka_num);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->stu_num, ka_num) == 0)
		{
			i++;
			biaozhi_2 = 0;
			break;
		}
		tail = tail->next;
	}
	if (biaozhi_2)
	{
		printf("不存在这个卡号\n");
		return 0;
	}
	for (j = 1; j < i; j++)
	{
		pnew1 = pnew1->next;
	}
	pnew1->next = tail->next;
	free(tail);
	fp = fopen("ka.txt", "w");
	if (pnew1->next)
	{
		while (pnew2->next);
		{
			fwrite(pnew2, sizeof(struct student), 1, fp);
			pnew2 = pnew2->next;
		}
	}
	else
	{
		fwrite(NULL, 0, 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("***************************[操作成功]*****************************\n\n");
	return --n;
}
//按照书名搜索书籍信息
int search_book_1(struct book* head)
{
	int i;
	char bookname[50];
	struct book* tail;
	tail = head->next;
	system("cls");
	printf("请输入要找的书的书名：");
	scanf("%s", bookname);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->book_name, bookname) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("书籍库为空\n");
	}
	else
	{
		if (tail == 0)
		{
			printf("书库中没有该书\n");
			return 0;
		}
	}
	system("cls");
	printf("书号：%s  书名：%s  价格：%d元  状态：", tail->book_num, tail->book_name, tail->book_price);
	if (tail->here == 0)
	{
		printf("不在\n");
	}
	else
		printf("在架\n");
	printf("\n");
	printf("***************************[操作成功]*****************************\n\n");
	return 0;
}
//按照作者名字搜索书籍信息
//可以搜索同一作者的所有书籍
int search_book_2(struct book* head)
{
	int i = 0, xunhuan;
	char writername[50];
	struct book* tail;
	tail = head->next;
	system("cls");
	printf("请输入作者姓名：");
	scanf("%s", writername);
	for (xunhuan = 0; tail != 0; xunhuan++)
	{
		for (; tail != 0; i++)
		{
			if (strcmp(tail->book_writer, writername) == 0)
			{
				i++;
				break;
			}
			tail = tail->next;
		}
		if (i == 0)
		{
			printf("书籍库为空\n");
			return 0;
		}
		else
		{
			if ((tail == 0) && (xunhuan == 0))
			{
				printf("书库中没有该作者的书\n");
				return 0;
			}
		}
		if (xunhuan == 0)
		{
			system("cls");
		}
		printf("作者：%s  书号：%s  书名：%s  价格：%d元  状态：", tail->book_writer, tail->book_num, tail->book_name, tail->book_price);
		if (tail->here == 0)
		{
			printf("不在\n");
		}
		else
		{
			printf("在架\n");
		}
		tail = tail->next;
	}
	printf("***************************[操作成功]*****************************\n\n");
	return 0;
}
//按照书的书号搜书
int search_book_3(struct book* head)
{
	int i;
	char booknum[10];
	struct book* tail;
	tail = head->next;
	system("cls");
	printf("请输入要找的书号：");
	scanf("%s", booknum);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->book_num, booknum) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("书籍库为空");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("书库中没有该书");
			return 0;
		}
	}
	system("cls");
	printf("书号：%s  书名：%s  价格：%d元  状态：", tail->book_num, tail->book_name, tail->book_price);
	if (tail->here == 0)
	{
		printf("不在，借书人：%s \n", tail->borrow_book_man);
	}
	else
		printf("在架\n");
	printf("***************************[操作成功]*****************************\n\n");
	return 0;
}
//根据借书证号找读者信息
int search_ka_1(struct student* head)
{
	int i;
	char kanum[10];
	struct student* tail;
	tail = head->next;
	system("cls");
	printf("请输入要找的书证号：");
	scanf("%s", kanum);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->stu_num, kanum) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("系统中借书证信息为空\n");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("系统中没有该借书证\n");
			return 0;
		}
	}
	system("cls");
	printf("读者借书证号：%s 读者姓名：%s  所借书籍：%s", tail->stu_num, tail->stu_name, tail->borrow_book);
	printf("\n***************************[操作成功]*****************************\n\n");
	return 0;
}
//根据读者姓名找读者信息
int search_ka_2(struct student* head)
{
	int i;
	char studentname[50];
	struct student* tail;
	tail = head->next;
	system("cls");
	printf("请输入读者姓名：");
	scanf("%s", studentname);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->stu_name, studentname) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("系统中借书证信息为空\n");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("系统中没有该借书证\n");
			return 0;
		}
	}
	system("cls");
	printf("读者借书证号：%s 读者姓名：%s  所借书籍：%s", tail->stu_num, tail->stu_name, tail->borrow_book);
	printf("\n***************************[操作成功]*****************************\n\n");
	return 0;
}
//根据所借书籍找读者信息
int search_ka_3(struct student* head)
{
	int i;
	char borrow_book_name[50];
	struct student* tail;
	tail = head->next;
	system("cls");
	printf("请输入书籍名：");
	scanf("%s", borrow_book_name);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->borrow_book, borrow_book_name) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("系统中借书证信息为空\n");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("系统中没有该借书证\n");
			return 0;
		}
	}
	system("cls");
	printf("读者借书证号：%s 读者姓名：%s  所借书籍：%s", tail->stu_num, tail->stu_name, tail->borrow_book);
	printf("\n***************************[操作成功]*****************************\n\n");
	return 0;
}

//搜借书证的开始的程序
int search_ka(struct student* head)
{
	int k;
	system("cls");
	printf("1 按借书证号查找\n2 按读者名字查找\n3 按所借书籍查找\n0 返回上一层\n");
shuru_2:
	printf("请选择功能0-3：");
	scanf("%d", &k);
	printf("**********************************\n");
	switch (k)
	{
	case 1:search_ka_1(head); break;
	case 2:search_ka_2(head); break;
	case 3:search_ka_3(head); break;
	case 0:
		system("cls");
		printf("****************[操作成功]********************\n\n");
		return 0;
	default:
		printf("输入错误，"); goto shuru_2;
	}
	return 0;
}
//搜书的开始程序
int search_book(struct book* head)
{
	int k;
	system("cls");
	printf("1 按书名查找\n2 按作者查找\n3 按书号查找\n0 返回上一层\n");
shuru_2:
	printf("请选择功能0-3：");
	scanf("%d", &k);
	printf("**********************************\n");
	switch (k)
	{
	case 1:search_book_1(head); break;
	case 2:search_book_2(head); break;
	case 3:search_book_3(head); break;
	case 0:
		system("cls");
		printf("****************[操作成功]********************\n\n");
		return 0;
	default:
		printf("输入错误，"); goto shuru_2;
	}
	return 0;
}
//借书
int borrow_book(struct student* head1, struct book* head2)
{
	FILE* fp, * fp2;
	struct student* tail, * pnew;
	struct book* tail_2, * pnew_2;
	int i, j;//biaozhi_4;
	char student_num[10];
	char borrow_num[10];
	system("cls");
	tail = head1->next;
	tail_2 = head2->next;
	pnew = head1->next;
	pnew_2 = head2->next;
	printf("请输入借书证号：");
	scanf("%s", student_num);
	for (i = 0; tail != 0; i++)//根据借书证号找到该学生
	{
		if (strcmp(tail->stu_num, student_num) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("系统中没有该借书证号。\n");
		return 0;
	}
	if (strcmp(tail->borrow_book, "无"))//如果借了书
	{
		printf("该读者仍未还书，无法借书。\n");
		return 0;
	}
	printf("请输入书号：");
	scanf("%s", borrow_num);
	for (j = 0; tail_2 != 0; j++)//根据书号找到该书籍
	{
		if (strcmp(tail_2->book_num, borrow_num) == 0)
		{
			j++;
			break;
		}
		tail_2 = tail_2->next;
	}
	if (j == 0)
	{
		printf("书库中不存在该书。\n");
		return 0;
	}
	if (tail_2->here == 0)
	{
		printf("该书不在架，已经外借\n");
		return 0;
	}
	strcpy(tail->borrow_book, tail_2->book_name);
	tail_2->here = 0;
	strcpy(tail_2->borrow_book_man, tail->stu_name);
	fp = fopen("ka.txt", "w");
	while (pnew->next)
	{
		fwrite(pnew, sizeof(struct student), 1, fp);
		pnew = pnew->next;
	}
	fclose(fp);
	fp2 = fopen("book.txt", "w");
	while (pnew_2->next)
	{
		fwrite(pnew_2, sizeof(struct book), 1, fp2);
		pnew_2 = pnew_2->next;
	}
	fclose(fp2);
	system("cls");
	printf("***************************[操作成功]*****************************\n\n");
	return 0;
}
//还书
int back_book(struct student* head, struct book* head2)
{
	FILE* fp, * fp2;
	struct student* tail, * pnew;
	struct book* tail_2, * pnew_2;
	int i;
	int chose;
	char kanum[10];
	system("cls");
	tail = head->next;
	tail_2 = head2->next;
	pnew = head->next;
	pnew_2 = head2->next;
	printf("请输入卡号:");
	scanf("%s", kanum);
	for (i = 0; tail != 0; i++)//根据卡号找到该学生
	{
		if (strcmp(tail->stu_num, kanum) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("系统中没有该借书证号。\n");
		return 0;
	}
	if (strcmp(tail->borrow_book, "无"))//如果借了书
	{
	fanhui_1:
		printf("借的书是：%s\n", tail->borrow_book);
		printf("确认归还该书？\n（1  确认   0 取消）");
		scanf("%d", &chose);
		switch (chose)
		{
		case 1:
			while (strcmp(tail->borrow_book, tail_2->book_name))//根据学生借的书找到该书
			{
				tail_2 = tail_2->next;
			}
			tail_2->here = 1;//更改书的状态
			strcpy(tail_2->borrow_book_man, "");
			strcpy(tail->borrow_book, "");
			break;
		case 0:return 0;
		default:printf("请输入1或0\n"); goto fanhui_1;
		}
	}
	else
	{
		printf("该读者还没借书\n");
		return 0;
	}
	fp = fopen("ka.txt", "w");
	fp2 = fopen("book.txt", "w");

	while (pnew->next)
	{
		fwrite(pnew, sizeof(struct student), 1, fp);
		pnew = pnew->next;
	}
	while (pnew_2)
	{
		fwrite(pnew_2, sizeof(struct book), 1, fp2);
		pnew_2 = pnew_2->next;
	}
	fclose(fp);
	fclose(fp2);
	system("cls");
	printf("***************************[操作成功]*****************************\n\n");
	return 0;
}
//显示书库中的所有书籍
void printf_book(struct book* head)
{
	struct book* tail;//*pnew;
	int i;
	tail = head->next;
	system("cls");
	for (i = 1; tail != 0; i++)
	{
		printf("第%d本书是：\n", i);
		printf("书号：%s  书名：%s  作者：%s  单价：%d元  状态：", tail->book_num, tail->book_name, tail->book_writer, tail->book_price);
		if (tail->here == 0)
			printf("不在，借书人为：%s", tail->borrow_book_man);
		else
			printf("在");
		printf("\n");
		tail = tail->next;
	}
	if (i == 1)
	{
		printf("*****************书库为空*******************\n");
	}
	printf("***************************[操作成功]*****************************\n\n");
}
//显示所有读者信息
void printf_ka(struct student* head)
{
	struct student* tail;//*pnew;
	int i;
	tail = head->next;
	system("cls");
	for (i = 1; tail != 0; i++)
	{
		printf("第%d个读者是：\n", i);
		printf("借书证号：%s  姓名：%s  所借书籍：%s\n", tail->stu_num, tail->stu_name, tail->borrow_book);
		tail = tail->next;
	}
	if (i == 1)
	{
		printf("*****************借书证存储系统为空*******************\n");
	}
	printf("***************************[操作成功]*****************************\n\n");
}
//修改书籍信息的程序
int change_1(struct book* head)
{
	FILE* fp;
	struct book* tail, * pnew;
	struct book* new_change;
	char booknum[20];
	int i, chose;
	system("cls");
	new_change = (struct book*)malloc(sizeof(struct book));
	tail = head->next;
	pnew = head->next;
	printf("请输入要修改的书的书号:");
	scanf("%s", booknum);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->book_num, booknum) == 0)
		{
			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("书库为空\n");
		return 0;
	}
	if (tail == 0)
	{
		printf("书库中不存在该书\n");
		return  0;
	}
	printf("书籍原信息为：\n");
	printf("书号：%s  书名：%s  作者：%s  单价：%d元  状态：", tail->book_num, tail->book_name, tail->book_writer, tail->book_price);
	if (tail->here == 0)
	{
		printf("不在,借书人为：%s", tail->borrow_book_man);
	}
	else
	{
		printf("在");
	}
shuru_9:
	printf("\n1 修改书号\n2 修改书名\n3 修改作者\n4 修改单价\n5 修改状态\n6 修改借书人\n0 取消，返回上一级\n");
	scanf("%d", &chose);
	switch (chose)
	{
	case 1:
		printf("请输入新书号：");
		scanf("%s", new_change->book_num);
		strcpy(tail->book_num, new_change->book_num);
		break;
	case 2:
		printf("请输入新书名：");
		scanf("%s", new_change->book_name);
		strcpy(tail->book_name, new_change->book_name);
		break;
	case 3:
		printf("请输入新作者：");
		scanf("%s", new_change->book_writer);
		strcpy(tail->book_writer, new_change->book_writer);
		break;
	case 4:
		printf("请输入新单价：");
		scanf("%d", &new_change->book_price);
		tail->book_price = new_change->book_price;
		break;
	case 5:
		printf("请输入新状态（1 在架；2 不在）：");
		scanf("%d", &new_change->here);
		tail->here = new_change->here;
		break;
	case 6:
		printf("请输入新的借书人：");
		scanf("%s", new_change->borrow_book_man);
		strcpy(tail->borrow_book_man, new_change->borrow_book_man);
		break;
	case 0:return 0;
	default:printf("输入错误，请重新输入。\n"); goto shuru_9;
	}
	free(new_change);
	fp = fopen("book.txt", "w");
	while (pnew)
	{
		fwrite(pnew, sizeof(struct book), 1, fp);
		pnew = pnew->next;
	}
	fclose(fp);
	system("cls");
	printf("***************************[操作成功]*****************************\n\n");
	return 0;
}
//修改借书证信息的程序
int change_2(struct student* head)
{
	FILE* fp;
	struct student* tail, * pnew;
	struct student* new_change;
	char studentnum[10];
	int i, chose;
	system("cls");
	tail = head->next;
	pnew = head->next;
	printf("请输入要修改的借书证的证号:");
	scanf("%s", studentnum);
	for (i = 0; tail != 0; i++)
	{
		if (strcmp(tail->stu_num, studentnum) == 0)
		{

			i++;
			break;
		}
		tail = tail->next;
	}
	if (i == 0)
	{
		printf("借书证信息为空\n");
		return 0;
	}
	if (tail->next == 0)
	{
		printf("系统中不存在该借书证\n");
		return  0;
	}
	printf("读者原信息为：\n");
	printf("借书证号：%s  姓名：%s  所借书籍：%s", tail->stu_num, tail->stu_name, tail->borrow_book);
shuru_8:
	printf("\n1 修改借书证号\n2 修改读者姓名\n3 修改所借书籍\n0 取消\n");
	scanf("%d", &chose);
	new_change = (struct student*)malloc(sizeof(struct student));
	switch (chose)
	{
	case 1:printf("请输入新借书证号："); scanf("%s", new_change->stu_num); strcpy(tail->stu_num, new_change->stu_num); break;
	case 2:printf("请输入新读者姓名："); scanf("%s", new_change->stu_name); strcpy(tail->stu_num, new_change->stu_num); break;
	case 3:printf("请输入新所借书籍："); scanf("%s", new_change->borrow_book); strcpy(tail->borrow_book, new_change->borrow_book); break;
	case 0:return 0;
	default:printf("输入错误，请重新输入。\n"); goto shuru_8;
	}
	free(new_change);
	fp = fopen("ka.txt", "w");
	while (pnew)
	{
		fwrite(pnew, sizeof(struct student), 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("***************************[操作成功]*****************************\n\n");
	return 0;
}