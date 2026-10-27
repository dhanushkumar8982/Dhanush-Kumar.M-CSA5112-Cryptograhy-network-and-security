 #include <stdio.h>
#include <string.h>

int main()
{
    char text[] = "HELLO CBC";
    int key = 5;
    int iv = 10;
    int i, cipher;

    printf("Plaintext: %s\n", text);
    printf("Ciphertext: ");

    for (i = 0; i < strlen(text); i++)
    {
        cipher = text[i] ^ key ^ iv;
        printf("%02X ", cipher);
        iv = cipher;
    }

    printf("\n");
    return 0;
}