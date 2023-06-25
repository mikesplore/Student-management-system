void edithosteldetails() {
    int num, num1, option;
    char name[100], availability[100];
   

    printf("Which hostel detail do you want to edit?\n");
    printf("1. Hostel room number\n");
    printf("2. Hostel name\n");
    printf("3. Hostel availability\n");
    printf("4. Back to main menu\n");
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg1 = fopen("malehostel.txt", "r");
            FILE* Temp1 = fopen("temp.txt", "w");

            if (reg1 != NULL && Temp1 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg1)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, hostel.availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room Number: ");
                        scanf("%d", &num1);
                        fprintf(Temp1, "%d, %s, %s\n", num1, hostel.hostelName, hostel.availability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp1, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, hostel.availability);
                    }
                }

                fclose(reg1);
                fclose(Temp1);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("malehostel.txt");
                    rename("temp.txt", "malehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 2:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg2 = fopen("malehostel.txt", "r");
            FILE* Temp2 = fopen("temp.txt", "w");

            if (reg2 != NULL && Temp2 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg2)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, hostel.availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room name: ");
                        scanf(" %[^\n]", name);
                        fprintf(Temp2, "%d, %s, %s\n", hostel.roomNo, name, hostel.availability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp2, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, hostel.availability);
                    }
                }

                fclose(reg2);
                fclose(Temp2);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("malehostel.txt");
                    rename("temp.txt", "malehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        case 3:
            printf("Enter the room number you want to edit: ");
            scanf("%d", &num);

            FILE* reg3 = fopen("malehostel.txt", "r");
            FILE* Temp3 = fopen("temp.txt", "w");

            if (reg3 != NULL && Temp3 != NULL) {
                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), reg3)) {
                    sscanf(line, "%d, %[^,], %[^\n]", &hostel.roomNo, hostel.hostelName, hostel.availability);
                    if (hostel.roomNo == num) {
                        printf("Enter the new room availability: ");
                        scanf(" %[^\n]", availability);
                        fprintf(Temp3, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, availability);
                        printf("Details updated successfully\n");
                        found = 1;
                    } else {
                        fprintf(Temp3, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, hostel.availability);
                    }
                }

                fclose(reg3);
                fclose(Temp3);

                if (!found) {
                    printf("Room number %d not found.\n", num);
                } else {
                    remove("malehostel.txt");
                    rename("temp.txt", "malehostel.txt");
                }
            } else {
                printf("Error opening file.\n");
            }
            break;

        default:
            printf("Invalid option\n");
            break;
    }
}