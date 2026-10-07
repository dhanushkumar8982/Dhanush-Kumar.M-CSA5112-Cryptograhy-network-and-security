#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;   // Combine I and J

    for (i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main()
{
    char key[100], plaintext[200], prepared[200];
    int i, j, len = 0;
    int r1, c1, r2, c2;

    printf("Enter the keyword: ");
    scanf("%s", key);

    createMatrix(key);

    printf("\n5 x 5 Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }

    printf("\nEnter the plaintext: ");
    scanf("%s", plaintext);

    /* Prepare plaintext */
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = toupper(plaintext[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z')
            prepared[len++] = ch;
    }

    prepared[len] = '\0';

    /* Insert X between repeated letters */
    char temp[200];
    int t = 0;

    for (i = 0; i < len; i++)
    {
        temp[t++] = prepared[i];

        if (i + 1 < len && prepared[i] == prepared[i + 1])
            temp[t++] = 'X';
    }

    if (t % 2 != 0)
        temp[t++] = 'X';

    temp[t] = '\0';

    printf("Prepared Text: %s\n", temp);

    printf("Ciphertext: ");

    for (i = 0; i < t; i += 2)
    {
        findPosition(temp[i], &r1, &c1);
        findPosition(temp[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            printf("%c%c",
                   matrix[r1][(c1 + 1) % 5],
                   matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2)
        {
            printf("%c%c",
                   matrix[(r1 + 1) % 5][c1],
                   matrix[(r2 + 1) % 5][c2]);
        }
        else
        {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }

    printf("\n");

    return 0;
}