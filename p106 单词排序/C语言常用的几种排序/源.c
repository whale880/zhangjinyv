ð������

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



ѡ������

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



ȫָ���������

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

	printf("�����������������:\n");

	for (int i = 0; i < 5; i++) {

		scanf("%d", &array[i]);

	}

	p = array;

	print(p, 5);

	printf("����֮��:\n");

	inter(array, 5);

	print(array, 5);

	return 0;

}



��ͨ��������



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

	printf("�������������:\n");

	for (int i = 0; i < 5; i++) {

		scanf("%d", &array[i]);

	}

	print(array, 5);

	printf("����֮��:\n");

	inter(array, 5);

	print(array, 5);

	return 0;

}



��������

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

		int KeyData = array[first]; //����һ��Ԫ�ؿ������ؼ�����

		while (i < j) {

			//�Ӻ���ǰɨ���ж����һ���Ƿ���ڹؼ�����������ɨ��ǰһ��

			while ((i < j) && (array[j] >= KeyData)) {

				j--;

			}

			if (i < j) {

				array[i++] = array[j];

			}

			//��ǰ����ɨ���ж�ǰ����Ƿ�С�ڹؼ�����������ɨ����һ��

			while ((i < j) && array[i] < KeyData) {

				i++;

			}

			if (i < j) {

				array[j--] = array[i];

			}

		}

		array[i] = KeyData;

		QuaickSort(array, first, i - 1); //�ݹ����

		QuaickSort(array, i + 1, last);

	}

	return array;

}



int main() {

	int array[5];

	printf("�������������:\n");

	for (int i = 0; i < 5; i++) {

		scanf("%d", &array[i]);

	}

	print(array, 5);

	printf("����֮��:\n");

	QuaickSort(array, 0, 4);

	print(QuaickSort(array, 0, 4), 5);

	return 0;

}



������//�����ʵ��

#include "stdio.h"

#include<stdlib.h>

void AdjustHeap(int array[], int index, int length) {//���顢��Ҷ�ӽ����������

	printf("������:\n");

	int temp = array[index];//��ʱ�洢��Ҷ�ӽ��

	int nChildIndex = 0;//Ҷ�ӽ��

	for (; 2 * index + 1 < length; index = nChildIndex) {//�ж����ӽ�������Ƿ�С�����峤��

		nChildIndex = 2 * index + 1;//���ӽ�������

		//�ж����ӽ�������Ƿ�С�����峤�Ⱥ����ӽ���Ƿ�������ӽ�㣬����ִ����������

		if (nChildIndex<length - 1 && array[nChildIndex + 1]>array[nChildIndex])

			nChildIndex++;

		//����������������������ӽ����ڷ�Ҷ�ӽ��ͽ������򲻽����������������������������ӽ��������ӽ��ͽ������򲻽�����

		if (array[nChildIndex] > temp) {

			array[index] = array[nChildIndex];

			array[nChildIndex] = temp;

		}
		else

			break;

	}

}

void BuidHeap(int array[], int length) {

	printf("������:\n");

	for (int i = length / 2 - 1; i >= 0; i--) {

		AdjustHeap(array, i, length);

	}

}



void heapSort(int array[], int length) {

	BuidHeap(array, length);

	//�Ѷ���ѵ׻���λ�ã���ķ��ڶѵף�С�ķ��ڶѶ�����ȥ���һ���ѵף�ʹǰһ����Ϊ�ѵס�����������˼����������ѣ���Ϊ����ѣ��ظ�ѭ��

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