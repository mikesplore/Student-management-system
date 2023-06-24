void editfemalerecords() {
    int reg, reg1, dob, option, phone;
    char name[100], nationality[100], address[100];
    struct Student student;

    printf("Which detail do you want to edit?\n");
    printf("1. Registration number\n");
    printf("2. Name\n");
    printf("3. Date of birth\n");
    printf("4. Nationality\n");
    printf("5. Address\n");
    printf("6. Phone number\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the regNo you want to edit: ");
            scanf("%d", &reg);

            FILE* regfile = fopen("femaledetails.txt", "r");
            FILE* tempFile = fopen("temp.txt", "w");

            if (regfile != NULL && tempFile != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), regfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new regNo: ");
                        scanf("%d", &reg1);
                        fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", reg1, student.name, student.dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(regfile);
                fclose(tempFile);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 2:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* namefile = fopen("femaledetails.txt", "r");
            FILE* tempFile1 = fopen("temp.txt", "w");

            if (namefile != NULL && tempFile1 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), namefile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new name: ");
                        scanf(" %[^\n]%*c", name);
                        fprintf(tempFile1, "%d, %s, %d, %s, %s, %d\n", student.regNo, name, student.dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile1, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(namefile);
                fclose(tempFile1);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 3:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* dobfile = fopen("femaledetails.txt", "r");
            FILE* tempFile2 = fopen("temp.txt", "w");

            if (dobfile != NULL && tempFile2 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), dobfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new date of birth: ");
                        scanf("%d", &dob);
                        fprintf(tempFile2, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, dob, student.nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile2, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(dobfile);
                fclose(tempFile2);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 4:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* natfile = fopen("femaledetails.txt", "r");
            FILE* tempFile3 = fopen("temp.txt", "w");

            if (natfile != NULL && tempFile3 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), natfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new nationality: ");
                        scanf(" %[^\n]%*c", nationality);
                        fprintf(tempFile3, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, nationality, student.address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile3, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(natfile);
                fclose(tempFile3);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 5:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* addrfile = fopen("femaledetails.txt", "r");
            FILE* tempFile5 = fopen("temp.txt", "w");

            if (addrfile != NULL && tempFile5 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), addrfile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new address: ");
                        scanf(" %[^\n]%*c", address);
                        fprintf(tempFile5, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, address, student.phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile5, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(addrfile);
                fclose(tempFile5);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 6:
            printf("Enter the regNo of the student: ");
            scanf("%d", &reg);

            FILE* phonefile = fopen("femaledetails.txt", "r");
            FILE* tempFile4 = fopen("temp.txt", "w");

            if (phonefile != NULL && tempFile4 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), phonefile)) {
                    sscanf(line, "%d, %[^,], %d, %[^,], %[^,], %d", &student.regNo, student.name, &student.dob, student.nationality, student.address, &student.phone);

                    if (student.regNo == reg) {
                        printf("Enter the new phone number: ");
                        scanf("%d", &phone);
                        fprintf(tempFile4, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, phone);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(tempFile4, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
                    }
                }

                fclose(phonefile);
                fclose(tempFile4);

                if (!found) {
                    printf("Student with id %d not found.\n", reg);
                } else {
                    remove("femaledetails.txt");
                    rename("temp.txt", "femaledetails.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        default:
            printf("Invalid option selected.\n");
            break;
    }
}
