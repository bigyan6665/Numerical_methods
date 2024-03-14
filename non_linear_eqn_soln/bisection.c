#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) pow(x, 3) - 3 * x + 1
// #define f(x) cos(x) - x *exp(x)

int main()
{
    float x0, x1, x2, f0, f1, f2, e = 0.001, E;
    int iteration = 1;
    printf("\nEnter two initial guesses:");
    scanf("%f%f", &x1, &x2);
    f1 = f(x1);
    f2 = f(x2);
    if (f1 * f2 > 0.0)
    {
        printf("Incorrect Initial Guesses.\n");
        exit(0);
    }
    printf("\n");
    printf("iteration\tx1\t\tf(x1)\t\tx2\t\tf(x2)\t\tx0\t\tf(x0)\t\tE\n");
    do
    {
        x0 = (x1 + x2) / 2;
        f0 = f(x0);
        E = fabs((x2 - x1) / 2);
        printf("%d\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", iteration, x1, f1, x2, f2, x0, f0, E);
        if (f0 * f1 < 0)
        {
            x2 = x0;
            f2 = f0;
        }
        else
        {
            x1 = x0;
            f1 = f0;
        }
        iteration = iteration + 1;
    } while (E > e);
    printf("\nRoot is: %.3f", x0);
    return 0;
}
