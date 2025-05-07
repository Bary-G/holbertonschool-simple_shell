#include <string.h>
#include "shell.h"

/**
 * parse_input - Tokenizes the input line into arguments
 * @line: The input line
 * @args: The array to store tokens
 */
void parse_input(char *line, char *args[])
{
	char *token;
	int i = 0;

	token = strtok(line, " \t");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " \t");
	}
	args[i] = NULL;
}
