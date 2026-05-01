#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float data;
    struct Node* next;
};

void insert(struct Node** head, float value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data < value)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    struct Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        insert(&buckets[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        struct Node* temp = buckets[i];
        while (temp != NULL)
        {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);

    return 0;
}