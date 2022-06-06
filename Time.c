#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 
#include "Ressources.h"
#include<string.h>

int book_in_verif(char *scanfusertab, char *buffertab){ // This function verifies if 2 character strings are exactly the same

    if(strlen(scanfusertab)!=strlen(buffertab)){ // if the length of the 2 character strings is not the same, they can't be the same 
        return 0; // returns 0 if they are not the same
    }
    for(int i=0; i<strlen(scanfusertab); i++){
        if(scanfusertab[i]!=buffertab[i]){ // if one letter is different, they can't be the same
            return 0; // returns 0 if they are not the same
        }
    }
    return 1; // returns 1 if they are the same
}
 
void edit_back_library(int nbbooks,Book books[nbbooks],int books_borrow_to_change,int book_id_number){
	
	
                    FILE *new_library=NULL;			
                    new_library=fopen("nex_lib.txt","w+");
                    allocation_test(new_library);
                    
			char int_borrow_to_char[3];
			char nbbooks_char[5];
			
                    sprintf(nbbooks_char, "%d", nbbooks); 
                    fputs(nbbooks_char,new_library);
                    fputs("\n",new_library);
		
			space_detection(books, nbbooks);	//WE are turning the spaces into underscore to copy all the content in the library 
			
                    for(int i=0; i<nbbooks; i++){
                        fputs(books[i].title, new_library);     	//Exept the borrow numbers nothing is changed                 
                        fputs("\n", new_library);
                        fputs(books[i].author, new_library);
                        fputs("\n", new_library);
                        fputs(books[i].id_number, new_library);
                        fputs("\n", new_library);
                        fputs(books[i].category, new_library);
                        fputs("\n", new_library);
                        
                        
                        int id_number;
                        id_number=atoi(books[i].id_number);	// We turn the *char into a int
                        
                        		
                        if((books[i].borrow==books_borrow_to_change) && (id_number==book_id_number)){
                        
                        	fputs("0", new_library);	// The borrow number becomes a 0 cause the book is now free
                        	books[i].borrow=0;

                        }
                        else{
                        	
                        	sprintf(int_borrow_to_char,"%d",books[i].borrow);
                        	fputs(int_borrow_to_char,new_library);
                        }
                        
                        fputs("\n", new_library);
                    }
                    rename("nex_lib.txt","DATA_BASE_BOOKS.txt");
                    
                    underscore_detection(books, nbbooks); //we remoove the underscore for the display
                    
                    fclose(new_library);
}

int book_check(char books_borrowed[5][100],char book_to_return[100],int nb_books_borrowed){
	
	for(int i=0;i<nb_books_borrowed;i++){
		
		if(book_in_verif(book_to_return,books_borrowed[i])==1){	//This fonction return 0 if there is a book_to_return in books_borrowed which is a two-dimensional table
			
			
			return 0;
		}
	}
	
	return 1;

}

int book_check_delete(char books_borrowed[5][100],char book_to_return[100],int nb_books_borrowed,int *book_position){
	
	for(int i=0;i<nb_books_borrowed;i++){
		
		if(book_in_verif(book_to_return,books_borrowed[i])==1){	//This return the position of the book to delete
			
			*book_position=i;
			return 0;
		}	
	}
	
	return 1;

}
void books_borrowed_modification(char books_borrowed[5][100],char book_to_delete[],int nb_books_borrowed){
	
	int book_position;
	
	if(book_check_delete(books_borrowed,book_to_delete,nb_books_borrowed,&book_position)==0){
			
			int size=strlen(book_to_delete);
			for(int i=0;i<size;i++){
			
				books_borrowed[book_position][i]=0;		//This void modify the table: books_borrowed in order to delete the borrowed book
		
			}		
		
	}

}

int find_id_number(Book books[],char book_to_find[],int nbbooks){
	
	int id_number;
	
	for(int i=0;i<nbbooks;i++){

		if(book_in_verif(books[i].title,book_to_find)==1){	//This fonction return the id_number of the book_to_find
		
			id_number=atoi(books[i].id_number);
			return id_number ;			
			
		}	
	}
}

int return_book(Book books[],char books_borrowed[5][100],int nb_books_borrowed,int books_borrow_to_change,int nbbooks){

	char book_to_return[100];
	int nb_books_borrowed1=nb_books_borrowed; 
	int answer=10;
	

while(nb_books_borrowed>0){

	do{
	
		printf("What book do you want to return?\n\n" );		// We verify if book_to_return is in books_borrowed	
		clear_scan();
		scanf("%[^\n]",book_to_return);
		
	}while(book_check(books_borrowed,book_to_return,nb_books_borrowed1)==1);	
		
		for(int i=0;i<nb_books_borrowed1;i++){		// We go through book_borrowed and delete the book_to_return of the books_borrowed
			
			
			if(book_in_verif(book_to_return,books_borrowed[i])==1){
				
				edit_back_library(nbbooks,books,books_borrow_to_change,find_id_number(books,book_to_return,nbbooks)); //Modify the library...	
				printf("You have return the following book: %s \n",book_to_return);
				books_borrowed_modification(books_borrowed,book_to_return,nb_books_borrowed1);	//Modify the books_borrowed[][]
				
				nb_books_borrowed-=1;	
			}
		}
		
		if(nb_books_borrowed>0){
		
			printf("You still have the following books: \n\n");
		
			for(int i=0;i<nb_books_borrowed1;i++){		
		
					printf("%s\n",books_borrowed[i]);	
			}
		}
		
		
		while(nb_books_borrowed>0 && answer!=1 && answer!=2){
		
			printf("Do you want to return another book?\n 1-Yes \n 2-No \n\n");	
			clear_scan();	
			scanf("%d",&answer);
			
		}
		if(answer==2){
		
			return 0;	//exit the void 
		}
	
	}
	
	if(nb_books_borrowed==0){
	
	
		printf("You have returned all your books !!\n\n");	
	
	}	

}

void add_time(int time_to_add, int *h, int *min, int *s ){

	*h=(*h+(time_to_add/3600))%24;
	time_to_add=time_to_add%3600;		//This fonction add time to  a pointer
	*min=*min+(time_to_add/60);
	time_to_add=time_to_add%60;
	*s=*s+time_to_add;

}


void dead_line(char statut){

  	int h, min, s;
  	time_t now;
    
	// Returns the current time
  	time(&now);
  
  	// Convert to local time format 
  	printf("We are the : %s\n\n", ctime(&now));
  
  	struct tm *local = localtime(&now);
  	h = local->tm_hour;        
  	min = local->tm_min;       
 	 s = local->tm_sec;       
     	
     	
  	if(statut=='S'){	
  		
  		add_time(120,&h,&min,&s);  // Make a difference depending of the statut
  	}
  	
  	else{
  		
  		add_time(180,&h,&min,&s);
  	
  	}
  	
  	printf("You must return the book to: %02d:%02d:%02d\n\n",h,min,s);
  	
}




