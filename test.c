// #include<stdio.h>
// #include<sys/syscall.h>
// #include<string.h>
// #include<stdio.h>
#include<string.h>
// #include<unistd.h>
// #include<time.h>
// #include<dirent.h>
// #include <sys/wait.h>
// // #include <conio.h> 
// #include <sys/types.h> 
// #include <sys/stat.h>
#include<errno.h>

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

/*
 * Put your syscall number here.
 */
// #define sh_task_info 440

void main(){
	int a = syscall(440, "anshul.txt", 20);
	if(a!=0){
		printf("%s\n", strerror(errno));
	}
	// sh_task_info("anshul", 20);
}
