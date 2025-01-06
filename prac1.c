#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void main(){

	pid_t pid = fork();
	if(pid > 0)
	{
	printf("\n \t Completed . \n");
	exit(0);
	}
	else if(pid==0)
	{
	execl("/bin/ls","ls","-s",NULL);
	perror("\n Execl Failed. \n");
	}
	else{
	perror("\n Fork Failed.\n");}
	}
