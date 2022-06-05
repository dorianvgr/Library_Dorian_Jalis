#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Ressources.h"
#define FALSE 0
#define SESSION FALSE



int main(){

  while(SESSION==FALSE){
  
  	FILE *data_base_users=NULL;
  	FILE *admin_file=NULL;
  	data_base_users=fopen("DATA_BASE_USERS.txt","r+"); // we open our database of books
  	admin_file=fopen("Password_prof.txt","r+"); // we open our database of users
  	allocation_test(data_base_users); // verify if it opens "DATA_BASE_USERS.txt
  	allocation_test(admin_file); // verify if it opens "Password_prof.txt"
  	
  
   	 int start=first_interface(); // displays the first interface
   	 
 
    
   	 if (start==1){ // the user writes 1 to log in
    
        	login(data_base_users,admin_file);
    	}
    	
    	else if(start==2){ // the user writes 2 to create an account
    			
    		registration(data_base_users,admin_file);
    		
    	}
    
    	else{ // he writes 3 to exit 
        	printf("Goodbye !\n");
        	exit(1);
     		
     	}
     }
     
   return 0;
}

