#include <stdio.h>
float diffmul(int i, float u)
{
    if (i == 0)
    {
        return 1;
    }
    else
    {
        float x = (u - (i - 1)) / i;
        return x * diffmul((i - 1), u);
    }
}
int main()
{
    float x[20], y[20][20];
    int i, j, n;
    printf("Enter number of data?\n");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("y[%d]=", i);
        scanf("%f", &y[i][0]);
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
    // printf("\nFORWARD DIFFERENCE TABLE\n\n");
    // for (i = 0; i < n; i++)
    // {
    //     printf("%0.2f", x[i]);
    //     for (j = 0; j < n - i; j++)
    //     {
    //         printf("\t%0.2f", y[i][j]);
    //     }
    //     printf("\n");
    // }

    float base = x[0], ip, var[n], sum = 0;
    printf("\nEnter interpolation point = ");
    scanf("%f", &ip);
    float diff = x[1] - x[0]; // difference is assumed to be constant
    float u = (ip - base) / diff;
    for ( i = 0; i < n; i++)
    {
        var[i] = diffmul(i, u);
    }
    // newtons forward interpolation ko main step
    for ( i = 0; i < n; i++)
    {
        sum = sum + var[i] * y[0][i];
    }
    printf("Forward interpolation value at %f = %f ", ip, sum);
    return 0;
}
