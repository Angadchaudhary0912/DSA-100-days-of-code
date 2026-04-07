#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int dfs(int v, int parent, int n)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1)
        {
            if(visited[i] == 0)
            {
                if(dfs(i, v, n))
                    return 1;
            }
            else if(i != parent)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(i, -1, n))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}