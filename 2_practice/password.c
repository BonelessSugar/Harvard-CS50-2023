// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // Since you have to find at least one lower case letter, one upper case letter, one number and one symbol,
    // you may want to create a boolean variable for each and set each to false before you iterate through the string.
    bool lowerLetter = false;
    bool upperLetter = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (islower(password[i]) > 0)
        {
            lowerLetter = true;
        }
        if (isupper(password[i]) > 0)
        {
            upperLetter = true;
        }
        if (isdigit(password[i]) > 0)
        {
            number = true;
        }
        if (isalnum(password[i]) < 1)
        {
            symbol = true;
        }
        // printf("%d\n",islower(password[i]));
    }
    return lowerLetter && upperLetter && number && symbol;
}
