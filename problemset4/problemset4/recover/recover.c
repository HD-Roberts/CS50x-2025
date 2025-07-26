#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define FATsize 512

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./recover [filename]\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Invalid filename: %s\n", argv[1]);
        return 1;
    }

    uint8_t buffer[FATsize];
    int jpeg_count = 0;
    char filename[8];
    FILE *img = NULL;

    while (fread(buffer, FATsize, 1, input) == 1)
    {
        // Detect JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", jpeg_count);

            img = fopen(filename, "wb");
            jpeg_count++;
        }

        if (img != NULL)
        {
            fwrite(buffer, FATsize, 1, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(input);
    return 0;
}
