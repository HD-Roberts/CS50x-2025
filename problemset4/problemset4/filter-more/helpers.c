#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grayscaleValue = (int) round(
                (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtRed = grayscaleValue;
            image[i][j].rgbtGreen = grayscaleValue;
            image[i][j].rgbtBlue = grayscaleValue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int comparisons = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < comparisons; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int count = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    int positioni = i + row;
                    int positionj = j + col;

                    if (positioni >= 0 && positionj < height && positioni >= 0 && positionj < width)
                    {
                        totalRed += image[positioni][positionj].rgbtRed;
                        totalGreen += image[positioni][positionj].rgbtGreen;
                        totalBlue += image[positioni][positionj].rgbtBlue;
                        count++;
                    }
                }
            }
            temp[i][j].rgbtRed = round((float) totalRed / count);
            temp[i][j].rgbtGreen = round((float) totalGreen / count);
            temp[i][j].rgbtBlue = round((float) totalBlue / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    return;
}
