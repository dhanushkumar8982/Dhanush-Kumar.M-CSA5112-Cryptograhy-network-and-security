 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char msg[200], text[200], matrix[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };
    int i, j, n = 0, r1, c1, r2, c2;

    printf("Enter plaintext: ");
    fgets(msg, sizeof(msg), stdin);

    for (i = 0; msg[i] != '\0'; i++)
        if (isalpha((unsigned char)msg[i]))
        {
            char ch = toupper((unsigned char)msg[i]);
            if (ch == 'J') ch = 'I';
            text[n++] = ch;
        }

    printf("Encrypted text: ");

    for (i = 0; i < n;)
    {
        char a = text[i++];
        char b;

        if (i < n && text[i] != a)
            b = text[i++];
        else
            b = 'X';

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
            printf("%c%c", matrix[r1][(c1+1)%5],
                           matrix[r2][(c2+1)%5]);
        else if (c1 == c2)
            printf("%c%c", matrix[(r1+1)%5][c1],
                           matrix[(r2+1)%5][c2]);
        else
            printf("%c%c", matrix[r1][c2],
                           matrix[r2][c1]);
    }

    printf("\n");
    return 0;
}
