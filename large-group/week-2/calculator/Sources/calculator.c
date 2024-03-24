#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"calculator.h"

int top = -1;//���ڱ�עջ��λ�ã���ջʱΪ-1
int stack1[MAX_SIZE];//�ڼ����׺���ʽʱ����������ջ

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
    char stack2[MAX_SIZE];//���ڴ洢�������
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue;
        }
        else if (isdigit(infix[i])) {
            postfix[j++] = infix[i];//��������֣��ͼ����׺���ʽ
        }
        else if (isOperator(infix[i])) {
            while (top >= 0 && precedence(stack2[top]) >= precedence(infix[i])) {
                postfix[j++] = stack2[top--];//���ջ����Ԫ����ջ��Ԫ�ص����ȼ����ڽ���������׺���ʽ��Ԫ�ص����ȼ������ջ
            }
            stack2[++top] = infix[i];//���������ջ
        }
        else if (infix[i] == '(') {
            stack2[++top] = infix[i];//��������ջ
        }
        else if (infix[i] == ')') {
            while (top >= 0 && stack2[top] != '(') {
                postfix[j++] = stack2[top--];
            }//����������֮����������ջ
            top--; // ���� '('
        }
    }

    while (top >= 0) {
        postfix[j++] = stack2[top--];//��ʣ���Ԫ����ջ
    }

    postfix[j] = '\0';
}

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);//����������ֹ����ִ��
    }
    else {
        stack1[++top] = item;
    }
}

int pop() {
    if (top < -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);//������磬��ֹ����ִ��
    }
    if (top == -1) {
        return 0;//���ǵ�ֻ��һ������ʱ�����
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
            push(c - '0');//������ջ
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
        // ���֮ǰ������
        memset(infix, 0, sizeof(infix));
        memset(postfix, 0, sizeof(postfix));

        printf("��������׺���ʽ:");
        fgets(infix, MAX_SIZE, stdin);

        if (infix[0] == '\n') {
            printf("δ�����κ����ݣ����������롣\n");
            continue;
        }

        infix[strlen(infix) - 1] = '\0'; // ȥ�����з�

        infixToPostfix(infix, postfix);

        int result = evaluatePostfix(postfix);

        printf("�����: %d\n", result);

        printf("��������Ϊ��q\n");
        printf("�Ƿ�������㣿����������ţ�");
        scanf(" %c", &endSymbol); // ע��ո񣬱����ȡ��һ������Ļ��з�

        while ((getchar()) != '\n');//������뻺����

    } while (endSymbol != 'q'); // ����һ���������ţ����� 'q'

    return 0;

    system("pause");
}
