/*Write a C program to simulate process scheduling using a circular queue implemented with
arrays. The program should allow the user to add a process, remove a process, and display
all processes in the circular queue. Ensure that appropriate messages are shown for queue
overflow and underflow conditions.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct CircularQueue {
    int process[MAX];
    int front, rear;
};

void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(struct CircularQueue *q) {
    return q->front == -1;
}

void addProcess(struct CircularQueue *q, int pid) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot add new process.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->process[q->rear] = pid;
    printf("Process %d added to queue.\n", pid);
}

void removeProcess(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! No process to schedule.\n");
        return;
    }
    printf("Process %d scheduled and removed.\n", q->process[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

void displayQueue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("No processes in the queue.\n");
        return;
    }
    printf("Processes in Circular Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->process[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    int choice, pid;
    initQueue(&q);
    while (1) {
        printf("\nProcess Scheduling (Circular Queue)\n1. Add Process\n2. Remove Process\n3. Display Processes\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Process ID: ");
                scanf("%d", &pid);
                addProcess(&q, pid);
                break;
            case 2:
                removeProcess(&q);
                break;
            case 3:
                displayQueue(&q);
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
