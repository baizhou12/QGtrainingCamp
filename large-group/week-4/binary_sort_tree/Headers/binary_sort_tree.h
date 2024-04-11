#pragma once
//ջ�Ĵ�С
#define MAX_SIZE 100

// ����������Ľڵ�ṹ��
typedef struct Node {
    int key;
    struct Node* left, * right;
} Node;

// �����½ڵ�ĺ���
Node* CreateNode(int key);

// ������������в���һ���½ڵ�ĺ���
Node* InsertNode(Node* root, int key);

// �ڶ����������в���һ�����ĺ���
Node* SearchNode(Node* root, int key);

// Ѱ�Ҷ�������������С�ڵ�ĸ�������
Node* MinValueNode(Node* root);

// �Ӷ�����������ɾ���ڵ�ĺ���
Node* DeleteNode(Node* root, int key);

//ǰ������ĵݹ��㷨
void PreOrderTraverse_recursion(Node* root);

//��������ĵݹ��㷨
void InOrderTraverse_recursion(Node* root);

//��������ĵݹ��㷨
void PostOrderTraverse_recursion(Node* root);

//ǰ������ķǵݹ�汾
void PreOrderTraverse(Node* root);

//��������ķǵݹ�汾
void InOrderTraverse(Node* root);

//��������ķǵݹ�汾
void PostOrderTraverse(Node* root);

// �������������
void LevelOrderTraverse(Node* root);