 
#include <stdio.h>
#include <string.h>

int power(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        result = (result * a) % m;
        b--;
    }
    return result;
}

int inverse(int k, int q)
{
    int i;
    for (i = 1; i < q; i++)
        if ((k * i) % q == 1)
            return i;
    return -1;
}

int main()
{
    char msg[100];
    int i, h = 0;
    int p = 23, q = 11, g = 4;
    int x = 3, k1 = 2, k2 = 5;
    int r1, s1, r2, s2;
    int n = 143, d = 103;
    int rsa;

    printf("Enter message: ");
    scanf("%99s", msg);

    for (i = 0; i < strlen(msg); i++)
        h += msg[i];

    /* DSA signature 1 */
    r1 = power(g, k1, p) % q;
    s1 = (inverse(k1, q) * (h + x * r1)) % q;

    /* DSA signature 2 */
    r2 = power(g, k2, p) % q;
    s2 = (inverse(k2, q) * (h + x * r2)) % q;

    printf("\nDSA Signature 1: (%d, %d)", r1, s1);
    printf("\nDSA Signature 2: (%d, %d)", r2, s2);

    /* Deterministic textbook RSA signature */
    rsa = power(h, d, n);

    printf("\n\nRSA Signature 1: %d", rsa);
    printf("\nRSA Signature 2: %d", rsa);

    return 0;
}
