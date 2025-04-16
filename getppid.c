#include <stdio.h>
#include <unistd.h>

/**
 * main - Prints the PID of the parent process
 *
 * Return: Always 0
 */
int main(void)
{
    printf("%d\n", getppid());
    return (0);
}

