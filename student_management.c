#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Program closed.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void addStudent() {
    struct Student s;
    FILE *fp;

    fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    printf("\nEnter roll number: ");
    scanf("%d", &s.rollNo);

    printf("Enter student name: ");
    scanf(" %49[^\n]", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("Student added successfully.\n");
}

void displayStudents() {
    struct Student s;
    FILE *fp;
    int found = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("-----------------------------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        printf("%-10d %-25s %.2f\n", s.rollNo, s.name, s.marks);
        found = 1;
    }

    if (!found) {
        printf("No student records found.\n");
    }

    fclose(fp);
}

void searchStudent() {
    struct Student s;
    FILE *fp;
    int roll, found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.rollNo == roll) {
            printf("\nStudent found.\n");
            printf("Roll No: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

void updateStudent() {
    struct Student s;
    FILE *fp;
    int roll, found = 0;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    fp = fopen(FILE_NAME, "rb+");

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.rollNo == roll) {
            printf("Enter new name: ");
            scanf(" %49[^\n]", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(struct Student), SEEK_CUR);
            fwrite(&s, sizeof(struct Student), 1, fp);

            found = 1;
            printf("Student updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

void deleteStudent() {
    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    fp = fopen(FILE_NAME, "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("Unable to open file.\n");

        if (fp != NULL) {
            fclose(fp);
        }

        if (temp != NULL) {
            fclose(temp);
        }

        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.rollNo == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Student deleted successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}
