#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#define HEIGHT  20  //�궨���ͼ�߶�
#define WIDTH   40  //�궨���ͼ���
#define PRINTF  printf("��");//��Ϊ��ͼ�ı߽���������ÿһ��
#define LINE    printf("\n");//���廻�����
#define EMPTY   printf("  ");//����ո����
#define IMAX 5//��ʼ������
typedef struct Snakebody
{
	int x, y;//���������
	struct Snakebody* next;//�ṹ��ָ��
}Snakebody;//���������������������̰���ߵĺ��Ĵ�����Ǹ���α����ߵ�����
typedef struct Snakefood
{
	int x;//ʳ��ĺ�����
	int y;//ʳ���������
}foodxy; //��¼ʳ������
int sum = 0;     //�������ĵ÷�
int JudgeSum = 0;    //�ж��Ƿ�ӿ�
int Hard = 0;     //�����Ѷ�
int Pause = 200;   //��ͣ�ٶ�(�ƶ��ٶ�)
int JudgeDirection = 4;   //��ʼ������ķ���Ϊ��
Snakebody* Phead = NULL;  //�洢���������� ���ɸ���
Snakebody* Phead_1 = NULL;  //ָ������
Snakebody* Pbody = NULL;  //�����ڵ�
Snakebody* end = NULL;   //β�ڵ�
foodxy* Food = NULL;          //����ʳ��λ��
void Front();                   //��Ϸ��ʼҳ��1
void Jfood();     //����Ƿ�Ե�ʳ��1
int Jwall();     //�����ͷ�Ƿ�ײǽ1
int Jsnake();     //�����ͷ�Ƿ�ײ������1
void ISnake();     //��ʼ������1
void DrewMap();     //���Ƶ�ͼ1
void FoodRand();    //����ʳ��1
void ControlMove();    //�����ƶ�����ͣ1
void MoveCursor(int x, int y); //�����ƶ����1
void Move();     //��Ϸ����1
void Showf();                   //��ʾ�����Լ��Ѷ�1
void snake();
//void Free();//�ͷ��ڴ�
void snake()
{
	Front();//ģ����Ϸ���ؽ���
	DrewMap();//���Ƶ�ͼ�߽�
	Showf();//��ʾ�÷ֺ��Ѷ�
	/*MoveCursor(34, 10);
	printf("��");
	MoveCursor(31, 11);//���ó�ʼ���λ��
	printf("ʹ�á�����������");
	MoveCursor(31, 12);
	printf("�ߵ��ƶ���ײǽ��");
	*/
	MoveCursor(31, 10);
	printf("Ϸ������ÿ5���� ");
	MoveCursor(31, 14);
	printf("һ���Ѷ�(�ٶ�)");
	ISnake();//��ʼ������
	FoodRand();//��ʼ��ʳ��
	MoveCursor(40, 20);
	Move();//��Ϸ���н���Ļ���
	return;
}
void Front()//��һ��ҳ��Ļ���(��Ϸ��ʼ����)(ģ����Ϸ���ؽ���)
{
	MoveCursor(15, 8);
	printf(" ̰ �� �� ");
	MoveCursor(18, 15);
	printf("��Ϸ�����У����Ժ�......");
	Sleep(3000);
	/*for (int i = 0; i <= 1000000000; i++) {} */ //��һ��ҳ�����ͣ
	system("cls");
}
void DrewMap()    //��ͼ�Ļ���
{
	for (int i = 1; i <= WIDTH / 2; i++) //���
	{
		printf("\n");//ÿ�δ�ӡǰ����
		for (int j = 1; j <= HEIGHT; j++)//����
		{
			if (j == 1 || i == 1 || i == WIDTH / 2 || j == HEIGHT)
			{
				PRINTF//��ӡ�߿�
			}
			else EMPTY//��ӡ�ո�
		}
	}
}
void MoveCursor(int x, int y)//���ù��λ��(���������ʾ�Ŀ�ʼλ��)
{
	/*  COORD��Windows API�ж����һ�ֽṹ��
	* typedef struct _COORD
	* {
	* SHORT X;
	* SHORT Y;
	* } COORD;
	*  */
	COORD pos = { x * 2,y };//��Ϊ2�еľ�����Ϊһ����λ�����á��Ϳ����γ�һ����õ�map����ռ2����λ
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);//��ñ�׼����ľ��   
	SetConsoleCursorPosition(output, pos); //���ÿ���̨���λ��
}
void FoodRand()//����ʳ��1
{
	srand((int)time(0)); //���������Ӻ͵�ǰ��ʱ��
	int x = rand() % 8 + 2;//����food������ֵĺ�����(�������һ��2-8������)
	int y = rand() % 8 + 2;//����food������ֵ�������
	Phead_1 = Phead;//phead_1ָ�������ͷ
	for (int i = 0; i <= 200; i++)//����������������Ƿ���������ʳ������
	{
		if (Phead_1->x == x && Phead_1->y == y)//���������ʳ�����������������ˢ��ʳ��
		{
			x = rand() % 8 + 2;
			y = rand() % 8 + 2;
		}
		else
		{
			Phead_1 = Phead_1->next;//����ָ����һ��
		}
		if (Phead_1->next == NULL)
		{
			break;//����Ϊ�ռ���β������ѭ��
		}
	}
	MoveCursor(x, y);//��֮ǰ��������������������ƶ����
	PRINTF
		Food = (foodxy*)malloc(sizeof(foodxy));//����һ���µ�ʳ����ڴ�
	Food->x = x;
	Food->y = y;
	MoveCursor(33, 5);//ʳ��ĳ�ʼ��
	printf("  ");
	Showf();//������ʾ�÷�
	sum++;//�÷�����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);// �÷���ʾʹ����ɫ����
}
void ControlMove()//UP=1,DOWN=2,LEFT=3,RIGHT=4(���������)���ú��������ߵ��ƶ�(���ĺ���)
{
	if (GetAsyncKeyState(VK_UP) && 0x8000)//�жϰ��ķ�����Ƿ���ߵ��˶������Ƿ���ͬ��
	/*GetAsyncKeyState(VK_UP)����ȷ���û���ǰ�Ƿ����˼����ϵ�һ����*/
	{
		if (JudgeDirection == 2)
		{
		}
		else
		{
			JudgeDirection = 1;//��ͬ�ͽ��밴���ķ���
		}
	}
	if (GetAsyncKeyState(VK_DOWN) && 0x8000)//�жϰ��ķ�����Ƿ���ߵ��˶������Ƿ���ͬ
	{
		if (JudgeDirection == 1)
		{
		}
		else
		{
			JudgeDirection = 2;//��ͬ�ͽ��밴���ķ���
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) && 0x8000)//�жϰ��ķ�����Ƿ���ߵ��˶������Ƿ���ͬ
	{
		if (JudgeDirection == 3)
		{
		}
		else
		{
			JudgeDirection = 4;//��ͬ�ͽ��밴���ķ���
		}
	}
	if (GetAsyncKeyState(VK_LEFT) && 0x8000)//�жϰ��ķ�����Ƿ���ߵ��˶������Ƿ���ͬ
	{
		if (JudgeDirection == 4)
		{
		}
		else
		{
			JudgeDirection = 3;//��ͬ�ͽ��밴���ķ���
		}
	}
	if (GetAsyncKeyState(VK_RETURN) && 0x0D)//�������ENTER�س�������ͣ
	{
		while (1)//��������ѭ��
		{
			if (GetAsyncKeyState(VK_RETURN) && 0x0D)//�ٴΰ�ENTER������ѭ������Ϸ����
			{
				break;
			}
		}
	}
}
void ISnake()//��ʼ������
{
	for (int i = 0; i < IMAX; i++)//��ʼ���ߵĽ���ΪIMAX-1
	{
		Pbody = (Snakebody*)malloc(sizeof(Snakebody));//����snakebody�Ķ�̬�ռ�
		Pbody->x = 5 - i;
		Pbody->y = 5;
		if (Phead == NULL)//i=0ʱ���洢�ߵ�ͷ
		{
			Phead = Pbody;//ͷָ��ָ��pbody
		}
		else//�������������
		{
			end->next = Pbody;//β�ڵ��pbody����
		}
		Pbody->next = NULL;
		end = Pbody;//βָ������ָ��pbody��β�ڵ����Ϊ�������һλ
	}
	Phead_1 = Phead;//phead_1ָ��phead��ͷ����phead_1��������ʹ������
	while (Phead_1->next != NULL)
	{
		MoveCursor(Phead_1->x, Phead_1->y);//���߽�������
		PRINTF
			Phead_1 = Phead_1->next;//ת���������һ��
	}
}
void Move()//������Ϸ����1�����ü�ͷȥβ��
{
	int judge1, judge2;
	while (1)
	{
		Phead_1 = Phead;
		while (Phead_1->next->next != NULL)
		{
			Phead_1 = Phead_1->next;
		}
		Phead_1->next = NULL;
		Sleep(Pause);//��ͣpause����
		ControlMove(); //�����������ص�ֵ
		MoveCursor(Phead_1->x, Phead_1->y);
		EMPTY
			//����Ϊ����β��
			Snakebody* Phead_2 = (Snakebody*)malloc(sizeof(Snakebody));
		if (JudgeDirection == 1)//��������ֵΪ1
		{
			Phead_2->x = Phead->x;
			Phead_2->y = Phead->y - 1;
		}
		if (JudgeDirection == 2)
		{
			Phead_2->x = Phead->x;
			Phead_2->y = Phead->y + 1;
		}
		if (JudgeDirection == 3)
		{
			Phead_2->x = Phead->x - 1;
			Phead_2->y = Phead->y;
		}
		if (JudgeDirection == 4)
		{
			Phead_2->x = Phead->x + 1;
			Phead_2->y = Phead->y;
		}
		Phead_2->next = Phead;
		Phead = Phead_2;//������ͷ�;�ͷ��ͷָ������ָ����ͷ
		MoveCursor(Phead_2->x, Phead_2->y);
		PRINTF
			Jfood();
		judge1 = Jwall();
		judge2 = Jsnake();
		MoveCursor(40, 20);
		if (judge1 == 1 || judge2 == 1)
		{
			return;
		}
	}
}
void Jfood()//����Ƿ�Ե�ʳ��
{
	Phead_1 = Phead;//Phead_1ָ������
	if (Phead_1->x == Food->x && Phead_1->y == Food->y)//��ͷ�Ƿ�Ե�ʳ��
	{
		FoodRand();//ʳ����������
		JudgeSum += 1;//�����ļ�һ
		if (JudgeSum == 5)//ÿ5�֣��ѶȾ�����
		{
			JudgeSum = 0;
			Hard += 1;
			Pause -= 20;
		}
		while (Phead_1->next != NULL)//����ı���
		{
			Phead_1 = Phead_1->next;
		}
		Snakebody* S = (Snakebody*)malloc(sizeof(Snakebody));
		S->x = Food->x;
		S->y = Food->y;
		S->next = NULL;
		Phead_1->next = S;
		ControlMove();
		MoveCursor(Phead_1->x, Phead_1->y);
		PRINTF
	}
	//��ȡʳ����������ͷ���Ա�
}
int Jwall()   //�ж��Ƿ�ײ��ǽ
{
	if (Phead->x == 0 || Phead->x == 19 || Phead->y == 0 || Phead->y == 19)//������ֱ���ж���ͷ
	{
		MoveCursor(10, 25);
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
		printf("��Ǹ����ײ����ǽ����Ϸ����!              ");
		system("pause>nul");
		return  1;
	}
}
int Jsnake()//�ж��Ƿ�ײ���Լ�������
{
	Phead_1 = Phead->next;
	while (Phead_1->next != NULL)//�������ͷ�ı���
	{
		if ((Phead->x == Phead_1->x) && (Phead->y == Phead_1->y))//�ж��Ƿ���ͷ�����������
		{
			MoveCursor(10, 25);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
			printf("\n��Ǹ����ײ�����Լ�����Ϸ����!          ");
			system("pause>nul");
			return 1;//�ǵĻ�ֱ���˳���Ϸ
		}
		Phead_1 = Phead_1->next;
	}
}
void Showf()
{
	MoveCursor(33, 10);
	printf("�÷֣�%d", sum);
	MoveCursor(33, 12);
	printf("�Ѷȣ�%d", Hard);
}
