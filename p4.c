/*Write a C program to evaluate a valid postfix expression using stack. Assume that the
postfix expression is read as a single line consisting of non-negative single digit operands
and binary operators. The operators are + - * and /.*/

#include <stdio.h>
#include <ctype.h>
#define MAX 50

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int value) {
    s->items[++s->top] = value;
}

int pop(struct Stack *s) {
    return s->items[s->top--];
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluatePostfix(char postfix[]) {
    struct Stack s;
    initStack(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        else {
            int b = pop(&s);
            int a = pop(&s);
            int result = applyOperator(a, b, ch);
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() {
    char postfix[MAX];
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);
    return 0;
}
