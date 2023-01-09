#include <stdio.h>

int main(void)
{
    printf("Height: ");
    int height;
    scanf("%i",&height);
    while (height < 1 || height > 8)
    {
       printf("Height: ");
        scanf("%i",&height);
    }
    for (int i = height - 1; i >= 0; i--)
    {
        for (int k = i - 1; k >=0; k--)
        {
            printf(" ");
        }
        for (int j = height - i; j > 0; j--)
        {
            printf("#");
        }
        printf("  ");
        for (int j = height - i; j > 0; j--)
        {
            printf("#");
        }
    printf("\n");
    }
}
