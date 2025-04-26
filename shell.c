#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define MAX_ARGS 64

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_ARGS];
	pid_t pid;
	int status;

	while (1)
	{
	if (isatty(STDIN_FILENO))
	printf(PROMPT);

	if (getline(&line, &len, stdin) == -1)
	break;

	line[strcspn(line, "\n")] = '\0';

	if (line[0] == '\0')
	continue;

	if (strcmp(line, "exit") == 0)
	break;
	char *token = strtok(line, " \t");
	int i = 0;
	while (token != NULL && i < MAX_ARGS - 1)
{
	args[i++] = token;
	token = strtok(NULL, " \t");
	}
		args[i] = NULL;
		pid = fork();
		if (pid == -1)
	{	
		perror("fork");
		continue;
	}
		if (pid == 0)
{
	if (execvp(args[0], args) == -1)
{
	perror("execvp");
	exit(EXIT_FAILURE);
	}	

}
	else
{
	wait(&status);
}
	}

    free(line);
    return 0;
}

