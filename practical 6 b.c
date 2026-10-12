
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertEnd(struct node **head, int value)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

void display(struct node *head)
{
    struct node *temp = head;

    printf("Linked list: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteFirst(struct node **head)
{
    struct node *temp;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct node **head)
{
    struct node *temp, *prev;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    temp = *head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deleteAfter(struct node *head, int value)
{
    struct node *temp = head, *delnode;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Given node not found\n");
        return;
    }

    if (temp->next == NULL)
    {
        printf("No node exists after %d\n", value);
        return;
    }

    delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);
}

int main()
{
    struct node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Original list:\n");
    display(head);

    deleteFirst(&head);
    printf("After deleting first node:\n");
    display(head);

    deleteLast(&head);
    printf("After deleting last node:\n");
    display(head);

    deleteAfter(head, 20);
    printf("After deleting node after 20:\n");
    display(head);

    return 0;
}