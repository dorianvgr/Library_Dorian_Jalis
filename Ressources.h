#include<stdio.h>



typedef struct{ // structure of the books
    char title[100];
    char author[100];
    char id_number[5];
    char category[50];
    int borrow;
}Book;

typedef struct{ // structure of the borrow number converted to char
    char borrow_char[5];
}Borrow_Number;


int first_interface();
int second_interface();
int third_interface();
void allocation_test(FILE *pointer);
void new_username(char buffer_tab[]);
int password_strength(char tab[]);
int space_detection_id(char buffer_tab[]);
void data_filling(char new[], FILE *file);
void new_password(char tab[]);
void clear_scan();
int admin_code_check(FILE *file, char *iduser);
int id_check(FILE *file, char *iduser);
int idorpassword_verif(char *scanfusertab, char *buffertab);
int password_check(char *passworduser, char *bufferpassword);
void login(FILE *data_base_users,FILE *admin_file);
void registration(FILE *file,FILE *admin_file);
int create_id_check(FILE *username_file,char *username);
void underscore_detection(Book books[], int nbbooks);
void DisplayAllBooks(int nbbooks,Book books[nbbooks],char title[]);
void sort_by_title(Book *books, Book *books_title, int nbbooks);
void sort_by_author(Book *books, Book *books_author, int nbbooks);
void sort_by_category(Book *books, Book *books_category, int nbbooks);
int find_book_borrowed(Book *book1, char* title, int nbbooks);
int find_book_in_books(Book *book1, Book *books, int nbbooks, int book_borrowed);
int sprintf(char *str, const char *format, ...);
void fill_new_tab(FILE * newtab, Book *books, int nbbooks);
int rename(const char* ancienNom, const char* nouveauNom);
int remove(const char* fichierASupprimer);
void space_detection(Book books[], int nbbooks);
void edit_library(int nbbooks,Book books[nbbooks]);
void edit_back_library(int nbbooks,Book books[nbbooks],int books_borrow_to_change);
void return_book(Book books[],char books_borrowed[5][100],int nb_books_borrowed,int books_borrow_to_change,int nbbooks);
