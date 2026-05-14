#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int studentID;
    char studentName[50];
    char department[30];
    float marks;
} Student;

Student *records;
int totalStudents = 0;

void insertStudentRecord()
{
    int count, i;

    printf("\nEnter number of students to add: ");
    scanf("%d", &count);

    records = realloc(records, (totalStudents + count) * sizeof(Student));

    for(i = totalStudents; i < totalStudents + count; i++)
    {
        printf("\nEnter Student ID: ");
        scanf("%d", &records[i].studentID);

        printf("Enter Student Name: ");
        scanf("%s", records[i].studentName);

        printf("Enter Department: ");
        scanf("%s", records[i].department);

        do
        {
            printf("Enter Marks (0 - 100): ");
            scanf("%f", &records[i].marks);

            if(records[i].marks < 0 || records[i].marks > 100)
            {
                printf("Invalid marks! Please enter again.\n");
            }

        } while(records[i].marks < 0 || records[i].marks > 100);
    }

    totalStudents += count;

    printf("\nStudent record(s) added successfully.\n");
}

void displayAllRecords()
{
    int i;

    if(totalStudents == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for(i = 0; i < totalStudents; i++)
    {
        printf("\nStudent %d", i + 1);
        printf("\nStudent ID   : %d", records[i].studentID);
        printf("\nName         : %s", records[i].studentName);
        printf("\nDepartment   : %s", records[i].department);
        printf("\nMarks        : %.2f\n", records[i].marks);
    }
}

void searchStudentRecord()
{
    int choice, id, i, found = 0;
    char name[50];

    printf("\nSearch By:");
    printf("\n1. Student ID");
    printf("\n2. Student Name");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter Student ID: ");
        scanf("%d", &id);

        for(i = 0; i < totalStudents; i++)
        {
            if(records[i].studentID == id)
            {
                printf("\nRecord Found");
                printf("\nID          : %d", records[i].studentID);
                printf("\nName        : %s", records[i].studentName);
                printf("\nDepartment  : %s", records[i].department);
                printf("\nMarks       : %.2f\n", records[i].marks);

                found = 1;
                break;
            }
        }
    }
    else if(choice == 2)
    {
        printf("Enter Student Name: ");
        scanf("%s", name);

        for(i = 0; i < totalStudents; i++)
        {
            if(strcmp(records[i].studentName, name) == 0)
            {
                printf("\nRecord Found");
                printf("\nID          : %d", records[i].studentID);
                printf("\nName        : %s", records[i].studentName);
                printf("\nDepartment  : %s", records[i].department);
                printf("\nMarks       : %.2f\n", records[i].marks);

                found = 1;
            }
        }
    }

    if(found == 0)
    {
        printf("\nStudent record not found.\n");
    }
}

void removeStudentRecord()
{
    int id, i, j, found = 0;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < totalStudents; i++)
    {
        if(records[i].studentID == id)
        {
            for(j = i; j < totalStudents - 1; j++)
            {
                records[j] = records[j + 1];
            }

            totalStudents--;
            found = 1;

            printf("\nStudent record deleted successfully.\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent record not found.\n");
    }
}

void modifyStudentMarks()
{
    int id, i, found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalStudents; i++)
    {
        if(records[i].studentID == id)
        {
            printf("Enter New Marks: ");
            scanf("%f", &records[i].marks);

            printf("\nMarks updated successfully.\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent record not found.\n");
    }
}

void displayDepartmentWiseRecords()
{
    int i, found = 0;
    char dept[30];

    printf("\nEnter Department Name: ");
    scanf("%s", dept);

    printf("\n====== STUDENTS IN %s DEPARTMENT ======\n", dept);

    for(i = 0; i < totalStudents; i++)
    {
        if(strcmp(records[i].department, dept) == 0)
        {
            printf("\nStudent ID : %d", records[i].studentID);
            printf("\nName       : %s", records[i].studentName);
            printf("\nMarks      : %.2f\n", records[i].marks);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo records found in this department.\n");
    }
}

int main()
{
    int option;

    records = NULL;

    do
    {
        printf("\n\n========== STUDENT RECORD MANAGEMENT SYSTEM ==========");

        printf("\n1. Add Student Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Student Record");
        printf("\n4. Delete Student Record");
        printf("\n5. Update Student Marks");
        printf("\n6. Department Wise Display");
        printf("\n7. Exit");

        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                insertStudentRecord();
                break;

            case 2:
                displayAllRecords();
                break;

            case 3:
                searchStudentRecord();
                break;

            case 4:
                removeStudentRecord();
                break;

            case 5:
                modifyStudentMarks();
                break;

            case 6:
                displayDepartmentWiseRecords();
                break;

            case 7:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid option! Please try again.\n");
        }

    } while(option != 7);

    free(records);

    return 0;
}