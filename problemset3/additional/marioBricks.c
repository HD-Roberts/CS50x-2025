#include <cs50.h>
#include<stdio.h>
void Pyramidbuilder (int height, int width);

int main(void)
{
    int height = 4;
    Pyramidbuilder(height, 0); // the height of the pyramid, the starting row
}

void Pyramidbuilder (int height, int width)
{
    if (width == height || height <= 0)
    {
        return;
    }

    for (int bricks = 0; bricks < width+1; bricks++)
    {
        printf("#");
    }
    printf("\n");

    width++;
    return Pyramidbuilder (height, width);
}
