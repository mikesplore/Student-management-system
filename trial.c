
void editStudentRecords(int option) {
    int reg, reg1;
    struct Student student;

    printf("\nWhich detail do you want to edit?\n\n\n");
    printf("1. Registration number\n");
    printf("2. Name\n");
    printf("3. Date of birth\n");
    printf("4. Nationality\n");
    printf("5. Address\n");
    printf("6. Phone number\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    printf("Enter the regNo you want to edit: ");
    scanf("%d", &reg);

    FILE* maleFile = fopen("maledetails.txt", "r+");
    FILE* femaleFile = fopen("femaledetails.txt", "r+");
    int found = 0;

    if (maleFile != NULL && femaleFile != NULL) {
        char line[256];
        FILE* outputFile = NULL;

        // Search in male details file
        while (fgets(line, sizeof(line), maleFile)) {
            sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

            if (student.regNo == reg) {
                found = 1;
                outputFile = maleFile;
                break;
            }
        }

        // Search in female details file if not found in male details file
        if (!found) {
            while (fgets(line, sizeof(line), femaleFile)) {
                sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                if (student.regNo == reg) {
                    found = 1;
                    outputFile = femaleFile;
                    break;
                }
            }
        }

        if (found) {
            switch (option) {
                case 1:
                    printf("Enter the new regNo: ");
                    scanf("%d", &reg1);
                    student.regNo = reg1;
                    break;
                case 2:
                    printf("Enter the new name: ");
                    scanf(" %[^\n]s", student.name);
                    break;
                case 3:
                    printf("Enter the new date of birth: ");
                    scanf("%d", &student.dob);
                    break;
                case 4:
                    printf("Enter the new nationality: ");
                    scanf(" %[^\n]s", student.nationality);
                    break;
                case 5:
                    printf("Enter the new address: ");
                    scanf(" %[^\n]s", student.address);
                    break;
                case 6:
                    printf("Enter the new phone number: ");
                    scanf("%d", &student.phone);
                    break;
                default:
                    printf("Invalid option.\n");
                    break;
            }

            fseek(outputFile, ftell(outputFile) - strlen(line), SEEK_SET);
            fprintf(outputFile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
            fflush(outputFile);

            fclose(maleFile);
            fclose(femaleFile);

            printf("Student details updated successfully.\n");
        } else {
            fclose(maleFile);
            fclose(femaleFile);

            printf("Student with regNo %d not found.\n", reg);
        }
    } else {
        printf("Failed to open files.\n");
    }
}


