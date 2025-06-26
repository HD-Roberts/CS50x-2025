#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool pangramTest(string key);
void substiution(string key);

int main(int argc, string argv[])
{
    // returns 1 or 0 depending if argv[1] is a pangram
    if (argc != 2)
    {
        printf("error code: 1, invalid command line agrument\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("key must contain 26 characters\n");
        return 1;
    }

    bool pangram = pangramTest(argv[1]);
    if (pangram == 0)
    {
        printf("key incorrectly formated");
        return 1;
    }
    else
    {
        substiution(argv[1]);
    }
}

// checks every alphabet character exists in the key
bool pangramTest(string key)
{
    // makes a 4 bit unasigned int
    unsigned int pangramInt = 0;

    // iterates thought the key
    char current = key[0];
    for (int i = 0; current != '\0'; i++)
    {
        // formats current correctly
        current = tolower(key[i]);

        // checks if current is a alphabetic character
        if (isalpha(current))
        {
            // bitwise left opperation by current - a positions
            pangramInt |= 1 << (current - 'a');
        }
    }
    // if pargarmInt is 26 ones(this value in hexadecimal) it returns true
    return pangramInt == 0x3FFFFFF;
}

void substiution(string key)
{
    string plainText = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; plainText[i] != '\0'; i++)
    {
        if (isalpha(plainText[i]) && islower(plainText[i]))
        {
            printf("%c", tolower(key[tolower(plainText[i]) - 'a']));
        }
        else if (isalpha(plainText[i]) && islower(plainText[i]) == false)
        {
            printf("%c", toupper(key[tolower(plainText[i]) - 'a']));
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}
