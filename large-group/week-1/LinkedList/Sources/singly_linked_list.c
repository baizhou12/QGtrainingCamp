#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

// ����������
struct SingNode* createSinglyLinkedList() {
    struct SingNode* head = NULL;   // ͷָ�룬ָ������ĵ�һ���ڵ�
    struct SingNode* tail = NULL;   // βָ�룬ָ����������һ���ڵ�
    int data;
    char choice;

    do {
        printf("Enter data for the node: ");
        scanf("%d", &data);

        // �����½ڵ�
        struct SingNode* newNode = (struct SingNode*)malloc(sizeof(struct SingNode));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            // �������Ϊ�գ���ͷָ���βָ�붼ָ���½ڵ�
            head = newNode;
            tail = newNode;
        }
        else {
            // �����½ڵ����ӵ������β����������βָ��
            tail->next = newNode;
            tail = newNode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

// ɾ��������
void deleteSinglyLinkedList(struct SingNode* head) {
    struct SingNode* current = head;    // ��ǰ�ڵ�ָ��
    struct SingNode* temp;

    while (current != NULL) {
        temp = current;             // ���浱ǰ�ڵ�ĵ�ַ
        current = current->next;    // �ƶ�����һ���ڵ�
        free(temp);                 // �ͷŵ�ǰ�ڵ���ڴ�
    }
}

// ��ʾ������
void displaySinglyLinkedList(struct SingNode* head) {
    struct SingNode* current = head;    // ��ǰ�ڵ�ָ��

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);   // ��ӡ��ǰ�ڵ������
        current = current->next;            // �ƶ�����һ���ڵ�
    }
    printf("NULL\n");
}