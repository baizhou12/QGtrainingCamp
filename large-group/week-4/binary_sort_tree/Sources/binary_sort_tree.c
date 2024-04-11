#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include"binary_sort_tree.h"

// �����½ڵ�ĺ���
Node* CreateNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// ������������в���һ���½ڵ�ĺ���
Node* InsertNode(Node* root, int key) {
    // ������ǿյģ�����һ���½ڵ�
    if (root == NULL) return CreateNode(key);

    // ���򣬵ݹ���½���������������������
    if (key < root->key)
        root->left = InsertNode(root->left, key);
    else if (key > root->key)
        root->right = InsertNode(root->right, key);

    // ���أ�δ�޸ĵģ��ڵ�ָ��
    return root;
}

// �ڶ����������в���һ�����ĺ���
Node* SearchNode(Node* root, int key) {
    // ������������ǿջ�����ڸ���
    if (root == NULL || root->key == key)
        return root;

    // �����ڸ��ļ�
    if (root->key < key)
        return SearchNode(root->right, key);

    // ��С�ڸ��ļ�
    return SearchNode(root->left, key);
}

// Ѱ�Ҷ�������������С�ڵ�ĸ�������
Node* MinValueNode(Node* root) {
    Node* current = root;

    // ѭ�����ҵ�����ߵ�Ҷ�ӽڵ�
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// �Ӷ�����������ɾ���ڵ�ĺ���
Node* DeleteNode(Node* root, int key) {
    // �����Ϊ�գ�ֱ�ӷ���
    if (root == NULL) return root;

    // �ݹ������Ѱ��Ҫɾ���Ľڵ�
    if (key < root->key)
        root->left = DeleteNode(root->left, key);
    else if (key > root->key)
        root->right = DeleteNode(root->right, key);
    else {
        // ����ҵ���Ҫɾ���Ľڵ�

        // �ڵ�ֻ��һ���ӽڵ��û���ӽڵ�����
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // �ڵ��������ӽڵ��������ҵ��������е���С�ڵ�
        Node* temp = MinValueNode(root->right);

        // ���������е���С�ڵ�ļ����Ƶ���ǰ�ڵ�
        root->key = temp->key;

        // �ݹ��ɾ���������е���С�ڵ�
        root->right = DeleteNode(root->right, temp->key);
    }
    return root;
}

//ǰ������ĵݹ��㷨
void PreOrderTraverse_recursion(Node* root) {
    if (root == NULL) {
        return;
   }
    else {
        printf("%d ", root->key);
        PreOrderTraverse_recursion(root->left);
        PreOrderTraverse_recursion(root->right);
    }
}

//��������ĵݹ��㷨
void InOrderTraverse_recursion(Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        InOrderTraverse_recursion(root->left);
        printf("%d ", root->key);
        InOrderTraverse_recursion(root->right);
    }
}

//��������ĵݹ��㷨
void PostOrderTraverse_recursion(Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        PostOrderTraverse_recursion(root->left);
        PostOrderTraverse_recursion(root->right);
        printf("%d ", root->key);
    }
}

// ǰ������ķǵݹ�汾
void PreOrderTraverse(Node* root) {
    if (root == NULL) return;

    // ����һ��ջ
    Node* stack[MAX_SIZE];
    int top = -1;

    // �����ڵ�ѹ��ջ
    stack[++top] = root;

    // ѭ��ֱ��ջΪ��
    while (top >= 0) {
        // ����ջ���ڵ�
        Node* current = stack[top--];
        printf("%d ", current->key);

        // ���������������������ѹ��ջ
        if (current->right)
            stack[++top] = current->right;

        // ���������������������ѹ��ջ
        if (current->left)
            stack[++top] = current->left;
    }
}

//��������ķǵݹ�汾
void InorderTraverse(Node* root) {
    if (root == NULL) return;

    // ����һ��ջ
    Node* stack[MAX_SIZE];
    int top = -1;
    Node* current = root;

    // ѭ��ֱ��ջΪ���ҵ�ǰ�ڵ�Ϊ��
    while (top >= 0 || current != NULL) {
        // ����ǰ�ڵ㼰�����ӽڵ�����ѹ��ջ
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // ����ջ���ڵ㲢����
        current = stack[top--];
        printf("%d ", current->key);

        // �����ӽڵ�����Ϊ��ǰ�ڵ�
        current = current->right;
    }
}

// ��������ķǵݹ�汾
void PostorderTraverse(Node* root) {
    if (root == NULL) return;

    // ��������ջ
    Node* stack1[MAX_SIZE];
    Node* stack2[MAX_SIZE];
    int top1 = -1, top2 = -1;
    Node* current = root;

    // �����ڵ�ѹ���һ��ջ
    stack1[++top1] = root;

    // ѭ��ֱ����һ��ջΪ��
    while (top1 >= 0) {
        // ������һ��ջ���ڵ㲢ѹ��ڶ���ջ
        current = stack1[top1--];
        stack2[++top2] = current;

        // ��������ӽڵ㣬�����ӽڵ�ѹ���һ��ջ
        if (current->left)
            stack1[++top1] = current->left;

        // ��������ӽڵ㣬�����ӽڵ�ѹ���һ��ջ
        if (current->right)
            stack1[++top1] = current->right;
    }

    // ����ڶ���ջ�еĽڵ�
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->key);
    }
}

// �������������
void LevelOrderTraverse(Node* root) {
    // ����һ���������ڴ洢�������Ľ��
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*));
    int front = 0;  // ��ͷָ��
    int rear = 0;   // ��βָ��

    if (root == NULL) {
        return;
    }

    // ����������
    queue[rear++] = root;

    while (front < rear) {
        // ���Ӳ����ʵ�ǰ���
        struct Node* currentNode = queue[front++];
        printf("%d ", currentNode->key);

        // ����ǰ���������ӽ�����
        if (currentNode->left != NULL) {
            queue = (struct Node**)realloc(queue, (rear + 1) * sizeof(struct Node*));
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right != NULL) {
            queue = (struct Node**)realloc(queue, (rear + 1) * sizeof(struct Node*));
            queue[rear++] = currentNode->right;
        }
    }

    // �ͷŶ����ڴ�
    free(queue);
}

int main() {
    // ����������
    struct Node* root = CreateNode(100);
    root->left = CreateNode(70);
    root->right = CreateNode(120);
    root->left->left = CreateNode(50);
    root->left->right = CreateNode(80);

    int choice;
    do {
        printf("--------------------------------------\n");
        printf("1.����һ���½ڵ�\n");
        printf("2.����ĳһ���ڵ�\n");
        printf("3.ɾ��ĳһ���ڵ�\n");
        printf("4.ǰ�����(�ݹ�)\n");
        printf("5.�������(�ݹ�)\n");
        printf("6.�������(�ݹ�)\n");
        printf("7.ǰ�����\n");
        printf("8.�������\n");
        printf("9.�������\n");
        printf("10.�������\n");
        printf("11.�˳�\n");
        printf("--------------------------------------\n");
        
        //����������湦�ܵ���
        int key;
        Node* searchNode = NULL;

        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("��������Ҫ����Ľڵ����ֵ:\n");
            scanf("%d", &key);
            searchNode = SearchNode(root, key);
            if (searchNode != NULL) {
                printf("��������������Ѿ�����ֵΪ%d�Ľڵ�\n", key);
                break;
            }
            else {
                InsertNode(root, key);
                printf("����ɹ�\n");
            }
            break;
        case 2:
            printf("����������Ҫ���ҽڵ����ֵ:\n");
            scanf("%d", &key);
            searchNode= SearchNode(root, key);
            if (searchNode == NULL) {
                printf("�������������û����ֵΪ%d�Ľڵ�\n", key);
            }
            else {
                printf("���ҳɹ����Ѿ�����ָ��ýڵ��ָ��\n");
            }
                break;
        case 3:
            printf("����������Ҫɾ���ڵ����ֵ:\n");
            scanf("%d", &key);
            if (searchNode == NULL) {
                printf("�������������û����ֵΪ%d�Ľڵ�\n", key);
                break;
            }
            else {
                DeleteNode(root, key);
                printf("ɾ���ɹ�\n");
            }
            break;
        case 4:
            PreOrderTraverse_recursion(root);
            printf("\n");
            break;
        case 5:
            InOrderTraverse_recursion(root);
            printf("\n");
            break;
        case 6:
            PostOrderTraverse_recursion(root);
            printf("\n");
            break;
        case 7:
            PreOrderTraverse(root);
            printf("\n");
            break;
        case 8:
            InorderTraverse(root);
            printf("\n");
            break;
        case 9:
            PostorderTraverse(root);
            printf("\n");
            break;
        case 10:
            LevelOrderTraverse(root);
            printf("\n");
            break;
        case 11:
            printf("���Ѿ��˳�\n");
            break;
        default:
            printf("��Ч��ѡ��\n");
        }
    } while (choice != 11);

    system("pause");
    return 0;
}