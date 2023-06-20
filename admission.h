#ifndef ADMISSION_H
#define ADMISSION_H

struct Student {
        int regNo;
        char name[100];
        char gender;
        char nationality[50];
        char address[100];
        int phone;
        int dob;
    };

int readNumberFromFile();
void writeNumberToFile(int number);
int generateIncreasingNumber();
void maledetails();
void femaledetails();
void viewmaledetails();
void viewfemaledetails();
void searchmalestudent(int id);
void searchfemalestudent(int id);
void deleteMaleStudentRecord(int id);
void deleteFemaleStudentRecord(int id);

#endif  // ADMISSION_H