#include <stdio.h>
#include "path_list.h"

void print_path_list(path_node *head)
{
while (head != NULL)
{
printf("%s\n", head->dir);
head = head->next;
}
}

