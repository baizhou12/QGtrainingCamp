#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

// ����˫������
struct DoubleNode* createDoublyLinkedList() {
    struct DoubleNode* head = NULL;   // ͷָ�룬ָ������ĵ�һ���ڵ�
    struct DoubleNode* tail = NULL;   // βָ�룬ָ����������һ���ڵ�
    int data;
    char choice;

    do {
        printf("Enter data for the node: ");
        scanf("%d", &data);

        // �����½ڵ�
        struct DoubleNode* newNode = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            // �������Ϊ�գ���ͷָ���βָ�붼ָ���½ڵ�
            head = newNode;
            tail = newNode;
        }
        else {
            // �����½ڵ����ӵ������β����������βָ��
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

// ɾ��˫������
void deleteDoublyLinkedList(struct DoubleNode* head) {
    struct DoubleNode* current = head;    // ��ǰ�ڵ�ָ��
    struct DoubleNode* temp;

    while (current != NULL) {
        temp = current;             // ���浱ǰ�ڵ�ĵ�ַ
        current = current->next;    // �ƶ�����һ���ڵ�
        free(temp);                 // �ͷŵ�ǰ�ڵ���ڴ�
    }
}

// ��ʾ˫������
void displayDoublyLinkedList(struct DoubleNode* head) {
    struct DoubleNode* current = head;    // ��ǰ�ڵ�ָ��

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);   // ��ӡ��ǰ�ڵ������
        current = current->next;            // �ƶ�����һ���ڵ�
    }
    printf("NULL\n");
}