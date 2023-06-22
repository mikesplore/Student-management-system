#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "admission.h"
#include "library.h"
char availability1[20]="available";
//generating book id number
int readNumberFromFile2() {
    int number = 1;  // Default value if the file doesn't exist

    FILE* file = fopen("booknumber.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &number);
        fclose(file);
    }

    return number;
}

void writeNumberToFile2(int number) {
    FILE* file = fopen("booknumber.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", number);
        fclose(file);
    }
}

int generateIncreasingNumber2() {
    int number = readNumberFromFile2();
    printf("%03d\n", number);

    number++;
    writeNumberToFile2(number);
}
// registering new book
void registerbook() {
    struct Book books;
    printf("Enter Book Name: ");
    scanf(" %99[^\n]", books.bookName);

    printf("Enter publication year: ");
    scanf("%d", &books.year);

    printf("Enter book author: ");
    scanf(" %49[^\n]%*c", books.bookAuthor);

    

    books.bookID= readNumberFromFile2();
    writeNumberToFile2(books.bookID + 1);

    FILE* bookfile = fopen("bookdetails.txt", "a");
    if (bookfile != NULL) {
        fprintf(bookfile, "%d, %s, %s, %d\n", books.bookID, books.bookName, books.bookAuthor, books.year);
        fclose(bookfile);
        printf("\n\nDetails captured successfully!\nBook ID number is %d\n", books.bookID);
    } else {
        printf("Error opening the file\n");
    }
}

//view registered books
void viewbookdetails() {
    FILE* file = fopen("bookdetails.txt", "r");
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