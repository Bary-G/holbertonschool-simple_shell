#include "shell.h"

/**
 * execute_command - Fork and execute a command with execve
 * @line: Command line entered by the user
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[MAX_ARGS];
	char *token;
	char *path_cmd = NULL;
	int i = 0;

	token = strtok(line, " \t");
	while (token && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;
	if (argv[0] == NULL)
        return (-1);

	if (access(argv[0], X_OK) == 0)
	path_cmd = strdup(argv[0]);

	else
	
	path_cmd = find_command(argv[0]);

	if (!path_cmd)
	{
		write(STDERR_FILENO, "./hsh: command not found\n", 26);
		return (-1);
	}

	pid = fork();
	if (pid == -1)

	{
		perror("fork");
		free(path_cmd);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(path_cmd, argv, environ) == -1)
		{
			perror("./hsh");
			free(path_cmd);
			exit(EXIT_FAILURE);
		}
	}
	
	else
	
	{
		waitpid(pid, &status, 0);
		free(path_cmd);
	}

	return (0);
}

