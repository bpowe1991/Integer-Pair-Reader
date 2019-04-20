//-----------------------------------------------------------------------
// Programmer: Briton A. Powe
// Lab: #1, "About Me"                 Filename: hw1.cpp
// Due Date: 06/24/16                  Class: CS1250, Section 1
//------------------------------------------------------------------------
// Program Description:
// Displays a message about the programmer.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

	static int  status;
	pid_t cpid = fork();
	if(cpid < 0){
		perror("Child not created");
		exit(1);
	}
	else if(cpid == 0)
	{
		execl("childProj3", "childProj3", NULL);
		exit(1);
	}
	else
	{
		int fd;
		char*pipeName = "intPipe";
		mkfifo (pipeName, 0704);
		fd = open(pipeName, O_WRONLY);
                int num1=-1 , num2=-1;
		while(num1 != 0 && num2 != 0)
		{
			scanf("%d", &num1);
			scanf("%d", &num2);
			int sum = num1 + num2;
			int difference=num1-num2;
			
			if(num1<num2)
			{
				difference = num2-num1;
			}
			else
			{
				difference = num1-num2;
			}
			write(fd, &sum, sizeof(sum));
			write(fd, &difference, sizeof(sum));

		 }

		waitpid(cpid, &status, 0);
		const int var = WEXITSTATUS(status);
		printf("\n");
		printf("Number of Sucessful Pairs: ");
		printf("%d", var);
		printf("\n\n");
		unlink(pipeName);
	}
	return 0;
}
