#pragma once

#define MAX_SIZE 100

//定义运算符的优先级
int precedence(char op);

//判断是否为运算符
int isOperator(char c);

//将中缀表达式转换为后缀表达式
void infixToPostfix(char* infix, char* postfix);

//入栈
void push(int item);

//出栈
int pop();

//计算后缀表达式
int evaluatePostfix(char* postfix);