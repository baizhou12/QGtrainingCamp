#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// ˫������ڵ�ṹ��
struct DoubleNode {
    int data;               // �ڵ�����
    struct DoubleNode* prev;      // ָ����һ���ڵ��ָ��
    struct DoubleNode* next;      // ָ����һ���ڵ��ָ��
};

// ����˫������
struct DoubleNode* createDoublyLinkedList();

// ɾ��˫������
void deleteDoublyLinkedList(struct DoubleNode* head);

// ��ʾ˫������
void displayDoublyLinkedList(struct DoubleNode* head);

#endif