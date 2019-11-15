#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
// exit
#include <stdlib.h>
// wait3()
#include <sys/wait.h>

pid_t global_pid=-1;

int main(int argc, char* argv[]){
	pid_t child_pid;

	if ((child_pid=fork()) == -1){
		fprintf(stderr, "fork error");
		exit(1);
	}else if(child_pid == 0){
		fprintf(stdout, "this is sub process\n");
		exit(0);
	}else{
		fprintf(stdout, "this is main process\n");
		global_pid = child_pid;
		fprintf(stdout, "child process pid is: %d\n", global_pid);
		pid_t get_pid;
		int statloc;
		while(1){
			if((get_pid = wait3(&statloc,WNOHANG,NULL)) != 0) {
				int exitcode = WEXITSTATUS(statloc);
				fprintf(stdout, "exit process pid is: %d\n", get_pid);
				fprintf(stdout, "exitcode is: %d\n", exitcode);
				if (get_pid == global_pid) {
					break;
				}
			}
		}
	}
	return 0;
}