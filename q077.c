#include <stdio.h>

int visited[100];

void dfs(int node, int n, int adj[100][100])
{
    visited[node] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i, n, adj);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100] = {0};

    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1, n, adj);

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");

    return 0;
}