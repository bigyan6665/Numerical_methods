#include <stdio.h>
#include <stdlib.h>
int main()
{
    int no, i, j, k;
    printf("Enter the no. of terms=");
    scanf("%d", &no);
    float x[no], y[no];
    float sumx = 0, sumy = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumxy = 0, sumx2y = 0;
    printf("Enter the data:\n");
    for (i = 1; i <= no; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumx3 = sumx3 + x[i] * x[i] * x[i];
        sumx4 = sumx4 + x[i] * x[i] * x[i] * x[i];
        sumxy = sumxy + x[i] * y[i];
        sumx2y = sumx2y + x[i] * x[i] * y[i];
    }
    // printf("\nsumx = %f\n", sumx);
    // printf("sumy = %f\n", sumy);
    // printf("sumx2 = %f\n", sumx2);
    // printf("sumx3 = %f\n", sumx3);
    // printf("sumx4 = %f\n", sumx4);
    // printf("sumxy = %f\n", sumxy);
    // printf("sumx2y = %f\n", sumx2y);
    int n = 3;
    float a[n][n + 1], z[n], ratio;
    a[1][1] = no, a[1][2] = sumx, a[1][3] = sumx2, a[1][4] = sumy;
    a[2][1] = sumx, a[2][2] = sumx2, a[2][3] = sumx3, a[2][4] = sumxy;
    a[3][1] = sumx2, a[3][2] = sumx3, a[3][3] = sumx4, a[3][4] = sumx2y;
    /* Applying Gauss Elimination */
    for (i = 1; i <= n - 1; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = i + 1; j <= n; j++)
        {
            ratio = a[j][i] / a[i][i];

            for (k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
    /* Obtaining Solution by Back Subsitution */
    z[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 1; i--)
    {
        z[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++)
        {
            z[i] = z[i] - a[i][j] * z[j];
        }
        z[i] = z[i] / a[i][i];
    }
    printf("\n%0.3f + %0.3fx + %0.3fx^2", z[1], z[2], z[3]);
    return 0;
}