#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define FALSE 0
#define TRUE 1

int x[20];
int place(int k, int i)
{
    int j;
    for (j = 1; j <= k; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return FALSE;
    }
    return TRUE;
}

void nqueens(int k, int n)
{
    int i, a;
    for (i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                for (a = 1; a <= n; a++)
                    printf("%d\t", x[a]);
                printf("\n");
            }
            else
                nqueens(k + 1, n);
        }
    }
}
void main()
{
    int n;
    double clk;
    clock_t starttime, endtime;
    printf("\nEnter the number of queens:");
    scanf("%d", &n);
    printf("\n The solution to N Queens problem is: \n");
    starttime = clock();
    nqueens(1, n);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The time taken is %f\n", clk);
}