#ifndef SHELL_H
#define SHELL_H

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

path_node *build_path_list(void);
void print_path_list(path_node *head);
void free_path_list(path_node *head);
path_node *build_path_list(const char *path_value);

#endif

