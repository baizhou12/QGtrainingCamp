#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

// 创建单链表
struct SingNode* createSinglyLinkedList() {
    struct SingNode* head = NULL;   // 头指针，指向链表的第一个节点
    struct SingNode* tail = NULL;   // 尾指针，指向链表的最后一个节点
    int data;
    char choice;

    do {
        printf("Enter data for the node: ");
        scanf("%d", &data);

        // 创建新节点
        struct SingNode* newNode = (struct SingNode*)malloc(sizeof(struct SingNode));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            // 如果链表为空，将头指针和尾指针都指向新节点
            head = newNode;
            tail = newNode;
        }
        else {
            // 否则将新节点连接到链表的尾部，并更新尾指针
            tail->next = newNode;
            tail = newNode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

// 删除单链表
void deleteSinglyLinkedList(struct SingNode* head) {
    struct SingNode* current = head;    // 当前节点指针
    struct SingNode* temp;

    while (current != NULL) {
        temp = current;             // 保存当前节点的地址
        current = current->next;    // 移动到下一个节点
        free(temp);                 // 释放当前节点的内存
    }
}

// 显示单链表
void displaySinglyLinkedList(struct SingNode* head) {
    struct SingNode* current = head;    // 当前节点指针

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);   // 打印当前节点的数据
        current = current->next;            // 移动到下一个节点
    }
    printf("NULL\n");
}