#pragma once


// �ڵ�ṹ��
typedef struct Node {
    void* data;  // ������ָ�룬���ڴ洢�������͵�����
    struct Node* next;
} Node;

// ���нṹ��
typedef struct {
    Node* front;  // ����ͷ��ָ��
    Node* rear;   // ����β��ָ��
} Queue;

// ��������
Queue* createQueue();


// ��Ӳ���
void enqueue(Queue* queue, void* data);


// �ͷŶ���
void releaseQueue(Queue* queue);