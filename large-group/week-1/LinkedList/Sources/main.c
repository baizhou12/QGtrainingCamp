#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"
#include "doubly_linked_list.h"

int main() {
    int choice;

    do {
        printf("Choose an option:\n");
        printf("1. Create and display a singly linked list\n");
        printf("2. Create and display a doubly linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            // 创建并显示单链表
            struct Node* singlyList = createSinglyLinkedList();
            displaySinglyLinkedList(singlyList);
            deleteSinglyLinkedList(singlyList);
            break;
        }
        case 2: {
            // 创建并显示双向链表
            struct Node* doublyList = createDoublyLinkedList();
            displayDoublyLinkedList(doublyList);
            deleteDoublyLinkedList(doublyList);
            break;
        }
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 3);

    return 0;
}