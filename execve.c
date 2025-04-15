#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
	char *argum = (argc > 1) ? argv[1] : "default_value";
	int status,i;
	char cmd[512];
	pid_t process_id = 0;
	for (i = 0; i <= 5; i++)
	{
		process_id = fork();
		if (process_id < 0)
		{
			printf("fork failed - %d!\n",i);
			continue;
		}
		else if(process_id > 0)
		{
			printf("process_id of child process %d \n", process_id);
		}
		else
		{
			sprintf(cmd,"./test %s",argum);
			status = system(cmd);
			exit(0);
		}
	}
	for (i = 0; i < 5; i++)
	{
		wait(NULL);
	}

	return (0);
}