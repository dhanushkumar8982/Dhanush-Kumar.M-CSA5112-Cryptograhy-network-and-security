 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char c[200], p[200], result[26][200];
    int score[26], i, j, shift, n, temp;
    char ch, t;

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    n = strlen(c);

    for (shift = 0; shift < 26; shift++)
    {
        score[shift] = 0;

        for (i = 0; i < n; i++)
        {
            ch = c[i];

            if (isalpha(ch))
            {
                ch = toupper(ch);
                p[i] = (ch - 'A' - shift + 26) % 26 + 'A';

                if (p[i] == 'E' || p[i] == 'T' ||
                    p[i] == 'A' || p[i] == 'O' ||
                    p[i] == 'I' || p[i] == 'N')
                    score[shift]++;
            }
            else
                p[i] = ch;
        }

        p[n] = '\0';
        strcpy(result[shift], p);
    }

    for (i = 0; i < 26; i++)
        for (j = i + 1; j < 26; j++)
            if (score[j] > score[i])
            {
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;

                strcpy(p, result[i]);
                strcpy(result[i], result[j]);
                strcpy(result[j], p);
            }

    printf("\nTop 10 possible plaintexts:\n");

    for (i = 0; i < 10; i++)
        printf("%d. %s\n", i + 1, result[i]);

    return 0;
}
