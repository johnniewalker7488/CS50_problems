#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);
int main(int argc, string argv[])
{
    // check the number of arguments
    if (argc != 2)
    {
        printf("Usage: ./vinegere keyword\n");
        return 1;
    }
    // check the argument is aphabetical
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Usage: ./vinegere keyword\n");
            return 1;
        }
    }
    
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    int keylen = strlen(argv[1]);
    int j = 0;
    int key;
    char cipher;
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        j = j % keylen;
        if isupper(plain[i])
        {
            key = shift(argv[1][j]);
            cipher = (plain[i] - 'A' + key) % 26 + 65;
            printf("%c", cipher);
        }
        else if islower(plain[i])
        {
            key = shift(argv[1][j]);
            cipher = (plain[i] - 'a' + key) % 26 + 97;
            printf("%c", cipher);
        }  
        // no shift for non-alphabetical
        else
        {
            printf("%c", plain[i]);
        }
        if isalpha(plain[i])
        {
            j++;
        }
    }
    printf("\n");
}

int shift(char c)
{
    int key;
    if isupper(c)
    {
        key = c - 65;
        return key;
    }
    else
    {
        key = c - 97;
        return key;
    }
}
