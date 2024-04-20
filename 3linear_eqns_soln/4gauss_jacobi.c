#include <stdio.h>
#include <math.h>
float F1(float x, float y, float z)
{
    return ((-1 + 2 * y - 3 * z) / 5);
}
float F2(float x, float y, float z)
{
    return ((2 + 3 * x - z) / 9);
}
float F3(float x, float y, float z)
{
    return ((3 - 2 * x + y) / -7);
}
int main()
{
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int count = 1;
    printf("Enter tolerable error = ");
    scanf("%f",&e);
    printf("\nCount\tx\ty\tz\n");
    do
    {
        x1 = F1(x0, y0, z0);
        y1 = F2(x0, y0, z0);
        z1 = F3(x0, y0, z0);
        printf("%d\t%0.2f\t%0.2f\t%0.2f\n", count, x1, y1, z1);
        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);
        count++;
        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (e1 > e && e2 > e && e3 > e);
    printf("\nSolution: x=%0.2f, y=%0.2f and z = %0.2f\n", x1, y1, z1);
    return 0;
}
