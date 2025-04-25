#include <stdio.h>

/**
 * main - Prints the environment variables
 * @ac: Argument count (unused)
 * @av: Argument vector (unused)
 * @env: Array of environment variable strings
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i;
	(void)ac;
	(void)av;
	i = 0;
	while (env[i] != NULL)
	{
	printf("%s\n", env[i]);
	i++;
}
	return (0);
}

