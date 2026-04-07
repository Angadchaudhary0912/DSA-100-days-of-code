#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v)
{
    if(rear == MAX - 1) return;
    if(front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue()
{
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int n, int s)
{
    int i;
    enqueue(s);
    visited[s] = 1;

    while(front <= rear)
    {
        int v = dequeue();
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, i, j, s;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    scanf("%d", &s);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    bfs(n, s);

    return 0;
}