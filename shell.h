#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

/**
 * struct path_node - singly linked list for PATH directories
 * @dir: a directory string
 * @next: pointer to the next node
 */
typedef struct path_node
{
char *dir;
struct path_node *next;
} path_node;

extern char **environ;
/* Function Prototypes */
char *readline(void);
char **splitline(char *line);
int execute(char **args);
char *get_path(char *command);
char *_strcat(char *dest, char *src);
char **tokenize_env(char *path);
int _strcmp(char *s1, char *s2);
void sigint_handler(int sig);
int _putchar(char c);
char *_getenv(char *var);
void _printenv(void);
int _strlen(char *s);
int _strncmp(char *str1, char *str2, int n);
path_node *build_path_list(void);
void print_path_list(path_node *head);
void free_path_list(path_node *head);
path_node *build_path_list(const char *path_value);

#endif

