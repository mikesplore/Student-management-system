#include <stdio.h>
#include "functions.h"

int main(){
    int option,id;
    
    do{
       printf("\n\nSTUDENT MANAGEMENT SYSTEM\n");
       printf("Choose one of the following\n");
       printf("1. Register new Student\n");
       printf("2. View Student Details\n");
       printf("3. Search Student\n");
       printf("4. Exit\n");
       printf("Choose an option: ");
    scanf("%d",&option);
    switch(option){
        case 1:
        spdetails();
        break;
        
        case 2:
        viewpdetails();
        break;

        case 3:
        searchByID(id);
        break;

        case 4:
        printf("Thatnk you for using our services!. Exiting...");
        return 0;
        break;

        default:
        printf("Invalid selection.");
        break;
    }
    }while(option !=5);
    return 0;
}