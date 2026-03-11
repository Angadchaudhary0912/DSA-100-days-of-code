#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int x)
{
    if(front==0)
        printf("Overflow\n");
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        deque[front]=x;
    }
    else
    {
        front--;
        deque[front]=x;
    }
}

void push_back(int x)
{
    if(rear==MAX-1)
        printf("Overflow\n");
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        deque[rear]=x;
    }
    else
    {
        rear++;
        deque[rear]=x;
    }
}

void pop_front()
{
    if(front==-1)
        printf("-1\n");
    else if(front==rear)
        front=rear=-1;
    else
        front++;
}

void pop_back()
{
    if(rear==-1)
        printf("-1\n");
    else if(front==rear)
        front=rear=-1;
    else
        rear--;
}

void show()
{
    if(front==-1)
    {
        printf("Deque empty\n");
        return;
    }
    for(int i=front;i<=rear;i++)
        printf("%d ",deque[i]);
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    pop_back();
    push_back(30);
    show();
    return 0;
}