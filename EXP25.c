 
#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int p = 17, q = 11;
    int n = p * q;
    int e = 7;
    int m, c, i;

    printf("Enter plaintext block: ");
    scanf("%d", &m);

    // RSA encryption
    c = 1;
    for(i = 0; i < e; i++)
        c = (c * m) % n;

    printf("\nRSA Encryption\n");
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Ciphertext: %d\n", c);

    // Check common factor
    int g = gcd(m, n);

    printf("\nGCD(%d, %d) = %d\n", m, n, g);

    if(g > 1 && g < n)
    {
        printf("Common factor found!\n");
        printf("One factor of n = %d\n", g);
        printf("Other factor of n = %d\n", n/g);
        printf("RSA modulus can be factorized.\n");
    }
    else
    {
        printf("No useful common factor found.\n");
    }

    return 0;
}
