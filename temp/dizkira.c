#include <stdio.h>
#include <time.h>

#define MAX 10

int choose(int dist[], int s[], int n)
{
    int j = 1, min = __INT_MAX__;
    for (int i = 1; i <= n; i++)
    {
        if ((dist[i] < min) && (s[i] == 0))
        {
            min = dist[i];
            j = i;
        }
    }
    return j;
}

void spath(int v, int cost[][MAX], int dist[], int n)
{
    int u, i, num, s[MAX];
    for (i = 1; i <= n; i++)
    {
        s[i] = 0;
        dist[i] = cost[v][i];
    }

    // s[v] = 0;
    // dist[i] = 999;

    for (num = 2; num <= n; num++)
    {
        u = choose(dist, s, n);
        s[u] = 1;

        for (int j = 1; j <= n; j++)
        {
            if ((dist[u] + cost[u][j]) < dist[j] && !s[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }
}

void main()
{
    int cost[MAX][MAX], dist[MAX];

    int n;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);

    printf("\nEnter the cost of adjacency matrix\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    int v;
    printf("\nEnter the source vertex");
    scanf("%d", &v);

    clock_t st = clock();
    spath(v, cost, dist, n);
    clock_t et = clock();

    printf("\nShortest  distance\n");
    for (int i = 1; i <= n; i++)
        printf("\n%d to %d = %d", v, i, dist[i]);

    double time_taken = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\nThe time taken is %f\n", time_taken);

    return ;
}