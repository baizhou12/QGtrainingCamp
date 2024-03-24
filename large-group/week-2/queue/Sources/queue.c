#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include"queue.h"

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void releaseQueue(Queue* queue) {
    while (queue->front != NULL) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp->data); // 释放节点数据
        free(temp); // 释放节点
    }
    queue->rear = NULL; // 将队列尾部指针置空
}

int main() {
    Queue* queue = createQueue();
    int choice;
    int intValue;
    float floatValue;
    char* stringValue;

    while (1) {
        printf("\n选择操作:\n");
        printf("1. 入队\n");
        printf("2. 释放队列\n");
        printf("3. 退出\n");
        printf("请输入选项: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入要入队的数据类型 (1: 整数, 2: 浮点数, 3: 字符串): ");
            int dataType;
            scanf("%d", &dataType);
            switch (dataType) {
            case 1:
                printf("请输入整数值: ");
                if (scanf("%d", &intValue) == 1) {
                    enqueue(queue, &intValue);
                }
                else {
                    printf("错误：输入数据类型与要求的数据类型不匹配\n");
                }
                break;
            case 2:
                printf("请输入浮点数值: ");
                if (scanf("%f", &floatValue) == 1) {
                    enqueue(queue, &floatValue);
                }
                else {
                    printf("错误：输入数据类型与要求的数据类型不匹配\n");
                }
                break;
            case 3:
                stringValue = (char*)malloc(100 * sizeof(char));
                printf("请输入字符串值: ");
                if (scanf("%s", stringValue) == 1) {
                    enqueue(queue, stringValue);
                }
                else {
                    printf("错误：输入数据类型与要求的数据类型不匹配\n");
                    free(stringValue); // 释放未使用的字符串内存
                }
                break;
            default:
                printf("无效的数据类型\n");
            }
            break;
        case 2:
            printf("释放队列\n");
            releaseQueue(queue);
            printf("队列已释放\n");
            break;
        case 3:
            printf("程序退出\n");
            exit(0);
        default:
            printf("无效的选项\n");
        }
    }

    return 0;

    system("pause");
}

