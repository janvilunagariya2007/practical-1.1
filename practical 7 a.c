
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int value)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insert_end(int value)
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

void insert_after(int key, int value)
{
    struct node *temp = head;
    struct node *newnode;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        if (temp->data == key)
            break;

        temp = temp->next;
    } while (temp != head);

    if (temp->data != key)
    {
        printf("Given node not found\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = temp->next;
    temp->next = newnode;
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
    printf("Original list: ");
    insert_end(10);
    insert_end(20);
    insert_end(30);
    display();

    insert_begin(5);
    printf("After insertion at beginning: ");
    display();

    insert_end(40);
    printf("After insertion at end: ");
    display();

    insert_after(20, 25);
    printf("After insertion after 20: ");
    display();

    return 0;
}