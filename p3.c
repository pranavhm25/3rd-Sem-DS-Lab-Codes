/*Write a C program to convert and print a given valid parenthesized infix arithmetic
expression to postfix expression. The expression consists of single character operands and
binary operators + - * /. Apply the concept of stack data structure to solve this problem.*/

//Also included '^' operator

#include <stdio.h>
#include <ctype.h>
#define MAX 50

struct Stack {
    char items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char ch) {
    s->items[++s->top] = ch;
}

char pop(struct Stack *s) {
    return s->items[s->top--];
}

char peek(struct Stack *s) {
    return s->items[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    int i = 0, k = 0;
    char ch;
    initStack(&s);
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);
        }
        else {
            while (!isEmpty(&s) && (precedence(peek(&s)) > precedence(ch) || (precedence(peek(&s)) == precedence(ch) && ch != '^'))) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
