/*Write a C program to implement a Circular Queue data structure using a circular linked list
for a simple real-world application, such as managing customers waiting in a service
counter. The program should support enqueue and dequeue operations and display the
updated queue after each action. Ensure that appropriate messages are shown for queue
underflow or other exceptions.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int customerID;
    struct Node *next;
};

struct Node *rear = NULL;

void enqueue(int id) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->customerID = id;
    if (rear == NULL) {
        rear = newNode;
        rear->next = rear;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    printf("Customer %d added to the queue.\n", id);
}

void dequeue() {
    if (rear == NULL) {
        printf("Queue Underflow! No customers to serve.\n");
        return;
    }
    struct Node *front = rear->next;
    if (front == rear) {
        printf("Customer %d served and removed.\n", front->customerID);
        free(front);
        rear = NULL;
    } else {
        printf("Customer %d served and removed.\n", front->customerID);
        rear->next = front->next;
        free(front);
    }
}

void display() {
    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = rear->next;
    printf("Current Queue: ");
    do {
        printf("%d -> ", temp->customerID);
        temp = temp->next;
    } while (temp != rear->next);
    printf("(back to front)\n");
}

int main() {
    int choice, id;

    while (1) {
        printf("\n--- Service Counter Queue ---\n");
        printf("1. Enqueue Customer\n");
        printf("2. Dequeue Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                enqueue(id);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
