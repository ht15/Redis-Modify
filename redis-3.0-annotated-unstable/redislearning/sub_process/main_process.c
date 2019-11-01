#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
// exit
#include <stdlib.h>
// wait3()
#include <sys/wait.h>
#include <fcntl.h>

#include "sub_process_func.h"

// 管道实现 父子进程间的通信 http://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/6-IPC1/exercise-1.html
// 共享内存 父子进程间通信的例子 https://www.jianshu.com/p/6bbf5d474f89 TODO 如果使用信号量进行控制

int global_vars = 1;

pid_t global_pid=-1;

static int pipfd1[2], pipfd2[2];

char buff[20];

int main(int argc, char* argv[]){
	pid_t child_pid;
	

	TELL_WAIT();

	if ((child_pid=fork()) == -1){
		fprintf(stderr, "fork error");
		exit(1);
	}else if(child_pid == 0){
		fprintf(stdout, "this is sub process\n");
		close(pipfd1[1]);
		close(pipfd2[0]);
		WAIT_PARENT();
		charatatime("OUTPUT FROM CHILD\n");
		Echo(10, child_pid==0);
		TELL_PARENT();
		exit(0);
	}else{
		fprintf(stdout, "this is main process\n");
		close(pipfd1[0]);
		close(pipfd2[1]);
		global_pid = child_pid;
		fprintf(stdout, "child process pid is: %d\n", global_pid);
		charatatime("OUTPUT FROM parent\n");
		pid_t get_pid;
		int statloc;
		Echo(20, child_pid==0);
		TELL_CHILD();
		WAIT_CHILD();
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

static void charatatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL);
	for(ptr = str; (c = *ptr++) != 0; )
		putc(c, stdout);
}

void TELL_WAIT(){
	if(pipe(pipfd1) < 0 || pipe(pipfd2) < 0){
		fprintf(stderr, "%s\n", "create pipe error");
		exit(1);
	}
}

void TELL_CHILD(){
	write(pipfd1[1], "p", 2);
	printf("parent send message to CHILD!\n");
	close(pipfd1[1]);
}

void TELL_PARENT(){
	write(pipfd2[1], "c", 2);
	printf("Child send message to parent!\n");
	close(pipfd2[1]);
}

void WAIT_PARENT(){
	int ret = read(pipfd1[0], buff, 2);
	printf("child read from parent %s, ret is: %d\n", buff, ret);
	close(pipfd1[0]);
}

void WAIT_CHILD(){
	int ret = read(pipfd2[0], buff, 2);
	printf("parent read from child %s, ret is: %d\n", buff, ret);
	close(pipfd2[0]);
}