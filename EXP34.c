 
#include <stdio.h>

int encrypt(int x)
{
    return (5 * x + 7) % 256;
}

int main()
{
    int p[10], ecb[10], cbc[10], cfb[10];
    int n, i, iv = 10, prev, stream;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter plaintext blocks (0-255): ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    /* ECB */
    for (i = 0; i < n; i++)
        ecb[i] = encrypt(p[i]);

    /* CBC */
    prev = iv;
    for (i = 0; i < n; i++)
    {
        cbc[i] = encrypt(p[i] ^ prev);
        prev = cbc[i];
    }

    /* CFB */
    prev = iv;
    for (i = 0; i < n; i++)
    {
        stream = encrypt(prev);
        cfb[i] = p[i] ^ stream;
        prev = cfb[i];
    }

    printf("\nECB: ");
    for (i = 0; i < n; i++)
        printf("%d ", ecb[i]);

    printf("\nCBC: ");
    for (i = 0; i < n; i++)
        printf("%d ", cbc[i]);

    printf("\nCFB: ");
    for (i = 0; i < n; i++)
        printf("%d ", cfb[i]);

    return 0;
}
