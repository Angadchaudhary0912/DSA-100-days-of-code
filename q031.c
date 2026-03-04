#include <stdio.h>
#define MAX 100

int main()
{
    int stack[MAX];
    int top = -1;
    int n, choice, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &choice);

        if(choice == 1)
        {
            scanf("%d", &value);
            if(top == MAX - 1)
            {
                printf("Stack Overflow\n");
            }
            else
            {
                stack[++top] = value;
            }
        }
        else if(choice == 2)
        {
            if(top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("%d\n", stack[top--]);
            }
        }
        else if(choice == 3)
        {
            if(top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                for(int j = top; j >= 0; j--)
                {
                    printf("%d", stack[j]);
                    if(j > 0)
                        printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}