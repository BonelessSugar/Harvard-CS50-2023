#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        printf("Minimum: ");
        scanf("%i", &min);
    }
    while (min < 1);

    int max;
    do
    {
        printf("Maximum: ");
        scanf("%i", &max);
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    // check if the input number is prime
    // do this by either:
    // checking if a number is divisible by every number between 2 and 1 less than itself
    // or
    // find a faster way
    if (number == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
