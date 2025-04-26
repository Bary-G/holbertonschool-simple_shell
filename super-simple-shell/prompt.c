#include "shell.h"

/**
 * display_prompt - Affiche le prompt du shell
 *
 * Return: None
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * main - Point d'entrée du shell
 *
 * Return: 0 si tout se passe bien, 1 en cas d'erreur
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\nExiting shell...\n", 19);
			break;
		}

		line[strcspn(line, "\n")] = '\0';
		if (line[0] == '\0')
			continue;

		if (strcmp(line, "exit") == 0)
			break;
		execute_command(line);
	}

	free(line);
	return (0);
}

