#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define PROMPT "#cisfun$ "
#define MAX_ARGS 64

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_ARGS];

	while (1)

	{
		if (isatty(STDIN_FILENO))
			printf(PROMPT);

		if (getline(&line, &len, stdin) == -1)

		{
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (line[0] == '\0')
			continue;

		if (strcmp(line, "exit") == 0)
			break;

		parse_input(line, args);
		execute_command(args);
	}

	free(line);
	return (0);
}

