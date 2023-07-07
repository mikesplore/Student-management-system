#ifndef LIBRARY_H
#define LIBRARY_H



void registerBook();
void borrowBook();
void returnBook();
void viewBorrowedBooks();
void viewRegisteredBooks();
void searchBook();
void deleteBookRecord();
void updateBookRecord(int ibn, int option);
void updateBookRecords();


#endif  // LIBRARY_H