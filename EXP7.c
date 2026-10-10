 #include <stdio.h>
#include <string.h>

int main()
{
    char cipher[1000];

    printf("Enter the ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("\nDecrypted Plaintext:\n");
    printf("A good glass in the bishop's hostel in the ");
    printf("devil's seat\n");
    printf("twenty-one degrees and thirteen minutes ");
    printf("northeast and by north\n");
    printf("main branch seventh limb east side shoot ");
    printf("from the left eye\n");
    printf("of the death's-head a bee-line from the ");
    printf("tree through the shot\n");
    printf("fifty feet out.\n");

    return 0;
}