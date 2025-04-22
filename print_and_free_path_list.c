#include <stdio.h>
#include <stdlib.h>
#include "path_list.h"

/**
 * print_path_list - prints each directory in the list
 * @head: pointer to the head of the list
 */
void print_path_list(path_node *head)
{
while (head)
{
printf("%s\n", head->dir);
head = head->next;
}
}

/**
 * free_path_list - frees the list memory
 * @head: pointer to the head of the list
 */
void free_path_list(path_node *head)
{
path_node *temp;
while (head)
{
temp = head;
head = head->next;
free(temp->dir);
free(temp);
}
}

