 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int power(int a, int b, int n)
{
    int result = 1;

    while(b > 0)
    {
        result = (result * a) % n;
        b--;
    }

    return result;
}

int main()
{
    char text[100];
    int e = 7, n = 187;
    int i, m, c;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("\nRSA Encryption:\n");

    for(i = 0; text[i] != '\0'; i++)
    {
        m = toupper(text[i]) - 'A';

        if(m < 0 || m > 25)
            continue;

        c = power(m, e, n);

        printf("%d ", c);
    }

    printf("\n");
    return 0;
}
