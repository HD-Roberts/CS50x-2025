// preprocessor initatives
#include <cs50.h>
#include <stdio.h>

// prototype's
float readingLevel(string text);

int main(void)
{
    //initalising and assigning variables
    const string text = get_string("enter the excert: ");
    int level = readingLevel(text) + 0.5;

    // outputs the correct grade level as a side effect
    if (level < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (level > 0 && level <= 16)
    {
        printf("Grade %i\n", level);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

float readingLevel(string text)
{
    // asigns variables
    float letters = 0;
    float words = 1;
    float sentences = 0;

    //iterates though the input extract
    for (int i = 0; text[i] != '\0'; i++)
    {
        //checks if the value is alphabetic
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }

        //checks for spaces to indicate new words
        else if (text[i] == ' ')
        {
            words++;
        }

        //checks for sentance terminators
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

    }
    // returns the level caculation formula
    return 0.0588 * ((float) letters / words * 100) - 0.296 * ((float) sentences / words * 100) -
           15.8;
}
