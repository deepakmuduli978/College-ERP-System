#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ---------------- STRUCTURES ----------------

struct Student {
    int roll;
    char name[50];
    char department[50];
    int marks;
};

struct Staff {
    int id;
    char name[50];
    char department[50];
};

struct Timetable {
    char course[50];
    char schedule[200];   
};

// ---------------- GLOBAL ARRAYS ----------------

struct Student students[MAX];
struct Staff staff[MAX];
struct Timetable timetable[MAX];

int studentCount = 0;
int staffCount = 0;
int timeCount = 0;
int i,j;

// ---------------- STUDENT FUNCTIONS ----------------

void addStudent() {

    if(studentCount >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    getchar(); 

    printf("Enter Name: ");
    fgets(students[studentCount].name, 50, stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;

    printf("Enter Roll No: ");
    scanf("%d", &students[studentCount].roll);

    getchar();  
    printf("Enter Department: ");
    fgets(students[studentCount].department, 50, stdin);
    students[studentCount].department[strcspn(students[studentCount].department, "\n")] = 0;

    printf("Enter Marks: ");
    scanf("%d", &students[studentCount].marks);

    studentCount++;
    printf("? Student Added Successfully!\n");
}
void displayStudents() {
    printf("\n---- Student List ----\n");
    for(i = 0; i < studentCount; i++) {
        printf("Roll: %d | Name: %s | Dept: %s | Marks: %d\n",
               students[i].roll,
               students[i].name,
               students[i].department,
               students[i].marks);
    }
}

void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    for(i = 0; i < studentCount; i++) {
        if(students[i].roll == roll) {
            for(j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            found = 1;
            printf("? Student Deleted Successfully!\n");
            break;
        }
    }

    if(!found)
        printf("? Student Not Found!\n");
}

// ---------------- STAFF FUNCTIONS ----------------

void addStaff() {
    printf("\nEnter Staff ID: ");
    scanf("%d", &staff[staffCount].id);

    printf("Enter Name: ");
    scanf("%s", staff[staffCount].name);

    printf("Enter Department: ");
    scanf("%s", staff[staffCount].department);

    staffCount++;
    printf("? Staff Added Successfully!\n");
}

void displayStaff() {
    printf("\n---- Staff List ----\n");
    for( i = 0; i < staffCount; i++) {
        printf("ID: %d | Name: %s | Dept: %s\n",
               staff[i].id,
               staff[i].name,
               staff[i].department);
    }
}

// ---------------- TIMETABLE FUNCTIONS ----------------

void addTimetable() {

    if(timeCount >= MAX) {
        printf("Timetable limit reached!\n");
        return;
    }

    getchar(); 

    printf("\nEnter Course Name (Example: MCA): ");
    fgets(timetable[timeCount].course, 50, stdin);
    timetable[timeCount].course[strcspn(timetable[timeCount].course, "\n")] = 0;

    printf("Enter Full Time Table (Example: Java 1PM, CC 2PM, Data Science 4PM): ");
    fgets(timetable[timeCount].schedule, 200, stdin);
    timetable[timeCount].schedule[strcspn(timetable[timeCount].schedule, "\n")] = 0;

    timeCount++;
    printf("? Timetable Added Successfully!\n");
}

void displayTimetable() {
    printf("\n---- Timetable ----\n");
    for(i = 0; i < timeCount; i++) {
        printf("Course: %s\n", timetable[i].course);
        printf("Time Table: %s\n\n", timetable[i].schedule);
    }
}

// ---------------- MAIN MENU ----------------

int main() {
    int choice;

    printf("===== WELCOME TO ERP SYSTEM =====\n");

    while(1) {
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Delete Student");
        printf("\n4. Add Staff");
        printf("\n5. Display Staff");
        printf("\n6. Add Timetable");
        printf("\n7. Display Timetable");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: deleteStudent(); break;
            case 4: addStaff(); break;
            case 5: displayStaff(); break;
            case 6: addTimetable(); break;
            case 7: displayTimetable(); break;
            case 8: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}
