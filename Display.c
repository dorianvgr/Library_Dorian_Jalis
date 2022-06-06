#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Ressources.h"

int first_interface(){ // displays the 1st interface

    int answer;
    printf("*****************************************\n\tApplication CY-BiblioTECH\t\n*****************************************\n");
    printf("\n\n1. Log in.\n2. Register\n3. Exit \n"); 
    scanf("%d", &answer);
    while(answer!=1 && answer!=2 && answer!=3){ // uses a while to deny the user to write other things than 1, 2 or 3
        printf("Please write 1,2 or 3\n");
        clear_scan();
        scanf("%d", &answer);
    }
    return answer; // returns what the user has written
}

int second_interface(int nb_books_borrow, char S_or_P){ // displays the 2nd interface
    int answer;
    printf("What do you want to do ?\n1.Borrow a new book\n2.Return a book\n3.Disconnect\n");
    scanf("%d",&answer);
    while(answer!=1 && answer!=2 && answer!=3){
        printf("Please write 1, 2 or 3\n");
        clear_scan();
        scanf("%d", &answer); 
	}
    if(S_or_P=='S'){
        if (nb_books_borrow==3){
            if(answer==1){
                printf("You can't borrow more books (max : 3)\n");
                return 0;
            }
        }
                
    }
        return answer;
}

int third_interface(){ // displays the third interface

    int answer1;
    printf("1.Do a research by the title\n2.Do a research by the author\n3.Do a research by the category\n4.Go back\n"); // 3rd interface
    scanf("%d", &answer1);
    while(answer1!=1 && answer1!=2 && answer1!=3 && answer1!=4){
        printf("Please write 1, 2, 3 or 4\n");
        clear_scan();
        scanf("%d", &answer1);
    }
    return answer1;
}

void DisplayBookInfo(Book *b) { // This function is used to display a book
    printf("Title : %s --- Author : %s --- Id number : %s --- Category : %s\n", b->title,b->author,b->id_number,b->category);
}


void DisplayAllBooks(int nbbooks,Book books[nbbooks],char title[]) { // This function is used to display all the books of a table of books except the ones borrowed
    puts(title);
    for(int i=0;i<nbbooks;i++){
        if (books[i].borrow==0){ // if a book is borrowed (that means the number of the .borrow of the book !=0),  don't display this book
            DisplayBookInfo(&books[i]);
        }
    }
    puts("---------------------");
}