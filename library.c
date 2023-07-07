#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admission.h"

char availability1[20] = "available";
int option1;

struct Book {
    char title[50];
    char author[50];
    int isbn;
    int units;
    int total_units;
    int initialUnits;
};

void registerBook() {
    struct Book book;

    printf("Enter book title: ");
    scanf(" %[^\n]s", book.title);

    printf("Enter book author: ");
    scanf(" %[^\n]s", book.author);

    printf("Enter book ISBN: ");
    scanf("%d", &book.isbn);

    printf("Enter number of units: ");
    scanf("%d", &book.units);

    book.initialUnits = book.units;

    FILE* file = fopen("books.txt", "a");
    if (file != NULL) {
        printf("\nConfirm the book details\n");
        printf("--------------------------\n");
        printf("ISBN: %d\nTitle: %s\nAuthor: %s\nUnits: %d\nInitial Units: %d\n", book.isbn, book.title, book.author, book.units, book.initialUnits);
        printf("--------------------------\n");
        printf("1. Yes, proceed\n2. No, abort book registration\n");
        printf("Enter option: ");
        scanf("%d", &option1);
        switch (option1) {
            case 1:
                fprintf(file, "%d,%s,%s,%d,%d\n", book.isbn, book.title, book.author, book.units, book.initialUnits);
                fclose(file);
                printf("\nBook registered successfully.\n");
                break;
            case 2:
                printf("\nBook registration aborted\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } else {
        printf("Error opening the books file.\n");
    }
}



void borrowBook() {
    struct Student student;
    struct Book book;
    int isbn, regNo;

    printf("Enter student registration number: ");
    scanf("%d", &regNo);

    FILE* studentFile = fopen("maledetails.txt", "r");
    if (studentFile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), studentFile)) {
            sscanf(line, "%d,%[^,]%*c", &student.regNo, student.name);
            if (student.regNo == regNo) {
                found = 1;
                break;
            }
        }
        fclose(studentFile);

        if (!found) {
            studentFile = fopen("femaledetails.txt", "r");
            if (studentFile != NULL) {
                found = 0;
                while (fgets(line, sizeof(line), studentFile)) {
                    sscanf(line, "%d,%[^,]%*c", &student.regNo, student.name);
                    if (student.regNo == regNo) {
                        found = 1;
                        break;
                    }
                }
                fclose(studentFile);
            } else {
                printf("Error opening the female student details file\n");
                return;
            }
        }

        if (!found) {
            printf("Student with ID %d not found\n", regNo);
            return;
        }
    } else {
        printf("Error opening the male student details file\n");
        return;
    }

    printf("Enter book ISBN: ");
    scanf("%d", &isbn);

    FILE* bookFile = fopen("books.txt", "r+");
    if (bookFile != NULL) {
        char line[256];
        int found = 0;
        FILE* tempFile = fopen("temp.txt", "w");
        FILE* borrowFile = fopen("borrowedbooks.txt", "a");
        while (fgets(line, sizeof(line), bookFile)) {
            sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.isbn, book.title, book.author, &book.units, &book.initialUnits);
            if (book.isbn == isbn) {
                if (book.units > 0) {
                    found = 1;
                    book.units--;
                    fprintf(borrowFile, "%d,%d\n", regNo, isbn);
                } else {
                    printf("No available units of the book with ISBN %d\n", isbn);
                }
            }
            fprintf(tempFile, "%d,%s,%s,%d,%d\n", book.isbn, book.title, book.author, book.units, book.initialUnits);
        }
        fclose(bookFile);
        fclose(tempFile);
        fclose(borrowFile);

        if (found) {
            remove("books.txt");
            rename("temp.txt", "books.txt");
            printf("\nBook borrowed successfully.\n");
        } else {
            remove("temp.txt");
        }
    } else {
        printf("Error opening the books file.\n");
    }
}



void returnBook() {
    struct Book book;
    int isbn;

    printf("Enter book ISBN: ");
    scanf("%d", &isbn);

    FILE* bookFile = fopen("books.txt", "r+");
    if (bookFile != NULL) {
        char line[256];
        int found = 0;
        FILE* tempFile = fopen("temp.txt", "w");
        while (fgets(line, sizeof(line), bookFile)) {
            sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.isbn, book.title, book.author, &book.units, &book.initialUnits);
            if (book.isbn == isbn) {
                found = 1;
                book.units++;
            }
            fprintf(tempFile, "%d,%s,%s,%d,%d\n", book.isbn, book.title, book.author, book.units, book.initialUnits);
        }
        fclose(bookFile);
        fclose(tempFile);

        if (found) {
            remove("books.txt");
            rename("temp.txt", "books.txt");
            printf("\nBook returned successfully.\n");
        } else {
            remove("temp.txt");
            printf("Book with ISBN %d not found\n", isbn);
        }
    } else {
        printf("Error opening the books file.\n");
    }
}



void searchBook() {
    struct Book book;
    int isbn;

    printf("Enter book ISBN: ");
    scanf("%d", &isbn);

    FILE* file = fopen("books.txt", "r");
    if (file != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.isbn, book.title, book.author, &book.units, &book.initialUnits);
            if (book.isbn == isbn) {
                found = 1;
                printf("\nBook found.\n");
                printf("Title: %s\nAuthor: %s\nUnits Available: %d\n", book.title, book.author, book.units);
                break;
            }
        }
        fclose(file);
        if (!found) {
            printf("Book with ISBN %d not found\n", isbn);
        }
    } else {
        printf("Error opening the books file.\n");
    }
}

void deleteBookRecord() {
    struct Book book;
    int isbn;

    printf("Enter book ISBN: ");
    scanf("%d", &isbn);

    FILE* bookFile = fopen("books.txt", "r");
    if (bookFile != NULL) {
        char line[256];
        int found = 0;
        FILE* tempFile = fopen("temp.txt", "w");
        while (fgets(line, sizeof(line), bookFile)) {
            sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.isbn, book.title, book.author, &book.units, &book.initialUnits);
            if (book.isbn == isbn) {
                found = 1;
                continue;
            }
            fprintf(tempFile, "%d,%s,%s,%d,%d\n", book.isbn, book.title, book.author, book.units, book.initialUnits);
        }
        fclose(bookFile);
        fclose(tempFile);

        if (found) {
            remove("books.txt");
            rename("temp.txt", "books.txt");
            printf("\nBook record deleted successfully.\n");
        } else {
            remove("temp.txt");
            printf("Book with ISBN %d not found\n", isbn);
        }
    } else {
        printf("Error opening the books file.\n");
    }
}

void updateBookRecord(int isbn, int option) {
    struct Book book;
    FILE* bookFile = fopen("books.txt", "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (bookFile == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), bookFile)) {
        sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.isbn, book.title, book.author, &book.units, &book.total_units);

        if (book.isbn == isbn) {
            switch (option) {
                case 1:
                    printf("Enter the new book ISBN: ");
                    scanf("%d", &book.isbn);
                    break;
                case 2:
                    printf("Enter the new book title: ");
                    scanf(" %[^\n]", book.title);
                    break;
                case 3:
                    printf("Enter the new book author: ");
                    scanf(" %[^\n]", book.author);
                    break;
                case 4:
                    printf("Enter the new book units: ");
                    scanf("%d", &book.total_units);
                    break;
                default:
                    printf("Invalid option selected.\n");
                    fclose(bookFile);
                    fclose(tempFile);
                    return;
            }

            printf("Details updated successfully\n\n");
            printf("New book details are:\n");
            printf("----------------------------------\n");
            printf("Book ISBN: %d\nBook title: %s\nBook Author: %s\nAvailable units: %d\nTotal units: %d\n", book.isbn, book.title, book.author, book.units, book.total_units);
            printf("----------------------------------\n");
            found = 1;
        }

        fprintf(tempFile, "%d,%s,%s,%d,%d\n", book.isbn, book.title, book.author, book.units, book.total_units);
    }

    fclose(bookFile);
    fclose(tempFile);

    if (!found) {
        printf("Book with ISBN %d not found.\n", isbn);
        return;
    }

    remove("books.txt");
    rename("temp.txt", "books.txt");
}

void updateBookRecords() {
    int isbn, option;

    printf("\nWhich detail do you want to edit?\n\n");
    printf("1. Book ISBN\n");
    printf("2. Book title\n");
    printf("3. Book author\n");
    printf("4. Total book units\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    printf("Enter the book ISBN you want to edit: ");
    scanf("%d", &isbn);

    updateBookRecord(isbn, option);
}



void viewRegisteredBooks() {
    FILE* file = fopen("books.txt", "r");
    if (file != NULL) {
        char line[256];
        int count = 0;
        printf("Registered Books:\n");
        printf("-----------------\n");
        while (fgets(line, sizeof(line), file)) {
            struct Book book;
            sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.isbn, book.title, book.author, &book.units, &book.initialUnits);
            printf("ISBN: %d\n", book.isbn);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Units: %d\n", book.units);
            printf("-----------------\n");
            count++;
        }
        fclose(file);
        if (count == 0) {
            printf("No books registered.\n");
        }
    } else {
        printf("Error opening the book details file.\n");
        return;
    }
}

void viewBorrowedBooks() {
    FILE* file = fopen("borrowedbooks.txt", "r");
    if (file != NULL) {
        char line[256];
        int count = 0;
        printf("Borrowed Books:\n");
        printf("-----------------\n");
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
            count++;
        }
        fclose(file);
        if (count == 0) {
            printf("No books currently borrowed.\n");
        }
    } else {
        printf("Error opening the borrowed books file.\n");
        return;
    }
}

