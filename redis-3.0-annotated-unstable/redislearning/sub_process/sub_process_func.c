#include <unistd.h>
#include <stdio.h>
#include "sub_process_func.h"

void Echo(int count, bool is_sub_process){
	for(int i=0; i<count; i++){
		sleep(1);
		global_vars += 1;
		if(is_sub_process)
			fprintf(stdout, "sub process print: %d\n", i);
		else
			fprintf(stdout, "main process print: %d\n", i);
	}
}