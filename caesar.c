#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
            
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    // shifting the plain text by argument[1]
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            if ((plain[i] + atoi(argv[1]) % 26) > 'z') // rotation check
            {
                printf("%c", (plain[i] + (atoi(argv[1]) % 26 - 26)));
            }
            else
            {
                printf("%c", (plain[i] + atoi(argv[1]) % 26));
            }
        }
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            if ((plain[i] + atoi(argv[1]) % 26) > 'Z') // rotation check
            {
                printf("%c", (plain[i] + (atoi(argv[1]) % 26 - 26)));
            }
            else
            {
                printf("%c", (plain[i] + atoi(argv[1]) % 26));
            }
        }
        else
        {
            printf("%c", plain[i]); // convert letters only
        }
    }
    printf("\n");
    return 0;
}
