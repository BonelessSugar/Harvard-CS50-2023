// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


string replace(string inStr);

int main(int argc, string argv[])
{
    // Your program must accept a single command-line argument, which will be the word that you want to convert.

    // If your program is executed without any command-line arguments or with more than one command-line argument,
    // your program should print an error message of your choice (with printf) and return from main a value of 1
    // (which tends to signify an error) immediately.

    // argc defaults to 1 with no input, 2 with one input, 3... etc.
    if (argc != 2) {
        printf("Please input a single command-line argument.\n");
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    printf("%s\n",replace(argv[1]));
}

string replace(string inStr)
{
    // Your program must contain a function called replace which takes a string input and returns a string output.
    string changeStr = inStr;
    // This function will change the following vowels to numbers: a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not change.
    for (int i = 0, n = strlen(changeStr); i < n; i++)
    {
        switch (changeStr[i])
        {
            case 'a':
                changeStr[i] = '6';
                break;
            case 'e':
                changeStr[i] = '3';
                break;
            case 'i':
                changeStr[i] = '1';
                break;
            case 'o':
                changeStr[i] = '0';
                break;
            default:
                break;
        }
    }
    return  changeStr;
    // The input parameter for the replace function will be argv[1] and the return value is the converted word.

    // The main function will then print the converted word, followed by \n.

    // You may want to try using the switch case default statement in your replace function.
}
