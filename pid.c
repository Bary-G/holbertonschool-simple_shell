#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - Print the current process ID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();

	printf("%d\n", my_pid);

	return (0);
}

