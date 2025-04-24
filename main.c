#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * main - Entry point, builds and prints the PATH linked list.
 *
 * Return: 0 on success, 1 if PATH variable not found.
 */
int main(void)
{
char *path_value;
path_node *head;
path_value = getenv("PATH");
if (path_value == NULL)
{
printf("PATH variable not found.\n");
return (1);
}
head = build_path_list(path_value);
print_path_list(head);
free_path_list(head);
return (0);
}

