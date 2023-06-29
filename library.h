#ifndef LIBRARY_H
#define LIBRARY_H

struct Book {
    char title[50];
    char author[50];
    int isbn;
    char availability1[20];
};

void registerBook();
void borrowBook();
void returnBook();
void viewborrowedbooks();
void viewregisteredbooks();
void searchbook(int ibn);
void deletebookrecord(int ibn);
void updatebookrecords();


#endif  // LIBRARY_H