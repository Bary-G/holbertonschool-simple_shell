#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the linked list node
typedef struct path_node {
char *path;
struct path_node *next;
} path_node;

// Function to print the linked list of paths
void print_path_list(path_node *head)
{
while (head != NULL)
{
printf("%s\n", head->path); // Print the path in each node
head = head->next;
}
}

// Function to build the linked list of PATH directories
path_node *build_path_list(const char *path_value)
{
path_node *head = NULL, *current = NULL, *new_node = NULL;
char *token;
char *path_copy = strdup(path_value); // Duplicate the PATH value
if (path_copy == NULL)
{
perror("Unable to allocate memory for path_copy");
return NULL;
}
// Tokenize the PATH string by colon ':'
token = strtok(path_copy, ":");
while (token != NULL)
{
// Create a new node for the path
new_node = malloc(sizeof(path_node));
if (new_node == NULL)
{
perror("Unable to allocate memory for new node");
free(path_copy); // Free the duplicated string before returning
return NULL;
}
new_node->path = strdup(token);  // Duplicate the token (directory path)
new_node->next = NULL;
// If it's the first node, make it the head, otherwise, link it to the list
if (head == NULL)
{
head = new_node;
}
else
{
current->next = new_node;
}
current = new_node;  // Move current to the new node
token = strtok(NULL, ":"); // Get the next token
}
free(path_copy);  // Free the duplicated PATH string
return head;
}

// Function to free the linked list memory
void free_path_list(path_node *head)
{
path_node *temp;
while (head != NULL)
{
temp = head;
head = head->next;
free(temp->path);  // Free the duplicated path string
free(temp);         // Free the node
}
}

int main(void)
{
char *path_value = getenv("PATH"); // Get the PATH environment variable
if (path_value == NULL)
{
printf("PATH variable not found.\n");
return 1;
}
//Build the path list from the PATH environment variable
path_node *head = build_path_list(path_value);
// Print the path list
printf("Directories in the PATH variable:\n");
print_path_list(head);
// Free the memory allocated for the linked list
free_path_list(head);
return 0;
}

