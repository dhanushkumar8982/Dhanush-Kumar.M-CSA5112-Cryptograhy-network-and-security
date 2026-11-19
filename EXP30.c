 
#include <stdio.h>

/* Toy block cipher for demonstration only */
unsigned int encrypt(unsigned int key, unsigned int block)
{
    return (5 * block + key) % 256;
}

int main()
{
    unsigned int key, x, t, c1, c2;

    printf("Enter key (0-255): ");
    scanf("%u", &key);

    printf("Enter message X (0-255): ");
    scanf("%u", &x);

    /* CBC-MAC of one-block message */
    t = encrypt(key, x);

    /* CBC-MAC of two-block message */
    c1 = encrypt(key, x);
    c2 = encrypt(key, (x ^ t) ^ c1);

    printf("\nMAC of X = %u", t);
    printf("\nSecond block = X XOR T = %u", x ^ t);
    printf("\nMAC of two-block message = %u", c2);

    if (t == c2)
        printf("\nForgery successful! Both MAC values are equal.");

    return 0;
}
