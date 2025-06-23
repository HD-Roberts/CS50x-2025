// libarys
#include <cs50.h>
#include <math.h>
#include <stdio.h>

// prototypes
void validCardType(long cardNumber);
bool checksum(int length, long cardNumber);

int main(void)
{
    long cardNumber = get_long("enter long card number: \n");
    validCardType(cardNumber);
}

void validCardType(long cardNumber)
{
    // visa 16 long
    if (cardNumber / 1000000000000000 == 4)
    {
        bool valid = checksum(15, cardNumber);
        if (valid == true)
        {
            printf("VISA\n");
        }
    }

    // visa 13 long
    else if (cardNumber / 1000000000000 == 4)
    {
        bool valid = checksum(15, cardNumber);
        if (valid == true)
        {
            printf("VISA\n");
        }
    }

    // mastercard 16 long
    else if (cardNumber / 100000000000000 > 50 && cardNumber / 100000000000000 < 56)
    {
        bool valid = checksum(15, cardNumber);
        if (valid == true)
        {
            printf("MASTERCARD\n");
        }
    }

    // american express 15 long
    else if (cardNumber / 10000000000000 == 34 || cardNumber / 10000000000000 == 37)
    {
        bool valid = checksum(15, cardNumber);
        if (valid == true)
        {
            printf("AMEX\n");
        }
    }

    // non acceptable input
    else
    {
        printf("INVALID\n");
    }
}

bool checksum(int length, long cardNumber)
{
    long power = 1;
    long powerPlusOne = 10;
    int sum = 0;

    for (int digit = 0; digit <= length; digit++)
    {
        int nthNumber = (cardNumber % powerPlusOne) / power;

        if ((length - digit - 1) % 2 == 0)
        {
            sum += nthNumber;
        }

        else
        {
            if (nthNumber * 2 > 9)
            {
                sum += (nthNumber * 2) % 10 + (nthNumber * 2) / 10;
            }
            else
            {
                sum += nthNumber * 2;
            }
        }

        power = power * 10;
        powerPlusOne = powerPlusOne * 10;
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    printf("INVALID\n");
    return false;
}
