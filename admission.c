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


void editmalerecords() {
    int reg, reg1, dob, option, phone;
    char name[100], nationality[100], address[100];
    struct Student student;

    printf("\nWhich detail do you want to edit?\n\n\n");
    printf("1. Registration number\n");
    printf("2. Name\n");
    printf("3. Date of birth\n");
    printf("4. Nationality\n");
    printf("5. Address\n");
    printf("6. Phone number\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the regNo you want to edit: ");
            scanf("%d", &reg);

            FILE* regfile = fopen("maledetails.txt", "r");
            FILE* tempFile = fopen("temp.txt", "w");

            if (regfile != NULL && tempFile != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), regfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new regNo: ");
                        scanf("%d", &reg1);
                        fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", reg1, student.name, student.dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(regfile);
                fclose(tempFile);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("maledetails.txt");
                    rename("temp.txt", "maledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 2:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* namefile = fopen("maledetails.txt", "r");
            FILE* tempFile1 = fopen("temp.txt", "w");

            if (namefile != NULL && tempFile1 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), namefile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new name: ");
                        scanf(" %[^\n]%*c", name);
                        fprintf(tempFile1, "%d, %s, %d, %s, %s, %d\n", student.regNo, name, student.dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile1, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(namefile);
                fclose(tempFile1);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("maledetails.txt");
                    rename("temp.txt", "maledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 3:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* dobfile = fopen("maledetails.txt", "r");
            FILE* tempFile2 = fopen("temp.txt", "w");

            if (dobfile != NULL && tempFile2 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), dobfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new date of birth: ");
                        scanf("%d", &dob);
                        fprintf(tempFile2, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile2, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(dobfile);
                fclose(tempFile2);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("maledetails.txt");
                    rename("temp.txt", "maledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 4:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* natfile = fopen("maledetails.txt", "r");
            FILE* tempFile3 = fopen("temp.txt", "w");

            if (natfile != NULL && tempFile3 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), natfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new nationality: ");
                        scanf(" %[^\n]%*c", nationality);
                        fprintf(tempFile3, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile3, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(natfile);
                fclose(tempFile3);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("maledetails.txt");
                    rename("temp.txt", "maledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 5:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* addrfile = fopen("maledetails.txt", "r");
            FILE* tempFile5 = fopen("temp.txt", "w");

            if (addrfile != NULL && tempFile5 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), addrfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new address: ");
                        scanf(" %[^\n]%*c", address);
                        fprintf(tempFile5, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile5, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(addrfile);
                fclose(tempFile5);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("maledetails.txt");
                    rename("temp.txt", "maledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 6:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* phonefile = fopen("maledetails.txt", "r");
            FILE* tempFile4 = fopen("temp.txt", "w");

            if (phonefile != NULL && tempFile4 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), phonefile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new phone number: ");
                        scanf("%d", &phone);
                        fprintf(tempFile4, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile4, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(phonefile);
                fclose(tempFile4);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("maledetails.txt");
                    rename("temp.txt", "maledetails.txt");
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

//edit female details
void editfemalerecords() {
    int reg, reg1, dob, option, phone;
    char name[100], nationality[100], address[100];
    struct Student student;

    printf("\nWhich detail do you want to edit?\n\n");
    printf("1. Registration number\n");
    printf("2. Name\n");
    printf("3. Date of birth\n");
    printf("4. Nationality\n");
    printf("5. Address\n");
    printf("6. Phone number\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the regNo you want to edit: ");
            scanf("%d", &reg);

            FILE* regfile = fopen("femaledetails.txt", "r");
            FILE* tempFile = fopen("temp.txt", "w");

            if (regfile != NULL && tempFile != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), regfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new regNo: ");
                        scanf("%d", &reg1);
                        fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", reg1, student.name, student.dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(regfile);
                fclose(tempFile);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 2:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* namefile = fopen("femaledetails.txt", "r");
            FILE* tempFile1 = fopen("temp.txt", "w");

            if (namefile != NULL && tempFile1 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), namefile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new name: ");
                        scanf(" %[^\n]%*c", name);
                        fprintf(tempFile1, "%d, %s, %d, %s, %s, %d\n", student.regNo, name, student.dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile1, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(namefile);
                fclose(tempFile1);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 3:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* dobfile = fopen("femaledetails.txt", "r");
            FILE* tempFile2 = fopen("temp.txt", "w");

            if (dobfile != NULL && tempFile2 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), dobfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new date of birth: ");
                        scanf("%d", &dob);
                        fprintf(tempFile2, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile2, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(dobfile);
                fclose(tempFile2);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 4:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* natfile = fopen("femaledetails.txt", "r");
            FILE* tempFile3 = fopen("temp.txt", "w");

            if (natfile != NULL && tempFile3 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), natfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new nationality: ");
                        scanf(" %[^\n]%*c", nationality);
                        fprintf(tempFile3, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile3, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(natfile);
                fclose(tempFile3);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 5:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* addrfile = fopen("femaledetails.txt", "r");
            FILE* tempFile5 = fopen("temp.txt", "w");

            if (addrfile != NULL && tempFile5 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), addrfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new address: ");
                        scanf(" %[^\n]%*c", address);
                        fprintf(tempFile5, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile5, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(addrfile);
                fclose(tempFile5);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 6:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* phonefile = fopen("femaledetails.txt", "r");
            FILE* tempFile4 = fopen("temp.txt", "w");

            if (phonefile != NULL && tempFile4 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), phonefile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new phone number: ");
                        scanf("%d", &phone);
                        fprintf(tempFile4, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile4, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(phonefile);
                fclose(tempFile4);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
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
