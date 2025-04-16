#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - Print the parent process ID
 *
 * Return: Always 0.
 */
int main(void)
{
pid_t my_ppid;
my_ppid = getppid();
printf("%d\n", my_ppid);
return (0);
}

