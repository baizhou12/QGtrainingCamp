#pragma once

#define MAX_SIZE 100

//��������������ȼ�
int precedence(char op);

//�ж��Ƿ�Ϊ�����
int isOperator(char c);

//����׺���ʽת��Ϊ��׺���ʽ
void infixToPostfix(char* infix, char* postfix);

//��ջ
void push(int item);

//��ջ
int pop();

//�����׺���ʽ
int evaluatePostfix(char* postfix);