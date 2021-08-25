#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
#define MAX 20

void warshall(int a[][MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                a[i][j] = (a[i][j] || a[i][k] && a[k][j]);
            }
        }
    }

    
}




int main()
{
    struct timeval tv1, tv2;
    struct rusage r_usage;
    int n,a[MAX][MAX];

    printf("Enter the no. of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    gettimeofday(&tv1, NULL);
    warshall(a,n);
    gettimeofday(&tv2, NULL);
    printf("the path matrix is \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

printf("\nTime =%f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));//in microseconds
getrusage(RUSAGE_SELF,&r_usage);
printf("\nMemory usage: %ld kilobytes\n",r_usage.ru_maxrss);
}