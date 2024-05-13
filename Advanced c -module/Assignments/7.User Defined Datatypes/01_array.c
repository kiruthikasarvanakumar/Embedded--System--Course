/*
Name : S.Kiruthika
Date : 02-04-2024
Description : WAP to Implement the student record using array of structures 
Sample input : Enter no.of students : 2
               Enter no.of subjects : 2
               Enter the name of subject 1 : Maths
               Enter the name of subject 2 : Science
             ----------Enter the student datails-------------
               Enter the student Roll no. : 1
               Enter the student 1 name : Nandhu
               Enter Maths mark : 99
               Enter Science mark : 91
             ----------Enter the student datails-------------
               Enter the student Roll no. : 2
               Enter the student 2 name : Bindhu
               Enter Maths mark : 88
               Enter Science mark : 78
                       ----Display Menu----
               1. All student details
               2. Particular student details
               Enter your choice : 2

             ----Menu for Particular student----
               1. Name.
               2. Roll no.
               Enter you choice : 1

Sample output : Enter the name of the student : Nandhu
                Roll No.   Name           Maths         Science       Average       Grade
                1              Nandhu        99               91                95                  A
                Do you want to continue to display(Y/y) : n
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 4
#define MAX_NAME_LENGTH 20

//define a structure 
struct Student {
    int roll_no;
    char name[MAX_NAME_LENGTH];
    int marks[MAX_SUBJECTS];
    float avg;
    char grade;
};

//function to calculate the average and grade of a student
void calculateAverageAndGrade(struct Student *s, int num_subjects) {
    int total_marks = 0;

    //calculate total marks
    for (int i = 0; i < num_subjects; ++i) 
    {
        total_marks += s->marks[i];
    }

    //calculate average
    s->avg = (float)total_marks / num_subjects;

    //grade based on average 
    if (s->avg >= 90) 
    {
        s->grade = 'A';
    } 
    else if (s->avg >= 80) 
    {
        s->grade = 'B';
    } 
    else if (s->avg >= 70) 
    {
        s->grade = 'C';
    } 
    else if (s->avg >= 60) 
    {
        s->grade = 'D';
    } 
    else 
    {
        s->grade = 'F';
    }
}

int main() {
    int num_students, num_subjects;

    //user to enter number of students and subjects
    printf("Enter no.of students: ");
    scanf("%d", &num_students);
    printf("Enter no.of subjects: ");
    scanf("%d", &num_subjects);

    //array to store names of subjects
    char subject_names[MAX_SUBJECTS][MAX_NAME_LENGTH];

    //user to enter names of subjects
    for (int i = 0; i < num_subjects; ++i) 
    {
        printf("Enter the name of subject %d: ", i + 1);
        scanf("%s", subject_names[i]);
    }

    //array to store student details
    struct Student students[MAX_STUDENTS];

    //Input student details
    for (int i = 0; i < num_students; ++i) 
    {
        printf("---------- Enter student %d details ----------\n", i + 1);
        printf("Enter the student Roll no.: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter the student1 name: ");
        scanf("%s", students[i].name);
        for (int j = 0; j < num_subjects; ++j) 
        {
            printf("Enter %s mark : ", subject_names[j]);
            scanf("%d", &students[i].marks[j]);
        }
        calculateAverageAndGrade(&students[i], num_subjects);
    }

    char choice;

    //menu loop
    do {
        printf("----Display Menu----\n");
        printf("1.All Student details\n");
        printf("2.Particular student details\n");
        printf("Enter your choice : ");
        scanf(" %c", &choice);
        printf("\n---- Menu for Particular student ----\n");
        printf("1. Read name\n");
        printf("2. Read roll number\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) 
        {
            case '1': 
            {
                char search_name[MAX_NAME_LENGTH];
                printf("Enter the name of the student : ");
                scanf("%s", search_name);

                // Search for the student by name
                for (int i = 0; i < num_students; ++i) 
                {
                    if (strcmp(students[i].name, search_name) == 0) 
                    {
                        printf("\nRoll No.\tName\t");
                        for (int j = 0; j < num_subjects; ++j) 
                        {
                            printf("%s\t", subject_names[j]);
                        }
                        printf("Average\tGrade\n");
                        printf("%d\t\t%s\t", students[i].roll_no, students[i].name);
                        for (int j = 0; j < num_subjects; ++j) 
                        {
                            printf("%d\t", students[i].marks[j]);
                        }

                        //print average without decimal places
                        printf("%d\t%c\n", (int)students[i].avg, students[i].grade);
                        break;
                    }
                }
                break;
            }
            case '2': 
            {
                int search_roll_no;
                printf("Enter the roll number of the student: ");
                scanf("%d", &search_roll_no);

                // Search for the student by roll number
                for (int i = 0; i < num_students; ++i) 
                {
                    if (students[i].roll_no == search_roll_no) 
                    {
                        printf("Roll No.\tName\t");
                        for (int j = 0; j < num_subjects; ++j) 
                        {
                            printf("%s\t", subject_names[j]);
                        }
                        printf("Average\tGrade\n");
                        printf("%d\t\t%s\t", students[i].roll_no, students[i].name);
                        for (int j = 0; j < num_subjects; ++j) 
                        {
                            printf("%d\t", students[i].marks[j]);
                        }
                        printf("%d\t%c\n", (int)students[i].avg, students[i].grade);
                        break;
                    }
                }
                break;
            }
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue (Y/y): ");
        scanf(" %c", &choice);
    } 
    while (choice == 'Y' || choice == 'y');

    return 0;
}

