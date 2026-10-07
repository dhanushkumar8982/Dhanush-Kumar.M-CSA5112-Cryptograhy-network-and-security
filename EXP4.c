 #include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100], key[100];
    char encrypted[100], decrypted[100];
    int i, keyLen;

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    keyLen = strlen(key);

    /* Encryption */
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        encrypted[i] = ((toupper(plaintext[i]) - 'A' +
                         toupper(key[i % keyLen]) - 'A') % 26) + 'A';
    }
    encrypted[i] = '\0';

    /* Decryption */
    for (i = 0; encrypted[i] != '\0'; i++)
    {
        decrypted[i] = ((encrypted[i] - 'A' -
                         (toupper(key[i % keyLen]) - 'A') + 26) % 26) + 'A';
    }
    decrypted[i] = '\0';

    printf("\nEncrypted Text: %s\n", encrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}