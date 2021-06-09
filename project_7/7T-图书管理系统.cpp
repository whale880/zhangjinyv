#include"practice7.h"

//����֤��Ϣ
struct student
{
	char stu_num[10];
	char stu_name[20];
	char borrow_book[50];
	struct student* next;
}*stu1, * stu2;
//�鼮��Ϣ
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

//������
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
	printf("\t\tĿǰϵͳ���Ѵ洢�ˣ�%d����%d������֤\n", k, i);
shuru_3:
	printf("\t********************��1��ҳ��_����ͼ�����ϵͳ******************\n");
	printf("��1�� ����\n��2�� ����\n��3�� ͼ���ѯ\n��4�� ����֤��Ϣ��ѯ\n��5�� ϵͳ����\n��0�� �ر�ϵͳ\n");
	printf("��ѡ����0-5:");
	scanf("%d", &a[0]);
	switch (a[0])
	{
	case 0:printf("\t**************[�ɹ��ر�ϵͳ]*****************");
		return;
	case 1:
		printf("\t***************��2��ҳ��_����ϵͳ**************\n");
		borrow_book(s1, b1); goto shuru_3;
	case 2:
		printf("\t***************��2��ҳ��_����ϵͳ**************\n");
		back_book(s1, b1); goto shuru_3;
	case 3:
		printf("\t***************��2��ҳ��_ͼ���ѯ**************\n");
		search_book(b1);
		goto shuru_3;
	case 4:
		printf("\t***************��2��ҳ��_����֤��Ϣ��ѯ**************\n");
		search_ka(s1); goto shuru_3;
	case 5:
	second_1:
		system("cls");
	second_11:
		printf("\t***************��2��ҳ��_ϵͳ����**************\n");
		printf("��1�� �°����֤\n��2�� ע������֤\n��3�� ����ͼ��\n��4�� ɾ��ͼ��\n��5�� �޸ľ�����Ϣ\n��6�� ��ʾ����������鼮\n��7��  ��ʾ���н���֤��Ϣ\n��0�� ������һ��\n");
		printf("��ѡ����0-5:");
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
	default:printf("***********�������***************\n"); goto shuru_3;
	}
}

//��������Ҳ�����µĽ���֤�������¶���
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
	printf("�����°�Ľ���֤�ţ�");
	scanf("%s", &pnew->stu_num);
	printf("�����µĶ�������");
	scanf("%s", pnew->stu_name);
	strcpy(pnew->borrow_book, "��");
	pnew->next = NULL;
	tail->next = pnew;
	fp = fopen("ka.txt", "a");
	fwrite(pnew, sizeof(struct student), 1, fp);
	fclose(fp);
	system("cls");
	printf("***************************[�����ɹ�]*****************************\n\n");
	return ++n;
}
//������
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
	printf("��������:\n");
	scanf("%s", pnew->book_num);
	printf("���������:\n");
	scanf("%s", pnew->book_name);
	printf("��������:\n");
	scanf("%s", pnew->book_writer);
	printf("����:\n");
	scanf("%d", &pnew->book_price);
	printf("�����趨���״̬(1�ڼ�/0����):\n");
	scanf("%d", &pnew->here);
	pnew->next = NULL;
	tail->next = pnew;
	fp = fopen("book.txt", "a");
	fwrite(pnew, sizeof(struct book), 1, fp);
	fclose(fp);
	printf("***************************[�����ɹ�]*****************************\n\n");
	return ++n;
}
//ɾ����
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
	printf("����Ҫɾ����������:\n");
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
		printf("������������\n");
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
	printf("***************************[�����ɹ�]*****************************\n\n");
	return --n;
}
//ע������֤
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
	printf("Ҫɾ���Ŀ���:\n");
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
		printf("�������������\n");
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
	printf("***************************[�����ɹ�]*****************************\n\n");
	return --n;
}
//�������������鼮��Ϣ
int search_book_1(struct book* head)
{
	int i;
	char bookname[50];
	struct book* tail;
	tail = head->next;
	system("cls");
	printf("������Ҫ�ҵ����������");
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
		printf("�鼮��Ϊ��\n");
	}
	else
	{
		if (tail == 0)
		{
			printf("�����û�и���\n");
			return 0;
		}
	}
	system("cls");
	printf("��ţ�%s  ������%s  �۸�%dԪ  ״̬��", tail->book_num, tail->book_name, tail->book_price);
	if (tail->here == 0)
	{
		printf("����\n");
	}
	else
		printf("�ڼ�\n");
	printf("\n");
	printf("***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//�����������������鼮��Ϣ
//��������ͬһ���ߵ������鼮
int search_book_2(struct book* head)
{
	int i = 0, xunhuan;
	char writername[50];
	struct book* tail;
	tail = head->next;
	system("cls");
	printf("����������������");
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
			printf("�鼮��Ϊ��\n");
			return 0;
		}
		else
		{
			if ((tail == 0) && (xunhuan == 0))
			{
				printf("�����û�и����ߵ���\n");
				return 0;
			}
		}
		if (xunhuan == 0)
		{
			system("cls");
		}
		printf("���ߣ�%s  ��ţ�%s  ������%s  �۸�%dԪ  ״̬��", tail->book_writer, tail->book_num, tail->book_name, tail->book_price);
		if (tail->here == 0)
		{
			printf("����\n");
		}
		else
		{
			printf("�ڼ�\n");
		}
		tail = tail->next;
	}
	printf("***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//��������������
int search_book_3(struct book* head)
{
	int i;
	char booknum[10];
	struct book* tail;
	tail = head->next;
	system("cls");
	printf("������Ҫ�ҵ���ţ�");
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
		printf("�鼮��Ϊ��");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("�����û�и���");
			return 0;
		}
	}
	system("cls");
	printf("��ţ�%s  ������%s  �۸�%dԪ  ״̬��", tail->book_num, tail->book_name, tail->book_price);
	if (tail->here == 0)
	{
		printf("���ڣ������ˣ�%s \n", tail->borrow_book_man);
	}
	else
		printf("�ڼ�\n");
	printf("***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//���ݽ���֤���Ҷ�����Ϣ
int search_ka_1(struct student* head)
{
	int i;
	char kanum[10];
	struct student* tail;
	tail = head->next;
	system("cls");
	printf("������Ҫ�ҵ���֤�ţ�");
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
		printf("ϵͳ�н���֤��ϢΪ��\n");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("ϵͳ��û�иý���֤\n");
			return 0;
		}
	}
	system("cls");
	printf("���߽���֤�ţ�%s ����������%s  �����鼮��%s", tail->stu_num, tail->stu_name, tail->borrow_book);
	printf("\n***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//���ݶ��������Ҷ�����Ϣ
int search_ka_2(struct student* head)
{
	int i;
	char studentname[50];
	struct student* tail;
	tail = head->next;
	system("cls");
	printf("���������������");
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
		printf("ϵͳ�н���֤��ϢΪ��\n");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("ϵͳ��û�иý���֤\n");
			return 0;
		}
	}
	system("cls");
	printf("���߽���֤�ţ�%s ����������%s  �����鼮��%s", tail->stu_num, tail->stu_name, tail->borrow_book);
	printf("\n***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//���������鼮�Ҷ�����Ϣ
int search_ka_3(struct student* head)
{
	int i;
	char borrow_book_name[50];
	struct student* tail;
	tail = head->next;
	system("cls");
	printf("�������鼮����");
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
		printf("ϵͳ�н���֤��ϢΪ��\n");
		return 0;
	}
	else
	{
		if (tail == 0)
		{
			printf("ϵͳ��û�иý���֤\n");
			return 0;
		}
	}
	system("cls");
	printf("���߽���֤�ţ�%s ����������%s  �����鼮��%s", tail->stu_num, tail->stu_name, tail->borrow_book);
	printf("\n***************************[�����ɹ�]*****************************\n\n");
	return 0;
}

//�ѽ���֤�Ŀ�ʼ�ĳ���
int search_ka(struct student* head)
{
	int k;
	system("cls");
	printf("1 ������֤�Ų���\n2 ���������ֲ���\n3 �������鼮����\n0 ������һ��\n");
shuru_2:
	printf("��ѡ����0-3��");
	scanf("%d", &k);
	printf("**********************************\n");
	switch (k)
	{
	case 1:search_ka_1(head); break;
	case 2:search_ka_2(head); break;
	case 3:search_ka_3(head); break;
	case 0:
		system("cls");
		printf("****************[�����ɹ�]********************\n\n");
		return 0;
	default:
		printf("�������"); goto shuru_2;
	}
	return 0;
}
//����Ŀ�ʼ����
int search_book(struct book* head)
{
	int k;
	system("cls");
	printf("1 ����������\n2 �����߲���\n3 ����Ų���\n0 ������һ��\n");
shuru_2:
	printf("��ѡ����0-3��");
	scanf("%d", &k);
	printf("**********************************\n");
	switch (k)
	{
	case 1:search_book_1(head); break;
	case 2:search_book_2(head); break;
	case 3:search_book_3(head); break;
	case 0:
		system("cls");
		printf("****************[�����ɹ�]********************\n\n");
		return 0;
	default:
		printf("�������"); goto shuru_2;
	}
	return 0;
}
//����
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
	printf("���������֤�ţ�");
	scanf("%s", student_num);
	for (i = 0; tail != 0; i++)//���ݽ���֤���ҵ���ѧ��
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
		printf("ϵͳ��û�иý���֤�š�\n");
		return 0;
	}
	if (strcmp(tail->borrow_book, "��"))//���������
	{
		printf("�ö�����δ���飬�޷����顣\n");
		return 0;
	}
	printf("��������ţ�");
	scanf("%s", borrow_num);
	for (j = 0; tail_2 != 0; j++)//��������ҵ����鼮
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
		printf("����в����ڸ��顣\n");
		return 0;
	}
	if (tail_2->here == 0)
	{
		printf("���鲻�ڼܣ��Ѿ����\n");
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
	printf("***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//����
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
	printf("�����뿨��:");
	scanf("%s", kanum);
	for (i = 0; tail != 0; i++)//���ݿ����ҵ���ѧ��
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
		printf("ϵͳ��û�иý���֤�š�\n");
		return 0;
	}
	if (strcmp(tail->borrow_book, "��"))//���������
	{
	fanhui_1:
		printf("������ǣ�%s\n", tail->borrow_book);
		printf("ȷ�Ϲ黹���飿\n��1  ȷ��   0 ȡ����");
		scanf("%d", &chose);
		switch (chose)
		{
		case 1:
			while (strcmp(tail->borrow_book, tail_2->book_name))//����ѧ��������ҵ�����
			{
				tail_2 = tail_2->next;
			}
			tail_2->here = 1;//�������״̬
			strcpy(tail_2->borrow_book_man, "");
			strcpy(tail->borrow_book, "");
			break;
		case 0:return 0;
		default:printf("������1��0\n"); goto fanhui_1;
		}
	}
	else
	{
		printf("�ö��߻�û����\n");
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
	printf("***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//��ʾ����е������鼮
void printf_book(struct book* head)
{
	struct book* tail;//*pnew;
	int i;
	tail = head->next;
	system("cls");
	for (i = 1; tail != 0; i++)
	{
		printf("��%d�����ǣ�\n", i);
		printf("��ţ�%s  ������%s  ���ߣ�%s  ���ۣ�%dԪ  ״̬��", tail->book_num, tail->book_name, tail->book_writer, tail->book_price);
		if (tail->here == 0)
			printf("���ڣ�������Ϊ��%s", tail->borrow_book_man);
		else
			printf("��");
		printf("\n");
		tail = tail->next;
	}
	if (i == 1)
	{
		printf("*****************���Ϊ��*******************\n");
	}
	printf("***************************[�����ɹ�]*****************************\n\n");
}
//��ʾ���ж�����Ϣ
void printf_ka(struct student* head)
{
	struct student* tail;//*pnew;
	int i;
	tail = head->next;
	system("cls");
	for (i = 1; tail != 0; i++)
	{
		printf("��%d�������ǣ�\n", i);
		printf("����֤�ţ�%s  ������%s  �����鼮��%s\n", tail->stu_num, tail->stu_name, tail->borrow_book);
		tail = tail->next;
	}
	if (i == 1)
	{
		printf("*****************����֤�洢ϵͳΪ��*******************\n");
	}
	printf("***************************[�����ɹ�]*****************************\n\n");
}
//�޸��鼮��Ϣ�ĳ���
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
	printf("������Ҫ�޸ĵ�������:");
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
		printf("���Ϊ��\n");
		return 0;
	}
	if (tail == 0)
	{
		printf("����в����ڸ���\n");
		return  0;
	}
	printf("�鼮ԭ��ϢΪ��\n");
	printf("��ţ�%s  ������%s  ���ߣ�%s  ���ۣ�%dԪ  ״̬��", tail->book_num, tail->book_name, tail->book_writer, tail->book_price);
	if (tail->here == 0)
	{
		printf("����,������Ϊ��%s", tail->borrow_book_man);
	}
	else
	{
		printf("��");
	}
shuru_9:
	printf("\n1 �޸����\n2 �޸�����\n3 �޸�����\n4 �޸ĵ���\n5 �޸�״̬\n6 �޸Ľ�����\n0 ȡ����������һ��\n");
	scanf("%d", &chose);
	switch (chose)
	{
	case 1:
		printf("����������ţ�");
		scanf("%s", new_change->book_num);
		strcpy(tail->book_num, new_change->book_num);
		break;
	case 2:
		printf("��������������");
		scanf("%s", new_change->book_name);
		strcpy(tail->book_name, new_change->book_name);
		break;
	case 3:
		printf("�����������ߣ�");
		scanf("%s", new_change->book_writer);
		strcpy(tail->book_writer, new_change->book_writer);
		break;
	case 4:
		printf("�������µ��ۣ�");
		scanf("%d", &new_change->book_price);
		tail->book_price = new_change->book_price;
		break;
	case 5:
		printf("��������״̬��1 �ڼܣ�2 ���ڣ���");
		scanf("%d", &new_change->here);
		tail->here = new_change->here;
		break;
	case 6:
		printf("�������µĽ����ˣ�");
		scanf("%s", new_change->borrow_book_man);
		strcpy(tail->borrow_book_man, new_change->borrow_book_man);
		break;
	case 0:return 0;
	default:printf("����������������롣\n"); goto shuru_9;
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
	printf("***************************[�����ɹ�]*****************************\n\n");
	return 0;
}
//�޸Ľ���֤��Ϣ�ĳ���
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
	printf("������Ҫ�޸ĵĽ���֤��֤��:");
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
		printf("����֤��ϢΪ��\n");
		return 0;
	}
	if (tail->next == 0)
	{
		printf("ϵͳ�в����ڸý���֤\n");
		return  0;
	}
	printf("����ԭ��ϢΪ��\n");
	printf("����֤�ţ�%s  ������%s  �����鼮��%s", tail->stu_num, tail->stu_name, tail->borrow_book);
shuru_8:
	printf("\n1 �޸Ľ���֤��\n2 �޸Ķ�������\n3 �޸������鼮\n0 ȡ��\n");
	scanf("%d", &chose);
	new_change = (struct student*)malloc(sizeof(struct student));
	switch (chose)
	{
	case 1:printf("�������½���֤�ţ�"); scanf("%s", new_change->stu_num); strcpy(tail->stu_num, new_change->stu_num); break;
	case 2:printf("�������¶���������"); scanf("%s", new_change->stu_name); strcpy(tail->stu_num, new_change->stu_num); break;
	case 3:printf("�������������鼮��"); scanf("%s", new_change->borrow_book); strcpy(tail->borrow_book, new_change->borrow_book); break;
	case 0:return 0;
	default:printf("����������������롣\n"); goto shuru_8;
	}
	free(new_change);
	fp = fopen("ka.txt", "w");
	while (pnew)
	{
		fwrite(pnew, sizeof(struct student), 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("***************************[�����ɹ�]*****************************\n\n");
	return 0;
}