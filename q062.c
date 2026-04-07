#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v)
{
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main()
{
    int n, m, i;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    for(i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    for(i = 0; i < n; i++)
    {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}