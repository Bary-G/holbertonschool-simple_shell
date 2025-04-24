#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern char **environ;

/**
 * _unsetenv - Removes an environment variable
 * @name: The name of the variable to remove
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
size_t name_len, i, j;
if (!name || strchr(name, '='))
return (-1);
name_len = strlen(name);
for (i = 0; environ[i]; i++)
{
if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
{
free(environ[i]);

/* Shift the rest of the array back */
for (j = i; environ[j]; j++)
environ[j] = environ[j + 1];
return (0);
}
}

/* Not found, no error */
return (0);
}

int main(void)
{
char *value;
value = _getenv("PATH");
if (value)
printf("PATH: %s\n", value);
else
printf("PATH not found.\n");
return (0);
}

