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

#endif  // HOSTELS_H