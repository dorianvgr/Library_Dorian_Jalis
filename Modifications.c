#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Ressources.h"


void underscore_detection(Book books[], int nbbooks){ // This function removes underscores in the title and in the author of all the books in a table of books and replace them by spaces

	for (int i=0; i<nbbooks; i++){ // the loop goes through all the table of nbbooks books
		for(int j=0; j<strlen(books[i].title); j++){
			if (books[i].title[j]=='_'){
				books[i].title[j]=' '; // replaces '_' with ' ' for the title
			}
		}
		for(int k=0; k<strlen(books[i].author); k++){
			if (books[i].author[k]=='_'){
				books[i].author[k]=' '; // replaces '_' with ' ' for the author
			}
		} 

	}
}

void space_detection(Book books[], int nbbooks){ // This function removes spaces in the title and in the author of all the books in a table of books and replace them by underscores

	for (int i=0; i<nbbooks; i++){ // the loop goes through all the table of nbbooks books
		for(int j=0; j<strlen(books[i].title); j++){
			if (books[i].title[j]==' '){
				books[i].title[j]='_'; // replaces ' ' with '_' for the title
			}
		}
		for(int k=0; k<strlen(books[i].author); k++){
			if (books[i].author[k]==' '){
				books[i].author[k]='_'; // replaces ' ' with '_' for the author
			}
		} 

	}
}