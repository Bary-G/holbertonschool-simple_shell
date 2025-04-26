#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64

void parse_input(char *line, char **args);
void execute_command(char **args);

#endif

