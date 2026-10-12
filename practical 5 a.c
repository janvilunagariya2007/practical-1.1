
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
        printf("%d inserted into queue\n", value);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("%d deleted from queue\n", queue[front]);
        front++;

        if (front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}