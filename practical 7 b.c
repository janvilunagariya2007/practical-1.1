
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int value)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
}

void deleteFirst()
{
    struct node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head->next == head)
    {
        head = NULL;
        free(temp);
        return;
    }

    last = head;
    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    free(temp);
}

void deleteLast()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

void deleteAfter(int value)
{
    struct node *temp, *delnode;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do
    {
        if (temp->data == value)
            break;

        temp = temp->next;
    } while (temp != head);

    if (temp->data != value)
    {
        printf("Given node not found\n");
        return;
    }

    if (temp->next == temp)
    {
        printf("No node exists after %d\n", value);
        return;
    }

    delnode = temp->next;

    if (delnode == head)
        head = head->next;

    temp->next = delnode->next;
    free(delnode);
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    printf("Original list:\n");
    display();

    deleteFirst();
    printf("After deleting first node:\n");
    display();

    deleteLast();
    printf("After deleting last node:\n");
    display();

    deleteAfter(20);
    printf("After deleting node after 20:\n");
    display();

    return 0;
}