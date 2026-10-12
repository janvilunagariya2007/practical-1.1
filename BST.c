#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *left, *right;
};

struct Node* createNode(char name[]) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, char name[]) {
    if (root == NULL)
        return createNode(name);

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name);

    return root;
}

void search(struct Node* root, char name[]) {
    if (root == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (strcmp(root->name, name) == 0)
        printf("Contact found: %s\n", root->name);
    else if (strcmp(name, root->name) < 0)
        search(root->left, name);
    else
        search(root->right, name);
}

void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%s\n", root->name);
        display(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50];

    do {
        printf("\n1. Add Contact");
        printf("\n2. Search Contact");
        printf("\n3. Display Contacts");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%49s", name);

                root = insert(root, name);
                printf("Contact added!\n");
                break;

            case 2:
                printf("Enter name to search: ");
                scanf("%49s", name);

                search(root, name);
                break;

            case 3:
                printf("\nContact List:\n");
                display(root);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}