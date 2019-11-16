#include <unistd.h>
#include <stdio.h>
void Echo(){
	for(int i=0; i<10; i++){
		sleep(1);
		fprintf(stdout, "sub process print: %d\n", i);
	}
}