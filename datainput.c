#include <stdio.h>
#include <string.h>

int main() {
    char name[100], name1[100];  // Use char array for storing the name
    int age, num, option;
    
    printf("Enter your Name: ");
    scanf("%s", name);  // Remove '&' before name as it is already an array

    printf("Enter your age: ");
    scanf("%d", &age);

    FILE* file = fopen("details.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s, %d\n", name, age);  // Remove extra quotation marks
        fclose(file);
        printf("Data saved to file.\n");
    } else {
        printf("Error opening file.\n");
    }

    printf("See results? y/n\n");
    scanf(" %c", &num);  // Read a single character using %c

    if (num == 'y' || num == 'Y') {  // Check for 'y' or 'Y'
        printf("Here are the contents of the file:\n");
        file = fopen("details.txt", "r");  // Reopen the file in read mode
        if (file != NULL) {
            while (fscanf(file, "%[^,], %d%*c", name, &age) != EOF) {
                printf("%s, %d\n", name, age);
            }
            fclose(file);
        } else {
            printf("Error opening the file.\n");
        }
    } else {
        printf("Bye.\n");
    }

    printf("Search data? y/n\n");
    scanf(" %c", &option);  // Read a single character using %c

    if (option == 'y' || option == 'Y') {  // Check for 'y' or 'Y'
        printf("Enter the name: ");
        scanf("%s", name1);
        printf("Here is the searched result:\n");
        file = fopen("details.txt", "r");  // Reopen the file in read mode
        if (file != NULL) {
            int found = 0;  // Flag to indicate if the name is found
            while (fscanf(file, "%[^,], %d%*c", name, &age) != EOF) {
                if (strcmp(name1, name) == 0) {  // Compare names using strcmp()
                    printf("%s, %d\n", name, age);
                    found = 1;
                }
            }
            fclose(file);
            if (!found) {
                printf("Name not found.\n");
            }
        } else {
            printf("Error opening the file.\n");
        }
    } else {
        printf("Bye.\n");
    }

    return 0;
}


/*
Personal Information:

Full Name
Date of Birth
Gender
Nationality
Address
Contact Information (Phone Number, Email)
Identification Information:

Student ID Number
Social Security Number (or equivalent identification number)
Passport or ID Card Number
Academic Information:

School/University Name
Grade/Level/Year of Study
Major/Program of Study
Course Schedule/Subjects
Previous Education History (Schools attended, graduation dates, etc.)
Emergency Contact Information:

Name of Emergency Contact
Relationship to the Student
Phone Number of Emergency Contact
Health and Medical Information:

Medical Conditions (allergies, chronic illnesses, etc.)
Emergency Medical Contact Information
Health Insurance Details
Parent/Guardian Information:

Parent/Guardian Names
Relationship to the Student
Contact Information (Phone Numbers, Email)
Parent/Guardian Occupation
Additional Information:

Extracurricular Activities
Interests/Hobbies
Language Proficiency
Special Needs or Accommodation Requirements*/