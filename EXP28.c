 
#include <stdio.h>

long long power(long long a, long long b, long long q)
{
    long long result = 1;
    for (int i = 0; i < b; i++)
        result = (result * a) % q;
    return result;
}

int main()
{
    long long q = 23, a = 5;
    long long x = 6, y = 15;
    long long A, B, key1, key2;

    A = power(a, x, q);
    B = power(a, y, q);

    key1 = power(B, x, q);
    key2 = power(A, y, q);

    printf("Alice sends: %lld\n", A);
    printf("Bob sends: %lld\n", B);
    printf("Alice's secret key: %lld\n", key1);
    printf("Bob's secret key: %lld\n", key2);

    return 0;
}
