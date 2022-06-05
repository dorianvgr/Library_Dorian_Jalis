#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<errno.h>
#include"Ressources.h"

void clear_scan(){ // This function is used to empty the buffer of \n
	char c;
	int res;
	do{
		res = fscanf(stdin, "%c",&c);
	}while(res==1 && c !='\n');
}

int pointer_test(char *pointer){ // This function verifies that when we create a pointer, the pointer==NULL or not

	if(pointer==NULL){
		
		return 0;
	}
	
	else{
	
		return 1;
	}
}

void allocation_test(FILE *pointer_fichier){ // This function verifies if, when we fopen a file, it doesn't fail
	
	if(pointer_fichier==NULL){
		
		printf("Cannot open the file\n");
		printf("error code	= %d \n",errno);
		printf("Error message = %s \n",strerror(errno));	
		exit(1);
	}
	
}