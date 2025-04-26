#include <string.h>
#include "shell.h"

/**
 * parse_input - Tokenizes a line into arguments
 * @line: Input string
 * @args: Array to store arguments
 */
void parse_input(char *line, char **args)
{
	int i = 0;
	char *token = strtok(line, " \t");

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " \t");
	}

	args[i] = NULL;
}

