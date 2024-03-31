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

 // �ϲ�������������
 void merge(int arr[], int left, int mid, int right) {
     int n1 = mid - left + 1;
     int n2 = right - mid;
     int* L = (int*)malloc(n1 * sizeof(int));
     int* R = (int*)malloc(n1 * sizeof(int));
     int i, j, k;

     // �����ݸ��Ƶ���ʱ���� L �� R ��
     for (i = 0; i < n1; i++)
         L[i] = arr[left + i];
     for (j = 0; j < n2; j++)
         R[j] = arr[mid + 1 + j];

     // �鲢��ʱ���鵽 arr[left..right]
     i = 0;
     j = 0;
     k = left;
     while (i < n1 && j < n2) {
         arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
     }

     // ��ʣ��Ԫ�ظ��Ƶ� arr ��
     while (i < n1) {
         arr[k++] = L[i++];
     }
     while (j < n2) {
         arr[k++] = R[j++];
     }

     //�ͷŶ�̬�����ڴ�
     free(L);
     free(R);
 }

 // �鲢������
 void MergeSort(int arr[], int left, int right) {
     if (left < right) {
         int mid = left + (right - left) / 2;
         MergeSort(arr, left, mid);
         MergeSort(arr, mid + 1, right);
         merge(arr, left, mid, right);
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

 // ����������
 void QuickSort(int arr[], int low, int high) {
     if (low < high) {
         // ��������з���������ȡ��׼ֵ������
         int pi = partition(arr, low, high);
         // �Ի�׼ֵ��ߵ���������п�������
         QuickSort(arr, low, pi - 1);
         // �Ի�׼ֵ�ұߵ���������п�������
         QuickSort(arr, pi + 1, high);
     }
 }

 // ����������
 void CountingSort(int arr[], int n) {
     // ���������е����ֵ��ȷ����������Ĵ�С
     int max = arr[0];
     for (int i = 1; i < n; ++i) {
         if (arr[i] > max) {
             max = arr[i];
         }
     }

     // �����������飬����ʼ��Ϊ0
     int* count = (int*)malloc((max + 1) * sizeof(int));
     for (int i = 0; i <= max; ++i) {
         count[i] = 0;
     }

     // ͳ��ÿ��Ԫ�س��ֵĴ���
     for (int i = 0; i < n; ++i) {
         count[arr[i]]++;
     }

     // ���ݼ����������¶�ԭʼ�����������
     int index = 0;
     for (int i = 0; i <= max; ++i) {
         while (count[i] > 0) {
             arr[index++] = i;
             count[i]--;
         }
     }

     // �ͷŶ�̬������ڴ�
     free(count);
 }

 //���������еļ�������
void CountSort(int arr[], int n, int exp) {
     int* output=(int*)malloc(n*sizeof(int)); // ��ʱ�������ڴ洢�����Ľ��
     int count[10] = { 0 }; // ��������

     // ͳ��ÿ�����ֳ��ֵĴ���
     for (int i = 0; i < n; i++) {
         count[(arr[i] / exp) % 10]++;
     }

     // ����������ת��Ϊλ�����飬��ʾÿ����������������е�λ��
     for (int i = 1; i < 10; i++) {
         count[i] += count[i - 1];
     }

     // ���ݵ�ǰλ�������ַ�����ʱ�����У���ͬʱ���¼�������
     for (int i = n - 1; i >= 0; i--) {
         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
         count[(arr[i] / exp) % 10]--;
     }

     // �������Ľ�����ƻ�ԭʼ����
     for (int i = 0; i < n; i++) {
         arr[i] = output[i];
     }

     //�ͷŶ�̬�����ڴ�
     free(output);
 }

 // ����������
 void RadixSort(int arr[], int n) {
     // ��ȡ�����е��������
     int max = arr[0];
     for (int i = 1; i < n; i++) {
         if (arr[i] > max) {
             max = arr[i];
         }
     }

     // ��ÿ��λ���������򣬴Ӹ�λ��ʼֱ�����λ
     for (int exp = 1; max / exp > 0; exp *= 10) {
         CountSort(arr,n,exp);
     }
 }

 // ���Ժ���1
 double test_sort_algorithm1(void (*algorithm)(int arr[], int n), int arr_size) {
     int* arr = (int*)malloc(sizeof(int) * arr_size);
     // �����������
     for (int i = 0; i < arr_size; ++i) {
         arr[i] = rand(); // ���������
     }

     clock_t start_time, end_time;
     start_time = clock();
     // ���������㷨
     algorithm(arr, arr_size);
     end_time = clock();

     free(arr);

     return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
 }

 // ���Ժ���2
 double test_sort_algorithm2(void (*algorithm)(int arr[], int start,int end), int arr_size) {
     int* arr = (int*)malloc(sizeof(int) * arr_size);
     // �����������
     for (int i = 0; i < arr_size; ++i) {
         arr[i] = rand(); // ���������
     }

     clock_t start_time, end_time;
     start_time = clock();
     // ���������㷨
     algorithm(arr,0, arr_size-1);
     end_time = clock();

     free(arr);

     return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
 }

 //���Ժ���3
 double test_sort_algorithm3(void (*algorithm)(int arr[], int n), int arr_size, int num_tests) {
     double total_time = 0.0;

     for (int i = 0; i < num_tests; ++i) {
         int* arr = (int*)malloc(sizeof(int) * arr_size);
         // �����������
         for (int j = 0; j < arr_size; ++j) {
             arr[j] = rand(); // ���������
         }

         clock_t start_time, end_time;
         start_time = clock();
         // ���������㷨
         algorithm(arr, arr_size); // ����������ʼ�����ͽ�������
         end_time = clock();

         total_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

         free(arr);
     }

     return total_time;
 }

 //���Ժ���4
 double test_sort_algorithm4(void (*algorithm)(int arr[], int start, int end), int arr_size, int num_tests) {
     double total_time = 0.0;

     for (int i = 0; i < num_tests; ++i) {
         int* arr = (int*)malloc(sizeof(int) * arr_size);
         // �����������
         for (int j = 0; j < arr_size; ++j) {
             arr[j] = rand(); // ���������
         }

         clock_t start_time, end_time;
         start_time = clock();
         // ���������㷨
         algorithm(arr, 0, arr_size - 1); // ����������ʼ�����ͽ�������
         end_time = clock();

         total_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

         free(arr);
     }

     return total_time;
 }

 //���ɲ������ݲ����浽��Ӧ���ļ�
 void generate_test_data(const char* file_name) {
     int num_elements, min_value, max_value;

     printf("������Ҫ���ɵ���������");
     scanf("%d", &num_elements);

     printf("���������������Сֵ��");
     scanf("%d", &min_value);

     printf("����������������ֵ��");
     scanf("%d", &max_value);

     FILE* file = fopen(file_name, "w");
     if (file == NULL) {
         printf("�޷����ļ� %s\n", file_name);
         return;
     }

     srand(time(NULL)); // ��ʼ�����������

     for (int i = 0; i < num_elements; ++i) {
         int random_number = rand() % (max_value - min_value + 1) + min_value;
         fprintf(file, "%d\n", random_number);
     }

     if (fclose(file) == 0) {
         printf("�ļ� %s ����ɹ���\n", file_name);
     }
     else {
         printf("�ļ� %s ����ʧ�ܣ�\n", file_name);
     }

 }

 //��ȡ��Ӧ�ļ��Ĳ������ݲ�ѡ����Ӧ�������㷨��������
 void read_and_sort_data(const char* file_name) {
     FILE* file = fopen(file_name, "r");
     if (file == NULL) {
         printf("�޷����ļ� %s\n", file_name);
         return;
     }

     // ��ȡ�ļ��е����ݸ���
     int num_elements = 0;
     int value;
     while (fscanf(file, "%d", &value) != EOF) {
         num_elements++;
     }

     // ���¶�λ�ļ�ָ�뵽�ļ���ͷ
     fseek(file, 0, SEEK_SET);

     // �����ڴ����洢����
     int* data = (int*)malloc(num_elements * sizeof(int));

     // ��ȡ���ݵ�������
     int index = 0;
     while (fscanf(file, "%d", &value) != EOF) {
         data[index++] = value;
     }

     if (fclose(file) == 0) {
         printf("�ļ� %s ����ɹ���\n", file_name);
     }
     else {
         printf("�ļ� %s ����ʧ�ܣ�\n", file_name);
         free(data);
         return;
     }

     int choice;
     printf("��ѡ�������㷨��\n");
     printf("1. ��������\n");
     printf("2. ��������\n");
     printf("3. ��������\n");
     printf("4. �鲢����\n");
     printf("5. ��������\n");
     printf("������ѡ�����ţ�");
     scanf("%d", &choice);

     // �����û�ѡ��������㷨��������
     switch (choice) {
     case 1:
         // ���ò���������
         InsertSort(data, num_elements);
         printf("��ѡ���˲�������\n");
         break;
     case 2:
         // ���ò���������
         CountingSort(data, num_elements);
         printf("��ѡ���˼�������\n");
         break;
     case 3:
         // ���û���������
         RadixSort(data, num_elements);
         printf("��ѡ���˻�������\n");
         break;
     case 4:
         // ���ù鲢������
         MergeSort(data, 0, num_elements-1);
         printf("��ѡ���˹鲢����\n");
         break;
     case 5:
         // ���ÿ���������
         QuickSort(data, 0, num_elements-1);
         printf("��ѡ���˿�������\n");
         break;
     default:
         printf("��Ч��ѡ��\n");
     }
     
     printf("����ɹ�\n");
     //�ͷŶ�̬������ڴ�
     free(data);
 }

 int main() {

     int sizes[] = { 10000,50000,200000 };
     int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

     int arr_size = 100; // �����С
     int num_tests = 100000; // ���Դ���

     const char* file_name = "test_data.txt";

     int choice;
     do {
         printf("��ѡ����幦�ܣ�\n");
         printf("1. ��ͬ���������µ�����ʱ�����\n");
         printf("2. ����С�������µ�����ʱ�����\n");
         printf("3. ���ɲ��������ļ�\n");
         printf("4. ��ȡ�ļ������ݲ�������\n");
         printf("5. �˳���������\n");
         printf("\n������ѡ�����ţ�");
         scanf("%d", &choice);

         //�����û���ѡ��ִ�ж�Ӧ����
         switch (choice) {
         case 1:
             srand(time(NULL)); // ��ʼ�����������
             for (int i = 0; i < num_sizes; ++i) {
                 int size = sizes[i];
                 printf("\n�������ݵĲ�Σ� %d\n", size);
                 printf("�������� %.6f��\n", test_sort_algorithm1(InsertSort, size));
                 printf("�������� %.6f��\n", test_sort_algorithm1(CountingSort, size));
                 printf("�������� %.6f��\n", test_sort_algorithm1(RadixSort, size));
                 printf("�鲢���� %.6f��\n", test_sort_algorithm2(MergeSort, size));
                 printf("�������� %.6f��\n", test_sort_algorithm2(QuickSort, size));
             }
             break;

         case 2:
             // ���Բ�������
             double InsertSort_time = test_sort_algorithm3(InsertSort, arr_size, num_tests);
             printf("����������ʱ��%d������*%d������: %.6f��\n", arr_size, num_tests, InsertSort_time);

             // ���Լ�������
             double CountingSort_time = test_sort_algorithm3(CountingSort, arr_size, num_tests);
             printf("����������ʱ��%d������*%d������: %.6f��\n", arr_size, num_tests, CountingSort_time);

             // ���Ի�������
             double RadixSort_time = test_sort_algorithm3(RadixSort, arr_size, num_tests);
             printf("����������ʱ��%d������*%d������: %.6f��\n", arr_size, num_tests, RadixSort_time);

             // ���Թ鲢����
             double MergeSort_time = test_sort_algorithm4(MergeSort, arr_size, num_tests);
             printf("�鲢������ʱ��%d������*%d������: %.6f ��\n", arr_size, num_tests, MergeSort_time);

             // ���Կ�������
             double QuickSort_time = test_sort_algorithm4(QuickSort, arr_size, num_tests);
             printf("����������ʱ��%d������*%d������: %.6f ��\n", arr_size, num_tests, QuickSort_time);
             break;

         case 3:
             generate_test_data(file_name);
             break;

         case 4:
             read_and_sort_data(file_name);
             break;

         case 5:
             printf("���Ѿ��˳�");
             break;

         default:
             printf("��Ч��ѡ��\n");
         }  
         printf("\n");

     } while (choice != 5);

     return 0;
 }


