 
#include <stdio.h>

int main()
{
    int P[4] = {10, 20, 30, 40};
    int K = 5, IV = 7;
    int C[4], D[4], i;

    printf("ECB Mode:\n");

    for (i = 0; i < 4; i++)
        C[i] = P[i] ^ K;

    C[0] = C[0] ^ 1;

    for (i = 0; i < 4; i++)
        D[i] = C[i] ^ K;

    printf("Plaintext after error: ");
    for (i = 0; i < 4; i++)
        printf("%d ", D[i]);

    printf("\nCBC Mode:\n");

    for (i = 0; i < 4; i++)
    {
        C[i] = P[i] ^ K ^ IV;
        IV = C[i];
    }

    C[0] = C[0] ^ 1;
    IV = 7;

    printf("Plaintext after error: ");

    for (i = 0; i < 4; i++)
    {
        D[i] = C[i] ^ K ^ IV;
        printf("%d ", D[i]);
        IV = C[i];
    }

    printf("\n");
    return 0;
}
