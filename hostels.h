#ifndef HOSTELS_H
#define HOSTELS_H

struct Hostel {
    int roomNo;
    char hostelName[50];
    int bedNo;
    
};

void registermaleHostel();
void registerfemaleHostel();
void viewmalehostels();
void viewfemalehostels();
int checkAllocation(int regNo, int roomNo);
void allocatemalehostel();
void allocatefemalehostel();
void allocatedmalestudents();
void allocatedfemalestudents();
void allocatedmalerooms();
void allocatedmalerooms();
void allocatedfemalerooms(); 
void vacatemalehostel();
void vacatefemalehostel();
void editmalehosteldetails();
void editfemalehosteldetails();
void deletemalehostelrecord(int hnum);
void deletefemalehostelrecord(int hnum);

#endif  // HOSTELS_H