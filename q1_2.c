#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include <sys/wait.h>
// #include <conio.h> 
#include <sys/types.h> 
#include <sys/stat.h>

int x=10;

void *child_process(void *args){
	printf("%s\n", "Child process:");
	printf("%s %d\n", "Initial value:", x);
	for(x;x>-90;){
		x--;
	}
	printf("%s %d\n", "Final value:", x);
}

void main(){
	pthread_t child;
	// x = 10;
	pthread_create(&child, NULL, &child_process, NULL);
	
	printf("%s\n", "Parent process");
	printf("%s %d\n", "Initial value:", x);
	for(x; x<100;){
		x++;
	}
	printf("%s %d\n", "Final value:", x);
	if (pthread_join(child, NULL))
    {
        printf("ERROR");
        exit(1);
    }
}
