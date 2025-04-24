#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * build_path_list - Builds a linked list from a colon-separated PATH string.
 * @path_str: The PATH environment variable value.
 *
 * Return: Pointer to the head of the list, or NULL on failure.
 */
path_node *build_path_list(const char *path_str)
{
path_node *head = NULL, *node = NULL, *last = NULL;
char *copy, *token;

if (!path_str)
return (NULL);

copy = strdup(path_str);
if (!copy)
return (NULL);

token = strtok(copy, ":");
while (token != NULL)
{
node = malloc(sizeof(path_node));
if (!node)
{
free(copy);
free_path_list(head);
return (NULL);
}

node->path = strdup(token);
node->next = NULL;

if (!head)
head = node;
else
last->next = node;

last = node;
token = strtok(NULL, ":");
}

free(copy);
return (head);
}

/**
 * print_path_list - Prints the directories stored in the path list.
 * @head: Pointer to the head of the list.
 */
void print_path_list(path_node *head)
{
while (head != NULL)
{
printf("%s\n", head->path);
head = head->next;
}
}

/**
 * free_path_list - Frees the memory used by the path linked list.
 * @head: Pointer to the head of the list.
 */
void free_path_list(path_node *head)
{
path_node *temp;

while (head != NULL)
{
temp = head;
head = head->next;
free(temp->path);
free(temp);
}
}

