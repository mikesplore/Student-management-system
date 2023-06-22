#ifndef LIBRARY_H
#define LIBRARY_H

struct Book{
    int bookID;
    char bookName[20];
    char bookAuthor[50];
    int year;
};

void registerbook();
void viewbookdetails();


#endif  // LIBRARY_H