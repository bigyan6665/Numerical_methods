#include <stdio.h>
float horner(int n, float a[], float x)
{
    int i;
    float p;
    p = a[n];
    for (i = n - 1; i >= 0; i--)
    {
        p = p * x + a[i];
    }
    return p;
}
int main()
{
    
    int n, i;
    float x, p, a[10];
    printf("Enter the degree of the polynomial = ");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        printf("Enter a[%d] = ", i);
        scanf("%f", &a[i]);
    }
    printf("Enter the point at which to evaluate the polynomial = ");
    scanf("%f", &x);
    p = horner(n, a, x);
    printf("f(x)=%f at x=%f ", p, x);
    return 0;
}