#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int val;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int main()
{
    char postfix[100];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            b = pop();
            a = pop();

            if(postfix[i] == '+')
                push(a + b);
            else if(postfix[i] == '-')
                push(a - b);
            else if(postfix[i] == '*')
                push(a * b);
            else if(postfix[i] == '/')
                push(a / b);
        }
    }

    result = pop();

    printf("Result = %d\n", result);

    return 0;
}