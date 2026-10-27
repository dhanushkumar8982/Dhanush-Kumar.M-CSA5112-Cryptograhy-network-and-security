 
#include <stdio.h>
#include <string.h>

int main()
{
    char p[5], c[5];
    int P[2][2], C[2][2], inv[2][2], K[2][2];
    int det, m, i, j;

    printf("Enter plaintext (4 letters): ");
    scanf("%4s", p);

    printf("Enter ciphertext (4 letters): ");
    scanf("%4s", c);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            P[i][j] = p[2*j+i] - 'A';
            C[i][j] = c[2*j+i] - 'A';
        }

    det = (P[0][0]*P[1][1] -
           P[0][1]*P[1][0] + 26) % 26;

    for (m = 1; m < 26; m++)
        if ((det*m) % 26 == 1)
            break;

    if (m == 26)
    {
        printf("Cannot recover key: plaintext matrix has no inverse.");
        return 0;
    }

    inv[0][0] = P[1][1]*m % 26;
    inv[0][1] = ((-P[0][1]*m)%26+26)%26;
    inv[1][0] = ((-P[1][0]*m)%26+26)%26;
    inv[1][1] = P[0][0]*m % 26;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            K[i][j] = (C[i][0]*inv[0][j] +
                       C[i][1]*inv[1][j]) % 26;

    printf("Recovered key matrix:\n");
    for (i = 0; i < 2; i++)
        printf("%d %d\n", K[i][0], K[i][1]);

    return 0;
}
