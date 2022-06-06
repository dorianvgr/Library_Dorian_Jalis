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
   	 int to_continue;
   	 
 time_t begin;
 time_t end ;
    
   	 if (start==1){ // the user writes 1 to log in
    
        	to_continue=login(data_base_users,admin_file);
        		

        	if(to_continue==1){
        		
        		          begin = time( NULL );	//initialization of begin 
        	}
        	else if(to_continue==2){
        		
        		     end = time( NULL);  		//initialisatoin of end
        		    
        		    unsigned long time_borrow = (unsigned long) difftime( end, begin ); //convert the miscroseconde in seconde and make the difference between end and begin 	
        		    printf( "You borrowed this book during %ld sec\n", time_borrow  ); 
        		    
        		    if(time_borrow>120){
                 
                			printf("You have exceeded the time limit, you are no longer allowed to borrow books!\n\n"); //if the time exceed a certain limit the user is please do not boprrow books anymore 
                			exit(1);
           			}
        	}
        	
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
