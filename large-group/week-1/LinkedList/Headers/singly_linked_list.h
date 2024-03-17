
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

//单链表结构体
struct SingNode {
    int data;               // 节点数据
    struct SingNode* next;  // 指向下一个节点的指针
};

// 创建单链表
struct SingNode* createSinglyLinkedList();

// 删除单链表
void deleteSinglyLinkedList(struct SingNode* head);

// 显示单链表
void displaySinglyLinkedList(struct SingNode* head);

#endif