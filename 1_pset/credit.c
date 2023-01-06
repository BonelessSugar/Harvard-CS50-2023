#include <stdbool.h>
#include <stdio.h>

bool luhns(long number, int length);
bool cardLength(long number, int length);

int main(void)
{
    printf("Number: ");
    long CCNumber;
    // unsigned long, will never be negative
    scanf("%lu", &CCNumber);

    int CCLength = 0;
    long tempCC = CCNumber;
    while (tempCC > 0)
    {
        CCLength++;
        tempCC /= 10;
    }

    bool longEnough = false;
    bool luhnsReturn = false;
    if (CCLength >= 2)
    {
        luhnsReturn = luhns(CCNumber, CCLength);
    }
    if (luhnsReturn)
    {
        longEnough = cardLength(CCNumber, CCLength);
    }
    // longEnough will always be false if luhnsReturn is false, so only use longEnough condition
    if (!longEnough)
    {
        printf("INVALID\n");
    }
}

bool luhns(long number, int length)
{
    int secondDigits[length / 2];
    int i = 0;
    int luhnsTotal = 0;
    long tempNum = number;
    // not sure if this matters if it is 1 or 10.
    while (tempNum >= 1)
    {
        // Add the sum to the sum of the digits that weren’t multiplied by 2.
        // 13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
        luhnsTotal += (tempNum % 10);
        tempNum /= 10;
        // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
        // 4003600000000014
        // 1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2
        // 2 + 0 + 0 + 0 + 0 + 12 + 0 + 8
        // 2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
        secondDigits[i] = (tempNum % 10) * 2;
        i++;
        tempNum /= 10;
    }
    while (i >= 0)
    // error here, it has 1-2 extra zeroes in the "i".
    {
        if (secondDigits[i] > 9)
        {
            luhnsTotal += (secondDigits[i] - 10 + 1);
        }
        else
        {
            luhnsTotal += secondDigits[i];
        }
        i--;
    }
    // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (luhnsTotal % 10 == 0)
    {
        return true;
    }
    // else
    return false;
}

bool cardLength(long number, int length)
{
    switch (length)
    {
        // American Express uses 15-digit numbers
        case 15:
        {
            int firstTwo = number / 10000000000000;
            // All American Express numbers start with 34 or 37
            if (
                firstTwo == 37 ||
                firstTwo == 34)
            {
                printf("AMEX\n");
                return true;
            }
        }
        // MasterCard uses 16-digit numbers
        case 16:
        {
            int firstTwo = number / 100000000000000;
            int firstOne = number / 1000000000000000;
            // all Visa numbers start with 4
            if (firstOne == 4)
            {
                printf("VISA\n");
                return true;
            }
            // most MasterCard numbers start with 51, 52, 53, 54, or 55
            if (
                firstTwo == 51 ||
                firstTwo == 52 ||
                firstTwo == 53 ||
                firstTwo == 54 ||
                firstTwo == 55)
            {
                printf("MASTERCARD\n");
                return true;
            }
        }
        // Visa uses 13- and 16-digit numbers.
        case 13:
        {
            int firstOne = number / 1000000000000;
            // all Visa numbers start with 4
            if (firstOne == 4)
            {
                printf("VISA\n");
                return true;
            }
        }
    }
    // else
    return false;
}
