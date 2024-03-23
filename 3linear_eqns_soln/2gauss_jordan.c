#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int i, j, k, n;
    printf("Enter number of unknown variables: ");
    scanf("%d", &n);
    float a[n][n + 1], x[n], ratio;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    /* Applying Gauss Jordan */
    for (i = 1; i <= n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
    /* Obtaining Solution */
    for (i = 1; i <= n; i++)
    {
        x[i] = a[i][n + 1] / a[i][i];
    }
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    return (0);
}