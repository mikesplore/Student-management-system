#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "hostels.h"
#include "admission.h"

char availability[20]="available";

//generating hostel number
int readNumberFromFile1() {
    int number = 1;  // Default value if the file doesn't exist

    FILE* file = fopen("hostelnumber.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &number);
        fclose(file);
    }

    return number;
}

void writeNumberToFile1(int number) {
    FILE* file = fopen("hostelnumber.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", number);
        fclose(file);
    }
}

int generateIncreasingNumber1() {
    int number = readNumberFromFile();
    printf("%03d\n", number);

    number++;
    writeNumberToFile1(number);
}

//HOSTEL FUNCTIONS
//Register male hostels
void registermaleHostel(){
    struct Hostel hostel;
    srand(time(NULL));
    hostel.roomNo = readNumberFromFile1();
    writeNumberToFile1(hostel.roomNo + 1);

    printf("The new hostel number is: %d\n",hostel.roomNo);
    printf("Enter hostel name: ");
    scanf(" %s",&hostel.hostelName);
    
    FILE*file=fopen("malehostel.txt","a");
    if(file !=NULL){
        fprintf(file, "%d, %s, %s\n",hostel.roomNo,hostel.hostelName,availability);
        fclose(file);
        printf("Hostel registered successfully!\n");
        }
        
        else{
            printf("Error opening file.\n");
        }
}

//register female hostel
void registerfemaleHostel(){
    struct Hostel hostel;
    srand(time(NULL));
    
    hostel.roomNo = readNumberFromFile1();
    writeNumberToFile1(hostel.roomNo + 1);

    printf("The new hostel number is: %d\n",hostel.roomNo);
    printf("Enter hostel name: ");
    scanf(" %s",&hostel.hostelName);

    FILE*file=fopen("femalehostel.txt","a");
    if(file !=NULL){
        fprintf(file, "%d, %s, %s\n",hostel.roomNo,hostel.hostelName,availability);
        fclose(file);
        printf("Hostel registered successfully!\n");
        }
        
        else{
            printf("Error opening file.\n");
        }
}

//FUNCTIONS TO CHECK AVAILABLE HOSTELS
//view available male hostels
void viewmalehostels() {
    FILE* file = fopen("malehostel.txt", "r");
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

//view available female hostels
void viewfemalehostels() {
    FILE* file = fopen("femalehostel.txt", "r");
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

//function for allocating hostel to students
//allocation of male hostel

int checkAllocation(int regNo, int roomNo) {
    FILE* allocfile = fopen("allocatedmalerooms.txt", "r");
    if (allocfile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), allocfile)) {
            int fileRegNo, fileRoomNo;
            sscanf(line, "Student regNo: %d\nHostel room number: %d", &fileRegNo, &fileRoomNo);
            if (fileRegNo == regNo || fileRoomNo == roomNo) {
                fclose(allocfile);
                return 1;  // Room or student already allocated
            }
        }
        fclose(allocfile);
    }
    return 0;  // Room and student not allocated
}

void allocatemalehostel() {
    struct Student student;
    struct Hostel hostel;
    

    int id, roomid;
    printf("Enter student registration number: ");
    scanf("%d", &id);

    // Check if student has already booked a room
    if (checkAllocation(id, -1)) {
        printf("Student with ID %d has already booked a room\n", id);
        return;
    }

    FILE* studentfile = fopen("maledetails.txt", "r");
    if (studentfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), studentfile)) {
            sscanf(line, "%d,%[^,]%*c", &student.regNo, student.name);
            if (student.regNo == id) {
                found = 1;
                break;
            }
        }
        fclose(studentfile);

        if (!found) {
            printf("Student with ID %d not found\n", id);
            return;
        }
    } else {
        printf("Error opening the male students' details file\n");
        return;
    }

    printf("Enter room number: ");
    scanf("%d", &roomid);

    // Check if room is already allocated
    if (checkAllocation(-1, roomid)) {
        printf("Room with ID %d is already allocated\n", roomid);
        return;
    }

    FILE* malehostelfile = fopen("malehostel.txt", "r+");
    if (malehostelfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), malehostelfile)) {
            sscanf(line, "%d, %s, %s", &hostel.roomNo, hostel.hostelName, availability);
            if (hostel.roomNo == roomid && strcmp(availability, "available") == 0) {
                fseek(malehostelfile, -strlen(line), SEEK_CUR);
                fprintf(malehostelfile, "%d, %s allocated\n", hostel.roomNo, hostel.hostelName);
                found = 1;
                break;
            }
        }
        fclose(malehostelfile);

        if (!found) {
            printf("Room with ID %d not found or not available\n", roomid);
            return;
        }
    } else {
        printf("Error opening the room details file\n");
        return;
    }

    FILE* allocfile = fopen("allocatedmalerooms.txt", "a");
    if (allocfile != NULL) {
        fprintf(allocfile, "Student name: %s\nStudent regNo: %d\nHostel room number: %d\nHostel name: %s\n\n", student.name, student.regNo, hostel.roomNo, hostel.hostelName);
        fclose(allocfile);
        printf("Room allocated successfully\n");
    } else {
        printf("Error opening the allocated room details file\n");
    }
}

//allocate female hostel

void allocatefemalehostel() {
    struct Student student;
    struct Hostel hostel;
    

    int id, roomid;
    printf("Enter student registration number: ");
    scanf("%d", &id);

    FILE* studentfile = fopen("femaledetails.txt", "r");
    if (studentfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), studentfile)) {
            sscanf(line, "%d,%[^,]%*c", &student.regNo, student.name);
            if (student.regNo == id) {
                found = 1;
                break;
            }
        }
        fclose(studentfile);

        if (!found) {
            printf("Student with ID %d not found\n", id);
            return;
        }
    } else {
        printf("Error opening the female students' details file\n");
        return;
    }

    printf("Enter room number: ");
    scanf("%d", &roomid);

    FILE* femalehostelfile = fopen("femalehostel.txt", "r+");
    if (femalehostelfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), femalehostelfile)) {
            sscanf(line, "%d, %s, %s", &hostel.roomNo, hostel.hostelName, availability);
            if (hostel.roomNo == roomid && strcmp(availability, "available") == 0) {
                fseek(femalehostelfile, -strlen(line), SEEK_CUR);
                fprintf(femalehostelfile, "%d, %s allocated\n", hostel.roomNo, hostel.hostelName);
                found = 1;
                break;
            }
        }
        fclose(femalehostelfile);

        if (!found) {
            printf("Room with ID %d not found or not available\n", roomid);
            return;
        }
    } else {
        printf("Error opening the room details file\n");
        return;
    }

    FILE* allocfile = fopen("allocatedfemalerooms.txt", "a");
    if (allocfile != NULL) {
        fprintf(allocfile, "Student name: %s\nStudent regNo: %d\nHostel room number: %d\nHostel name: %s \n\n", student.name, student.regNo, hostel.roomNo, hostel.hostelName);
        fclose(allocfile);
        printf("Room allocated successfully\n");
    } else {
        printf("Error opening the allocated room details file\n");
    }
}

//VIEW ALLOCATED MALE AND FEMALE HOSTELS
//view allocated male students
void allocatedmalestudents() {
    FILE* file = fopen("allocatedmalerooms.txt", "r");
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

//view allocated female students
void allocatedfemalestudents() {
    FILE* file = fopen("allocatedfemalerooms.txt", "r");
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
//check allocated hostels
//allocated male hostels
void allocatedmalerooms() {
    struct Hostel hostel;
    

    FILE* file = fopen("malehostel.txt", "r");

    if (file != NULL) {
        char line[256];
        int found = 0;

        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d, %[^,], %s", &hostel.roomNo, hostel.hostelName, availability);

            if (strcmp(availability, "allocated") == 0) {
                printf("%d, %s\n", hostel.roomNo, hostel.hostelName);
                found = 1;
            }
        }

        fclose(file);

        if (!found) {
            printf("No rooms are allocated for now.\n");
        }
    } else {
        printf("Error opening the male hostel file\n");
    }
}

//allocated female hostels
void allocatedfemalerooms() {
    struct Hostel hostel;
    

    FILE* file = fopen("femalehostel.txt", "r");

    if (file != NULL) {
        char line[256];
        int found = 0;

        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d, %[^,], %s", &hostel.roomNo, hostel.hostelName, availability);

            if (strcmp(availability, "allocated") == 0) {
                printf("%d, %s\n", hostel.roomNo, hostel.hostelName);
                found = 1;
            }
        }

        fclose(file);

        if (!found) {
            printf("No rooms are allocated for now.\n");
        }
    } else {
        printf("Error opening the male hostel file\n");
    }
}

//vacate male hostel
void vacatemalehostel() {
    struct Hostel hostel;
    int roomid;
    printf("Enter room number to vacate: ");
    scanf("%d", &roomid);

    // Update room availability in malehostel.txt
    FILE* malehostelfile = fopen("malehostel.txt", "r+");
    if (malehostelfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), malehostelfile)) {
            sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
            if (hostel.roomNo == roomid && strcmp(availability, "allocated") == 0) {
                fseek(malehostelfile, -strlen(line), SEEK_CUR);
                fprintf(malehostelfile, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, "available");
                found = 1;
                break;
            }
        }
        fclose(malehostelfile);

        if (!found) {
            printf("Room with ID %d not found or not allocated\n", roomid);
            return;
        }
    } else {
        printf("Error opening the room details file\n");
        return;
    }

    // Delete allocation records from allocatedmalerooms.txt
    FILE* allocfile = fopen("allocatedmalerooms.txt", "r");
    if (allocfile != NULL) {
        FILE* temp = fopen("temp.txt", "w");  // Temporary file to write updated records
        if (temp != NULL) {
            char line[256];
            int found = 0;
            while (fgets(line, sizeof(line), allocfile)) {
                int tempRoomNo;
                sscanf(line, "Hostel room number: %d", &tempRoomNo);
                if (tempRoomNo != roomid) {
                    fputs(line, temp);  // Write the record to temporary file
                } else {
                    found = 1;
                }
            }
            fclose(temp);
            fclose(allocfile);

            if (!found) {
                printf("No allocation records found for room with ID %d\n", roomid);
                remove("temp.txt");  // Delete the temporary file
                return;
            }

            remove("allocatedmalerooms.txt");        // Delete the original allocation file
            rename("temp.txt", "allocatedmalerooms.txt");  // Rename the temporary file to the original filename
            printf("Room vacation successful\n");
        } else {
            fclose(allocfile);
            printf("Error creating temporary file\n");
        }
    } else {
        printf("Error opening the allocated room details file\n");
    }
}

//vacate female hostel
void vacatefemalehostel() {
    struct Hostel hostel;
    int roomid;
    printf("Enter room number to vacate: ");
    scanf("%d", &roomid);

    // Update room availability in femalehostel.txt
    FILE* malehostelfile = fopen("femalehostel.txt", "r+");
    if (malehostelfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), malehostelfile)) {
            sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
            if (hostel.roomNo == roomid && strcmp(availability, "allocated") == 0) {
                fseek(malehostelfile, -strlen(line), SEEK_CUR);
                fprintf(malehostelfile, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, "available");
                found = 1;
                break;
            }
        }
        fclose(malehostelfile);

        if (!found) {
            printf("Room with ID %d not found or not allocated\n", roomid);
            return;
        }
    } else {
        printf("Error opening the room details file\n");
        return;
    }

    // Delete allocation records from allocatedfemalerooms.txt
    FILE* allocfile = fopen("allocatedfemalerooms.txt", "r");
    if (allocfile != NULL) {
        FILE* temp = fopen("temp.txt", "w");  // Temporary file to write updated records
        if (temp != NULL) {
            char line[256];
            int found = 0;
            while (fgets(line, sizeof(line), allocfile)) {
                int tempRoomNo;
                sscanf(line, "Hostel room number: %d", &tempRoomNo);
                if (tempRoomNo != roomid) {
                    fputs(line, temp);  // Write the record to temporary file
                } else {
                    found = 1;
                }
            }
            fclose(temp);
            fclose(allocfile);

            if (!found) {
                printf("No allocation records found for room with ID %d\n", roomid);
                remove("temp.txt");  // Delete the temporary file
                return;
            }

            remove("allocatedfemalerooms.txt");        // Delete the original allocation file
            rename("temp.txt", "allocatedfemalerooms.txt");  // Rename the temporary file to the original filename
            printf("Room vacation successful\n");
        } else {
            fclose(allocfile);
            printf("Error creating temporary file\n");
        }
    } else {
        printf("Error opening the allocated room details file\n");
    }
}

//edithosteldetails
void editmalehosteldetails(){
int num,num1,option;
char avail[100],name[100];
struct Hostel hostel;
printf("Which hostel detail do you want to edit?\n");
    printf("1. Hostel room number\n");
    printf("2. Hostel name\n");
    printf("3. Hostel availability\n");
    printf("4. Back to main menu\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg1 = fopen("malehostel.txt", "r");
            FILE* Temp1 = fopen("temp.txt", "w");

            if (reg1 != NULL && Temp1 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg1)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room Number: ");
                        scanf("%d", &num1);
                        fprintf(Temp1, "%d, %s, %s\n", num1, hostel.hostelName, availability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp1, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, availability);
                    }
                }

                fclose(reg1);
                fclose(Temp1);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("malehostel.txt");
                    rename("temp.txt", "malehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 2:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg2 = fopen("malehostel.txt", "r");
            FILE* Temp2 = fopen("temp.txt", "w");

            if (reg2 != NULL && Temp2 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg2)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room name: ");
                        scanf(" %[^\n]", name);
                        fprintf(Temp2, "%d, %s, %s\n", hostel.roomNo, name, availability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp2, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, availability);
                    }
                }

                fclose(reg2);
                fclose(Temp2);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("malehostel.txt");
                    rename("temp.txt", "malehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 3:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg3 = fopen("malehostel.txt", "r");
            FILE* Temp3 = fopen("temp.txt", "w");

            if (reg3 != NULL && Temp3 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg3)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room availability: ");
                        scanf(" %[^\n]", avail);
                        fprintf(Temp3, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, avail);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp3, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, availability);
                    }
                }

                fclose(reg3);
                fclose(Temp3);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("malehostel.txt");
                    rename("temp.txt", "malehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        default:
            printf("Main menu...\n");
            break;
    }
}

//editfemalehostel
void editfemalehosteldetails(){
int num,num1,option;
char avail[100],name[100];
struct Hostel hostel;
printf("Which hostel detail do you want to edit?\n");
    printf("1. Hostel room number\n");
    printf("2. Hostel name\n");
    printf("3. Hostel availability\n");
    printf("4. Back to main menu\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg1 = fopen("femalehostel.txt", "r");
            FILE* Temp1 = fopen("temp.txt", "w");

            if (reg1 != NULL && Temp1 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg1)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room Number: ");
                        scanf("%d", &num1);
                        fprintf(Temp1, "%d, %s, %s\n", num1, hostel.hostelName, availability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp1, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, availability);
                    }
                }

                fclose(reg1);
                fclose(Temp1);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("femalehostel.txt");
                    rename("temp.txt", "femalehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 2:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg2 = fopen("femalehostel.txt", "r");
            FILE* Temp2 = fopen("temp.txt", "w");

            if (reg2 != NULL && Temp2 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg2)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room name: ");
                        scanf(" %[^\n]", name);
                        fprintf(Temp2, "%d, %s, %s\n", hostel.roomNo, name, availability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp2, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, availability);
                    }
                }

                fclose(reg2);
                fclose(Temp2);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("femalehostel.txt");
                    rename("temp.txt", "femalehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 3:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg3 = fopen("femalehostel.txt", "r");
            FILE* Temp3 = fopen("temp.txt", "w");

            if (reg3 != NULL && Temp3 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg3)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room availability: ");
                        scanf(" %[^\n]", avail);
                        fprintf(Temp3, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, avail);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp3, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, availability);
                    }
                }

                fclose(reg3);
                fclose(Temp3);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("femalehostel.txt");
                    rename("temp.txt", "femalehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        default:
            printf("Main menu...\n");
            break;
    }
}

void deleteHostelRecord() {
    int hnum;
    printf("Enter hostel Room number to delete: ");
    scanf("%d", &hnum);

    // Delete record from male hostel file
    FILE* maleFile = fopen("malehostel.txt", "r");
    if (maleFile != NULL) {
        FILE* maleTempFile = fopen("maletemp.txt", "w");
        if (maleTempFile != NULL) {
            char line[256];
            int found = 0;
            while (fgets(line, sizeof(line), maleFile)) {
                int regNo;
                sscanf(line, "%d", &regNo);
                if (regNo != hnum) {
                    fprintf(maleTempFile, "%s", line);
                } else {
                    found = 1;
                }
            }
            fclose(maleTempFile);
            fclose(maleFile);

            if (found) {
                remove("malehostel.txt");
                rename("maletemp.txt", "malehostel.txt");
                printf("Hostel with Room number %d deleted successfully from male hostel\n", hnum);
            } else {
                printf("Room number %d not found in male hostel\n", hnum);
                remove("maletemp.txt");
            }
        } else {
            printf("Error creating temporary file for male hostel\n");
            fclose(maleFile);
        }
    } else {
        printf("Error opening the male hostel file\n");
    }

    // Delete record from female hostel file
    FILE* femaleFile = fopen("femalehostel.txt", "r");
    if (femaleFile != NULL) {
        FILE* femaleTempFile = fopen("femaletemp.txt", "w");
        if (femaleTempFile != NULL) {
            char line[256];
            int found = 0;
            while (fgets(line, sizeof(line), femaleFile)) {
                int regNo;
                sscanf(line, "%d", &regNo);
                if (regNo != hnum) {
                    fprintf(femaleTempFile, "%s", line);
                } else {
                    found = 1;
                }
            }
            fclose(femaleTempFile);
            fclose(femaleFile);

            if (found) {
                remove("femalehostel.txt");
                rename("femaletemp.txt", "femalehostel.txt");
                printf("Hostel with Room number %d deleted successfully from female hostel\n", hnum);
            } else {
                printf("Room number %d not found in female hostel\n", hnum);
                remove("femaletemp.txt");
            }
        } else {
            printf("Error creating temporary file for female hostel\n");
            fclose(femaleFile);
        }
    } else {
        printf("Error opening the female hostel file\n");
    }
}


int checkAvailability(int roomNo, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            struct Hostel hostel;
            sscanf(line, "%d, %[^,], %s", &hostel.roomNo, hostel.hostelName, availability);
            if (hostel.roomNo == roomNo && strcmp(availability, "available") == 0) {
                fclose(file);
                return 1;
            }
        }
        fclose(file);
    }
    return 0;
}

