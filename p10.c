/*Write a C program to simulate forward and backward web browsing using a Stack
implemented with a linked list. Each node in the stack should represent a web page visited.
Implement stack operations to handle the following actions: Back (pop the current page and
move to the previous page), Forward (push pages when navigating forward), Visit a new
page (push a new node onto the stack). Demonstrate all operations and display the updated
list of visited pages after each action. Ensure appropriate messages are shown in case of
stack underflow.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int page;
    struct Node *next;
};

struct Node *top = NULL;

void push(int page) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->page = page;
    newNode->next = top;
    top = newNode;
    printf("Visited page %d\n", page);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! No previous page.\n");
        return;
    }
    struct Node *temp = top;
    printf("Moved back from page %d\n", temp->page);
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("No pages in browsing history.\n");
        return;
    }
    struct Node *temp = top;
    printf("Browsing History (Current → Oldest): ");
    while (temp != NULL) {
        printf("%d -> ", temp->page);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, page;
    while (1) {
        printf("\nWeb Browsing System\n1. Visit New Page\n2. Back\n3. Forward (Visit Next Page)\n4. Display Browsing History\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter page number: ");
                scanf("%d", &page);
                push(page);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                printf("Enter page number to move forward: ");
                scanf("%d", &page);
                push(page);
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
