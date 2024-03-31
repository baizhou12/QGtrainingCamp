#pragma once

//生成的随机数组的大小
#define SIZE 10

//颜色排序
void ColourSort(int a[], int n);


// 交换数组中两个元素的值
void swap(int* a, int* b);

// 根据第一个元素作为基准值进行分区，并返回基准值的索引
int partition(int arr[], int low, int high);

//找出排行第k小的数
int FindKthLargest(int arr[], int low, int high, int k);
