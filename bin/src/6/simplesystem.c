#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	
	pid = fork();
	if(pid == 0) {
		execl("/bin/ls", argv[1], argv[2],(char *)0);
		perror("execl failed");
	} else if(pid>0) {
		wait((int *) 0);
		printf("ls completed\n");
		exit(0);
	} else
		perror("fork failed");
}
	

