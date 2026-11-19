 
#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

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
    int p = 17, q = 11;
    int n = p * q;
    int phi = (p-1) * (q-1);

    int e = 7;
    int d = 23;

    int newe = 3, newd = 27;
    int message = 20;
    int cipher, decrypted;

    printf("RSA Public Key Encryption\n");

    cipher = power(message,e,n);

    printf("Original Public Key: (%d,%d)\n",e,n);
    printf("Original Private Key: %d\n",d);

    printf("\nBob leaks his private key!\n");

    if(gcd(newe,phi) == 1)
    {
        printf("New Public Key: (%d,%d)\n",newe,n);
        printf("New Private Key: %d\n",newd);

        decrypted = power(cipher,newd,n);

        printf("Encrypted Message: %d\n",cipher);
        printf("Decrypted Message: %d\n",decrypted);
    }
    else
    {
        printf("Invalid new public key\n");
    }

    return 0;
}
