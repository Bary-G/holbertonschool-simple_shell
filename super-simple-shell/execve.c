#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
printf("Before execve\n");
if (execve(argv[0], argv, NULL) == -1)
{
perror("Error:");
}
printf("After execve\n");
return (0);
}

