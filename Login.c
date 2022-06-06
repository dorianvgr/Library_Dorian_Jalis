#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Ressources.h"


void edit_library(int nbbooks,Book books[nbbooks]){ // This function creates a new .txt to put the modifications there and transfers them in the original .txt for books
    FILE * new_library=NULL;
    new_library=fopen("New_Library.txt","w"); // create a new .txt to store the new library with the modifications
    allocation_test(new_library);
    char nbbooks_char[5];
    sprintf(nbbooks_char, "%d", nbbooks);
    Borrow_Number tab_borrow_number[nbbooks];
                    
    for(int j=0; j<nbbooks; j++){ // uses a loop and the function "sprintf" to convert all the .borrow which have type int into type char

        sprintf(tab_borrow_number[j].borrow_char, "%d", books[j].borrow);
    }

    fputs(nbbooks_char, new_library); // we first write the number of books of our library in the first line of the .txt
    fputc('\n', new_library);
    space_detection(books, nbbooks); // replaces all the spaces in the titles or authors of the books with underscores
    for(int i=0; i<nbbooks; i++){  // fill the new .txt with all the books
        fputs(books[i].title, new_library);                     
        fputc('\n', new_library);
        fputs(books[i].author, new_library);
        fputc('\n', new_library);
        fputs(books[i].id_number, new_library);
        fputc('\n', new_library);
        fputs(books[i].category, new_library);
        fputc('\n', new_library);
        fputs(tab_borrow_number[i].borrow_char, new_library);
        fputc('\n', new_library);
    }
    rename("New_Library.txt","DATA_BASE_BOOKS.txt"); // Our database is updated
    fclose(new_library);
}

int login(FILE *data_base_users,FILE *admin_file){
    
    char id_user[30];
    int variable_for_id_check=0, trials_numbers=0, answer=0;
    printf("\nLog in :\n");
    
    do{
        printf("Please enter your identifiant :\n");
        clear_scan();
        scanf("%s", id_user);
        variable_for_id_check=id_check(data_base_users,id_user); // we stores the return of id_check to know the location number of the user who is connecting
        trials_numbers+=1;

        if(trials_numbers%3==0){                                             // every time the user fails 3 times in a row, he has the choice of 1.continue or 2. create an account
        	
        	do{
        		printf("Maybe you don't have an account and want to create one?\n-1 Continue the log in\n-2 Create an account \n\nPlease write 1 or 2\n");
        		clear_scan();
        		scanf("%d",&answer);
        		
        	}while(answer!=1 && answer !=2);
        	
        }
        
    }while (variable_for_id_check==0 && answer!=2); // as long as the user doesn't write a good username or doesn't want to create an account, the user will still be asked to write a good username or to create an account
    
    if(answer==2){ // if he types 2, that means he wants to create an account
    	
    	registration(data_base_users,admin_file); // This function creates an account for the user
 
    }
    
    else{
        fclose(admin_file); // close the .txt which contains the administrators codes for teachers
    	char buffer_password[30];
    	char * password_of_the_user = fgets(buffer_password, 29, data_base_users); // store the password in a pointer
    	int variable_for_password_check;

    	do{
    	    variable_for_password_check = password_check(password_of_the_user, buffer_password); // verifies if the password written is the good one
    	}while (variable_for_password_check==1); // as long as the password is wrong, the use is asked to try again

        char S_or_T = fgetc(data_base_users);
        FILE * data_base_books=NULL;
        data_base_books=fopen("DATA_BASE_BOOKS.txt", "r+"); // opens the .txt which contains the books
        allocation_test(data_base_books);
        rewind(data_base_books);
    	printf("\nWelcome %s !\n", id_user);
    	
        int nbbooks=0;
        fscanf(data_base_books,"%d", &nbbooks); // nbbooks = number of books in the .txt
        
        Book books[nbbooks];
        for (int i=0; i<nbbooks; i++){  // puts all the books in a table
                
            fscanf(data_base_books,"%s", books[i].title);
            fscanf(data_base_books,"%s", books[i].author);
            fscanf(data_base_books,"%s", books[i].id_number);
            fscanf(data_base_books,"%s", books[i].category);
            fscanf(data_base_books,"%d", &books[i].borrow);
        }
        underscore_detection(books, nbbooks); // removes all the underscores in the table of books and replaces them by spaces

        int nb_books_borrow=0;
        char books_borrow[5][100]={0};
        for (int i=0; i<nbbooks; i++){

            if (books[i].borrow==variable_for_id_check){ // looks if a book is already borrowed by the user
                
                nb_books_borrow++;
                
                for(int j=0;j<strlen(books[i].title);j++){ // 
                
                books_borrow[nb_books_borrow-1][j]=books[i].title[j];
                
                }
            }
        }
        if(nb_books_borrow==0){ // he didn't borrow any books

	        printf("you haven't borrow any books yet\n");

        }
        else{ // He borrowed books

        printf("You have borrowed the following books : \n");
        
        for (int j=0; j<nb_books_borrow; j++){
            printf("%s\n",books_borrow[j]); // displays the books borrowed by him  
        }       

        }
    	printf("\n");
    	int answer_second_interface = second_interface(nb_books_borrow, S_or_T); // displays the second interface
        while(answer_second_interface==0){
            answer_second_interface = second_interface(nb_books_borrow, S_or_T);
        }
        if (answer_second_interface==3){ // if he types 3, it goes back to the 1st interface
        
            printf("Goodbye %s !\n\n", id_user);
        }

        if (answer_second_interface==1){ // he wants to borrow a book

            
            int answer_third_interface = third_interface(); // displays the third interface
            if (answer_third_interface!=4){

                Book * books_title_author_or_category;
                books_title_author_or_category = calloc(nbbooks, sizeof(Book)); // creates another table to store the books the user wants to display
                calloc_test(books_title_author_or_category);
                if (answer_third_interface==1){
                    sort_by_title(books, books_title_author_or_category, nbbooks);
                }
                else if(answer_third_interface==2){
                    sort_by_author(books, books_title_author_or_category, nbbooks);
                }
                else if(answer_third_interface==3){
                    sort_by_category(books, books_title_author_or_category, nbbooks);
                }

                printf("Which book would you like to borrow ?\n");
                char title_scanf[50];

                int which_book_is_borrowed;
                do{                                                        // uses a loop to be sure that he enters a correct title
                    printf("Please type the title of a book available\n");
                    clear_scan();
                    scanf("%[^\n]", title_scanf);
                    which_book_is_borrowed = find_book_borrowed(books_title_author_or_category, title_scanf, nbbooks); // store the return of find_book_borrowed to know where is the book he wants to borrow
                }while(which_book_is_borrowed==-1);
                // DisplayAllBooks(nbbooks, books, "Books which are not borrowed");
                printf("You have successfully borrowed the book : %s !\n", title_scanf);
                
                dead_line( S_or_T);
                    
                books_title_author_or_category[which_book_is_borrowed].borrow = variable_for_id_check; // write the location number of the user in the .borrow of the book to know which user borrowed this book
                int where_book_in_books = find_book_in_books(books_title_author_or_category, books, nbbooks, which_book_is_borrowed); // uses it to know where is the book borrowed in the table "books"
                books[where_book_in_books].borrow = books_title_author_or_category[which_book_is_borrowed].borrow; // write the number of the user in the .borrow of the book in the table "books"
                free(books_title_author_or_category);
                fclose(data_base_books);
                fclose(data_base_users);

                edit_library(nbbooks, books); 
                return 1;
            }
            
        }
        if (answer_second_interface==2){ // He want to return a book if he writes 2
        	
        	if(nb_books_borrow>0){ // This condition verifies that he borrowed at least 1 book
        		
        		return_book(books, books_borrow,nb_books_borrow,variable_for_id_check,nbbooks); // This function allows the user to return a book
        		return 2;        		
        	
        	}
        	else{ // He didn't borrow any books
        		
        		printf("you haven't borrow any books yet\n");
        	}
        }
    }
}






