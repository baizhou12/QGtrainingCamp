#pragma once

//插入排序
void InsertSort(int a[], int len);

// 合并两个有序数组
void merge(int arr[], int left, int mid, int right);
//归并排序函数
void MergeSort(int arr[], int left, int right);


// 交换数组中两个元素的值
void swap(int* a, int* b);
// 根据第一个元素作为基准值进行分区，并返回基准值的索引
int partition(int arr[], int low, int high);

// 快速排序函数
void QuickSort(int arr[], int low, int high);

// 计数排序函数
void CountingSort(int arr[], int n);


//基数排序中的计数排序
void CountSort(int arr[], int n, int exp);

// 基数排序函数
void RadixSort(int arr[], int n);

//测试函数1，2都是用来进行不同大数据量下的排序时间测序，分1，2主要是各个排序函数的形参不完全一致

// 测试函数1
double test_sort_algorithm1(void (*algorithm)(int arr[], int n), int arr_size);

// 测试函数2
double test_sort_algorithm2(void (*algorithm)(int arr[], int start, int end), int arr_size);

//测试函数3，4都是用来进行大量小数据量下的排序时间测序，分3，4主要是各个排序函数的形参不完全一致

 //测试函数3
double test_sort_algorithm3(void (*algorithm)(int arr[], int n), int arr_size, int num_tests);

//测试函数4
double test_sort_algorithm4(void (*algorithm)(int arr[], int start, int end), int arr_size, int num_tests);

//生成测试数据并保存到对应的文件
void generate_test_data(const char* file_name);

//读取对应文件的测试数据并选择相应的排序算法进行排序
void read_and_sort_data(const char* file_name);
