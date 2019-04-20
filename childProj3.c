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
#include <stdbool.h>

int main()
{
	int fd, pairCount = 0;; 
	static int status;
	int buf;
    	char*pipeName = "intPipe";
        fd = open(pipeName, O_RDONLY);
	bool goStatus = false;
	printf("\n");
	printf("Pairs: \n");
	while(goStatus != true)
	{
		int sum; 
		 read(fd, &sum, sizeof(sum));
		int difference; 
		 read(fd, &difference, sizeof(difference));
	
	    if(sum != 0 && difference !=0)
	    {
	    	int num1 = (sum+difference)/2;
	    	int num2 = sum - num1;
	    	printf("%d, %d\n", num1, num2);
	    	pairCount++;
	    }
	    else
	    {
	    	goStatus = true;
		status = pairCount;
	    	return status;
	    }
	}
}
