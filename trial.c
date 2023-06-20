void allocatemalehostel() {
    struct Student student;
    struct Hostel hostel;
    char availability[20] = "available";

    int id, roomid;
    printf("Enter student registration number: ");
    scanf("%d", &id);

    FILE* studentfile = fopen("maledetails.txt", "r");
    if (studentfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), studentfile)) {
            sscanf(line, "%d,%[^,]%*c", &student.regNo, student.name);
            if (student.regNo == id) {
                found = 1;
                break;
            }
        }
        fclose(studentfile);

        if (!found) {
            printf("Student with ID %d not found\n", id);
            return;
        }
    } else {
        printf("Error opening the male students' details file\n");
        return;
    }

    printf("Enter room number: ");
    scanf("%d", &roomid);

    FILE* malehostelfile = fopen("malehostel.txt", "r+");
    if (malehostelfile != NULL) {
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), malehostelfile)) {
            sscanf(line, "%d, %s, %s", &hostel.roomNo, hostel.hostelName, availability);
            if (hostel.roomNo == roomid && strcmp(availability, "available") == 0) {
                fseek(malehostelfile, -strlen(line), SEEK_CUR);
                fprintf(malehostelfile, "%d, %s allocated\n", hostel.roomNo, hostel.hostelName);
                found = 1;
                break;
            }
        }
        fclose(malehostelfile);

        if (!found) {
            printf("Room with ID %d not found or not available\n", roomid);
            return;
        }
    } else {
        printf("Error opening the room details file\n");
        return;
    }

    FILE* allocfile = fopen("allocatedmalerooms.txt", "a");
    if (allocfile != NULL) {
        fprintf(allocfile, "Student name: %s\nStudent regNo: %d\nHostel room number: %d\nHostel name: %s \n\n", student.name, student.regNo, hostel.roomNo, hostel.hostelName);
        fclose(allocfile);
        printf("Room allocated successfully\n");
    } else {
        printf("Error opening the allocated room details file\n");
    }
}