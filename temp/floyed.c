#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>
void floyd(int a[20][20], int n)
{
    int k, i, j;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (a[i][j] > (a[i][k] + a[k][j]))
                    a[i][j] = (a[i][k] + a[k][j]);
    printf(" All Pairs Shortest Paths:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
void main()
{
    struct timeval tv1, tv2;
    struct rusage r_usage;
    int n, a[20][20], i, j;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix for the graph [999 for no edge, 0 for self loops]: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    gettimeofday(&tv1, NULL);
    floyd(a, n);
    gettimeofday(&tv2, NULL);

    printf("\nTime =%f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec)); //in microseconds
    //printf ("Time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("\nMemory usage: %ld kilobytes\n", r_usage.ru_maxrss);
}
