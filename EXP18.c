 
#include <stdio.h>
#include <stdint.h>

int PC1[56] = {
57,49,41,33,25,17,9,1,58,50,42,34,26,18,
10,2,59,51,43,35,27,19,11,3,60,52,44,36,
63,55,47,39,31,23,15,7,62,54,46,38,30,22,
14,6,61,53,45,37,29,21,13,5,28,20,12,4
};

int PC2[48] = {
14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,
26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,
51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32
};

int shift[16] = {
1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
};

uint64_t permute(uint64_t x, int p[], int n, int bits)
{
    uint64_t result = 0;
    int i;

    for (i = 0; i < n; i++)
        result = (result << 1) |
                 ((x >> (bits - p[i])) & 1);

    return result;
}

int main()
{
    unsigned long long key;
    uint64_t k56, subkey;
    unsigned int c, d;
    int i, s;

    printf("Enter 64-bit key in hexadecimal: ");
    scanf("%llx", &key);

    k56 = permute(key, PC1, 56, 64);

    c = (unsigned int)(k56 >> 28);
    d = (unsigned int)(k56 & 0x0FFFFFFF);

    for (i = 0; i < 16; i++)
    {
        s = shift[i];

        c = ((c << s) | (c >> (28 - s))) & 0x0FFFFFFF;
        d = ((d << s) | (d >> (28 - s))) & 0x0FFFFFFF;

        subkey = permute(((uint64_t)c << 28) | d,
                         PC2, 48, 56);

        printf("K%-2d = %012llX\n", i + 1,
               (unsigned long long)subkey);
    }

    return 0;
}
 