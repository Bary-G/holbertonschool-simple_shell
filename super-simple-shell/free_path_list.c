#include <stdlib.h>
#include "shell.h"

/**
 * free_path_list - frees a linked list of paths
 * @head: pointer to the first node
 */
void free_path_list(path_node *head)
{
path_node *tmp;
while (head)
{
tmp = head;
head = head->next;
free(tmp->dir);
free(tmp);
}
}

