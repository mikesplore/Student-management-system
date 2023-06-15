#include <stdio.h>
#include "functions.h"

int main(){
    int option;
    printf("Choose an option: ");
    scanf("%d",&option);
    switch(option){
        case 1:
        randomNumber();
        break;
        
        case 2:
        pdetails();
        break;

        case 3:
        //function
        break;

        default:
        printf("Invalid selection.");
        break;
    }
    return 0;
}