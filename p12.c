/*Write a C program to simulate an image-indexing system for a hospital database using a
Binary Search Tree (BST). Each CT image is represented by a unique numeric ID. Insert these
image IDs into the BST to build an efficient indexing structure. Implement preorder traversal
to display the indexed image IDs, showing how the system retrieves stored images.
Additionally, include a feature to identify and display the largest image IDs in the BST,
representing the highest indexed images in the database.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int imageID;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int id) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->imageID = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int id) {
    if (root == NULL)
        return createNode(id);
    if (id < root->imageID)
        root->left = insert(root->left, id);
    else if (id > root->imageID)
        root->right = insert(root->right, id);
    return root;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->imageID);
        preorder(root->left);
        preorder(root->right);
    }
}

int findLargest(struct Node *root) {
    if (root == NULL) {
        printf("Database is empty.\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->imageID;
}

int main() {
    struct Node *root = NULL;
    int choice, id;
    while (1) {
        printf("\nHospital Image Indexing System\n1. Insert CT Image ID\n2. Display Indexed Images (Preorder)\n3. Display Largest Image ID\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Image ID: ");
                scanf("%d", &id);
                root = insert(root, id);
                printf("Image ID %d indexed successfully.\n", id);
                break;
            case 2:
                if (root == NULL)
                    printf("No images indexed.\n");
                else {
                    printf("Preorder Traversal (Indexed Images): ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 3:
                id = findLargest(root);
                if (id != -1)
                    printf("Largest Image ID in Database: %d\n", id);
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
