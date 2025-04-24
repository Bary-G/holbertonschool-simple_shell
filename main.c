#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the function and structure declaration
#include "shell.h" // This should contain the path_node struct and function prototype

int main(void)
{
char *path_value = getenv("PATH"); // Get the PATH environment variable
if (path_value == NULL)
{
printf("PATH variable not found.\n");
return 1;
}
// Build the path list
path_node *head = build_path_list(path_value);
// Print the path list
print_path_list(head); // Function from print_path_list.c
// Free the memory allocated for the linked list
free_path_list(head); // Function from free_path_list.c
return 0;
}

