#include <stdio.h>

/**
 * main - print all args
 *
 * @ac: number of args
 * @av: array of args
 *
 * Return: Always 0.
*/
int main(int ac, char **av)
{
	int i = 0;

	for(i = 0; i < ac; i++)
	{
		(void) ac;
		printf("%s\n", av[i]);
	}
	return (0);
}
