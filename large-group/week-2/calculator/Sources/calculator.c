#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"calculator.h"

int top = -1;//用于标注栈顶位置，空栈时为-1
int stack1[MAX_SIZE];//在计算后缀表达式时用于数字入栈

int precedence(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	else
		return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

void infixToPostfix(char* infix, char* postfix) {
    char stack2[MAX_SIZE];//用于存储运算符号
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue;
        }
        else if (isdigit(infix[i])) {
            postfix[j++] = infix[i];//如果是数字，就加入后缀表达式
        }
        else if (isOperator(infix[i])) {
            while (top >= 0 && precedence(stack2[top]) >= precedence(infix[i])) {
                postfix[j++] = stack2[top--];//如果栈内有元素且栈顶元素的优先级大于接下来的中缀表达式中元素的优先级，则出栈
            }
            stack2[++top] = infix[i];//将运算符入栈
        }
        else if (infix[i] == '(') {
            stack2[++top] = infix[i];//左括号入栈
        }
        else if (infix[i] == ')') {
            while (top >= 0 && stack2[top] != '(') {
                postfix[j++] = stack2[top--];
            }//将两个括号之间的运算符出栈
            top--; // 弹出 '('
        }
    }

    while (top >= 0) {
        postfix[j++] = stack2[top--];//将剩余的元素入栈
    }

    postfix[j] = '\0';
}

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);//如果溢出，终止程序执行
    }
    else {
        stack1[++top] = item;
    }
}

int pop() {
    if (top < -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);//如果下溢，终止程序执行
    }
    if (top == -1) {
        return 0;//考虑当只有一个数字时的情况
    }
    else {
            return stack1[top--];
    }
}


int evaluatePostfix(char* postfix) {
    int i = 0;
    char c;
    int op1, op2, result;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            push(c - '0');//数字入栈
        }
        else if (isOperator(c)) {
            op2 = pop();
            op1 = pop();

            switch (c) {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                if (op2 != 0)
                    push(op1 / op2);
                else {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                break;
            }
        }
    }

    result = pop();
    return result;
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    char endSymbol;

    do {
        // 清空之前的数据
        memset(infix, 0, sizeof(infix));
        memset(postfix, 0, sizeof(postfix));

        printf("请输入中缀表达式:");
        fgets(infix, MAX_SIZE, stdin);

        if (infix[0] == '\n') {
            printf("未输入任何内容，请重新输入。\n");
            continue;
        }

        infix[strlen(infix) - 1] = '\0'; // 去掉换行符

        infixToPostfix(infix, postfix);

        int result = evaluatePostfix(postfix);

        printf("结果是: %d\n", result);

        printf("结束符号为：q\n");
        printf("是否继续计算？输入结束符号：");
        scanf(" %c", &endSymbol); // 注意空格，避免读取上一次输入的换行符

        while ((getchar()) != '\n');//清空输入缓冲区

    } while (endSymbol != 'q'); // 设置一个结束符号，比如 'q'

    return 0;

    system("pause");
}
