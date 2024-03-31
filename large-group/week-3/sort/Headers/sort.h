#pragma once

//��������
void InsertSort(int a[], int len);

// �ϲ�������������
void merge(int arr[], int left, int mid, int right);
//�鲢������
void MergeSort(int arr[], int left, int right);


// ��������������Ԫ�ص�ֵ
void swap(int* a, int* b);
// ���ݵ�һ��Ԫ����Ϊ��׼ֵ���з����������ػ�׼ֵ������
int partition(int arr[], int low, int high);

// ����������
void QuickSort(int arr[], int low, int high);

// ����������
void CountingSort(int arr[], int n);


//���������еļ�������
void CountSort(int arr[], int n, int exp);

// ����������
void RadixSort(int arr[], int n);

//���Ժ���1��2�����������в�ͬ���������µ�����ʱ����򣬷�1��2��Ҫ�Ǹ������������ββ���ȫһ��

// ���Ժ���1
double test_sort_algorithm1(void (*algorithm)(int arr[], int n), int arr_size);

// ���Ժ���2
double test_sort_algorithm2(void (*algorithm)(int arr[], int start, int end), int arr_size);

//���Ժ���3��4�����������д���С�������µ�����ʱ����򣬷�3��4��Ҫ�Ǹ������������ββ���ȫһ��

 //���Ժ���3
double test_sort_algorithm3(void (*algorithm)(int arr[], int n), int arr_size, int num_tests);

//���Ժ���4
double test_sort_algorithm4(void (*algorithm)(int arr[], int start, int end), int arr_size, int num_tests);

//���ɲ������ݲ����浽��Ӧ���ļ�
void generate_test_data(const char* file_name);

//��ȡ��Ӧ�ļ��Ĳ������ݲ�ѡ����Ӧ�������㷨��������
void read_and_sort_data(const char* file_name);
