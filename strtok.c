#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - separate main string into multiples strings
 *
 * Return: Always 0.
*/
int main()
{
    char str[] = "- This is pidarast -";
    const char * separators = " ,.-!";

    char * strToken = strtok (str, separators);
    while (strToken != NULL)
    {
        printf("%s\n", strToken);
        strToken = strtok(NULL, separators);
    }

    return (0);
}
