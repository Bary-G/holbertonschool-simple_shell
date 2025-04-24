#include <stdio.h>
#include "shell.h"

/**
 * print_path_list - Prints each path from a linked list.
 * @head: Pointer to the head of the path_node linked list.
 */
void print_path_list(path_node *head)
{
while (head != NULL)
{
printf("%s\n", head->dir);
head = head->next;
}
}

/**
 * main - Test _getenv function.
 *
 * Return: Always 0.
 */
int main(void)
{
char *value;
value = _getenv("PATH");
if (value)
printf("PATH: %s\n", value);
else
printf("PATH not found.\n");
return (0);
}

