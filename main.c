#include <stdio.h>
#include "admission.h"
#include "hostels.h"
#include "library.h"

 int option, id, roomid,hnum,ibn;

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
            printf("\nSTUDENT MANAGEMENT\n");
            printf("1. Register new student\n");
            printf("2. Search Student\n");
            printf("3. Delete student record\n");
            printf("4. View student details\n");
            printf("5. Edit student details\n");
            printf("6. Check student count\n");
            printf("7. Back to main menu\n");
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
                        registerStudentDetails("maledetails.txt");
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        registerStudentDetails("femaledetails.txt");
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
                searchstudentdetails(id);
                break;
            
            case 3:
            printf("\nDELETE STUDENT\n");
                deleteStudentRecord(id);
                break;

            case 4:
                printf("\nVIEW STUDENT REGISTRATION\n");
                printf("1. View male details\n");
                printf("2. View female details\n");
                printf("3. View all details\n");
                printf("4. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("\nMale registration details\n");
                        printf("--------------------------------------------------\n");
                        viewmaledetails();
                        printf("--------------------------------------------------\n");
                        break;

                    case 2:
                        printf("--------------------------------------------------\n");
                        viewfemaledetails();
                        printf("--------------------------------------------------\n");
                        break;

                    case 3:
                    printf("ALL DETAILS\n");
                        printf("\n--------------------------------------------------\n");
                        viewAlldetails();
                        printf("--------------------------------------------------\n");
                    case 4:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;

            case 5:
            printf("\nEDIT STUDENT RECORDS\n\n");
                editStudentRecords();
                break;

            case 6:
            studentCount();

            case 7:
            continue;

            default:
            printf("Invalid option\n");


            }//end of student management

        break;
            //end of case 1


        case 2:
            printf("\nHOSTEL MANAGEMENT\n\n");
            printf("1. Register new hostel\n");
            printf("2. View hostels\n");
            printf("3. Allocate hostel\n");
            printf("4. View allocated students\n");
            printf("5. View allocated hostels\n");
            printf("6. Vacate hostel\n");
            printf("7. Edit hostel details\n");
            printf("8. Delete hostel detail\n");
            printf("9. Back to main menu\n");
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
                printf("\nEDIT HOSTEL DETAILS\n");
                printf("1. Edit male hostel details\n");
                printf("2. Edit female hostel details\n");
                printf("3. Back to main menu\n");
                printf("Enter an option: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("---------------------------------------------\n");
                        editmalehosteldetails();
                        printf("---------------------------------------------\n");
                        break;

                    case 2:
                        printf("---------------------------------------------\n");
                        editfemalehosteldetails();
                        printf("---------------------------------------------\n");
                        break;

                    case 3:
                        continue;

                    default:
                        printf("Invalid option\n");
                }
                break;
            
            case 8:
                printf("\nDELETE HOSTEL DETAILS\n");
                deleteHostelRecord();

            case 9:
                continue;

            default:
            printf("Invalid option\n");

            }
            break;

        case 3:
        
            printf("Coming soon!");
            break;

        case 4:
        printf("\nLIBRARY MANAGEMENT\n\n");
        printf("1. Register new book\n");
        printf("2. View registered books\n");
        printf("3. Borrow a book\n");
        printf("4. View borrowed books\n");
        printf("5. Return a book\n");
        printf("6. Search a book\n");
        printf("7. Delete book record\n");
        printf("8. Update book record\n");
        printf("9. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
            printf("----------------------------------\n");
                registerBook();
            printf("----------------------------------\n");
                break;
            case 2:
            printf("----------------------------------\n");
                viewRegisteredBooks();
            printf("----------------------------------\n");
                break;
            case 3:
            printf("----------------------------------\n");
                borrowBook();
            printf("----------------------------------\n");
                break;
            case 4:
            printf("----------------------------------\n");
                viewBorrowedBooks();
            printf("----------------------------------\n");
                break;
            case 5:
                returnBook();
                break;
            case 6:
            printf("----------------------------------\n");
                searchBook();
            printf("----------------------------------\n");
                break;
            case 7:
            printf("----------------------------------\n");
                deleteBookRecord();
            printf("----------------------------------\n");
                break;
            case 8:
            printf("----------------------------------\n");
                updateBookRecords();
            printf("----------------------------------\n");
                break;
            case 9:
                printf("Going back to main menu");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
            
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
    } while(option !=10);
    return 0;
                    


    }
