/*Write a C program to implement a Stack data structure using arrays, where each pushed
number represents a web page visited. When a new web page is visited, push its page
number onto the stack. When the user moves backward, pop and display the page number
removed from the stack. Use a structure to represent the Stack. Handle and display
appropriate messages for stack overflowand underflow conditions.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int page) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot visit new page.\n");
        return;
    }
    s->items[++s->top] = page;
    printf("Visited page number %d\n", page);
}

void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! No pages to go back.\n");
        return;
    }
    printf("Moved back from page number %d\n", s->items[s->top--]);
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("No pages in history.\n");
        return;
    }
    printf("Page History (Top -> Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack history;
    int choice, page;
    initStack(&history);
    while (1) {
        printf("\nWeb Page Navigation\n1. Visit New Page\n2. Go Back\n3. Display Page History\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter page number: ");
                scanf("%d", &page);
                push(&history, page);
                break;
            case 2:
                pop(&history);
                break;
            case 3:
                display(&history);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
