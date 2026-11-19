 
#include <stdio.h>

int main()
{
    int n = 3599, e = 31;
    int p, q, phi;
    int i, d = 0;

    // Find prime factors
    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            p = i;
            q = n / i;
            break;
        }
    }

    // Calculate Euler's totient
    phi = (p - 1) * (q - 1);

    // Find private key using Extended Euclidean Algorithm
    int a = e, b = phi;
    int x1 = 1, x2 = 0;

    while(b != 0)
    {
        int quotient = a / b;
        int temp = a % b;
        a = b;
        b = temp;

        temp = x1 - quotient * x2;
        x1 = x2;
        x2 = temp;
    }

    d = x1;

    if(d < 0)
        d += phi;

    printf("RSA Private Key Calculation\n");
    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("Public Key (e) = %d\n", e);
    printf("Phi(n) = %d\n", phi);
    printf("Private Key (d) = %d\n", d);

    return 0;
}
