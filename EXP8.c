 #include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[] = "CIPHER";
    char cipher[27];
    int i, j, k = 0;

    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = tolower(key[i]);
        int found = 0;

        for (j = 0; j < k; j++)
            if (cipher[j] == ch)
                found = 1;

        if (!found)
            cipher[k++] = ch;
    }

    for (i = 0; i < 26; i++)
    {
        char ch = 'a' + i;
        int found = 0;

        for (j = 0; j < k; j++)
            if (cipher[j] == ch)
                found = 1;

        if (!found)
            cipher[k++] = ch;
    }

    cipher[26] = '\0';

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Encrypted text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        char ch = tolower(text[i]);

        if (ch >= 'a' && ch <= 'z')
            printf("%c", cipher[ch - 'a']);
        else
            printf("%c", text[i]);
    }

    return 0;
}