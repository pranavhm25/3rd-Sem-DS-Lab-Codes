/*Write a C programto simulate a call center phone system using a queue data structure as an
array. The system should store incoming customer calls in the order they arrive and provide
service based on this order (FIFO). The program must include options to add a new phone
call to the queue and remove a call when it is being serviced. Display appropriate messages
for queue overflowand underflow situations.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Queue {
    int calls[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue *q) {
    return q->front > q->rear;
}

void enqueue(struct Queue *q, int callID) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot accept new call.\n");
        return;
    }
    q->calls[++q->rear] = callID;
    printf("Incoming call %d added to queue.\n", callID);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! No calls to service.\n");
        return;
    }
    printf("Servicing call %d\n", q->calls[q->front++]);
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No pending calls in queue.\n");
        return;
    }
    printf("Pending Calls: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->calls[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    int choice, callID;
    initQueue(&q);
    while (1) {
        printf("\nCall Center Phone System\n1. Add Incoming Call\n2. Service Call\n3. Display Pending Calls\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter call ID: ");
                scanf("%d", &callID);
                enqueue(&q, callID);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
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
