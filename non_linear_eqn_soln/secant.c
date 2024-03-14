#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) pow(x, 5) + pow(x, 3) + 5

int main()
{
    float x0, x1, x2, f0, f1, f2, e = 0.0001, E;
    int step = 1, N = 40;
    printf("\nEnter initial guesses:");
    scanf("%f%f", &x0, &x1);
    printf("\n");
    printf("Step\tx0\t\tf(x0)\t\tx1\t\tf(x1)\t\tx2\t\tE\n");
    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1)
        {
            printf("Mathematical Error.");
            exit(0);
        }
        x2 = (f1 * x0 - f0 * x1) / (f1 - f0);
        f2 = f(x2);
        E = fabs((x2 - x1) / x2);
        printf("%d\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", step, x0, f0, x1, f1, x2, E);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        step = step + 1;
        if (step > N)
        {
            printf("Not Convergent.");
            exit(0);
        }
    } while (E > e);
    printf("\nRoot is: %.4f", x2);
    return 0;
}