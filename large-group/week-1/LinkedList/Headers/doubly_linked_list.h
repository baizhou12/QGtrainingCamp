#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// 双向链表节点结构体
struct DoubleNode {
    int data;               // 节点数据
    struct DoubleNode* prev;      // 指向上一个节点的指针
    struct DoubleNode* next;      // 指向下一个节点的指针
};

// 创建双向链表
struct DoubleNode* createDoublyLinkedList();

// 删除双向链表
void deleteDoublyLinkedList(struct DoubleNode* head);

// 显示双向链表
void displayDoublyLinkedList(struct DoubleNode* head);

#endif