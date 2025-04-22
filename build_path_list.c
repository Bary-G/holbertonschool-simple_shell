#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path_list.h"

/* Function to split a string by a delimiter (in this case, ":") */
char **split_string(const char *str, const char delimiter, int *count) {
int i = 0;
char **result = malloc(sizeof(char *) * 1);
char *token;
char *str_copy = strdup(str);  // Create a copy of the string to tokenize
*count = 0;
token = strtok(str_copy, &delimiter);
while (token != NULL) {
result = realloc(result, sizeof(char *) * (*count + 1));
result[*count] = strdup(token);
(*count)++;
token = strtok(NULL, &delimiter);
}
free(str_copy);
return result;
}
/* Function to build the linked list from the PATH directories */
path_node *build_path_list(const char *path_value)
{
path_node *head = NULL, *temp, *new_node;
int count, i;
if (path_value == NULL)
{
return NULL;
}
// Split the PATH value into directories using ":" as delimiter
char **paths = split_string(path_value, ':', &count);
// Create the linked list
for (i = 0; i < count; i++)
{
new_node = malloc(sizeof(path_node));
if (new_node == NULL)
{
perror("Unable to allocate memory");
return NULL;
}
new_node->path = paths[i];  // Assign the directory
new_node->next = NULL;
if (head == NULL) 
{
head = new_node;
} else 
{
temp = head;
while (temp->next != NULL) 
{
temp = temp->next;
}
temp->next = new_node;
}
}
// Free the temporary array of strings
free(paths);
return head;
}

