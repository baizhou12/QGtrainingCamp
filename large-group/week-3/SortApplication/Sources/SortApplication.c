#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"SortApplication.h"

//颜色排序
void ColourSort(int a[],int n) {
	int *p0, *p1,*p2;
	p0 = a;//指向开头
	p1 = a+1;//指向第二个，用来遍历
	p2 = a + n;//指向最后
	while (p1 != p2){
        //将0放到前面
		if (*p1 == 0){
			*p1 = *p0;
			*p0 = 0;
			*p0++;
			*p1--;//防止出现*p0为0的情况
		}

        //将2放到后面
		if (*p1 == 2) {
			*p1 = *p2;
			*p2 = 2;
			*p2--;
			*p1--;//防止出现*p2为2的情况
		}

		*p1++;
	 }
}

// 交换数组中两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 根据第一个元素作为基准值进行分区，并返回基准值的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // 将第一个元素设为基准值
    int storeIndex = low + 1; // 存储索引为基准值索引加一

    // 从第二个元素开始遍历数组
    for (int i = low + 1; i <= high; i++) {
        // 如果当前元素小于基准值，则交换当前元素和存储索引位置的元素
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++; // 存储索引自增
        }
    }
    // 将基准值交换到正确的位置上
    swap(&arr[low], &arr[storeIndex - 1]);
    return storeIndex - 1; // 返回基准值的索引
}

//找出排行第k小的数
int FindKthLargest(int arr[], int low, int high, int k) {
    int pivotIndex = partition(arr, low, high);  // 划分数组，返回基准元素的索引
    int rank = pivotIndex - low + 1;             // 计算基准元素的排名

    if (rank == k) {
        return arr[pivotIndex];  // 如果基准元素的排名等于 k，则找到了第 k 大的数
    }
    else if (rank > k) {
        return FindKthLargest(arr, low, pivotIndex - 1, k);  // 在左子数组中继续查找
    }
    else {
        return FindKthLargest(arr, pivotIndex + 1, high, k - rank);  // 在右子数组中继续查找
    }
}

int main() {
    int arr1[SIZE];  // 声明整型数组
    int i;

    // 设置随机数种子
    srand(time(NULL));

    // 随机生成数组元素
    for (i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 3;  // 生成范围在 0 到 2 之间的随机数
    }

    // 打印生成的数组
    printf("生成的数组为：\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    ColourSort(arr1,SIZE-1);

    printf("排序后的数组为：\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int arr2[SIZE];  // 声明整型数组
 
    // 设置随机数种子
    srand(time(NULL));

    // 随机生成数组元素
    for (i = 0; i < SIZE; i++) {
        arr2[i] = rand() % 100;  // 生成范围在 0 到 99 之间的随机数
    }

    // 打印生成的数组
    printf("生成的数组为：\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int k = 3;

   printf("排行第%d小的数为：%d",k, FindKthLargest(arr2, 0, SIZE-1, k));

   char c;
   c = getchar();

   system("pause");
   return 0;
}