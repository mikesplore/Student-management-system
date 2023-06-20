#include <stdio.h>
#include "admission.h"
#include "hostels.h"

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
        printf("6. Allocate hostels\n");
        printf("7. Delete student record\n");
        printf("8. View allocated students\n");
        printf("9. View allocated rooms\n");
        printf("10. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
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

            case 3:
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

            case 4:
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

            case 5:
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

            case 6:
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

            case 7:
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

            case 8:
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

            case 9:
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

            case 10:
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

            default:
                printf("Invalid selection.\n");
                break;
        }
    } while (option != 10);

    return 0;
}