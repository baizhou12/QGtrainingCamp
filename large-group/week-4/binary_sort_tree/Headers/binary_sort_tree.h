#pragma once
//栈的大小
#define MAX_SIZE 100

// 定义二叉树的节点结构体
typedef struct Node {
    int key;
    struct Node* left, * right;
} Node;

// 创建新节点的函数
Node* CreateNode(int key);

// 向二叉排序树中插入一个新节点的函数
Node* InsertNode(Node* root, int key);

// 在二叉排序树中查找一个键的函数
Node* SearchNode(Node* root, int key);

// 寻找二叉排序树中最小节点的辅助函数
Node* MinValueNode(Node* root);

// 从二叉排序树中删除节点的函数
Node* DeleteNode(Node* root, int key);

//前序遍历的递归算法
void PreOrderTraverse_recursion(Node* root);

//中序遍历的递归算法
void InOrderTraverse_recursion(Node* root);

//后序遍历的递归算法
void PostOrderTraverse_recursion(Node* root);

//前序遍历的非递归版本
void PreOrderTraverse(Node* root);

//中序遍历的非递归版本
void InOrderTraverse(Node* root);

//后序遍历的非递归版本
void PostOrderTraverse(Node* root);

// 层序遍历二叉树
void LevelOrderTraverse(Node* root);