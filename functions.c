#include<stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int randomNumber(){
    srand(time(NULL));
   int regNo=rand() % 9000+1000;
   printf ("%d",regNo);
   }
void pdetails(){
    char name[100],gender,nationality[50],address[100];
    int dob,phone;
   
    printf("Enter your Name: ");
    scanf(" %99[^\n]", name);

    printf("Enter your DOB: ");
    scanf("%d", &dob);

    printf("Enter your gender: ");
    scanf(" %c", &gender);  

    printf("Enter your nationality: ");
    scanf(" %49[^\n]%*c", nationality);
  
    printf("Enter your address: ");
    scanf(" %[^\n]", address);  // Add a space before %[^\n] to consume the newline character

    printf("Enter your mobile phone number: ");
    scanf("%d", &phone);  // Add & before phone

}
