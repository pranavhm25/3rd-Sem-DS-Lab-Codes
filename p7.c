/*Write a C program to implement a singly linked list to store customer IDs in a store billing
system. Each time a customer arrives for billing, insert the customer ID at the end of the list.
Once the billing is completed, remove the customer ID from the beginning of the list.
Demonstrate these operations and display the updated linked list after each action.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int customerID;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int id) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->customerID = id;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Customer %d added for billing.\n", id);
}

void deleteBegin() {
    if (head == NULL) {
        printf("No customers for billing (Underflow).\n");
        return;
    }
    struct Node *temp = head;
    printf("Billing completed for customer %d.\n", temp->customerID);
    head = head->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Billing list is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Current Billing Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->customerID);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, id;
    while (1) {
        printf("\nStore Billing System\n1. Customer Arrives (Insert)\n2. Billing Completed (Delete)\n3. Display Billing List\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                insertEnd(id);
                display();
                break;
            case 2:
                deleteBegin();
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
