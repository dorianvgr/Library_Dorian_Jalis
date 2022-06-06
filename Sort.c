#include"Ressources.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>






void fill_tab_for_sort(Book *books, Book *newbooks, int a, int c){ // This function is used to fill a new table of books after a sort(by title, author or category)
    
    for(int k=0; k<strlen(books[a].title); k++){ // This loop fills the title of the books of the 1st table in the 2nd table
        newbooks[c].title[k]=books[a].title[k];
    }
    for (int l=0; l<strlen(books[a].author); l++){ // This loop fills the author of the books of the 1st table in the 2nd table
        newbooks[c].author[l]=books[a].author[l];
    }
    for (int m=0; m<strlen(books[a].id_number); m++){ // This loop fills the id_number of the books of the 1st table in the 2nd table
        newbooks[c].id_number[m]=books[a].id_number[m];
    }
    for (int n=0; n<strlen(books[a].category); n++){ // This loop fills the category of the books of the 1st table in the 2nd table
        newbooks[c].category[n]=books[a].category[n];
    }
    newbooks[c].borrow = books[a].borrow;
}


int CmpTitle(const void *v1,const void *v2) { // This function is used to sort by the title
    return(strcmp(((Book *)v1)->title,((Book *)v2)->title));
}
int CmpAuthor(const void *v1,const void *v2) { // This function is used to sort by the author
    return(strcmp(((Book *)v1)->author,((Book *)v2)->author));
}
int CmpCategory(const void *v1,const void *v2) { // This function is used to sort by the category
    return(strcmp(((Book *)v1)->category,((Book *)v2)->category));
}

     
void sort_by_title(Book *books, Book *books_title, int nbbooks){ // This function sorts in alphabetical order the titles of all the books of a table of books in relation to what the user writes
    char answerresearch[50];
    int a=0;
    int c=0;
    int nb_books=0;
    printf("Which book are you looking at ?\n"); 
    scanf("%s", answerresearch); // stores what the user writes



    while(a<nbbooks){ // the loop goes through all the table of nbbooks books
        int j=0;
        while(books[a].title[j]==answerresearch[j] && j<strlen(answerresearch) ){ // This loop while searches if the letters of a title corresponds to what the user has written and increases j if so
            j++;
        }
        if (j==strlen(answerresearch)){ // if this condition is verified, that means that what the user wrote corresponds to a title or at least to the beginning of a title (research + sort)
            fill_tab_for_sort(books, books_title, a, c); // fill the new table "books_title" with the books corresponding to what the user has written
            nb_books++; // This variable is used to know how many books are corresponding to what the user has written
        c++; // This variable is used to fill the new table
        }
        a++;  // we increase "a" to move on to the next book
        
    }
    // printf("cacacacacac");
    // for (int i=0; i<nbbooks; i++){
    //     printf("%s", books_title[i].title);
    // }
    if (nb_books==0){ // if nb_books==0, that means that no books corresponded to what the user has written so he can't borrow any books
        printf("We didn't find anything starting with %s please type again\n", answerresearch);
        sort_by_title( books, books_title, nbbooks); // we do a recursive function to allow the user to write something until it corresponds to at least one title
    }
    else{ // the function finds one or few titles corresponding with what the user has written
    qsort(books_title,c,sizeof(Book),CmpTitle); // sort by alphabetical order the titles of the new table
    DisplayAllBooks(c,books_title,"Here is the result of your research :\n"); // display the books corresponding with what the user has written
    }
}

void sort_by_author(Book *books, Book *books_author, int nbbooks){ // This function sorts in alphabetical order the authors of all the books of a table of books in relation to what the user writes
    char answerresearch[50];                                       // It works the same way as the function"sort_by_title"
    int a=0;
    int c=0;
    int nb_books=0;
    printf("Write the author you want to research :\n"); 
    scanf("%s", answerresearch);
    while(a<nbbooks){
        int j=0;
        while(books[a].author[j]==answerresearch[j] && j<strlen(answerresearch) ){
            j++;
        }
        if (j==strlen(answerresearch)){
            fill_tab_for_sort(books, books_author, a, c);
            nb_books++;
        c++;
        }
        a++;
        
    }
    if (nb_books==0){
        printf("We didn't find anything starting with %s please type again\n", answerresearch);
        sort_by_author( books, books_author, nbbooks);
    }
    else{
    qsort(books_author,c,sizeof(Book),CmpAuthor);  // sort by alphabetical order the authors of the new table
    DisplayAllBooks(c,books_author,"Here is the result of your research :\n");
    }
}


void sort_by_category(Book *books, Book *books_category, int nbbooks){ // This function sorts in alphabetical order the categories of all the books of a table of books in relation to what the user writes
    char answerresearch[50];                                           // It works the same way as the function "sort_by_title"
    int a=0;
    int c=0;
    int nb_books;
    printf("What category are you looking at ?\n"); 
    scanf("%s", answerresearch);
    while(a<nbbooks){
        int j=0;
        while(books[a].category[j]==answerresearch[j] && j<strlen(answerresearch) ){
            j++;
        }
        if (j==strlen(answerresearch)){
            fill_tab_for_sort(books, books_category, a, c);
            nb_books++;
        c++;
        }
        a++;
        
    }
    if (nb_books==0){
        printf("We didn't find anything starting with %s please type again\n", answerresearch);
        sort_by_category( books, books_category, nbbooks);
    }
    else{
    qsort(books_category,c,sizeof(Book),CmpTitle);  // sort by alphabetical order the titles of the new table 
    DisplayAllBooks(c,books_category,"Here is the result of your research :\n");
    }
}

