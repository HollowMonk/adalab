#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;
int cost[10][10], parent[10];
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int kruskal_MST(int n)
{
    int count =1 ,a, b, u, v;
    int min, mincost = 0;
    while (count < n)
    {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }

        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("\n%d Edge (%d,%d) = %d\n", count++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    return mincost;
}



void main()
{
    double time;
    clock_t start, end;
    int n,mincost;
    printf("\nEnter the number of vertices.\n");
    scanf("%d", &n);
    printf("\nEnter the cost matrix.\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    printf("\nThe edges of Minimum Cost Spanning Tree are :\n");

    start = clock();
    mincost = kruskal_MST(n);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nMinimum cost = %d\n", mincost);
    printf("\nThe time taken to execute function is %fs.\n", time);
}

