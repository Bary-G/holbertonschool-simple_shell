#include "shell.h"

/**
 * execute_command - Forks and executes a command
 * @args: Array of arguments (command + NULL)
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)

	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}

