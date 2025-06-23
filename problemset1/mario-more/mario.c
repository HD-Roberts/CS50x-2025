// libary header files
#include <cs50.h>
#include <stdio.h>

int heightValidation(void);                // validation prototype
int rowGeneration(int height, int blocks); // row prototype

int main(void)
{
    int height = heightValidation(); // asigns height a valid value of height bounded by [1,8]
    for (int blocks = 1; blocks <= height; blocks++) // iterativly calls row generation fuction
    {
        rowGeneration(height, blocks);
    }
}

int rowGeneration(int height, int blocks) // generates the block rows
{
    for (int i = 0; i < height * 2 + 2; i++)
    {
        if (i < height - blocks)
        {
            printf(" ");
        }
        else if (i >= height && i < height + 2)
        {
            printf(" ");
        }
        else if ((i >= height - blocks && i < height) || (i < height * 2 + 2 - (height - blocks)))
        {
            printf("#");
        }
    }
    printf("\n");
    return 0;
}

int heightValidation(void) // ensures a valid input
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}
