 
#include <stdio.h>

int main()
{
    int state[5][5];
    int i, j;
    int nonzero = 16;
    int zero = 9;

    // Initialize the state matrix
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i < 3 || (i == 3 && j < 4))
                state[i][j] = 1;
            else
                state[i][j] = 0;
        }
    }

    printf("Initial SHA-3 State Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%d ", state[i][j]);

        printf("\n");
    }

    printf("\nNonzero lanes = %d", nonzero);
    printf("\nZero lanes = %d\n", zero);

    printf("\nWithout permutation or additional mixing,");
    printf("\nthe zero lanes remain zero indefinitely.\n");

    return 0;
}
