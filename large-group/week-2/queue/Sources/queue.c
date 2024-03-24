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
        free(temp->data); // �ͷŽڵ�����
        free(temp); // �ͷŽڵ�
    }
    queue->rear = NULL; // ������β��ָ���ÿ�
}

int main() {
    Queue* queue = createQueue();
    int choice;
    int intValue;
    float floatValue;
    char* stringValue;

    while (1) {
        printf("\nѡ�����:\n");
        printf("1. ���\n");
        printf("2. �ͷŶ���\n");
        printf("3. �˳�\n");
        printf("������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("������Ҫ��ӵ��������� (1: ����, 2: ������, 3: �ַ���): ");
            int dataType;
            scanf("%d", &dataType);
            switch (dataType) {
            case 1:
                printf("����������ֵ: ");
                if (scanf("%d", &intValue) == 1) {
                    enqueue(queue, &intValue);
                }
                else {
                    printf("������������������Ҫ����������Ͳ�ƥ��\n");
                }
                break;
            case 2:
                printf("�����븡����ֵ: ");
                if (scanf("%f", &floatValue) == 1) {
                    enqueue(queue, &floatValue);
                }
                else {
                    printf("������������������Ҫ����������Ͳ�ƥ��\n");
                }
                break;
            case 3:
                stringValue = (char*)malloc(100 * sizeof(char));
                printf("�������ַ���ֵ: ");
                if (scanf("%s", stringValue) == 1) {
                    enqueue(queue, stringValue);
                }
                else {
                    printf("������������������Ҫ����������Ͳ�ƥ��\n");
                    free(stringValue); // �ͷ�δʹ�õ��ַ����ڴ�
                }
                break;
            default:
                printf("��Ч����������\n");
            }
            break;
        case 2:
            printf("�ͷŶ���\n");
            releaseQueue(queue);
            printf("�������ͷ�\n");
            break;
        case 3:
            printf("�����˳�\n");
            exit(0);
        default:
            printf("��Ч��ѡ��\n");
        }
    }

    return 0;

    system("pause");
}

