冒泡排序：

#include <stdio.h>

#define N 5



void Maopao(int array[]) {

	for (int i = 0; i < N; i++) {

		for (int j = i + 1; j < N; j++) {

			if (array[i] > array[j]) {

				int temp = 0;

				temp = array[i];

				array[i] = array[j];

				array[j] = temp;

			}

		}

	}

}

void paixu(int array[]) {

	for (int i = 0; i < N; i++) {

		printf("array[%d]=%d\n", i, array[i]);

	}

}

int main(void) {

	int array[N];

	printf("please iuput number:\n");

	for (int i = 0; i < N; i++) {

		scanf("%d", &array[i]);

	}

	paixu(array);

	printf("\n");

	Maopao(array);

	paixu(array);

	return 0;

}



选择排序：

#include <stdio.h>

#define N 5

void xuanze(int array[]) {

	for (int i = 0; i < N - 1; i++) {

		int min = i;

		int temp;

		for (int j = i + 1; j < N; j++) {

			if (array[min] > array[j])

				min = j;

		}

		if (min != i) {

			temp = array[i];

			array[i] = array[min];

			array[min] = temp;

		}

	}

}

void paixu(int array[]) {

	for (int i = 0; i < N; i++) {

		printf("array[%d]=%d\n", i, array[i]);

	}

}

int main(void) {

	int array[N];

	printf("please iuput number:\n");

	for (int i = 0; i < N; i++) {

		scanf("%d", &array[i]);

	}

	paixu(array);

	printf("\n");

	xuanze(array);

	paixu(array);

	return 0;

}



全指针插入排序：

#include <stdio.h>

void print(int* array, int n) {

	for (int i = 0; i < 5; i++) {

		printf("array[%d]=%d\n", i, array[i]);

	}

}

void inter(int* array, int n) {

	int* p = array;

	int* q = array;

	int* k = array + n;

	for (; p < k; p++) {

		int temp = *p;

		for (q = p - 1; q >= 0; q--) {

			if (*q > temp)

				*(q + 1) = *q;

			else

				break;

		}

		*(q + 1) = temp;

	}

}

int main(int argc, const char* argv[]) {

	int array[5];

	int* p;

	printf("请随机随机输入五个数:\n");

	for (int i = 0; i < 5; i++) {

		scanf("%d", &array[i]);

	}

	p = array;

	print(p, 5);

	printf("排序之后:\n");

	inter(array, 5);

	print(array, 5);

	return 0;

}



普通插入排序：



#include <stdio.h>



void print(int array[], int n) {

	for (int i = 0; i < 5; i++) {

		printf("array[%d]=%d\n", i, array[i]);

	}

}



void inter(int array[], int n) {

	for (int i = 1; i < n; i++) {

		int temp = array[i];

		int j = i - 1;

		for (; j >= 0; j--) {

			if (array[j] > temp)

				array[j + 1] = array[j];

			else

				break;

		}

		array[j + 1] = temp;

	}

}

int main() {

	int array[5];

	printf("请随机输入数字:\n");

	for (int i = 0; i < 5; i++) {

		scanf("%d", &array[i]);

	}

	print(array, 5);

	printf("排序之后:\n");

	inter(array, 5);

	print(array, 5);

	return 0;

}



快速排序：

#include<stdio.h>

void print(int array[], int n) {

	for (int i = 0; i < n; i++) {

		printf("array[%d]=%d\n", i, array[i]);

	}

}



int* QuaickSort(int array[], int first, int last) {

	if (first < last) {

		int i = first;

		int j = last;

		int KeyData = array[first]; //将第一个元素拷贝给关键数据

		while (i < j) {

			//从后往前扫描判断最后一个是否大于关键数据满足在扫描前一个

			while ((i < j) && (array[j] >= KeyData)) {

				j--;

			}

			if (i < j) {

				array[i++] = array[j];

			}

			//从前往后扫描判断前面的是否小于关键数据满足在扫描下一个

			while ((i < j) && array[i] < KeyData) {

				i++;

			}

			if (i < j) {

				array[j--] = array[i];

			}

		}

		array[i] = KeyData;

		QuaickSort(array, first, i - 1); //递归调用

		QuaickSort(array, i + 1, last);

	}

	return array;

}



int main() {

	int array[5];

	printf("请输入五个数字:\n");

	for (int i = 0; i < 5; i++) {

		scanf("%d", &array[i]);

	}

	print(array, 5);

	printf("排序之后:\n");

	QuaickSort(array, 0, 4);

	print(QuaickSort(array, 0, 4), 5);

	return 0;

}



堆排序：//大根堆实现

#include "stdio.h"

#include<stdlib.h>

void AdjustHeap(int array[], int index, int length) {//数组、非叶子结点数、长度

	printf("调整堆:\n");

	int temp = array[index];//临时存储非叶子结点

	int nChildIndex = 0;//叶子结点

	for (; 2 * index + 1 < length; index = nChildIndex) {//判断左子结点索引是否小于整体长度

		nChildIndex = 2 * index + 1;//左子结点的索引

		//判断左子结点索引是否小于整体长度和右子结点是否大于左子结点，满足执行下面的语句

		if (nChildIndex<length - 1 && array[nChildIndex + 1]>array[nChildIndex])

			nChildIndex++;

		//如果上面的语句成立，如果右子结点大于非叶子结点就交换否则不交换。上面的条件不成立，如果左子结点大于右子结点就交换否则不交换。

		if (array[nChildIndex] > temp) {

			array[index] = array[nChildIndex];

			array[nChildIndex] = temp;

		}
		else

			break;

	}

}

void BuidHeap(int array[], int length) {

	printf("构建堆:\n");

	for (int i = length / 2 - 1; i >= 0; i--) {

		AdjustHeap(array, i, length);

	}

}



void heapSort(int array[], int length) {

	BuidHeap(array, length);

	//堆顶与堆底互换位置，大的放在堆底，小的放在堆顶，抛去最后一个堆底，使前一个成为堆底。不满足大根堆思想继续调整堆，成为大根堆，重复循环

	for (int i = length - 1; i >= 0; i--) {

		int temp = 0;

		temp = array[0];

		array[0] = array[i];

		array[i] = temp;

		AdjustHeap(array, 0, i);

	}

}

void print(int array[], int n) {

	for (int i = 0; i < n; i++) {

		printf("array[%d]=%d\n", i, array[i]);

	}

}

int main() {

	int array[8];

	printf("please initialize array[8]:\n");

	for (int i = 0; i < 8; i++) {

		scanf("%d", &array[i]);

	}

	printf("before sorting:\n");

	print(array, 8);

	heapSort(array, 8);

	print(array, 8);

	return 0;

}