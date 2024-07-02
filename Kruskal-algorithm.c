#include <stdio.h>
#define INF 999
int main() 
{
    int n, v, u, cost[10][10], parent[10] = {0}, i, j;
    int noe = 1, mincost = 0, min, a, b;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++) 
        {
            printf("(%d, %d): ", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) 
            {
                cost[i][j] = INF;
            }
        }
    }


    while (noe < n) 
    {
        min = INF;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min) 
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];

        if (u != v) 
        {
            noe++;
            printf("\nEdge (%d,%d) = %d", a, b, min);
            mincost += min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
