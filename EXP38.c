 
#include <stdio.h>

int main()
{
    int p[2][2], c[2][2];
    int det, inv, a, b, d, e;
    int i, j;

    printf("Enter 4 plaintext values (0-25):\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&p[i][j]);

    printf("Enter corresponding 4 ciphertext values:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&c[i][j]);

    det = (p[0][0]*p[1][1] -
           p[0][1]*p[1][0]) % 26;

    if(det < 0) det += 26;

    inv = -1;
    for(i=1;i<26;i++)
        if((det*i)%26 == 1)
            inv = i;

    if(inv == -1)
    {
        printf("Cannot recover key. Plaintext matrix is not invertible.");
        return 0;
    }

    a = (p[1][1]*inv)%26;
    b = (-p[0][1]*inv)%26;
    d = (-p[1][0]*inv)%26;
    e = (p[0][0]*inv)%26;

    if(b<0) b+=26;
    if(d<0) d+=26;

    printf("\nRecovered Hill Cipher Key:\n");
    printf("%d %d\n", (c[0][0]*a+c[0][1]*d)%26,
                       (c[0][0]*b+c[0][1]*e)%26);
    printf("%d %d\n", (c[1][0]*a+c[1][1]*d)%26,
                       (c[1][0]*b+c[1][1]*e)%26);

    return 0;
}
