#include"practice7.h"
#define FilePath1 "counter.dat"

int read(const char* path);
void write(int count, const char* path);

void counter()
{
	int count = 0;
	count = read(FilePath1) + 1;
	printf("程序已经运行：%d次", count);
	printf("\n-------------------------------------------\n");
	printf("下面将运行次数计入计数器文件（counter.dat）....\n");
	write(count, FilePath1);
	printf("写入程序结束！\n");
	printf("程序运行结束！\n");
	printf("\n-------------------------------------------\n");
	system("pause");
}

int read(const char* path)
{
	FILE* fp;
	int count;
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("没有计数器文件（counter.dat），保存此次运行次数时将新建该文件！\n");
		return 0;
	}
	fscanf(fp, "%d", &count);
	fclose(fp);
	return count;
}

void write(int count, const char* path)
{
	FILE* fp;
	if ((fp = fopen(path, "w")) == NULL)
	{
		printf("无法创建计数器文件\n");
		return;
	}
	fprintf(fp, "%d", count);
	fclose(fp);
}