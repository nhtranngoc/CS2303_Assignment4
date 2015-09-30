#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <errno.h>

int main(){
	char* input;
	int num;

	while(1){
		input = readline("How many employees are there? ");
		if (sscanf(input, "%d", &num)) break;
		free(input);
	}

	Employee** arr = (Employee**)malloc(sizeof(Employee) * num);
	int i;

	for(i = 0; i < num; i++){
		arr[i] = promptEmployee();
	}

	FILE *outfile = fopen("mainmainmain.txt", "w");
  	if (outfile == NULL){
    	fprintf(stderr, "In program mainmainmain.c, error number %d: ", errno);
    	printf("%s\n", strerror(errno));
    	return -1;
    }

    for (i = 0; i < num; i++){
    	printEmployee(arr[i]);
    	printEmployeeToFile(outfile, arr[i]);
    	freeEmployee(arr[i]);
    }
    
	return 0;
}