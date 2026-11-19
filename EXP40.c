 
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0}, used[26] = {0};
    int i, j, k, top, max, pos;
    char map[26];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of guesses: ");
    scanf("%d", &top);

    if (top > 26) top = 26;

    /* Count letter frequencies */
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;
        else if (text[i] >= 'a' && text[i] <= 'z')
            count[text[i] - 'a']++;
    }

    /* Sort cipher letters by frequency */
    for (i = 0; i < 26; i++)
        map[i] = '?';

    for (i = 0; i < 26; i++)
    {
        max = -1;
        pos = -1;

        for (j = 0; j < 26; j++)
        {
            if (!used[j] && count[j] > max)
            {
                max = count[j];
                pos = j;
            }
        }

        if (pos != -1)
        {
            used[pos] = 1;
            map[pos] = freq[i];
        }
    }

    printf("\nPossible plaintexts:\n");

    for (k = 0; k < top; k++)
    {
        printf("\nGuess %d: ", k + 1);

        for (i = 0; text[i] != '\0'; i++)
        {
            char ch = text[i];

            if (ch >= 'A' && ch <= 'Z')
                printf("%c", map[ch - 'A']);
            else if (ch >= 'a' && ch <= 'z')
                printf("%c", map[ch - 'a'] + 32);
            else
                printf("%c", ch);
        }
    }

    return 0;
}
