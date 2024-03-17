
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

//������ṹ��
struct SingNode {
    int data;               // �ڵ�����
    struct SingNode* next;  // ָ����һ���ڵ��ָ��
};

// ����������
struct SingNode* createSinglyLinkedList();

// ɾ��������
void deleteSinglyLinkedList(struct SingNode* head);

// ��ʾ������
void displaySinglyLinkedList(struct SingNode* head);

#endif