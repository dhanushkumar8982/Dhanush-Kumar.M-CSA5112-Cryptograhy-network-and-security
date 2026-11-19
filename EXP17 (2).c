 
#include <stdio.h>
#include <stdint.h>

// Initial Permutation
int IP[64] = {
58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7
};

// Final Permutation
int FP[64] = {
40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25
};

uint64_t permute(uint64_t data, int *table, int n)
{
    uint64_t result = 0;
    int i;

    for(i = 0; i < n; i++)
        result = (result << 1) |
        ((data >> (64 - table[i])) & 1);

    return result;
}

int main()
{
    uint64_t cipher = 0x85E813540F0AB405;
    uint64_t block;
    uint32_t L, R, temp;
    int i;

    // Example round keys (reverse order)
    uint64_t K[16] = {
        0x1B02EFFC7072,
        0x79AED9DBC9E5,
        0x55FC8A42CF99,
        0x72ADD6DB351D,
        0x7CEC07EB53A8,
        0x63A53E507B2F,
        0xEC84B7F618BC,
        0xF78A3AC13BFB,
        0xE0DBEBEDE781,
        0xB1F347BA464F,
        0x215FD3DED386,
        0x7571F59467E9,
        0x97C5D1FABA41,
        0x5F43B7F2E73A,
        0xBF918D3D3F0A,
        0xCB3D8B0E17F5
    };

    // Initial permutation
    block = permute(cipher, IP, 64);

    L = block >> 32;
    R = block & 0xFFFFFFFF;

    printf("DES Decryption\n");

    // 16 rounds using reverse keys
    for(i = 0; i < 16; i++)
    {
        temp = R;
        R = L;
        L = temp ^ (uint32_t)K[15-i];

        printf("Round %d completed\n", i+1);
    }

    block = ((uint64_t)R << 32) | L;

    // Final permutation
    block = permute(block, FP, 64);

    printf("\nDecrypted Text: %016llX\n",
           (unsigned long long)block);

    return 0;
}
