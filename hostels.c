#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "hostels.h"
#include "admission.h"

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
    char availability[]="available";
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
    char availability[]="available";
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

//view female hostels
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
    char availability[20] = "available";

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
        fprintf(allocfile, "Student name: %s\nStudent regNo: %d\nHostel room number: %d\nHostel name: %s \n\n", student.name, student.regNo, hostel.roomNo, hostel.hostelName);
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
    char availability[20] = "available";

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
//view allocated male hostels
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

//view allocated female hostels
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



