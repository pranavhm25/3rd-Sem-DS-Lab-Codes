/*Write a C program to read a polynomial expression from the user in sorted order of
exponents. Use a singly linked list and implement an “insert at end” function to store each
term of the polynomial. Write a function to add two polynomials and return the resulting
polynomial to the main program. Display all the input polynomials as well as the final added
polynomial.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head, int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* readPoly() {
    int n, coeff, exp;
    struct Node *head = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }
    return head;
}

void displayPoly(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addPoly(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
                result = insertEnd(result, sumCoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insertEnd(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            result = insertEnd(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertEnd(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertEnd(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct Node *poly1, *poly2, *polySum;
    printf("\nEnter first polynomial (exponents in sorted order):\n");
    poly1 = readPoly();
    printf("\nEnter second polynomial (exponents in sorted order):\n");
    poly2 = readPoly();
    polySum = addPoly(poly1, poly2);
    printf("\nFirst Polynomial: ");
    displayPoly(poly1);
    printf("Second Polynomial: ");
    displayPoly(poly2);
    printf("Sum Polynomial: ");
    displayPoly(polySum);
    return 0;
}
