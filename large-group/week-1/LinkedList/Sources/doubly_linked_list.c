#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

// 创建双向链表
struct DoubleNode* createDoublyLinkedList() {
    struct DoubleNode* head = NULL;   // 头指针，指向链表的第一个节点
    struct DoubleNode* tail = NULL;   // 尾指针，指向链表的最后一个节点
    int data;
    char choice;

    do {
        printf("Enter data for the node: ");
        scanf("%d", &data);

        // 创建新节点
        struct DoubleNode* newNode = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            // 如果链表为空，将头指针和尾指针都指向新节点
            head = newNode;
            tail = newNode;
        }
        else {
            // 否则将新节点连接到链表的尾部，并更新尾指针
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

// 删除双向链表
void deleteDoublyLinkedList(struct DoubleNode* head) {
    struct DoubleNode* current = head;    // 当前节点指针
    struct DoubleNode* temp;

    while (current != NULL) {
        temp = current;             // 保存当前节点的地址
        current = current->next;    // 移动到下一个节点
        free(temp);                 // 释放当前节点的内存
    }
}

// 显示双向链表
void displayDoublyLinkedList(struct DoubleNode* head) {
    struct DoubleNode* current = head;    // 当前节点指针

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);   // 打印当前节点的数据
        current = current->next;            // 移动到下一个节点
    }
    printf("NULL\n");
}