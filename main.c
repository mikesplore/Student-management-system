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
        printf("4. Register hostel\n");
        printf("5. View hostels\n");
        printf("6. Allocate  hostels\n");
        printf("7. Delete student record\n");
        printf("8. View allocated students\n");
        printf("9. Exit\n");
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
                    printf("---------------------------------------------\n");
                        maledetails();
                    printf("---------------------------------------------\n");
                        break;

                    case 2:
                    printf("---------------------------------------------\n");
                        femaledetails();
                    printf("---------------------------------------------\n");
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
                        searchmalestudent(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        searchfemalestudent(id);
                        printf("---------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 4:
                printf("\nREGISTER HOSTELS\n");
                printf("1. Register male Hostel\n");
                printf("2. Register female Hostel\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        registermaleHostel();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        registerfemaleHostel();
                        printf("---------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 5:
                printf("\nVIEW HOSTELS\n");
                printf("1. View male hostels\n");
                printf("2. View female hostels\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        viewmalehostels();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        viewfemalehostels();
                        printf("---------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 6:
                printf("\nHOSTEL ALLOCATION\n");
                printf("1. Allocate male hostel\n");
                printf("2. Allocate female hostel\n");
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

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 7:
                printf("\nDELETE STUDENTS' RECORD\n");
                printf("1. Delete male student registration details\n");
                printf("2. Delete female student registration details\n");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        deleteMaleStudentRecord(id);
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");                     
                        deleteFemaleStudentRecord(id);
                        printf("---------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid option\n");
                }
                break;


            case 8:
                printf("\nVIEW ALLOCATED STUDENTS\n");
                printf("1. View allocated male students\n");
                printf("2. View allocated female students\n");
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

                    default:
                        printf("Invalid option\n");
                }
                break;
            case 9:
            printf("Thank you for using our services. Exiting...");

            default:
                printf("Invalid selection.\n");
                break;
        }
    } while (option != 9);

    return 0;
}