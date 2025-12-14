/*Write a C program to simulate forward and backward web browsing using a Stack
implemented with a linked list. Each node in the stack should represent a web page visited.
Implement stack operations to handle the following actions: Back (pop the current page and
move to the previous page), Forward (push pages when navigating forward), Visit a new
page (push a new node onto the stack). Demonstrate all operations and display the updated
list of visited pages after each action. Ensure appropriate messages are shown in case of
stack underflow.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int page;
    struct Node *next;
} Node;
Node *backTop = NULL;
Node *forwardTop = NULL;

void pushBack(int page) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->page = page;
    newNode->next = backTop;
    backTop = newNode;
}

void pushForward(int page) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->page = page;
    newNode->next = forwardTop;
    forwardTop = newNode;
}

int popBack() {
    if (backTop == NULL)
        return -1;
    Node *temp = backTop;
    int page = temp->page;
    backTop = temp->next;
    free(temp);
    return page;
}

int popForward() {
    if (forwardTop == NULL)
        return -1;
    Node *temp = forwardTop;
    int page = temp->page;
    forwardTop = temp->next;
    free(temp);
    return page;
}

void clearForward() {
    while (forwardTop != NULL)
        popForward();
}

void display(Node *top) {
    if (top == NULL) {
        printf("Empty\n");
        return;
    }
    while (top != NULL) {
        printf("%d -> ", top->page);
        top = top->next;
    }
    printf("NULL\n");
}

void visitPage(int page) {
    pushBack(page);
    clearForward();
    printf("Visited page %d\n", page);
}

void goBack() {
    if (backTop == NULL || backTop->next == NULL) {
        printf("Stack Underflow! No previous page.\n");
        return;
    }
    int page = popBack();
    pushForward(page);
    printf("Moved back from page %d\n", page);
}

void goForward() {
    if (forwardTop == NULL) {
        printf("Stack Underflow! No forward page.\n");
        return;
    }
    int page = popForward();
    pushBack(page);
    printf("Moved forward to page %d\n", page);
}

int main() {
    int choice, page;
    while (1) {
        printf("\nWeb Browsing System\n1. Visit New Page\n2. Back\n3. Forward\n4. Display History\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter page number: ");
                scanf("%d", &page);
                visitPage(page);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                printf("Back Stack (Current -> Oldest): ");
                display(backTop);
                printf("Forward Stack: ");
                display(forwardTop);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
