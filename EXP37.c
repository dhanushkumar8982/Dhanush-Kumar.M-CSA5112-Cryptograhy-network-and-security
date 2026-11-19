 
#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[1000], result[1000];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0}, used[26] = {0};
    int top, i, j, max;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if (top < 1)
        return 0;

    /* Count letter frequencies */
    for (i = 0; cipher[i] != '\0'; i++)
        if (cipher[i] >= 'A' && cipher[i] <= 'Z')
            count[cipher[i] - 'A']++;
        else if (cipher[i] >= 'a' && cipher[i] <= 'z')
            count[cipher[i] - 'a']++;

    printf("\nPossible plaintexts:\n");

    /* Generate frequency-based guesses */
    for (j = 0; j < top; j++)
    {
        int temp[26];

        for (i = 0; i < 26; i++)
            temp[i] = count[i];

        for (i = 0; i <= j; i++)
        {
            max = -1;
            int pos = -1;

            for (int k = 0; k < 26; k++)
                if (!used[k] && temp[k] > max)
                {
                    max = temp[k];
                    pos = k;
                }

            if (pos != -1)
            {
                used[pos] = 1;
                result[pos] = freq[i];
            }
        }

        for (i = 0; i < 26; i++)
            if (used[i])
                result[i] = result[i];

        printf("\nGuess %d: ", j + 1);

        for (i = 0; cipher[i] != '\0'; i++)
        {
            char ch = cipher[i];

            if (ch >= 'A' && ch <= 'Z')
                printf("%c", result[ch - 'A']);
            else if (ch >= 'a' && ch <= 'z')
                printf("%c", result[ch - 'a'] + 32);
            else
                printf("%c", ch);
        }
    }

    return 0;
}
