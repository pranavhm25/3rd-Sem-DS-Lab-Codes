/*Write a C programto store andmanage a list of records student records (student name, usn,
department and cgpa) using structures. Using dynamic memory allocation and
pointers write functions to create student records, add the records, display and search
records based on usn.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    char usn[20];
    char dept[30];
    float CGPA;
} St;

St* create(int n) {
    St *s = (St*)malloc(n * sizeof(St));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return s;
}

void add(St *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("USN: ");
        scanf("%s", s[i].usn);
        printf("Department: ");
        scanf("%s", s[i].dept);
        printf("CGPA: ");
        scanf("%f", &s[i].CGPA);
    }
}


void display(St *s, int n) {
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\nName: %s\nUSN: %s\nDepartment: %s\nCGPA: %.2f\n", i + 1, s[i].name, s[i].usn, s[i].dept, s[i].CGPA);
    }
}

void ssearch(St *s, int n, char USN[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].usn, USN) == 0) {
            printf("\nStudent Found\nName: %s\nUSN: %s\nDepartment: %s\nCGPA: %.2f\n", s[i].name, s[i].usn, s[i].dept, s[i].CGPA);
            return;
        }
    }
    printf("\nStudent with USN %s not found\n", USN);
}

int main() {
    St *students;
    int n;
    char search[20];
    printf("Enter number of students: ");
    scanf("%d", &n);
    students = create(n);
    add(students, n);
    display(students, n);
    printf("\nEnter USN to search: ");
    scanf("%s", search);
    ssearch(students, n, search);
    free(students);
    return 0;
}
