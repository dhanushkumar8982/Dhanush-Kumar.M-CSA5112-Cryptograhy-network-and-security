 
#include <stdio.h>
#include <string.h>

int main()
{
    char p[] = "SENDMOREMONEY";
    char p2[] = "CASHNOTNEEDED";
    char c[14];
    int key[13] = {9, 0, 1, 7, 23, 15, 21,
                   14, 11, 11, 2, 8, 9};
    int newkey[13];
    int i, n = 13;

    for (i = 0; i < n; i++)
        c[i] = ((p[i] - 'A' + key[i]) % 26) + 'A';

    c[n] = '\0';

    printf("Ciphertext: %s\n", c);

    printf("New key stream: ");
    for (i = 0; i < n; i++)
    {
        newkey[i] = (c[i] - p2[i] + 26) % 26;
        printf("%d ", newkey[i]);
    }

    printf("\n");
    return 0;
}
