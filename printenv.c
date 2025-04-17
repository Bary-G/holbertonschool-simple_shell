#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the environment using the global variable 'environ'
 *
 * Return: Always 0.
 */
int main(void)
{
    extern char **environ;
    int i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
    
    return (0);
}

