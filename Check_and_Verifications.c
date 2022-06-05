#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Ressources.h"


int idorpassword_verif(char *scanfusertab, char *buffertab){ // This function verifies if 2 character strings are exactly the same

    if(strlen(scanfusertab)!=strlen(buffertab)-1){ // if the length of the 2 character strings is not the same, they can't be the same 

        return 0; // returns 0 if they are not the same
    }
    for(int i=0; i<strlen(scanfusertab); i++){
        if(scanfusertab[i]!=buffertab[i]){ // if one letter is different, they can't be the same
            return 0; // returns 0 if they are not the same
        }
    }
    return 1; // returns 1 if they are the same
}


int id_check(FILE *file,char *iduser){ // This function verifies if what the user write corresponds to a username in our database and returns the location number of the user
       
    char buffer_user[30];
    char *which_id;
    rewind(file);
    which_id = fgets(buffer_user, 29, file); 
    int id_counter=1;
    while (idorpassword_verif(iduser, buffer_user)==0 && which_id!=NULL){ // if we don't find an username and if the function has been through all the .txt, the function goes out of the while
        for (int i=0; i<3; i++){
            which_id = fgets(buffer_user, 29, file);
        }
        id_counter++;
    }

    if (which_id==NULL){ // the function didn't find any username : that means the user has written a wrong username
    
        printf("Wrong username !\n");
        return 0; // in this case, the function returns 0
    }
    else{
        return id_counter; // the function returns the location number of the user if it finds an username that corresponds 
   }
}


int password_check(char *passworduser, char *bufferpassword){ // This function verifies that the password the user write corresponds to the password affiliated with its username

       
    char password[30];
    printf("Enter your password\n");
    scanf("%s", password);
    if (idorpassword_verif(password, bufferpassword)==0){ 
        printf("Wrong password !\n");
        return 1; // if what he writes is different from the correct password, the function returns 1
    }
    
    else{
   	 return 0; // if the function finds it, it returns 0
    }
}


int find_book_borrowed(Book *book1, char* title, int nbbooks){ // This function verifies if what the user writes corresponds to the title of a book and if it finds one, it returns the location of this book
    int a=0;
    while(a<nbbooks){ 
        int j=0;
        while(book1[a].title[j]==title[j] && j<strlen(title) ){ // This loop while searches if the letters of a title corresponds to what the user has written and increases j if so
            j++;
        }
        if( j==strlen(book1[a].title) && j==strlen(title)){ // this condition verifies if all the letters of each character strings are the same and if they have the same length
            return a;  // returns "a" if what the user writes corresponds to the title of a book."a" is the location in the table of the book corresponding
        }
        a++; // we increase "a" to move on to the next book
    }
    return -1;  // returns -1 if what the user writes corresponds to no books 
}


int find_book_in_books(Book *book1, Book *books, int nbbooks, int book_borrowed){ // When a book is borrowed, this function is used to know the location of this book in the original table of books "books"
    int a=0;
    while(a<nbbooks){
        int j=0;
        while(book1[book_borrowed].title[j]==books[a].title[j] && j<strlen(book1[book_borrowed].title)){
            j++;
        }
        if( j==strlen(book1[book_borrowed].title) && j==strlen(books[a].title)){
            return a;  // returns "a" if the function finds the location of the book in the 2nd table. "a" is the location in the 2nd table of the book
        }
        a++;
    }
    return -1;  // returns -1 if it fails to find it
}
