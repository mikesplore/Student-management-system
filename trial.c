void registerStudentDetails(const char* filename);

void allocatemhostel(struct Student student);
void allocatefhostel(struct Student student);

void registerStudentDetails(const char* filename) {
    struct Student {
        char name[50];
        int dob;
        char nationality[50];
        char address[100];
        int phone;
        int regNo;
    } student;

    printf("Enter your Name: ");
    scanf(" %49[^\n]%*c", student.name);

    printf("Enter your DOB: ");
    scanf("%d", &student.dob);

    printf("Enter your nationality: ");
    scanf(" %49[^\n]%*c", student.nationality);

    printf("Enter your address: ");
    scanf(" %[^\n]%*c", student.address);

    printf("Enter your mobile phone number: ");
    scanf("%d", &student.phone);

    student.regNo = readNumberFromFile();
    writeNumberToFile(student.regNo + 1);

    printf("Do you want to book a hostel?\n");
    printf("1. Yes\n2. No\n");
    printf("Enter an option: ");
    int hostelChoice;
    scanf("%d", &hostelChoice);

    if (hostelChoice == 1) {
        printf("Which hostel would you like to allocate?\n");
        printf("1. Male Hostel\n2. Female Hostel\n");
        printf("Enter an option: ");
        int allocationChoice;
        scanf("%d", &allocationChoice);

        if (allocationChoice == 1) {
            allocatemhostel(student);
        } else if (allocationChoice == 2) {
            allocatefhostel(student);
        } else {
            printf("Invalid hostel allocation choice. Hostel allocation aborted.\n");
        }
    }

    FILE* file = fopen(filename, "a");
    if (file != NULL) {
        printf("\nConfirm the entered details\n");
        printf("-------------------------------------\n");
        printf("Registration number: %d\n", student.regNo);
        printf("Name: %s\n", student.name);
        printf("Date of birth: %d\n", student.dob);
        printf("Nationality: %s\n", student.nationality);
        printf("Address: %s\n", student.address);
        printf("Phone number: %d\n", student.phone);
        printf("-------------------------------------\n");
        printf("Do you want to continue?\n1. Yes\n2. No\nEnter an option: ");
        int option1;
        scanf("%d", &option1);
        if (option1 == 1) {
            fprintf(file, "%d, %s, %d, %s, %s, %d\n", student.regNo, student.name, student.dob, student.nationality, student.address, student.phone);
            fclose(file);
            printf("\n\nDetails captured successfully!\n");
        }
        else if (option1 == 2) {
            printf("Student registration aborted\n");
        }
        else {
            printf("Invalid option. Try again\n");
        }
    }
    else {
        printf("Error opening the file\n");
    }
}

void allocatemhostel(struct Student student) {
    struct Hostel {
        int roomNo;
        char hostelName[50];
        char availability[20];
    } hostel;

    strcpy(hostel.hostelName, "Male Hostel");

    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    // Check if room is already allocated
    if (checkAllocation(-1, roomNumber)) {
        printf("Room with ID %d is already allocated\n", roomNumber);
        return;
    }

    FILE* maleHostelFile = fopen("malehostel.txt", "r+");
    if (maleHostelFile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), maleHostelFile)) {
            sscanf(line, "%d, %[^,], %s", &hostel.roomNo, hostel.hostelName, hostel.availability);
            if (hostel.roomNo == roomNumber && strcmp(hostel.availability, "available") == 0) {
                fseek(maleHostelFile, -strlen(line), SEEK_CUR);
                fprintf(maleHostelFile, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, "allocated");
                found = 1;
                break;
            }
        }
        fclose(maleHostelFile);

        if (!found) {
            printf("Room with ID %d not found or not available\n", roomNumber);
            return;
        }
    } else {
        printf("Error opening the room details file\n");
        return;
    }

    FILE* allocatedRoomsFile = fopen("allocatedmalerooms.txt", "a");
    if (allocatedRoomsFile != NULL) {
        fprintf(allocatedRoomsFile, "Student name: %s\nStudent regNo: %d\nHostel room number: %d\nHostel name: %s\n\n", student.name, student.regNo, hostel.roomNo, hostel.hostelName);
        fclose(allocatedRoomsFile);
        printf("Room allocated successfully\n");
    } else {
        printf("Error opening the allocated room details file\n");
    }
}

void allocatefhostel(struct Student student) {
    struct Hostel {
        int roomNo;
        char hostelName[50];
        char availability[20];
    } hostel;

    strcpy(hostel.hostelName, "Female Hostel");

    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    // Check if room is already allocated
    if (checkAllocation(-1, roomNumber)) {
        printf("Room with ID %d is already allocated\n", roomNumber);
        return;
    }

    FILE* femaleHostelFile = fopen("femalehostel.txt", "r+");
    if (femaleHostelFile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), femaleHostelFile)) {
            sscanf(line, "%d, %[^,], %s", &hostel.roomNo, hostel.hostelName, hostel.availability);
            if (hostel.roomNo == roomNumber && strcmp(hostel.availability, "available") == 0) {
                fseek(femaleHostelFile, -strlen(line), SEEK_CUR);
                fprintf(femaleHostelFile, "%d, %s, %s\n", hostel.roomNo, hostel.hostelName, "allocated");
                found = 1;
                break;
            }
        }
        fclose(femaleHostelFile);

        if (!found) {
            printf("Room with ID %d not found or not available\n", roomNumber);
            return;
        }
    } else {
        printf("Error opening the room details file\n");
        return;
    }

    FILE* allocatedRoomsFile = fopen("allocatedfemalerooms.txt", "a");
    if (allocatedRoomsFile != NULL) {
        fprintf(allocatedRoomsFile, "Student name: %s\nStudent regNo: %d\nHostel room number: %d\nHostel name: %s\n\n%s\n", student.name, student.regNo, hostel.roomNo, hostel.hostelName);
        fclose(allocatedRoomsFile);
        printf("Room allocated successfully\n");
    } else {
        printf("Error opening the allocated room details file\n");
    }
}
