#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "admission.h"
#include "hostels.h"

//generating admission number
int readNumberFromFile() {
    int number = 1;  // Default value if the file doesn't exist

    FILE* file = fopen("admnumber.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &number);
        fclose(file);
    }

    return number;
}

void writeNumberToFile(int number) {
    FILE* file = fopen("admnumber.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", number);
        fclose(file);
    }
}

int generateIncreasingNumber() {
    int number = readNumberFromFile();
    printf("%03d\n", number);

    number++;
    writeNumberToFile(number);
}

void maledetails() {
    struct Student student;
    printf("Enter your Name: ");
    scanf(" %99[^\n]", student.name);

    printf("Enter your DOB: ");
    scanf("%d", &student.dob);

    printf("Enter your nationality: ");
    scanf(" %49[^\n]%*c", student.nationality);

    printf("Enter your address: ");
    scanf(" %[^\n]", student.address);

    printf("Enter your mobile phone number: ");
    scanf("%d", &student.phone);

    student.regNo = readNumberFromFile();
    writeNumberToFile(student.regNo + 1);

    FILE* malefile = fopen("maledetails.txt", "a");
    if (malefile != NULL) {
        fprintf(malefile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
        fclose(malefile);
        printf("\n\nDetails captured successfully!\nYour registration number is %d\n", student.regNo);
    } else {
        printf("Error opening the file\n");
    }
}

//register new female students details
void femaledetails() {
    struct Student student;
    printf("Enter your Name: ");
    scanf(" %99[^\n]", student.name);

    printf("Enter your DOB: ");
    scanf("%d", &student.dob);

    printf("Enter your nationality: ");
    scanf(" %49[^\n]%*c", student.nationality);

    printf("Enter your address: ");
    scanf(" %[^\n]", student.address);

    printf("Enter your mobile phone number: ");
    scanf("%d", &student.phone);

    student.regNo = readNumberFromFile();
    writeNumberToFile(student.regNo + 1);

    FILE* malefile = fopen("femaledetails.txt", "a");
    if (malefile != NULL) {
        fprintf(malefile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
        fclose(malefile);
        printf("\n\nDetails captured successfully!\nYour registration number is %d\n", student.regNo);
    } else {
        printf("Error opening the file\n");
    }
}

void viewmaledetails() {
    FILE* file = fopen("maledetails.txt", "r");
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


void viewfemaledetails() {
    FILE* file = fopen("femaledetails.txt", "r");
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
void searchmalestudent(int id) {
    printf("Enter student ID: ");
    scanf("%d",&id);
    FILE* file = fopen("maledetails.txt", "r");
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

//search female student
void searchfemalestudent(int id) {
    printf("Enter student ID: ");
    scanf("%d",&id);
    FILE* file = fopen("femaledetails.txt", "r");
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

void deleteMaleStudentRecord(int id) {
    printf("Enter student regNo to delete: ");
    scanf("%d", &id);

    FILE* file = fopen("maledetails.txt", "r");
    if (file != NULL) {
        FILE* tempFile = fopen("temp.txt", "w");
        if (tempFile != NULL) {
            char line[256];
            int found = 0;
            while (fgets(line, sizeof(line), file)) {
                int regNo;
                sscanf(line, "%d", &regNo);
                if (regNo != id) {
                    fprintf(tempFile, "%s", line);
                } else {
                    found = 1;
                }
            }
            fclose(tempFile);
            fclose(file);

            if (found) {
                remove("maledetails.txt");
                rename("temp.txt", "maledetails.txt");
                printf("Student with ID %d deleted successfully\n", id);
            } else {
                printf("Student with ID %d not found\n", id);
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

//delete female details
void deleteFemaleStudentRecord(int id) {
    printf("Enter student regNo to delete: ");
    scanf("%d", &id);

    FILE* file = fopen("femaledetails.txt", "r");
    if (file != NULL) {
        FILE* tempFile = fopen("temp1.txt", "w");
        if (tempFile != NULL) {
            char line[256];
            int found = 0;
            while (fgets(line, sizeof(line), file)) {
                int regNo;
                sscanf(line, "%d", &regNo);
                if (regNo != id) {
                    fprintf(tempFile, "%s", line);
                } else {
                    found = 1;
                }
            }
            fclose(tempFile);
            fclose(file);

            if (found) {
                remove("femaledetails.txt");
                rename("temp1.txt", "femaledetails.txt");
                printf("Student with ID %d deleted successfully\n", id);
            } else {
                printf("Student with ID %d not found\n", id);
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

