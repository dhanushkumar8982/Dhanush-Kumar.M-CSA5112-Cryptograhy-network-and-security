  #include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[] = "CIPHER";
    char cipher[27], used[26] = {0};
    int i, j = 0, k;

    /* Generate cipher sequence using keyword */
    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);
        if (!used[ch - 'A'])
        {
            cipher[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    /* Add remaining unused letters */
    for (i = 0; i < 26; i++)
    {
        if (!used[i])
            cipher[j++] = 'A' + i;
    }
    cipher[26] = '\0';

    printf("Plain alphabet : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("Cipher alphabet: %s\n", cipher);

    printf("\nEnter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Encrypted text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            k = toupper((unsigned char)text[i]) - 'A';
            char ch = cipher[k];

            if (islower((unsigned char)text[i]))
                ch = tolower(ch);

            putchar(ch);
        }
        else
        {
            putchar(text[i]);
        }
    }

    printf("\n");
    return 0;
}