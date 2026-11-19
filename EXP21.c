 
#include <stdio.h>
#include <string.h>

#define BLOCK 8

void encrypt(int b[])
{
    int key[8] = {1,0,1,0,1,1,0,1};
    int i;

    for(i = 0; i < 8; i++)
        b[i] = b[i] ^ key[i];
}

void pad(char p[], int *len)
{
    p[(*len)++] = '1';

    while(*len % BLOCK != 0)
        p[(*len)++] = '0';

    p[*len] = '\0';
}

int main()
{
    char p[200];
    int len, i, j;
    int b[8], iv[8] = {1,0,1,0,1,0,1,0};
    int temp[8];

    printf("Enter plaintext (binary): ");
    scanf("%199s", p);

    len = strlen(p);

    for(i = 0; i < len; i++)
    {
        if(p[i] != '0' && p[i] != '1')
        {
            printf("Invalid input");
            return 0;
        }
    }

    pad(p, &len);

    printf("\nPadded Plaintext: %s\n", p);

    // ECB MODE
    printf("\nECB Mode: ");
    for(i = 0; i < len; i += 8)
    {
        for(j = 0; j < 8; j++)
            b[j] = p[i+j] - '0';

        encrypt(b);

        for(j = 0; j < 8; j++)
            printf("%d", b[j]);
    }

    // CBC MODE
    printf("\nCBC Mode: ");
    for(i = 0; i < len; i += 8)
    {
        for(j = 0; j < 8; j++)
        {
            b[j] = (p[i+j]-'0') ^ iv[j];
        }

        encrypt(b);

        for(j = 0; j < 8; j++)
        {
            printf("%d", b[j]);
            iv[j] = b[j];
        }
    }

    // CFB MODE
    printf("\nCFB Mode: ");

    for(i = 0; i < len; i += 8)
    {
        for(j = 0; j < 8; j++)
            temp[j] = iv[j];

        encrypt(temp);

        for(j = 0; j < 8; j++)
        {
            b[j] = (p[i+j]-'0') ^ temp[j];
            printf("%d", b[j]);
            iv[j] = b[j];
        }
    }

    printf("\n");

    return 0;
}
