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
    float u = 0.5;
    float var[5];
    for (int i = 0; i < 5; i++)
    {
        var[i] = diffmul(i, u);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n%f\t", var[i]);
    }
    return 0;
}