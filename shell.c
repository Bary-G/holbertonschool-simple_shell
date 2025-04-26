#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define PROMPT "#cisfun$ "
#define BUFFER_SIZE 1024

/**
 * main - Simple shell loop
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	int status;

	while (1)
	{
		fflush(stdout);
		if (isatty(STDIN_FILENO))
		{
			printf(PROMPT);
		}
		if (getline(&line, &len, stdin) == -1)
		{
			break;
		}
			line[_strcspn(line, "\n")] = '\0';
			pid = fork();

			if (pid == -1)
		{
			perror("fork");
		}
			else if (pid == 0)
		{
			char *argv[2];

			argv[0] = line;
			argv[1] = NULL;
			if (execve(line, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		}
			else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
