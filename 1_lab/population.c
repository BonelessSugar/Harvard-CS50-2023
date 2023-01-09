#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    printf("Start size: ");
    scanf("%i",&start);
    // If the user enters a number less than 9
    while (start < 9)
    {
        printf("Start size cannot be less than 9.\n");
        printf("Start size: ");
        scanf("%i",&start);
    }
    // TODO: Prompt for end size
    int end;
    printf("End size: ");
    scanf("%i",&end);
    // If the user enters a number less than the starting population size
    while (end < start)
    {
        printf("End size cannot be less than start size.\n");
        printf("End size: ");
        scanf("%i",&end);
    }
    // TODO: Calculate number of years until we reach threshold
    //  Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
    // round down the born and died ints
    int years = 0;
    while (start < end)
    {
        start = start + start / 3 - start / 4;
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n",years);
}
