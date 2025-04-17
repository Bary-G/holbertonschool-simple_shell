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
pid_t ppid;
ppid = getppid();
printf("%d\n", ppid);
return (0);
}

