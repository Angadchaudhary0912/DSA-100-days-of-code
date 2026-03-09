#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;

    if(rear == NULL)
    {
        rear = temp;
        rear->next = rear;
    }
    else
    {
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct node *temp;

    if(rear == NULL)
        return;

    temp = rear->next;

    if(rear->next == rear)
    {
        rear = NULL;
        free(temp);
    }
    else
    {
        rear->next = temp->next;
        free(temp);
    }
}

void display()
{
    if(rear == NULL)
        return;

    struct node *temp = rear->next;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    while(temp != rear->next);
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}