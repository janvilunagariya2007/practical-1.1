#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty!");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));
    
    n1->data = 10;
    n1->next = n2;
    
    n2->data = 20;
    n2->next = n3;
    
    n3->data = 30; // Added for completeness based on the 3 nodes allocated
    n3->next = NULL;
    
    head = n1;
    display();
    
    return 0;
}