#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include"binary_sort_tree.h"

// 创建新节点的函数
Node* CreateNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// 向二叉排序树中插入一个新节点的函数
Node* InsertNode(Node* root, int key) {
    // 如果树是空的，返回一个新节点
    if (root == NULL) return CreateNode(key);

    // 否则，递归地下降到树的左子树或右子树
    if (key < root->key)
        root->left = InsertNode(root->left, key);
    else if (key > root->key)
        root->right = InsertNode(root->right, key);

    // 返回（未修改的）节点指针
    return root;
}

// 在二叉排序树中查找一个键的函数
Node* SearchNode(Node* root, int key) {
    // 基本情况：根是空或键就在根处
    if (root == NULL || root->key == key)
        return root;

    // 键大于根的键
    if (root->key < key)
        return SearchNode(root->right, key);

    // 键小于根的键
    return SearchNode(root->left, key);
}

// 寻找二叉排序树中最小节点的辅助函数
Node* MinValueNode(Node* root) {
    Node* current = root;

    // 循环地找到最左边的叶子节点
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// 从二叉排序树中删除节点的函数
Node* DeleteNode(Node* root, int key) {
    // 如果根为空，直接返回
    if (root == NULL) return root;

    // 递归地向下寻找要删除的节点
    if (key < root->key)
        root->left = DeleteNode(root->left, key);
    else if (key > root->key)
        root->right = DeleteNode(root->right, key);
    else {
        // 如果找到了要删除的节点

        // 节点只有一个子节点或没有子节点的情况
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

        // 节点有两个子节点的情况，找到右子树中的最小节点
        Node* temp = MinValueNode(root->right);

        // 将右子树中的最小节点的键复制到当前节点
        root->key = temp->key;

        // 递归地删除右子树中的最小节点
        root->right = DeleteNode(root->right, temp->key);
    }
    return root;
}

//前序遍历的递归算法
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

//中序遍历的递归算法
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

//后序遍历的递归算法
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

// 前序遍历的非递归版本
void PreOrderTraverse(Node* root) {
    if (root == NULL) return;

    // 创建一个栈
    Node* stack[MAX_SIZE];
    int top = -1;

    // 将根节点压入栈
    stack[++top] = root;

    // 循环直到栈为空
    while (top >= 0) {
        // 弹出栈顶节点
        Node* current = stack[top--];
        printf("%d ", current->key);

        // 如果有右子树，将右子树压入栈
        if (current->right)
            stack[++top] = current->right;

        // 如果有左子树，将左子树压入栈
        if (current->left)
            stack[++top] = current->left;
    }
}

//中序遍历的非递归版本
void InorderTraverse(Node* root) {
    if (root == NULL) return;

    // 创建一个栈
    Node* stack[MAX_SIZE];
    int top = -1;
    Node* current = root;

    // 循环直到栈为空且当前节点为空
    while (top >= 0 || current != NULL) {
        // 将当前节点及其左子节点依次压入栈
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // 弹出栈顶节点并访问
        current = stack[top--];
        printf("%d ", current->key);

        // 将右子节点设置为当前节点
        current = current->right;
    }
}

// 后序遍历的非递归版本
void PostorderTraverse(Node* root) {
    if (root == NULL) return;

    // 创建两个栈
    Node* stack1[MAX_SIZE];
    Node* stack2[MAX_SIZE];
    int top1 = -1, top2 = -1;
    Node* current = root;

    // 将根节点压入第一个栈
    stack1[++top1] = root;

    // 循环直到第一个栈为空
    while (top1 >= 0) {
        // 弹出第一个栈顶节点并压入第二个栈
        current = stack1[top1--];
        stack2[++top2] = current;

        // 如果有左子节点，将左子节点压入第一个栈
        if (current->left)
            stack1[++top1] = current->left;

        // 如果有右子节点，将右子节点压入第一个栈
        if (current->right)
            stack1[++top1] = current->right;
    }

    // 输出第二个栈中的节点
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->key);
    }
}

// 层序遍历二叉树
void LevelOrderTraverse(Node* root) {
    // 创建一个队列用于存储待遍历的结点
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*));
    int front = 0;  // 队头指针
    int rear = 0;   // 队尾指针

    if (root == NULL) {
        return;
    }

    // 将根结点入队
    queue[rear++] = root;

    while (front < rear) {
        // 出队并访问当前结点
        struct Node* currentNode = queue[front++];
        printf("%d ", currentNode->key);

        // 将当前结点的左右子结点入队
        if (currentNode->left != NULL) {
            queue = (struct Node**)realloc(queue, (rear + 1) * sizeof(struct Node*));
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right != NULL) {
            queue = (struct Node**)realloc(queue, (rear + 1) * sizeof(struct Node*));
            queue[rear++] = currentNode->right;
        }
    }

    // 释放队列内存
    free(queue);
}

int main() {
    // 创建二叉树
    struct Node* root = CreateNode(100);
    root->left = CreateNode(70);
    root->right = CreateNode(120);
    root->left->left = CreateNode(50);
    root->left->right = CreateNode(80);

    int choice;
    do {
        printf("--------------------------------------\n");
        printf("1.插入一个新节点\n");
        printf("2.查找某一个节点\n");
        printf("3.删除某一个节点\n");
        printf("4.前序遍历(递归)\n");
        printf("5.中序遍历(递归)\n");
        printf("6.后序遍历(递归)\n");
        printf("7.前序遍历\n");
        printf("8.中序遍历\n");
        printf("9.后序遍历\n");
        printf("10.层序遍历\n");
        printf("11.退出\n");
        printf("--------------------------------------\n");
        
        //用来方便后面功能调用
        int key;
        Node* searchNode = NULL;

        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("请你输入要插入的节点的数值:\n");
            scanf("%d", &key);
            searchNode = SearchNode(root, key);
            if (searchNode != NULL) {
                printf("这个二叉树里面已经有数值为%d的节点\n", key);
                break;
            }
            else {
                InsertNode(root, key);
                printf("插入成功\n");
            }
            break;
        case 2:
            printf("请你输入你要查找节点的数值:\n");
            scanf("%d", &key);
            searchNode= SearchNode(root, key);
            if (searchNode == NULL) {
                printf("这个二叉树里面没有数值为%d的节点\n", key);
            }
            else {
                printf("查找成功，已经返回指向该节点的指针\n");
            }
                break;
        case 3:
            printf("请你输入你要删除节点的数值:\n");
            scanf("%d", &key);
            if (searchNode == NULL) {
                printf("这个二叉树里面没有数值为%d的节点\n", key);
                break;
            }
            else {
                DeleteNode(root, key);
                printf("删除成功\n");
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
            printf("你已经退出\n");
            break;
        default:
            printf("无效的选择\n");
        }
    } while (choice != 11);

    system("pause");
    return 0;
}