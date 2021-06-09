#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#define HEIGHT  20  //宏定义地图高度
#define WIDTH   40  //宏定义地图宽度
#define PRINTF  printf("■");//作为地图的边界和蛇身体的每一节
#define LINE    printf("\n");//定义换行语句
#define EMPTY   printf("  ");//定义空格语句
#define IMAX 5//初始蛇身长度
typedef struct Snakebody
{
	int x, y;//身体的坐标
	struct Snakebody* next;//结构体指针
}Snakebody;//先来创建保持身体的链表，贪吃蛇的核心代码就是该如何保存蛇的身体
typedef struct Snakefood
{
	int x;//食物的横坐标
	int y;//食物的纵坐标
}foodxy; //记录食物坐标
int sum = 0;     //计算最后的得分
int JudgeSum = 0;    //判断是否加快
int Hard = 0;     //计算难度
int Pause = 200;   //暂停速度(移动速度)
int JudgeDirection = 4;   //初始化最初的方向为右
Snakebody* Phead = NULL;  //存储着整个蛇身 不可更改
Snakebody* Phead_1 = NULL;  //指向蛇身
Snakebody* Pbody = NULL;  //创建节点
Snakebody* end = NULL;   //尾节点
foodxy* Food = NULL;          //保存食物位置
void Front();                   //游戏开始页面1
void Jfood();     //检测是否吃到食物1
int Jwall();     //检测蛇头是否撞墙1
int Jsnake();     //检测蛇头是否撞到蛇身1
void ISnake();     //初始化蛇身1
void DrewMap();     //绘制地图1
void FoodRand();    //生成食物1
void ControlMove();    //控制移动和暂停1
void MoveCursor(int x, int y); //设置移动光标1
void Move();     //游戏运行1
void Showf();                   //显示分数以及难度1
void snake();
//void Free();//释放内存
void snake()
{
	Front();//模拟游戏加载界面
	DrewMap();//绘制地图边界
	Showf();//显示得分和难度
	/*MoveCursor(34, 10);
	printf("↑");
	MoveCursor(31, 11);//设置初始光标位置
	printf("使用←↓→来控制");
	MoveCursor(31, 12);
	printf("蛇的移动，撞墙游");
	*/
	MoveCursor(31, 10);
	printf("戏结束，每5分增 ");
	MoveCursor(31, 14);
	printf("一个难度(速度)");
	ISnake();//初始化蛇身
	FoodRand();//初始化食物
	MoveCursor(40, 20);
	Move();//游戏运行界面的绘制
	return;
}
void Front()//第一个页面的绘制(游戏开始界面)(模拟游戏加载界面)
{
	MoveCursor(15, 8);
	printf(" 贪 吃 蛇 ");
	MoveCursor(18, 15);
	printf("游戏加载中，请稍候......");
	Sleep(3000);
	/*for (int i = 0; i <= 1000000000; i++) {} */ //第一个页面的暂停
	system("cls");
}
void DrewMap()    //地图的绘制
{
	for (int i = 1; i <= WIDTH / 2; i++) //宽度
	{
		printf("\n");//每次打印前换行
		for (int j = 1; j <= HEIGHT; j++)//长度
		{
			if (j == 1 || i == 1 || i == WIDTH / 2 || j == HEIGHT)
			{
				PRINTF//打印边框
			}
			else EMPTY//打印空格
		}
	}
}
void MoveCursor(int x, int y)//设置光标位置(就是输出显示的开始位置)
{
	/*  COORD是Windows API中定义的一种结构体
	* typedef struct _COORD
	* {
	* SHORT X;
	* SHORT Y;
	* } COORD;
	*  */
	COORD pos = { x * 2,y };//因为2行的距离差不多为一个单位，故用■就可以形成一个完好的map，■占2个单位
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);//获得标准输出的句柄   
	SetConsoleCursorPosition(output, pos); //设置控制台光标位置
}
void FoodRand()//生成食物1
{
	srand((int)time(0)); //先设置种子和当前的时间
	int x = rand() % 8 + 2;//设置food随机出现的横坐标(随机出现一个2-8的整数)
	int y = rand() % 8 + 2;//设置food随机出现的纵坐标
	Phead_1 = Phead;//phead_1指向蛇身的头
	for (int i = 0; i <= 200; i++)//遍历整个蛇身，检查是否有蛇身与食物相遇
	{
		if (Phead_1->x == x && Phead_1->y == y)//如果蛇身与食物相遇，则重新随机刷新食物
		{
			x = rand() % 8 + 2;
			y = rand() % 8 + 2;
		}
		else
		{
			Phead_1 = Phead_1->next;//否则指向下一节
		}
		if (Phead_1->next == NULL)
		{
			break;//遍历为空即蛇尾，跳出循环
		}
	}
	MoveCursor(x, y);//以之前随机出来的坐标来设置移动光标
	PRINTF
		Food = (foodxy*)malloc(sizeof(foodxy));//开辟一个新的食物的内存
	Food->x = x;
	Food->y = y;
	MoveCursor(33, 5);//食物的初始化
	printf("  ");
	Showf();//重新显示得分
	sum++;//得分自增
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);// 得分显示使用蓝色字体
}
void ControlMove()//UP=1,DOWN=2,LEFT=3,RIGHT=4(方向键键码)，该函数控制蛇的移动(核心函数)
{
	if (GetAsyncKeyState(VK_UP) && 0x8000)//判断按的方向键是否和蛇的运动方向是否相同，
	/*GetAsyncKeyState(VK_UP)函数确定用户当前是否按下了键盘上的一个键*/
	{
		if (JudgeDirection == 2)
		{
		}
		else
		{
			JudgeDirection = 1;//不同就进入按键的方向
		}
	}
	if (GetAsyncKeyState(VK_DOWN) && 0x8000)//判断按的方向键是否和蛇的运动方向是否相同
	{
		if (JudgeDirection == 1)
		{
		}
		else
		{
			JudgeDirection = 2;//不同就进入按键的方向
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) && 0x8000)//判断按的方向键是否和蛇的运动方向是否相同
	{
		if (JudgeDirection == 3)
		{
		}
		else
		{
			JudgeDirection = 4;//不同就进入按键的方向
		}
	}
	if (GetAsyncKeyState(VK_LEFT) && 0x8000)//判断按的方向键是否和蛇的运动方向是否相同
	{
		if (JudgeDirection == 4)
		{
		}
		else
		{
			JudgeDirection = 3;//不同就进入按键的方向
		}
	}
	if (GetAsyncKeyState(VK_RETURN) && 0x0D)//如果按下ENTER回车键可暂停
	{
		while (1)//进入无限循环
		{
			if (GetAsyncKeyState(VK_RETURN) && 0x0D)//再次按ENTER键结束循环，游戏继续
			{
				break;
			}
		}
	}
}
void ISnake()//初始化蛇身
{
	for (int i = 0; i < IMAX; i++)//初始化蛇的节数为IMAX-1
	{
		Pbody = (Snakebody*)malloc(sizeof(Snakebody));//开辟snakebody的动态空间
		Pbody->x = 5 - i;
		Pbody->y = 5;
		if (Phead == NULL)//i=0时，存储蛇的头
		{
			Phead = Pbody;//头指针指向pbody
		}
		else//进行蛇身的塑造
		{
			end->next = Pbody;//尾节点和pbody相连
		}
		Pbody->next = NULL;
		end = Pbody;//尾指针重新指向pbody，尾节点更新为链表最后一位
	}
	Phead_1 = Phead;//phead_1指向phead蛇头，用phead_1遍历蛇身，使蛇形象化
	while (Phead_1->next != NULL)
	{
		MoveCursor(Phead_1->x, Phead_1->y);//对蛇进行形象化
		PRINTF
			Phead_1 = Phead_1->next;//转到链表的下一层
	}
}
void Move()//定义游戏运行1，采用加头去尾法
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
		Sleep(Pause);//暂停pause毫秒
		ControlMove(); //引进按键返回的值
		MoveCursor(Phead_1->x, Phead_1->y);
		EMPTY
			//上面为消除尾部
			Snakebody* Phead_2 = (Snakebody*)malloc(sizeof(Snakebody));
		if (JudgeDirection == 1)//按键返回值为1
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
		Phead = Phead_2;//连接新头和旧头，头指针重新指向蛇头
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
void Jfood()//检测是否吃到食物
{
	Phead_1 = Phead;//Phead_1指向蛇身
	if (Phead_1->x == Food->x && Phead_1->y == Food->y)//蛇头是否吃到食物
	{
		FoodRand();//食物重新生成
		JudgeSum += 1;//分数的加一
		if (JudgeSum == 5)//每5分，难度就增加
		{
			JudgeSum = 0;
			Hard += 1;
			Pause -= 20;
		}
		while (Phead_1->next != NULL)//蛇身的遍历
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
	//获取食物的坐标和蛇头做对比
}
int Jwall()   //判断是否撞到墙
{
	if (Phead->x == 0 || Phead->x == 19 || Phead->y == 0 || Phead->y == 19)//在这里直接判断蛇头
	{
		MoveCursor(10, 25);
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
		printf("抱歉，你撞到了墙，游戏结束!              ");
		system("pause>nul");
		return  1;
	}
}
int Jsnake()//判断是否撞向自己的身体
{
	Phead_1 = Phead->next;
	while (Phead_1->next != NULL)//蛇身除蛇头的遍历
	{
		if ((Phead->x == Phead_1->x) && (Phead->y == Phead_1->y))//判断是否蛇头坐标等于蛇身
		{
			MoveCursor(10, 25);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
			printf("\n抱歉，你撞到了自己，游戏结束!          ");
			system("pause>nul");
			return 1;//是的话直接退出游戏
		}
		Phead_1 = Phead_1->next;
	}
}
void Showf()
{
	MoveCursor(33, 10);
	printf("得分：%d", sum);
	MoveCursor(33, 12);
	printf("难度：%d", Hard);
}
