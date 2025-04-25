#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - endless prompt
 *
 * Return: Always 0.
 */
int main(void)
{
char *buffer;
size_t bufsize = 1024;
ssize_t read;
buffer = malloc(bufsize * sizeof(char));
if (buffer == NULL)
{
perror("Unable to allocate buffer");
exit(1);
}
while (1)
{
printf("$ ");
read = getline(&buffer, &bufsize, stdin);
if (read == -1)
{
printf("\n");
break;
}
printf("%s", buffer);
}
free(buffer);
return (0);
}

