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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed < 255) {image[i][j].rgbtRed = sepiaRed;} else {image[i][j].rgbtRed = 255;}
            if (sepiaGreen < 255) {image[i][j].rgbtGreen = sepiaGreen;} else {image[i][j].rgbtGreen = 255;}
            if (sepiaBlue < 255) {image[i][j].rgbtBlue = sepiaBlue;} else {image[i][j].rgbtBlue = 255;}
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

// Blur image
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

                    if (positioni >= 0 && positioni < height && positionj >= 0 && positionj < width)
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
