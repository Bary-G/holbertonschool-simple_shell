#include <stdio.h>
#include <stdlib.h>

/**
 * main - endless prompt
 *
 * Return: number of characters
*/
int main(void)
{
char *buffer;
size_t bufsize = 32;
ssize_t read;
buffer = (char *)malloc(bufsize * sizeof(char));
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
