#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int main()
{
    int n, i, j, edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    int topo[MAX];

    while (front != -1 && front <= rear)
    {
        int node = dequeue();
        topo[count++] = node;

        for (i = 0; i < n; i++)
        {
            if (adj[node][i] == 1)
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if (count != n)
    {
        printf("Graph has a cycle\n");
    }
    else
    {
        printf("Topological Order:\n");
        for (i = 0; i < count; i++)
            printf("%d ", topo[i]);
    }

    return 0;
}