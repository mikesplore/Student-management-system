#include <stdio.h>
#include "functions.h"

int main() {
    int option, id, roomid;

    do {
        printf("\n\nSTUDENT MANAGEMENT SYSTEM\n\n");
        printf("Choose one of the following\n");
        printf("1. Register new Student\n");
        printf("2. View Student Details\n");
        printf("3. Search Student\n");
        printf("4. Register male hostel\n");
        printf("5. Register female hostel\n");
        printf("6. View male hostels\n");
        printf("7. View female hostels\n");
        printf("8. Allocate male hostels\n");
        printf("9. Allocate female hostels\n");
        printf("10. Delete student record\n");
        printf("11. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nNEW STUDENT REGISTRATION\n");
                printf("1. Male student registration\n");
                printf("2. Female student registration\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        maledetails();
                        break;

                    case 2:
                        femaledetails();
                        break;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            case 2:
                printf("\nVIEW STUDENT REGISTRATION\n");
                printf("1. Male student registration details\n");
                printf("2. Female student registration details\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        viewmaledetails();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        viewfemaledetails();
                        printf("---------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 3:
                printf("Search student by regNo\n");
                printf("\nVIEW STUDENT REGISTRATION\n");
                printf("1. Male student registration details\n");
                printf("2. Female student registration details\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        printf("Enter student registration number: ");
                        scanf("%d", &id);
                        searchmalestudent(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        printf("Enter student registration number: ");
                        scanf("%d", &id);
                        searchfemalestudent(id);
                        printf("---------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 4:
                printf("\nYou're registering a new Male hostel\n\n");
                printf("---------------------------------------------\n");
                registermaleHostel();
                printf("---------------------------------------------\n");
                break;

            case 5:
                printf("\nYou're registering a new Female hostel\n");
                printf("---------------------------------------------\n");
                registerfemaleHostel();
                printf("---------------------------------------------\n");
                break;

            case 6:
                printf("\nYou're viewing available Male hostels\n");
                printf("---------------------------------------------\n");
                viewmalehostels();
                printf("---------------------------------------------\n");
                break;

            case 7:
                printf("\nYou're viewing available Female hostels\n");
                printf("---------------------------------------------\n");
                viewfemalehostels();
                printf("---------------------------------------------\n");
                break;

            case 8:
                printf("\nALLOCATION OF MALE HOSTEL\n");
                allocatemalehostel();
                break;

            case 9:
                printf("\nALLOCATION OF FEMALE HOSTEL\n");
                allocatefemalehostel();
                break;

            case 10:
                printf("\nDELETE STUDENTS' RECORD\n");
                printf("1. Delete male student registration details\n");
                printf("2. Delete female student registration details\n");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        printf("Enter student registration number: ");
                        scanf("%d", &id);
                        deleteMaleStudentRecord(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        printf("Enter student registration number: ");
                        scanf("%d", &id);
                        deleteFemaleStudentRecord(id);
                        printf("---------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 11:
                printf("\nThank you for using our services. Exiting...\n");
                return 0;

            case 12:
                printf("\nAllocated male hostel\n");
                printf("--------------------------------------------\n");
                allocatedmalestudents();
                printf("--------------------------------------------\n");
                break;

            case 13:
                printf("\nAllocated female hostel\n");
                printf("--------------------------------------------\n");
                allocatedfemalestudents();
                printf("--------------------------------------------\n");
                break;

            default:
                printf("Invalid selection.\n");
                break;
        }
    } while (option != 11);

    return 0;
}