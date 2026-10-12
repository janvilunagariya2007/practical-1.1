
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = value;
        printf("%d inserted into stack\n", value);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Deleted Element = %d\n", stack[top--]);
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top Element = %d\n", stack[top]);
    }
}

void display()
{
    int i;

    printf("Stack Elements:\n");

    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    peek();
    pop();
    display();

    return 0;
}