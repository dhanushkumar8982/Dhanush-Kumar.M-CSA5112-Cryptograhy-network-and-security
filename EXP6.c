 #include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    char text[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    a = (a % 26 + 26) % 26;
    b = (b % 26 + 26) % 26;

    if (gcd(a, 26) != 1)
    {
        printf("Invalid value of a.\n");
        printf("GCD(a, 26) must be 1.\n");
        return 0;
    }

    printf("Encrypted text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            p = toupper((unsigned char)text[i]) - 'A';
            c = (a * p + b) % 26;

            if (islower((unsigned char)text[i]))
                putchar(c + 'a');
            else
                putchar(c + 'A');
        }
        else
        {
            putchar(text[i]);
        }
    }

    printf("\n");
    return 0;
}