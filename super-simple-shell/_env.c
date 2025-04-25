#include <stdio.h>

extern char **environ;

/**
 * main - prints the addresses of envp and environ
 * @argc: argument count (unused)
 * @argv: argument vector (unused)
 * @envp: environment pointer (from main)
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
(void)argc;
(void)argv;
printf("envp address:    %p\n", (void *)envp);
printf("environ address: %p\n", (void *)environ);
return (0);
}

