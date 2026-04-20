#include <stdio.h>

int visited[100];
int adj[100][100];
int n;

void dfs(int node)
{
    visited[node] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int m, u, v;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int count = 0;

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}