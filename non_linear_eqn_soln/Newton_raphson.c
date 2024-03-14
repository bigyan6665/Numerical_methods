#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) 3 * x - cos(x) - 1
#define fd(x) 3 + sin(x)

int main()
{
	float x0, x1, f0, f1, fd0, e = 0.0001, E;
	int step = 1, N = 20;
	printf("\nEnter initial guess:");
	scanf("%f", &x0);
	printf("\nStep\tx0\tf(x0)\tfd(x0)\tx1\tE\n");
	do
	{
		fd0 = fd(x0);
		f0 = f(x0);
		if (fd0 == 0.0)
		{
			printf("Mathematical Error.");
			exit(0);
		}
		x1 = x0 - f0 / fd0;
		E = fabs((x1 - x0) / x1);
		printf("%d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", step, x0, f0, fd0, x1, E);
		x0 = x1;
		step = step + 1;
		if (step > N)
		{
			printf("Not Convergent.");
			exit(0);
		}
	} while (E > e);
	printf("\nRoot is: %.4f", x1);
	return 0;
}