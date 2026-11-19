 
#include <stdio.h>
#include <string.h>

int IP[]  = {2,6,3,1,4,8,5,7};
int IPI[] = {4,1,3,5,7,2,8,6};
int P10[] = {3,5,2,7,4,10,1,9,8,6};
int P8[]  = {6,3,7,4,8,5,10,9};
int EP[]  = {4,1,2,3,2,3,4,1};
int P4[]  = {2,4,3,1};

int S0[4][4] = {
    {1,0,3,2},
    {3,2,1,0},
    {0,2,1,3},
    {3,1,3,2}
};

int S1[4][4] = {
    {0,1,2,3},
    {2,0,1,3},
    {3,0,1,0},
    {2,1,0,3}
};

int permute(int x, int t[], int n, int size)
{
    int r = 0, i;
    for(i = 0; i < n; i++)
        r = (r << 1) | ((x >> (size-t[i])) & 1);
    return r;
}

int leftshift(int x, int n)
{
    return ((x << n) | (x >> (5-n))) & 31;
}

void generateKeys(int key, int *k1, int *k2)
{
    int p = permute(key, P10, 10, 10);
    int l = (p >> 5) & 31;
    int r = p & 31;

    l = leftshift(l, 1);
    r = leftshift(r, 1);
    *k1 = permute((l << 5) | r, P8, 8, 10);

    l = leftshift(l, 2);
    r = leftshift(r, 2);
    *k2 = permute((l << 5) | r, P8, 8, 10);
}

int substitute(int x, int s[4][4])
{
    int row = ((x & 8) >> 2) | (x & 1);
    int col = (x >> 1) & 3;
    return s[row][col];
}

int fk(int x, int key)
{
    int l = x >> 4;
    int r = x & 15;
    int e = permute(r, EP, 8, 4) ^ key;

    int a = substitute(e >> 4, S0);
    int b = substitute(e & 15, S1);

    int p = permute((a << 2) | b, P4, 4, 4);

    return ((l ^ p) << 4) | r;
}

int swap(int x)
{
    return ((x & 15) << 4) | (x >> 4);
}

int encrypt(int x, int k1, int k2)
{
    x = permute(x, IP, 8, 8);
    x = fk(x, k1);
    x = swap(x);
    x = fk(x, k2);
    return permute(x, IPI, 8, 8);
}

int decrypt(int x, int k1, int k2)
{
    x = permute(x, IP, 8, 8);
    x = fk(x, k2);
    x = swap(x);
    x = fk(x, k1);
    return permute(x, IPI, 8, 8);
}

void printBinary(int x)
{
    int i;
    for(i = 7; i >= 0; i--)
        printf("%d", (x >> i) & 1);
}

int main()
{
    int key = 0b0111111101;
    int iv = 0b10101010;
    int plain[2] = {0b00000001, 0b00100011};
    int cipher[2], recovered[2];
    int k1, k2, prev, i;

    generateKeys(key, &k1, &k2);

    printf("S-DES CBC Encryption\n");

    prev = iv;

    for(i = 0; i < 2; i++)
    {
        cipher[i] = encrypt(plain[i] ^ prev, k1, k2);
        prev = cipher[i];

        printf("Cipher Block %d: ", i+1);
        printBinary(cipher[i]);
        printf("\n");
    }

    printf("\nS-DES CBC Decryption\n");

    prev = iv;

    for(i = 0; i < 2; i++)
    {
        recovered[i] = decrypt(cipher[i], k1, k2) ^ prev;
        prev = cipher[i];

        printf("Plain Block %d: ", i+1);
        printBinary(recovered[i]);
        printf("\n");
    }

    printf("\nOriginal Plaintext: ");
    printBinary(recovered[0]);
    printf(" ");
    printBinary(recovered[1]);

    return 0;
}
