 
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    n = strlen(text);

    printf("Enter %d key values (0-25): ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &key[i]);

    printf("\nEncrypted text: ");
    for (i = 0; i < n; i++)
    {
        int p = text[i] - 'a';
        int c = (p + key[i]) % 26;
        printf("%c", c + 'a');
    }

    return 0;
}
