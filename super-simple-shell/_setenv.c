#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

extern char **environ;

/**
 * _setenv - Changes or adds an environment variable
 * @name: Name of the variable
 * @value: Value to set
 * @overwrite: If 0, do not overwrite an existing variable
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
char *env_str;
size_t name_len, i;
if (!name || !value || strchr(name, '='))
return (-1);
name_len = strlen(name);
env_str = malloc(name_len + strlen(value) + 2);
if (!env_str)
return (-1);

sprintf(env_str, "%s=%s", name, value);
for (i = 0; environ[i]; i++)
{
if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
{
if (!overwrite)
{
free(env_str);
return (0);
}
free(environ[i]);
environ[i] = env_str;
return (0);
}
}

environ[i] = env_str;
environ[i + 1] = NULL;
return (0);
}

/**
 * main - Entry point. Tests _setenv.
 *
 * Return: Always 0.
 */
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

