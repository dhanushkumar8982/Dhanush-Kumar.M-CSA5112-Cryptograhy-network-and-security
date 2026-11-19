 
#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[1000];
    int count[26] = {0};
    int shift, top, i, j;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if (top > 26) top = 26;

    /* Count letter frequencies */
    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z')
            count[cipher[i] - 'A']++;
        else if (cipher[i] >= 'a' && cipher[i] <= 'z')
            count[cipher[i] - 'a']++;
    }

    printf("\nPossible plaintexts in order:\n");

    /* Try all 26 possible shifts */
    for (j = 0; j < top; j++)
    {
        int best = -1;
        int bestShift = -1;

        for (shift = 0; shift < 26; shift++)
        {
            if (count[shift] > best)
            {
                best = count[shift];
                bestShift = shift;
            }
        }

        printf("\nGuess %d (Shift %d): ", j + 1, bestShift);

        for (i = 0; cipher[i] != '\0'; i++)
        {
            char ch = cipher[i];

            if (ch >= 'A' && ch <= 'Z')
                printf("%c", (ch - 'A' - bestShift + 26) % 26 + 'A');
            else if (ch >= 'a' && ch <= 'z')
                printf("%c", (ch - 'a' - bestShift + 26) % 26 + 'a');
            else
                printf("%c", ch);
        }

        count[bestShift] = -1;
    }

    return 0;
}
