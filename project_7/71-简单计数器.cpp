#include"practice7.h"
#define FilePath1 "counter.dat"

int read(const char* path);
void write(int count, const char* path);

void counter()
{
	int count = 0;
	count = read(FilePath1) + 1;
	printf("�����Ѿ����У�%d��", count);
	printf("\n-------------------------------------------\n");
	printf("���潫���д�������������ļ���counter.dat��....\n");
	write(count, FilePath1);
	printf("д����������\n");
	printf("�������н�����\n");
	printf("\n-------------------------------------------\n");
	system("pause");
}

int read(const char* path)
{
	FILE* fp;
	int count;
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("û�м������ļ���counter.dat��������˴����д���ʱ���½����ļ���\n");
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
		printf("�޷������������ļ�\n");
		return;
	}
	fprintf(fp, "%d", count);
	fclose(fp);
}