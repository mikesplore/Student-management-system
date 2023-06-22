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
//check allocated hostels
//allocated male hostels
void allocatedmalerooms() {
    struct Hostel hostel;
    

    FILE* file = fopen("fmalehostel.txt", "r");

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



#include <stdio.h>
#include "admission.h"
#include "hostels.h"
#include "library.h"

 int option, id, roomid;

int main() {

    printf("\n\nSTUDENT MANAGEMENT SYSTEM\n\n");
    do{
        printf("\nChoose one of the following.\n\n");
        printf("1. Student Management\n");
        printf("2. Hostel Management\n");
        printf("3. Course Application\n");
        printf("4. Library Managenent\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        
        switch(option){ //main switch option

        case 1: //start of student management
            printf("1. Register new student\n");
            printf("2. Search Student\n");
            printf("3. Delete student record\n");
            printf("4. View student details\n");
            printf("5. Back to main menu\n");
            printf("Enter an option: ");
            scanf("%d",&option);
            switch(option){
            case 1:
                printf("\nNEW STUDENT REGISTRATION\n");
                printf("1. Male student registration\n");
                printf("2. Female student registration\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);
    
                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        maledetails();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        femaledetails();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid choice\n");
                }
                break;
            
            case 2:
                printf("\nSEARCH STUDENT\n");
                printf("1. Search male student\n");
                printf("2. Search female student\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("\nSearch result\n");
                        printf("---------------------------------------------\n");
                        searchmalestudent(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("\nSearch result\n");
                        printf("---------------------------------------------\n");
                        searchfemalestudent(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;
            
            case 3:
                printf("\nDELETE STUDENTS' RECORD\n");
                printf("1. Delete male student registration details\n");
                printf("2. Delete female student registration details\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        printf("Enter student ID: ");
                        scanf("%d", &id);
                        deleteMaleStudentRecord(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        printf("Enter student ID: ");
                        scanf("%d", &id);
                        deleteFemaleStudentRecord(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 4:
                printf("\nVIEW STUDENT REGISTRATION\n");
                printf("1. Male student registration details\n");
                printf("2. Female student registration details\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("\nMale registration details\n");
                        printf("---------------------------------------------\n");
                        viewmaledetails();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("\nFemale registration details\n");
                        printf("---------------------------------------------\n");
                        viewfemaledetails();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 5:
                continue;

            default:
            printf("Invalid option\n");


            }//end of student management

        break;
            //end of case 1


        case 2:
            printf("\nHOSTEL MANAGEMENT\n\n");
            printf("choose one of the options\n");
            printf("1. Register new hostel\n");
            printf("2. View hostels\n");
            printf("3. Allocate hostel\n");
            printf("4. View allocated students\n");
            printf("5. View allocated students\n");
            printf("6. Vacate hostel\n");
            printf("7. Back to main menu\n");
            printf("Enter an option: ");
            scanf("%d",&option);

            switch(option){
            case 1:
                printf("\nREGISTER HOSTELS\n");
                printf("1. Register male Hostel\n");
                printf("2. Register female Hostel\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("\nMale hostel registration\n");
                        printf("---------------------------------------------\n");
                        registermaleHostel();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("\nFemale hostel registration\n");
                        printf("---------------------------------------------\n");
                        registerfemaleHostel();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 2:
                printf("\nVIEW HOSTELS\n");
                printf("1. View male hostels\n");
                printf("2. View female hostels\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("\nViewing all male hostels\n");
                        printf("---------------------------------------------\n");
                        viewmalehostels();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("\nViewing all female hostels\n");
                        printf("---------------------------------------------\n");
                        viewfemalehostels();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 3:
                printf("\nHOSTEL ALLOCATION\n");
                printf("1. Allocate male hostel\n");
                printf("2. Allocate female hostel\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        allocatemalehostel();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        allocatefemalehostel();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 4:
                printf("\nVIEW ALLOCATED STUDENTS\n");
                printf("1. View allocated male students\n");
                printf("2. View allocated female students\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        allocatedmalestudents();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        allocatedfemalestudents();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 5:
                printf("\nVIEW ALLOCATED HOSTELS\n");
                printf("1. View allocated male hostels\n");
                printf("2. View allocated female hostels\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        allocatedmalerooms();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        allocatedfemalerooms();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 6:
                printf("\nVACATE HOSTELS\n");
                printf("1. Vacate male hostels\n");
                printf("2. Vacate female hostels\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        vacatemalehostel();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        vacatefemalehostel();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 7:
                continue;

            default:
            printf("Invalid option\n");

            }
            break;

        case 3:
            printf("\nComing soon!\n\n");
            break;

        case 4:
        printf("\nLIBRARY MANAGEMENT\n\n");
         viewbookdetails() ;
        break;

        case 5:
            printf("Are you sure you want to exit?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("Thank you for using our services. Exiting...\n");
                        return 0;

                    case 2:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;



            //default and end of the main switch option
            default:
            printf("Invalid choice.\n");
        }
    } while(option !=5);
    return 0;
                    


}

