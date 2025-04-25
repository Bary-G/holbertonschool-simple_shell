#include <stdio.h>
#include "shell.h"

/**
 * print_path_list - Prints the directories in the path list.
 * @head: Pointer to the head of the list.
 */
void print_path_list(path_node *head)
{
while (head)
{
printf("%s\n", head->dir);
head = head->next;
}
}

