 
#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    if (gcd(a, 26) != 1)
    {
        printf("Invalid key! Choose a coprime with 26.");
        return 0;
    }

    printf("Encrypted text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        int p = text[i] - 'a';
        int c = (a * p + b) % 26;
        printf("%c", c + 'a');
    }

    return 0;
}
