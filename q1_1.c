#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h> 
#include <sys/types.h> 
#include <sys/stat.h>

void main(){
	int x = 10;
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr, "%s\n", "Fork Failed");
	}
	else if (pid ==0){
		printf("%s\n", "Child process:");
		printf("%s %d\n", "Initial value:", x);
		for(x;x>-90;){
			x--;
		}
		printf("%s %d\n", "Final value:", x);
	}else{
		// wait(NULL);
		printf("%s\n", "Parent process");
		printf("%s %d\n", "Initial value:", x);
		for(x;x<100;){
			x++;
		}
		printf("%s %d\n", "Final value:", x);
	}
}