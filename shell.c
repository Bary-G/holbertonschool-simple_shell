#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define MAX_ARGS 64

/**
 * handle_input - Reads input from the user
 * @line: Pointer to the input buffer
 * @len: Pointer to the size of the buffer
 * 
 * Return: Returns the line of input, or NULL if an error occurs
 */
char *handle_input(char *line, size_t *len)
{
    if (getline(&line, len, stdin) == -1)
    {
        return (NULL);
    }
    line[strcspn(line, "\n")] = '\0';
    return (line);
}

/**
 * tokenize_input - Tokenizes the input string into arguments
 * @line: The input line to be tokenized
 * @args: The array to store the arguments
 * 
 * Return: The number of arguments
 */
int tokenize_input(char *line, char *args[])
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
    return (i);
}

/**
 * execute_command - Forks a process to execute the command
 * @args: The array of arguments to execute
 */
void execute_command(char *args[])
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
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

/**
 * main - Main shell loop
 * 
 * Return: Always 0
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char *args[MAX_ARGS];

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            printf(PROMPT);
        }

        line = handle_input(line, &len);
        if (line == NULL)
        {
            break;f
        }

        if (line[0] == '\0')
        {
            continue;
        }

        if (strcmp(line, "exit") == 0)
        {
            break;
        }

        tokenize_input(line, args); ts
        execute_command(args);
    }

    free(line);
    return (0);
}

