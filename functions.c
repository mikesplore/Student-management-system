#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int randomNumber() {
    return rand() % 9000 + 1000;
}

struct Student {
    int regNo;
    char name[100];
    char gender;
    char nationality[50];
    char address[100];
    int phone;
    int dob;
};

void spdetails() {
    struct Student student;

    printf("Enter your Name: ");
    scanf(" %99[^\n]", student.name);

    printf("Enter your DOB: ");
    scanf("%d", &student.dob);

    printf("Enter your gender: ");
    scanf(" %c", &student.gender);

    printf("Enter your nationality: ");
    scanf(" %49[^\n]%*c", student.nationality);

    printf("Enter your address: ");
    scanf(" %[^\n]", student.address);

    printf("Enter your mobile phone number: ");
    scanf("%d", &student.phone);

    student.regNo = randomNumber();

    FILE* file = fopen("pdetails.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d, %s, %c, %s, %s, %d\n", student.regNo, student.name, student.gender, student.nationality, student.address, student.phone);
        fclose(file);
        printf("\n\nDetails captured successfully!\nYour registration number is %d\n", student.regNo);
    } else {
        printf("Error opening the file\n");
    }
}

void viewpdetails() {
    FILE* file = fopen("pdetails.txt", "r");
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

void searchByID(int id) {
    printf("Enter student ID: ");
    scanf("%d",&id);
    FILE* file = fopen("pdetails.txt", "r");
    if (file != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), file)) {
            int regNo;
            sscanf(line, "%d", &regNo);
            if (regNo == id) {
                printf("%s", line);
                found = 1;
                break;
            }
        }
        fclose(file);

        if (!found) {
            printf("Student with ID %d not found\n", id);
        }
    } else {
        printf("Error opening the file\n");
    }
}

