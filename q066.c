#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;

bool dfs(int v)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i])
            {
                if (!visited[i] && dfs(i))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

int main()
{
    int edges, u, v;

    scanf("%d", &n);
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (dfs(i))
        {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}