#include <stdio.h>
#include "path_list.h"

void print_path_list(path_node *head)
{
while (head != NULL)
{
printf("%s\n", head->path);
head = head->next;
}

/**
* main - test _getenv function
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

