#pragma once


// 节点结构体
typedef struct Node {
    void* data;  // 无类型指针，用于存储任意类型的数据
    struct Node* next;
} Node;

// 队列结构体
typedef struct {
    Node* front;  // 队列头部指针
    Node* rear;   // 队列尾部指针
} Queue;

// 创建队列
Queue* createQueue();


// 入队操作
void enqueue(Queue* queue, void* data);


// 释放队列
void releaseQueue(Queue* queue);