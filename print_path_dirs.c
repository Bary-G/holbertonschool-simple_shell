#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * print_path_dirs - prints each directory in PATH
 */
void print_path_dirs(void)
{
char *path, *token, *copy;
path = getenv("PATH");
if (path == NULL)
{
printf("PATH not found\n");
return;
}
copy = strdup(path);
if (copy == NULL)
{
perror("strdup");
return;
}

token = strtok(copy, ":");
while (token != NULL)
{
printf("%s\n", token);
token = strtok(NULL, ":");
}
free(copy);
}

/**
 * main - entry point
 *
 * Return: Always 0.
 */
int main(void)
{
print_path_dirs();
return (0);
}

