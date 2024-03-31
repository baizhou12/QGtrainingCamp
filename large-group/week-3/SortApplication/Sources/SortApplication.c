#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"SortApplication.h"

//��ɫ����
void ColourSort(int a[],int n) {
	int *p0, *p1,*p2;
	p0 = a;//ָ��ͷ
	p1 = a+1;//ָ��ڶ�������������
	p2 = a + n;//ָ�����
	while (p1 != p2){
        //��0�ŵ�ǰ��
		if (*p1 == 0){
			*p1 = *p0;
			*p0 = 0;
			*p0++;
			*p1--;//��ֹ����*p0Ϊ0�����
		}

        //��2�ŵ�����
		if (*p1 == 2) {
			*p1 = *p2;
			*p2 = 2;
			*p2--;
			*p1--;//��ֹ����*p2Ϊ2�����
		}

		*p1++;
	 }
}

// ��������������Ԫ�ص�ֵ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���ݵ�һ��Ԫ����Ϊ��׼ֵ���з����������ػ�׼ֵ������
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // ����һ��Ԫ����Ϊ��׼ֵ
    int storeIndex = low + 1; // �洢����Ϊ��׼ֵ������һ

    // �ӵڶ���Ԫ�ؿ�ʼ��������
    for (int i = low + 1; i <= high; i++) {
        // �����ǰԪ��С�ڻ�׼ֵ���򽻻���ǰԪ�غʹ洢����λ�õ�Ԫ��
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++; // �洢��������
        }
    }
    // ����׼ֵ��������ȷ��λ����
    swap(&arr[low], &arr[storeIndex - 1]);
    return storeIndex - 1; // ���ػ�׼ֵ������
}

//�ҳ����е�kС����
int FindKthLargest(int arr[], int low, int high, int k) {
    int pivotIndex = partition(arr, low, high);  // �������飬���ػ�׼Ԫ�ص�����
    int rank = pivotIndex - low + 1;             // �����׼Ԫ�ص�����

    if (rank == k) {
        return arr[pivotIndex];  // �����׼Ԫ�ص��������� k�����ҵ��˵� k �����
    }
    else if (rank > k) {
        return FindKthLargest(arr, low, pivotIndex - 1, k);  // �����������м�������
    }
    else {
        return FindKthLargest(arr, pivotIndex + 1, high, k - rank);  // �����������м�������
    }
}

int main() {
    int arr1[SIZE];  // ������������
    int i;

    // �������������
    srand(time(NULL));

    // �����������Ԫ��
    for (i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 3;  // ���ɷ�Χ�� 0 �� 2 ֮��������
    }

    // ��ӡ���ɵ�����
    printf("���ɵ�����Ϊ��\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    ColourSort(arr1,SIZE-1);

    printf("����������Ϊ��\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int arr2[SIZE];  // ������������
 
    // �������������
    srand(time(NULL));

    // �����������Ԫ��
    for (i = 0; i < SIZE; i++) {
        arr2[i] = rand() % 100;  // ���ɷ�Χ�� 0 �� 99 ֮��������
    }

    // ��ӡ���ɵ�����
    printf("���ɵ�����Ϊ��\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int k = 3;

   printf("���е�%dС����Ϊ��%d",k, FindKthLargest(arr2, 0, SIZE-1, k));

   char c;
   c = getchar();

   system("pause");
   return 0;
}