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

void registerStudentDetails(const char* filename) {
    struct Student {
        char name[50];
        int dob;
        char nationality[50];
        char address[100];
        int phone;
        int regNo;
    } student;

    int option1;
    printf("Enter your Name: ");
    scanf(" %49[^\n]%*c", student.name);

    printf("Enter your DOB: ");
    scanf("%d", &student.dob);

    printf("Enter your nationality: ");
    scanf(" %49[^\n]%*c", student.nationality);

    printf("Enter your address: ");
    scanf(" %[^\n]%*c", student.address);

    printf("Enter your mobile phone number: ");
    scanf("%d", &student.phone);

    student.regNo = readNumberFromFile();
    writeNumberToFile(student.regNo + 1);

    FILE* file = fopen(filename, "a");
    if (file != NULL) {
        printf("\nConfirm the entered details\n");
        printf("-------------------------------------\n");
        printf("Registration number: %d\n", student.regNo);
        printf("Name: %s\n", student.name);
        printf("Date of birth: %d\n", student.dob);
        printf("Nationality: %s\n", student.nationality);
        printf("Address: %s\n", student.address);
        printf("Phone number: %d\n", student.phone);
        printf("-------------------------------------\n");
        printf("Do you want to continue?\n1. Yes\n2. No\nEnter an option: ");
        scanf("%d", &option1);
        if (option1 == 1) {
            fprintf(file, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
            fclose(file);
            printf("\n\nDetails captured successfully!\nYour registration number is %d\n", student.regNo);
        }
        else if (option1 == 2) {
            printf("Student registration aborted\n");
        }
        else {
            printf("Invalid option. Try again\n");
        }
    }
    else {
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

void viewAlldetails(){
    viewmaledetails();
    viewfemaledetails();
}
void searchstudentdetails(int id) {
    printf("\nEnter student registration number: ");
    scanf("%d", &id);
    FILE* maleFile = fopen("maledetails.txt", "r");
    FILE* femaleFile = fopen("femaledetails.txt", "r");

    if (maleFile != NULL && femaleFile != NULL) {
        char line[256];
        int found = 0;
        
        // Search in male details file
        while (fgets(line, sizeof(line), maleFile)) {
            int regNo;
            sscanf(line, "%d", &regNo);
            if (regNo == id) {
                printf("\nSearch result:\n");
                printf("-----------------------------------------------------------\n");
                printf("%s", line);
                printf("-----------------------------------------------------------\n");
                found = 1;
                break;
            }
        }
        
        // If not found in male details file, search in female details file
        if (!found) {
            while (fgets(line, sizeof(line), femaleFile)) {
                int regNo;
                sscanf(line, "%d", &regNo);
                if (regNo == id) {
                    printf("\nSearch result:\n");
                    printf("-----------------------------------------------------------\n");
                    printf("%s", line);
                    printf("-----------------------------------------------------------\n");
                    found = 1;
                    break;
                }
            }
        }
        
        fclose(maleFile);
        fclose(femaleFile);

        if (!found) {
            printf("Student with ID %d not found in any details file\n", id);
        }
    } else {
        printf("Error opening the details file(s)\n");
        return;
    }
}


void deleteStudentRecord(int id) {
    printf("Enter student registration number: ");
    scanf("%d", &id);
    FILE* maleFile = fopen("maledetails.txt", "r");
    FILE* femaleFile = fopen("femaledetails.txt", "r");

    if (maleFile != NULL && femaleFile != NULL) {
        char line[256];
        int found = 0;

        // Search in male details file
        FILE* tempMaleFile = fopen("temp_male.txt", "w");
        if (tempMaleFile == NULL) {
            printf("Error creating temporary file for male details\n");
            fclose(maleFile);
            fclose(femaleFile);
            return;
        }

        while (fgets(line, sizeof(line), maleFile)) {
            int regNo;
            sscanf(line, "%d", &regNo);
            if (regNo != id) {
                fprintf(tempMaleFile, "%s", line);
            } else {
                found = 1;
            }
        }

        fclose(tempMaleFile);
        fclose(maleFile);

        // If not found in male details file, search in female details file
        if (!found) {
            FILE* tempFemaleFile = fopen("temp_female.txt", "w");
            if (tempFemaleFile == NULL) {
                printf("Error creating temporary file for female details\n");
                fclose(femaleFile);
                return;
            }

            while (fgets(line, sizeof(line), femaleFile)) {
                int regNo;
                sscanf(line, "%d", &regNo);
                if (regNo != id) {
                    fprintf(tempFemaleFile, "%s", line);
                } else {
                    found = 1;
                }
            }

            fclose(tempFemaleFile);
            fclose(femaleFile);

            if (found) {
                if (remove("femaledetails.txt") == 0 && rename("temp_female.txt", "femaledetails.txt") == 0) {
                    printf("Student with ID %d deleted successfully from female details\n", id);
                } else {
                    printf("Error deleting student from female details\n");
                }
            } else {
                printf("Student with ID %d not found in any details file\n", id);
                remove("temp_female.txt");
            }
        } else {
            fclose(femaleFile);

            if (found) {
                if (remove("maledetails.txt") == 0 && rename("temp_male.txt", "maledetails.txt") == 0) {
                    printf("Student with ID %d deleted successfully from male details\n", id);
                } else {
                    printf("Error deleting student from male details\n");
                }
            } else {
                printf("Student with ID %d not found in any details file\n", id);
                remove("temp_male.txt");
            }
        }
    } else {
        printf("Error opening the details file(s)\n");
        return;
    }
}





void editRecords(char* fileName) {
    int reg, option;
    struct Student student;
    char tempFileName[] = "temp.txt";

    printf("Which detail do you want to edit?\n\n");
    printf("1. Registration number\n");
    printf("2. Name\n");
    printf("3. Date of birth\n");
    printf("4. Nationality\n");
    printf("5. Address\n");
    printf("6. Phone number\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    printf("Enter the regNo of the student: ");
    scanf("%d", &reg);

    FILE* inputFile = fopen(fileName, "r");
    FILE* tempFile = fopen(tempFileName, "w");

    if (inputFile == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

        if (student.regNo == reg) {
            switch (option) {
                case 1:
                    printf("Enter the new regNo: ");
                    scanf("%d", &student.regNo);
                    break;
                case 2:
                    printf("Enter the new name: ");
                    scanf(" %[^\n]%*c", student.name);
                    break;
                case 3:
                    printf("Enter the new date of birth: ");
                    scanf("%d", &student.dob);
                    break;
                case 4:
                    printf("Enter the new nationality: ");
                    scanf(" %[^\n]%*c", student.nationality);
                    break;
                case 5:
                    printf("Enter the new address: ");
                    scanf(" %[^\n]%*c", student.address);
                    break;
                case 6:
                    printf("Enter the new phone number: ");
                    scanf("%d", &student.phone);
                    break;
                default:
                    printf("Invalid option selected.\n");
                    fclose(inputFile);
                    fclose(tempFile);
                    remove(tempFileName);
                    return;
            }

            fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
            printf("Details updated successfully\n");
            found = 1;
        } else {
            fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    if (!found) {
        printf("Student with id %d not found.\n", reg);
    } else {
        remove(fileName);
        rename(tempFileName, fileName);
    }
}

void editStudentRecords() {
    int choice;
    printf("\nWhich set of records do you want to edit?\n");
    printf("1. Male students\n");
    printf("2. Female students\n");
    printf("3. Back to main menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            editRecords("maledetails.txt");
            break;
        case 2:
            editRecords("femaledetails.txt");
            break;
        case 3:
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
}

void studentCount() {
    int maleCount = 0;
    int femaleCount = 0;
    int totalCount = 0;

    FILE* maleFile = fopen("maledetails.txt", "r");
    if (maleFile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), maleFile)) {
            maleCount++;
        }
        fclose(maleFile);
    }

    FILE* femaleFile = fopen("femaledetails.txt", "r");
    if (femaleFile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), femaleFile)) {
            femaleCount++;
        }
        fclose(femaleFile);
    }

    totalCount = maleCount + femaleCount;
    printf("\nCount result\n");
    printf("-----------------------------------------\n");
    printf("Number of registered male students: %d\n", maleCount);
    printf("Number of registered female students: %d\n", femaleCount);
    printf("Total number of registered students: %d\n", totalCount);
    printf("-----------------------------------------\n");
}
