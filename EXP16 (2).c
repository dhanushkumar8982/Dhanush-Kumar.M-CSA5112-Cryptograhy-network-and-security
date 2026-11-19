 
#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[1000];
    char result[1000];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int map[26];
    int i, j, n;

    printf("Enter encrypted text: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &n);

    if (n > 10) n = 10;

    // Count letter frequencies
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
            count[cipher[i] - 'a']++;

        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
            count[cipher[i] - 'A']++;
    }

    // Generate possible letter mappings
    for(i = 0; i < 26; i++)
        map[i] = i;

    for(i = 0; i < 26; i++)
    {
        for(j = i + 1; j < 26; j++)
        {
            if(count[map[j]] > count[map[i]])
            {
                int temp = map[i];
                map[i] = map[j];
                map[j] = temp;
            }
        }
    }

    // Display possible plaintexts
    printf("\nTop %d Possible Plaintexts:\n", n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; cipher[j] != '\0'; j++)
        {
            char ch = cipher[j];

            if(ch >= 'a' && ch <= 'z')
                result[j] = freq[(map[ch-'a'] + i) % 26];

            else if(ch >= 'A' && ch <= 'Z')
                result[j] = freq[(map[ch-'A'] + i) % 26];

            else
                result[j] = ch;
        }

        result[j] = '\0';
        printf("%d. %s", i+1, result);
    }

    return 0;
}
