
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int value)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("%d inserted\n", value);
}

void deleteNode()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        printf("%d deleted\n", head->data);
        head = head->next;
        free(temp);
    }
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked list: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    display();

    deleteNode();

    display();

    return 0;
}