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
    char availability1[20];
};

void registerBook() {
    struct Book book;

    printf("Enter book title: ");
    scanf(" %[^\n]s", book.title);

    printf("Enter book author: ");
    scanf(" %[^\n]s", book.author);

    printf("Enter book ISBN: ");
    scanf("%d", &book.isbn);

    strcpy(availability1, "available");

    FILE* file = fopen("books.txt", "a");
    if (file != NULL) {
        printf("\nConfirm the book details\n");
        printf("--------------------------\n");
        printf("ISBN: %d\nTitle: %s\nAuthor: %s\n",book.isbn, book.title, book.author);
        printf("--------------------------\n");
        printf("1.Yes, proceed\n2.No, abort book registration\n");
        printf("Enter option: ");
        scanf("%d",&option1);
        switch(option1){
            case 1:
        fprintf(file, "%d, %s, %s, %s\n", book.isbn, book.title, book.author, availability1);
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

void viewregisteredbooks() {
    FILE* file = fopen("books.txt", "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error opening the file\n");
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
        if (tempFile == NULL) {
            printf("Error creating temporary file.\n");
            fclose(bookFile);
            return;
        }

        while (fgets(line, sizeof(line), bookFile)) {
            sscanf(line, "%d,%[^,],%[^,],%s", &book.isbn, book.title, book.author, availability1);
            if (book.isbn == isbn && strcmp(availability1, "available") == 0) {
                found = 1;
                fprintf(tempFile, "%d,%s,%s,borrowed\n", book.isbn, book.title, book.author);
            } else {
                fprintf(tempFile, "%s", line);
            }
        }
        fclose(bookFile);
        fclose(tempFile);

        if (found) {
            remove("books.txt");
            rename("temp.txt", "books.txt");

            FILE* borrowedFile = fopen("borrowedbooks.txt", "a");
            if (borrowedFile != NULL) {
                fprintf(borrowedFile, "Book ISBN %d, %s borrowed by %s of reg number %d\n", book.isbn, book.title, student.name, student.regNo);
                fclose(borrowedFile);
                printf("Book borrowed successfully.\n");
            } else {
                printf("Error opening the borrowed books file.\n");
            }
        } else {
            printf("Book with ISBN %d has already been borrowed or is not available.\n", isbn);
            remove("temp.txt");
        }
    } else {
        printf("Error opening the book details file.\n");
        return;
    }
}


void viewborrowedbooks() {
    FILE* file = fopen("borrowedbooks.txt", "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error opening the file\n");
    }
}

void returnBook() {
    int ibn;
    printf("Enter book ISBN: ");
    scanf("%d", &ibn);

    FILE* file = fopen("books.txt", "r+");
    if (file != NULL) {
        char line[256];
        int found = 0;
        FILE* tempFile = fopen("temp.txt", "w");
        if (tempFile == NULL) {
            printf("Error creating temporary file.\n");
            fclose(file);
            return;
        }

        while (fgets(line, sizeof(line), file)) {
            struct Book book;
            sscanf(line, "%d, %[^,], %[^,], %s", &book.isbn, book.title, book.author, availability1);
            if (book.isbn == ibn && strcmp(availability1, "borrowed") == 0) {
                found = 1;
                fprintf(tempFile, "%d, %s, %s, available\n", book.isbn, book.title, book.author);
            } else {
                fprintf(tempFile, "%s", line);
            }
        }
        fclose(file);
        fclose(tempFile);

        if (found) {
            remove("books.txt");
            rename("temp.txt", "books.txt");
            printf("Book returned successfully.\n");
        } else {
            printf("Book with ID %d not found or already available.\n", ibn);
            remove("temp.txt");
        }
    } else {
        printf("Error opening the book details file.\n");
        return;
    }
}


void searchbook(int ibn) {
    printf("Enter book ISBN: ");
    scanf("%d",&ibn);
    FILE* file = fopen("books.txt", "r");
    if (file != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), file)) {
            int regNo;
            sscanf(line, "%d", &regNo);
            if (regNo == ibn) {
                printf("Search result:\n\n");
                printf("%s", line);
                found = 1;
                break;
            }
        }
        fclose(file);

        if (!found) {
            printf("Book with ISBN %d not found\n", ibn);
        }
    } else {
        printf("Error opening the file\n");
    }
}

void deletebookrecord(int ibn) {
    printf("Enter Book ISBN to delete: ");
    scanf("%d", &ibn);

    FILE* file = fopen("books.txt", "r");
    if (file != NULL) {
        FILE* tempFile = fopen("temp.txt", "w");
        if (tempFile != NULL) {
            char line[256];
            int found = 0;
            while (fgets(line, sizeof(line), file)) {
                int regNo;
                sscanf(line, "%d", &regNo);
                if (regNo != ibn) {
                    fprintf(tempFile, "%s", line);
                } else {
                    found = 1;
                }
            }
            fclose(tempFile);
            fclose(file);

            if (found) {
                remove("books.txt");
                rename("temp.txt", "books.txt");
                printf("Book with ISBN %d deleted successfully\n", ibn);
            } else {
                printf("Book with ISBN %d not found\n", ibn);
                remove("temp.txt");
            }
        } else {
            printf("Error creating temporary file\n");
            fclose(file);
        }
    } else {
        printf("Error opening the file\n");
    }
}


void updatebookrecords() {
    int ibn, ibn1, option;
    struct Book book;

    printf("\nWhich detail do you want to edit?\n\n");
    printf("1. Book ISBN\n");
    printf("2. Book title\n");
    printf("3. Book author\n");
    printf("4. Book Availability\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the book ISBN you want to edit: ");
            scanf("%d", &ibn);

            FILE* titlefile = fopen("books.txt", "r");
            FILE* tempFile = fopen("temp.txt", "w");

            if (titlefile != NULL && tempFile != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), titlefile)) {
                    sscanf(line, "%d, %[^,], %[^,], %s", &book.isbn, book.title, book.author, availability1);

                    if (book.isbn == ibn) {
                        printf("Enter the new book ISBN: ");
                        scanf("%d", &ibn1);
                        fprintf(tempFile, "%d, %s, %s, %s\n", ibn1, book.title, book.author, availability1);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile, "%d, %s, %s, %s\n", book.isbn, book.title, book.author, availability1);
                    }
                }

                fclose(titlefile);
                fclose(tempFile);

                if (!found) {
                    printf("Book with ISBN %d not found.\n", ibn);
                } else {
                    remove("books.txt");
                    rename("temp.txt", "books.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 2:
            printf("Enter the book ISBN you want to edit: ");
            scanf("%d", &ibn);

            titlefile = fopen("books.txt", "r");
            tempFile = fopen("temp.txt", "w");

            if (titlefile != NULL && tempFile != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), titlefile)) {
                    sscanf(line, "%d, %[^,], %[^,], %s", &book.isbn, book.title, book.author, availability1);

                    if (book.isbn == ibn) {
                        char newTitle[256];
                        printf("Enter the new book title: ");
                        scanf(" %[^\n]", newTitle);
                        fprintf(tempFile, "%d, %s, %s, %s\n", book.isbn, newTitle, book.author, availability1);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile, "%d, %s, %s, %s\n", book.isbn, book.title, book.author, availability1);
                    }
                }

                fclose(titlefile);
                fclose(tempFile);

                if (!found) {
                    printf("Book with ISBN %d not found.\n", ibn);
                } else {
                    remove("books.txt");
                    rename("temp.txt", "books.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 3:
            printf("Enter the book ISBN you want to edit: ");
            scanf("%d", &ibn);

            titlefile = fopen("books.txt", "r");
            tempFile = fopen("temp.txt", "w");

            if (titlefile != NULL && tempFile != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), titlefile)) {
                    sscanf(line, "%d, %[^,], %[^,], %s", &book.isbn, book.title, book.author, availability1);

                    if (book.isbn == ibn) {
                        char newAuthor[256];
                        printf("Enter the new book author: ");
                        scanf(" %[^\n]", newAuthor);
                        fprintf(tempFile, "%d, %s, %s, %s\n", book.isbn, book.title, newAuthor, availability1);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile, "%d, %s, %s, %s\n", book.isbn, book.title, book.author, availability1);
                    }
                }

                fclose(titlefile);
                fclose(tempFile);

                if (!found) {
                    printf("Book with ISBN %d not found.\n", ibn);
                } else {
                    remove("books.txt");
                    rename("temp.txt", "books.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 4:
            printf("Enter the book ISBN you want to edit: ");
            scanf("%d", &ibn);

            titlefile = fopen("books.txt", "r");
            tempFile = fopen("temp.txt", "w");

            if (titlefile != NULL && tempFile != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), titlefile)) {
                    sscanf(line, "%d, %[^,], %[^,], %s", &book.isbn, book.title, book.author, availability1);

                    if (book.isbn == ibn) {
                        char newAvailability[256];
                        printf("Enter the new book availability: ");
                        scanf(" %[^\n]", newAvailability);
                        fprintf(tempFile, "%d, %s, %s, %s\n", book.isbn, book.title, book.author, newAvailability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile, "%d, %s, %s, %s\n", book.isbn, book.title, book.author, availability1);
                    }
                }

                fclose(titlefile);
                fclose(tempFile);

                if (!found) {
                    printf("Book with ISBN %d not found.\n", ibn);
                } else {
                    remove("books.txt");
                    rename("temp.txt", "books.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        default:
            printf("Invalid option selected.\n");
            break;
    }
}