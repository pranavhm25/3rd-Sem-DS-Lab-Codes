/*Write a C program to simulate file memory allocation in an operating system using a doubly
linked list. Each node of the list should represent a file number. Implement the following
operations: a. Insert a new file at the front of the doubly linked list (representing a file being
newly created and placed in memory). b. Delete a file from a specified position in the list. c.
Display the list of files along with their allocatedmemory sizes.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int fileNo;
    int memory;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertF(int fileNo, int memory) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->fileNo = fileNo;
    newNode->memory = memory;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    printf("File %d allocated %d KB memory.\n", fileNo, memory);
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("Memory list is empty (Underflow).\n");
        return;
    }
    struct Node *temp = head;
    int count = 1;
    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        printf("File %d removed from memory.\n", temp->fileNo);
        free(temp);
        return;
    }
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    printf("File %d removed from memory.\n", temp->fileNo);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("No files in memory.\n");
        return;
    }
    struct Node *temp = head;
    printf("File Memory Allocation:\n");
    while (temp != NULL) {
        printf("File No: %d | Memory: %d KB\n", temp->fileNo, temp->memory);
        temp = temp->next;
    }
}

int main() {
    int choice, fileNo, memory, pos;
    while (1) {
        printf("\nFile Memory Allocation System\n1. Insert New File (Front)\n2. Delete File at Position\n3. Display Files\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter File Number: ");
                scanf("%d", &fileNo);
                printf("Enter Memory Size (KB): ");
                scanf("%d", &memory);
                insertF(fileNo, memory);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 3:
                display();
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
