 
#include <stdio.h>

void leftShift(unsigned char b[], int n, int rb)
{
    int i, carry = 0, next;

    for (i = n - 1; i >= 0; i--)
    {
        next = b[i] >> 7;
        b[i] = (b[i] << 1) | carry;
        carry = next;
    }

    if (carry)
        b[n - 1] ^= rb;
}

void display(unsigned char b[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%02X ", b[i]);
    printf("\n");
}

int main()
{
    unsigned char L[16], K1[16], K2[16];
    int bits, n, i, rb;

    printf("Enter block size (64 or 128): ");
    scanf("%d", &bits);

    if (bits != 64 && bits != 128)
    {
        printf("Invalid block size!");
        return 0;
    }

    n = bits / 8;
    rb = (bits == 64) ? 0x1B : 0x87;

    printf("Enter L in hexadecimal (%d bytes):\n", n);

    for (i = 0; i < n; i++)
        scanf("%2hhx", &L[i]);

    for (i = 0; i < n; i++)
        K1[i] = L[i];

    leftShift(K1, n, rb);

    for (i = 0; i < n; i++)
        K2[i] = K1[i];

    leftShift(K2, n, rb);

    printf("\nSubkey K1: ");
    display(K1, n);

    printf("Subkey K2: ");
    display(K2, n);

    return 0;
}
