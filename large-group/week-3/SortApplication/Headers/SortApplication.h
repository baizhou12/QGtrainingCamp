#pragma once

//���ɵ��������Ĵ�С
#define SIZE 10

//��ɫ����
void ColourSort(int a[], int n);


// ��������������Ԫ�ص�ֵ
void swap(int* a, int* b);

// ���ݵ�һ��Ԫ����Ϊ��׼ֵ���з����������ػ�׼ֵ������
int partition(int arr[], int low, int high);

//�ҳ����е�kС����
int FindKthLargest(int arr[], int low, int high, int k);
