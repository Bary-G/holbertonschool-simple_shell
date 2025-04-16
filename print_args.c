#include <stdio.h>

/**
 * main - Prints all arguments using only av
 * @ac: argument count (unused)
 * @av: argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
while (*av != NULL)
{
printf("%s\n", *av);
av++;
}
return (0);
}
