#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * build_path_list - Builds a linked list from PATH string.
 * @path: The PATH environment variable string.
 *
 * Return: Pointer to head of the linked list.
 */
path_node *build_path_list(const char *path)
{
path_node *head = NULL, *new_node, *last = NULL;
char *copy, *token;
if (!path)
return (NULL);
copy = strdup(path);
if (!copy)
return (NULL);
token = strtok(copy, ":");
while (token)
{
new_node = malloc(sizeof(path_node));
if (!new_node)
{
free(copy);
free_path_list(head);
return (NULL);
}
new_node->dir = strdup(token);
new_node->next = NULL;
if (!head)
head = new_node;
else
last->next = new_node;
last = new_node;
token = strtok(NULL, ":");
}
free(copy);
return (head);
}

