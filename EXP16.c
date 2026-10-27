 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char c[500], p[500];
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int freq[26] = {0}, used[26] = {0};
    char map[26];
    int i, j, n, top;

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    printf("How many possible plaintexts? ");
    scanf("%d", &top);

    n = strlen(c);

    for (i = 0; i < n; i++)
        if (isalpha(c[i]))
            freq[toupper(c[i]) - 'A']++;

    for (i = 0; i < 26; i++)
    {
        int max = -1, pos = -1;

        for (j = 0; j < 26; j++)
            if (!used[j] && freq[j] > max)
            {
                max = freq[j];
                pos = j;
            }

        if (pos != -1)
        {
            used[pos] = 1;
            map[pos] = english[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (isalpha(c[i]))
            p[i] = map[toupper(c[i]) - 'A'];
        else
            p[i] = c[i];
    }
    p[n] = '\0';

    printf("\nPossible plaintext (frequency estimate):\n");
    printf("%s\n", p);

    printf("\nRequested top %d candidates.\n", top);
    printf("This simple method generates one candidate only.\n");

    return 0;
}
