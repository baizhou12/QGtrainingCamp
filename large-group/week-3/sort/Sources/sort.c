#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

 void InsertSort(int a[], int len) {
     int i = 1;
     while (i < len) {
         int j = i - 1;
         int key = a[i];
         while (j >= 0 && a[j] > key) {
             a[j + 1] = a[j];
             j--;
         }
         a[j + 1] = key;
         i++;
     }
 }

 // 合并两个有序数组
 void merge(int arr[], int left, int mid, int right) {
     int n1 = mid - left + 1;
     int n2 = right - mid;
     int* L = (int*)malloc(n1 * sizeof(int));
     int* R = (int*)malloc(n1 * sizeof(int));
     int i, j, k;

     // 将数据复制到临时数组 L 和 R 中
     for (i = 0; i < n1; i++)
         L[i] = arr[left + i];
     for (j = 0; j < n2; j++)
         R[j] = arr[mid + 1 + j];

     // 归并临时数组到 arr[left..right]
     i = 0;
     j = 0;
     k = left;
     while (i < n1 && j < n2) {
         arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
     }

     // 将剩余元素复制到 arr 中
     while (i < n1) {
         arr[k++] = L[i++];
     }
     while (j < n2) {
         arr[k++] = R[j++];
     }

     //释放动态分配内存
     free(L);
     free(R);
 }

 // 归并排序函数
 void MergeSort(int arr[], int left, int right) {
     if (left < right) {
         int mid = left + (right - left) / 2;
         MergeSort(arr, left, mid);
         MergeSort(arr, mid + 1, right);
         merge(arr, left, mid, right);
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

 // 快速排序函数
 void QuickSort(int arr[], int low, int high) {
     if (low < high) {
         // 对数组进行分区，并获取基准值的索引
         int pi = partition(arr, low, high);
         // 对基准值左边的子数组进行快速排序
         QuickSort(arr, low, pi - 1);
         // 对基准值右边的子数组进行快速排序
         QuickSort(arr, pi + 1, high);
     }
 }

 // 计数排序函数
 void CountingSort(int arr[], int n) {
     // 查找数组中的最大值，确定计数数组的大小
     int max = arr[0];
     for (int i = 1; i < n; ++i) {
         if (arr[i] > max) {
             max = arr[i];
         }
     }

     // 创建计数数组，并初始化为0
     int* count = (int*)malloc((max + 1) * sizeof(int));
     for (int i = 0; i <= max; ++i) {
         count[i] = 0;
     }

     // 统计每个元素出现的次数
     for (int i = 0; i < n; ++i) {
         count[arr[i]]++;
     }

     // 根据计数数组重新对原始数组进行排序
     int index = 0;
     for (int i = 0; i <= max; ++i) {
         while (count[i] > 0) {
             arr[index++] = i;
             count[i]--;
         }
     }

     // 释放动态分配的内存
     free(count);
 }

 //基数排序中的计数排序
void CountSort(int arr[], int n, int exp) {
     int* output=(int*)malloc(n*sizeof(int)); // 临时数组用于存储排序后的结果
     int count[10] = { 0 }; // 计数数组

     // 统计每个数字出现的次数
     for (int i = 0; i < n; i++) {
         count[(arr[i] / exp) % 10]++;
     }

     // 将计数数组转换为位置数组，表示每个数字在输出数组中的位置
     for (int i = 1; i < 10; i++) {
         count[i] += count[i - 1];
     }

     // 根据当前位数将数字放入临时数组中，并同时更新计数数组
     for (int i = n - 1; i >= 0; i--) {
         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
         count[(arr[i] / exp) % 10]--;
     }

     // 将排序后的结果复制回原始数组
     for (int i = 0; i < n; i++) {
         arr[i] = output[i];
     }

     //释放动态分配内存
     free(output);
 }

 // 基数排序函数
 void RadixSort(int arr[], int n) {
     // 获取数组中的最大数字
     int max = arr[0];
     for (int i = 1; i < n; i++) {
         if (arr[i] > max) {
             max = arr[i];
         }
     }

     // 对每个位数进行排序，从个位开始直到最高位
     for (int exp = 1; max / exp > 0; exp *= 10) {
         CountSort(arr,n,exp);
     }
 }

 // 测试函数1
 double test_sort_algorithm1(void (*algorithm)(int arr[], int n), int arr_size) {
     int* arr = (int*)malloc(sizeof(int) * arr_size);
     // 生成随机数组
     for (int i = 0; i < arr_size; ++i) {
         arr[i] = rand(); // 生成随机数
     }

     clock_t start_time, end_time;
     start_time = clock();
     // 调用排序算法
     algorithm(arr, arr_size);
     end_time = clock();

     free(arr);

     return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
 }

 // 测试函数2
 double test_sort_algorithm2(void (*algorithm)(int arr[], int start,int end), int arr_size) {
     int* arr = (int*)malloc(sizeof(int) * arr_size);
     // 生成随机数组
     for (int i = 0; i < arr_size; ++i) {
         arr[i] = rand(); // 生成随机数
     }

     clock_t start_time, end_time;
     start_time = clock();
     // 调用排序算法
     algorithm(arr,0, arr_size-1);
     end_time = clock();

     free(arr);

     return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
 }

 //测试函数3
 double test_sort_algorithm3(void (*algorithm)(int arr[], int n), int arr_size, int num_tests) {
     double total_time = 0.0;

     for (int i = 0; i < num_tests; ++i) {
         int* arr = (int*)malloc(sizeof(int) * arr_size);
         // 生成随机数组
         for (int j = 0; j < arr_size; ++j) {
             arr[j] = rand(); // 生成随机数
         }

         clock_t start_time, end_time;
         start_time = clock();
         // 调用排序算法
         algorithm(arr, arr_size); // 传递数组起始索引和结束索引
         end_time = clock();

         total_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

         free(arr);
     }

     return total_time;
 }

 //测试函数4
 double test_sort_algorithm4(void (*algorithm)(int arr[], int start, int end), int arr_size, int num_tests) {
     double total_time = 0.0;

     for (int i = 0; i < num_tests; ++i) {
         int* arr = (int*)malloc(sizeof(int) * arr_size);
         // 生成随机数组
         for (int j = 0; j < arr_size; ++j) {
             arr[j] = rand(); // 生成随机数
         }

         clock_t start_time, end_time;
         start_time = clock();
         // 调用排序算法
         algorithm(arr, 0, arr_size - 1); // 传递数组起始索引和结束索引
         end_time = clock();

         total_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

         free(arr);
     }

     return total_time;
 }

 //生成测试数据并保存到对应的文件
 void generate_test_data(const char* file_name) {
     int num_elements, min_value, max_value;

     printf("请输入要生成的数据量：");
     scanf("%d", &num_elements);

     printf("请输入随机数的最小值：");
     scanf("%d", &min_value);

     printf("请输入随机数的最大值：");
     scanf("%d", &max_value);

     FILE* file = fopen(file_name, "w");
     if (file == NULL) {
         printf("无法打开文件 %s\n", file_name);
         return;
     }

     srand(time(NULL)); // 初始化随机数种子

     for (int i = 0; i < num_elements; ++i) {
         int random_number = rand() % (max_value - min_value + 1) + min_value;
         fprintf(file, "%d\n", random_number);
     }

     if (fclose(file) == 0) {
         printf("文件 %s 保存成功！\n", file_name);
     }
     else {
         printf("文件 %s 保存失败！\n", file_name);
     }

 }

 //读取对应文件的测试数据并选择相应的排序算法进行排序
 void read_and_sort_data(const char* file_name) {
     FILE* file = fopen(file_name, "r");
     if (file == NULL) {
         printf("无法打开文件 %s\n", file_name);
         return;
     }

     // 获取文件中的数据个数
     int num_elements = 0;
     int value;
     while (fscanf(file, "%d", &value) != EOF) {
         num_elements++;
     }

     // 重新定位文件指针到文件开头
     fseek(file, 0, SEEK_SET);

     // 分配内存来存储数据
     int* data = (int*)malloc(num_elements * sizeof(int));

     // 读取数据到数组中
     int index = 0;
     while (fscanf(file, "%d", &value) != EOF) {
         data[index++] = value;
     }

     if (fclose(file) == 0) {
         printf("文件 %s 保存成功！\n", file_name);
     }
     else {
         printf("文件 %s 保存失败！\n", file_name);
         free(data);
         return;
     }

     int choice;
     printf("请选择排序算法：\n");
     printf("1. 插入排序\n");
     printf("2. 计数排序\n");
     printf("3. 基数排序\n");
     printf("4. 归并排序\n");
     printf("5. 快速排序\n");
     printf("请输入选择的序号：");
     scanf("%d", &choice);

     // 根据用户选择的排序算法进行排序
     switch (choice) {
     case 1:
         // 调用插入排序函数
         InsertSort(data, num_elements);
         printf("您选择了插入排序。\n");
         break;
     case 2:
         // 调用插入排序函数
         CountingSort(data, num_elements);
         printf("您选择了计数排序。\n");
         break;
     case 3:
         // 调用基数排序函数
         RadixSort(data, num_elements);
         printf("您选择了基数排序。\n");
         break;
     case 4:
         // 调用归并排序函数
         MergeSort(data, 0, num_elements-1);
         printf("您选择了归并排序。\n");
         break;
     case 5:
         // 调用快速排序函数
         QuickSort(data, 0, num_elements-1);
         printf("您选择了快速排序。\n");
         break;
     default:
         printf("无效的选择！\n");
     }
     
     printf("排序成功\n");
     //释放动态分配的内存
     free(data);
 }

 int main() {

     int sizes[] = { 10000,50000,200000 };
     int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

     int arr_size = 100; // 数组大小
     int num_tests = 100000; // 测试次数

     const char* file_name = "test_data.txt";

     int choice;
     do {
         printf("请选择具体功能：\n");
         printf("1. 不同大数据量下的排序时间测试\n");
         printf("2. 大量小数据量下的排序时间测试\n");
         printf("3. 生成测试数据文件\n");
         printf("4. 读取文件中数据并且排序\n");
         printf("5. 退出整个程序\n");
         printf("\n请输入选择的序号：");
         scanf("%d", &choice);

         //根据用户的选择执行对应功能
         switch (choice) {
         case 1:
             srand(time(NULL)); // 初始化随机数种子
             for (int i = 0; i < num_sizes; ++i) {
                 int size = sizes[i];
                 printf("\n测试数据的层次： %d\n", size);
                 printf("插入排序： %.6f秒\n", test_sort_algorithm1(InsertSort, size));
                 printf("计数排序： %.6f秒\n", test_sort_algorithm1(CountingSort, size));
                 printf("基数排序： %.6f秒\n", test_sort_algorithm1(RadixSort, size));
                 printf("归并排序： %.6f秒\n", test_sort_algorithm2(MergeSort, size));
                 printf("快速排序： %.6f秒\n", test_sort_algorithm2(QuickSort, size));
             }
             break;

         case 2:
             // 测试插入排序
             double InsertSort_time = test_sort_algorithm3(InsertSort, arr_size, num_tests);
             printf("插入排序用时（%d个数据*%d次排序）: %.6f秒\n", arr_size, num_tests, InsertSort_time);

             // 测试计数排序
             double CountingSort_time = test_sort_algorithm3(CountingSort, arr_size, num_tests);
             printf("计数排序用时（%d个数据*%d次排序）: %.6f秒\n", arr_size, num_tests, CountingSort_time);

             // 测试基数排序
             double RadixSort_time = test_sort_algorithm3(RadixSort, arr_size, num_tests);
             printf("基数排序用时（%d个数据*%d次排序）: %.6f秒\n", arr_size, num_tests, RadixSort_time);

             // 测试归并排序
             double MergeSort_time = test_sort_algorithm4(MergeSort, arr_size, num_tests);
             printf("归并排序用时（%d个数据*%d次排序）: %.6f 秒\n", arr_size, num_tests, MergeSort_time);

             // 测试快速排序
             double QuickSort_time = test_sort_algorithm4(QuickSort, arr_size, num_tests);
             printf("快速排序用时（%d个数据*%d次排序）: %.6f 秒\n", arr_size, num_tests, QuickSort_time);
             break;

         case 3:
             generate_test_data(file_name);
             break;

         case 4:
             read_and_sort_data(file_name);
             break;

         case 5:
             printf("你已经退出");
             break;

         default:
             printf("无效的选择！\n");
         }  
         printf("\n");

     } while (choice != 5);

     return 0;
 }


