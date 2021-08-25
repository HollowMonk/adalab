#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>


void prim(int c[][20],int visited[],int n)
{

    int min, b, a, k, count = 0, cost = 0;
    min = 999;
    visited[1] = 1;
    while (count < n - 1)
    {
        min = 999;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (visited[i] && !visited[j] && min > c[i][j])
                {
                    min = c[i][j];
                    a = i;
                    b = j;
                }

        printf("%d--->%d = %d\n", a, b, c[a][b]);
        cost += c[a][b];
        visited[b] = 1;
        count++;
    }
    printf("Total cost of Spanning tree is %d", cost);
}

void main()
{
    struct timeval tv1, tv2;
    struct rusage r_usage;
    int n;
    int c[20][20], visited[20];
    printf("Enter number of vertices \n");
    scanf("%d", &n);
    printf("Enter the cost matrix \n");
    printf("Enter 999 if no direct edges \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
        visited[i] = 0;
    }
    gettimeofday(&tv1, NULL);
    prim(c,visited,n);
    gettimeofday(&tv2, NULL);
    printf("\nTime of =%f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec)); //in microseconds
    //printf ("Time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("\nMemory usage: %ld kilobytes\n", r_usage.ru_maxrss);
}
