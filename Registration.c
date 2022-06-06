#include"Ressources.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int admin_code_check(FILE *file,char *iduser){ // This functions verifies that if the user creates an account with a teacher status, he enters a correct admin code
        
	char buffer_user[30];
    	char *id_counter;
	
	 rewind(file);

	do{
    		id_counter = fgets(buffer_user, 29, file);
    		
    	} while (idorpassword_verif(iduser, buffer_user)==0 && id_counter!=NULL );

    if (id_counter==NULL){
    
        printf("Wrong admin code !\n");
        return 1;
    }
    return 0;
}

int space_detection_id(char buffer_tab[]){  // This function verifies if there are spaces when he creates his username
	
	int length=strlen(buffer_tab);
	
	for(int i=0;i<length;i++){
			
		if(buffer_tab[i]==' '){
			
			printf("Your username cannot contain spaces!\n\n");
			return 0;  // returns 0 if there is at least one space
					
		}
		
	}
}


void new_username(char buffer_tab[]){ // This function allows the user to create a username to create his account
	
	
	do{
	
		printf("Please create your username:\n");
		clear_scan();	
		scanf("%[^\n]",buffer_tab); // the function stores what he wrote in "buffer_tab"
		
	}while(space_detection_id(buffer_tab)==0); // as long as he's typing a space, the function asks him to write another username without spaces
	
	
}


int create_id_check(FILE *username_file,char *username){ // This functions verifies that if you create an account, the username you are creating is not already taken
       
	char buffer_user[30];
    	char *id_counter;
	
	 rewind(username_file);

    id_counter = fgets(buffer_user, 29, username_file);
    		
    while (idorpassword_verif(username, buffer_user)==0 && id_counter!=NULL ){ // This loop allows us to know if what the user wrote corresponds to an username in the database or not
        for(int i=0; i<3; i++){
            id_counter = fgets(buffer_user, 29, username_file);
        }
    } 

    if (id_counter==NULL){ // if id_counter==NULL, that means that the loop went through all the .txt and didn't find any username corresponding to what the user wrote
  
        return 1; // returns 1 if what the user wrote is not already in our database
    }
    
    else{
    
   	 printf("Your username is already taken please select another one!\n\n");
   	 return 0;
   }
}


void data_filling(char new[], FILE *file){ // This function fills the .txt which contains the users, their passwords and their status("DATA_BASE_USERS.txt") with the new username, new password or the new status

	fseek(file,0,2); // goes at the end of the .txt
	fputs(new,file); // write the new username, password or status
	fputs("\n",file);
	

}

int space_detection_password(char buffer_tab[]){ // This function verifies if there are spaces when he creates his password
	
	int length=strlen(buffer_tab);
	
	for(int i=0;i<length;i++){
			
		if(buffer_tab[i]==' '){
			
			printf("Your password cannot contain spaces!\n\n");
			return 0; // returns 0 if there is at least one space
					
		}
		
	}
}


int password_strength(char password_table[]){ // This function verifies if the password created by the user has at least 8 characters, 1 upper case character, 1 lower case character and 1 number
	
	int uper_char_nb=0,lower_char_nb=0,numbers_nb=0;
	
	if(strlen(password_table)<8){ // This condition verifies if the password is shorter than 8 characters
		
		printf("Your password is too short, it must contains at least 8 characters\n\n");
		return 0; // Returns 0 if the password is too short
	}
	else if(space_detection_password(password_table)==0){ 
	
		return 0; // Returns 0 if there is at least one space in the password
	}
	
	else{ // The password has minimum 8 characters now we verify the other conditions
	
		int size=strlen(password_table);
		
		for(int i=0;i<size;i++){
		
			if(password_table[i]>='A' && password_table[i]<='Z'){ // This condition verifies if the user writes upper case characters
		
				uper_char_nb+=1; // it increases this variable for each upper case character and stores the number of upper characters in it
			}
			if(password_table[i]>='a' && password_table[i]<='z'){ // This condition verifies if the user writes lower case characters
			
				lower_char_nb+=1; // it increases this variable for each lower case character and stores the number of lower characters in it
			}
			if(password_table[i]>='0' && password_table[i]<='9'){ // This condition verifies if the user writes numbers
		
				numbers_nb+=1; // it increases this variable for each number and stores the number of numbers in it
			}
		}
		
		if(uper_char_nb==0 || lower_char_nb==0 || numbers_nb==0){ // This condition verifies if the user has respected all the conditions
		
			printf("Your password must contain at least:\n\n-One upper case character \n-One lower case character\n-One number\n\n");
			return 0; // Returns 0 if he didn't respect the conditions to create a password
		}
		else{
			
			return 1; // returns 1 if he respected them
		}
	}
}


void new_password(char tab[]){ // This function allows the user to create a password to create his account
		
		do{
		
			printf("Please create your password :\n");
			clear_scan();	
			scanf("%[^\n]",tab); // stores the new password in "tab"
			
			
		}while (password_strength(tab)==0); // as long as the new password doesn't have at least 8 characters, one upper case character, one lower case character and one number, the user is asked to try again
		
	
}


void registration(FILE *file,FILE*admin_file){ // This function allows the user to register

	
	char buffer_tab1[30],buffer_tab2[30],buffer_tab3[30];
	int answer;
	
	do{
		printf("What is your status?\n\n1-Teacher\n2-Student\n\nPlease write 1 or 2\n"); // The user has to chose his status : teacher or student
		clear_scan();
		scanf("%d",&answer);
		
	}while(answer!=1 && answer!=2);
	
	if(answer==1){ // if he writes 1
		
		do{	
			printf("Please enter an administrator code:\n"); // The user has to enter an code to prove that he is a teacher
			clear_scan();
			scanf("%s",buffer_tab3);
		
		}while(admin_code_check(admin_file,buffer_tab3)==1); // as long as he doesn't write a correct admin code, he is asked to try again
		fclose(admin_file); // closes the .txt which contains the administrators codes for teachers
		printf("Correct admin code!\n");
		
		do{
			new_username(buffer_tab1); // now he can create a new username
		
		}while(create_id_check(file,buffer_tab1)==0); // as long as what he writes already exists in our database, he is asked to try again
		
		data_filling(buffer_tab1,file); // fills the database of users with his new username
	
		printf("Hello %s!!!!\n\nYour username has been successfully registered!\n",buffer_tab1);
	
		new_password(buffer_tab2); // function to create his password
	
		data_filling(buffer_tab2,file); // fills the databse of users with his new password
	
		printf("Your password has been successfully set up!!!\n\n");
		
		data_filling("T",file); // fills the database of users with his status
		
	}
	else{ // if he is not a teacher, he will to do the same procedure as a teacher but his status will be "S"
	
		do{
			new_username(buffer_tab1);
			
		}while(create_id_check(file,buffer_tab1)==0);
		
		data_filling(buffer_tab1,file);
	
		printf("Hello %s!!!!\n\nYour username has been successfully registered!\n",buffer_tab1);
	
		new_password(buffer_tab2);
	
		data_filling(buffer_tab2,file);
	
		printf("Your password has been successfully set up!!!\n\n");
		
		data_filling("S",file); // his status is "S"

	}
}

	


		