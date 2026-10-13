 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[100], text[200], matrix[5][5];
    int used[26] = {0};
    int i, j, k = 0, r1, c1, r2, c2;

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter ciphertext: ");
    scanf("%199s", text);

    used['J' - 'A'] = 1;

    for (i = 0; key[i]; i++)
    {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++)
        if (!used[i])
        {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }

    printf("Decrypted text: ");

    for (i = 0; text[i] && text[i + 1]; i += 2)
    {
        char a = toupper(text[i]);
        char b = toupper(text[i + 1]);

        if (a == 'J') a = 'I';
        if (b == 'J') b = 'I';

        for (r1 = 0; r1 < 5; r1++)
            for (c1 = 0; c1 < 5; c1++)
                if (matrix[r1][c1] == a)
                    goto first;

        first:
        for (r2 = 0; r2 < 5; r2++)
            for (c2 = 0; c2 < 5; c2++)
                if (matrix[r2][c2] == b)
                    goto second;

        second:
        if (r1 == r2)
            printf("%c%c", matrix[r1][(c1 + 4) % 5],
                           matrix[r2][(c2 + 4) % 5]);
        else if (c1 == c2)
            printf("%c%c", matrix[(r1 + 4) % 5][c1],
                           matrix[(r2 + 4) % 5][c2]);
        else
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
    }

    printf("\n");
    return 0;
}
