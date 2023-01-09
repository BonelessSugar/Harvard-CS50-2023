// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    printf("Bill before tax and tip: ");
    float bill_amount;
    scanf("%f", &bill_amount);
    printf("Sale Tax Percent: ");
    float tax_percent;
    scanf("%f", &tax_percent);
    printf("Tip percent: ");
    int tip_percent;
    scanf("%i", &tip_percent);

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // add tax to bill before calculating tip
    // return half the full amount
    // note: tip / 100 = int, tip / 100.0 = float
    float total = bill * (1 + tax / 100) * (1 + tip / 100.0);
    return total / 2;
}
