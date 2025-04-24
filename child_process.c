#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Executes "ls -l /tmp" in 5 different child processes
 *
 * Return: Always 0.
 */
int main(void)
{
pid_t pid;
int i;
char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
for (i = 0; i < 5; i++)
{
pid = fork();
if (pid == -1)
{
perror("fork");
return (1);
}
if (pid == 0)
{
if (execve(argv[0], argv, NULL) == -1)
{
perror("execve");
}
return (1);
}
else
{
wait(NULL);
}
}
return (0);
}

