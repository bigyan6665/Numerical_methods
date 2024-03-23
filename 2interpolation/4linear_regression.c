#include <stdio.h>
#include <conio.h>
int main()
{
    int n,i;
    printf("Enter the number of data = ");
    scanf("%d", &n);
    float x[n], y[n], sumx = 0, sumxy = 0, sumx2 = 0, sumy = 0;
    printf("Enter data:\n");
    for ( i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }
    for ( i = 0; i < n; i++)
    {
        sumx = sumx + x[i];
        sumxy = sumxy + x[i] * y[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumy = sumy + y[i];
    }
    float b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    float a = (sumy - b * sumx) / n;
    printf("a = %f , b = %f", a, b);
    return 0;
}
