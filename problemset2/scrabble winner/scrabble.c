// preprocessor initatives
#include <cs50.h>
#include <stdio.h>

// prototypes
int scoreCaculator(string word, int previousScore);
char lower(char letter);

int main(void)
{
    // get the players words as a input
    string firstWord = get_string("player one's word:");
    string secondWord = get_string("player two's word:");
    int playerOneScore = scoreCaculator(firstWord, 1000000);
    int playerTwoScore = scoreCaculator(secondWord, playerOneScore);

    if (playerOneScore > playerTwoScore)
    {
        printf("Player 1 wins!\n");
    }
    else if (playerOneScore < playerTwoScore)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("tie!\n");
    }
}

// caculates the words score
int scoreCaculator(string word, int previousScore)
{
    int score = 0;

    // ordered based on letter frequency: https://en.wikipedia.org/wiki/Letter_frequency
    char values[26][2] = {{'e', 1}, {'t', 1}, {'a', 1}, {'o', 1},  {'i', 1}, {'n', 1}, {'s', 1},
                          {'h', 4}, {'r', 1}, {'d', 2}, {'l', 1},  {'c', 3}, {'u', 1}, {'m', 3},
                          {'w', 4}, {'f', 4}, {'g', 2}, {'y', 4},  {'p', 3}, {'b', 3}, {'v', 4},
                          {'k', 5}, {'x', 8}, {'j', 8}, {'q', 10}, {'z', 10}};

    // iterates the characters in the string
    for (int i = 0; word[i] != '\0'; i++)
    {
        char formatedLetter = lower(word[i]);
        // iterates the letters to find the score of a letter
        for (int position = 0; position < 26; position++)
        {
            if (values[position][0] == formatedLetter)
            {
                score += values[position][1];
                break;
            }
        }

        // reduces iterations nessassary to decide the winner
        if (score > previousScore)
        {
            return score;
        }
    }

    return score;
}

// uses +32 ascii to stardardise input to lowercase while not changing the original value
char lower(char letter)
{
    if ((int) letter > 64 && (int) letter < 91)
    {
        return (int) letter + 32;
    }
    return letter;
}
