 
#include <stdio.h>
#include <math.h>

int main()
{
    double keys = 1;
    int i;
    double power;

    for (i = 1; i <= 25; i++)
        keys *= i;

    power = log(keys) / log(2);

    printf("Number of possible keys = 25! = %.0f\n", keys);
    printf("Approximate power of 2 = 2^%.0f\n", power);

    return 0;
}
