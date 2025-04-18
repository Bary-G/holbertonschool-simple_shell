#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
	printf("env adress %p\n", (void*)envp);
	printf("environ adress %p\n", (void*)environ);

	return (0);
}
