#include"practice6.h"

#define N 10

typedef struct cust
{
	char ID[N + 1];
	struct cust* next;
}customer;

void queue()
{
	char c;
	customer* p = NULL, * tmp = NULL, * head = NULL;
	do
	{
		printf("������ͻ�id�ţ�������10���ַ�����");
		tmp = (customer*)malloc(sizeof(customer));
		tmp->next = NULL;
		scanf("%s", tmp->ID);
		if (p == NULL)
		{
			p = tmp;
			head = p;
		}
		else
		{
			p->next = tmp;
			p = tmp;
		}
		printf("\n����q�˳������������������");
		fflush(stdin);
		c = getchar();
		printf("\n");
	} while (c != 'q' && c != 'Q');
	p = head;
	do
	{
		printf("%s\n", p->ID);
		p = p->next;
	} while (p != NULL);
}