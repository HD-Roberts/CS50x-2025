#include <cs50.h>
#include <stdio.h>

void slectionSort(int dataLength, int unorderedList[]);
void bubbleSort(int dataLength, int unorderedList[]);

int main(void)
{
    const int dataLength = 6;
    int unorderedList[dataLength] = {2, 1, 5 , 9, 2, 3};

    bubbleSort(dataLength, unorderedList);

    for (int i = 0; i<dataLength; i++)
    {
        printf("%i", unorderedList[i]);
    }
    printf("\n");
}

void slectionSort(int dataLength, int unorderedList[])
{
    for (int leftPosition = 0; leftPosition < dataLength; leftPosition++)
    {
        int lowestValue = 0x7FFFFFFF;
        int lowestvalueIndex = 0;

        for(int rightPosition = leftPosition; rightPosition < dataLength; rightPosition++)
        {
            if (unorderedList[rightPosition] < lowestValue)
            {
                lowestValue= unorderedList[rightPosition];
                lowestvalueIndex = rightPosition;
            }
        }

        int temp = unorderedList[leftPosition];
        unorderedList[leftPosition] = lowestValue;
        unorderedList[lowestvalueIndex] = temp;
    }
}

void bubbleSort(int dataLength, int unorderedList[])
{
    for (int i = 0; i < dataLength; i++)
    {
        int swapCount = 0;
        for(int pointer = 0; pointer < dataLength-1-i; pointer++)
            {
            if(unorderedList[pointer] > unorderedList[pointer+1])
            {
                int temp = unorderedList[pointer];
                unorderedList[pointer] = unorderedList[pointer+1];
                unorderedList[pointer+1] = temp;
                swapCount++;
            }
        }
        if (swapCount == 0)
        {
            break;
        }
    }
}
