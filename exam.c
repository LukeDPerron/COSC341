/*
Write a function that displays a user id and a password for a user based on the first
name, last name, and year of birth of the user. The user id is the first letter of the first
name followed by the last name. The password is the first three letters of the first name,
followed by the last two digits of the year of birth, followed by the last three letters of the
last name. The function prototype is void id_password(char first[], char
last[], int year). The first and last names are strings of length at least three. The
year is a four digit integer. The function displays the id and password.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void id_password(char first[], char last[], int year){
    char firstthree[4];
    char lastthree[4];
    int i;
    for(i = 0; i < 3; i++){
        firstthree[i] = first[i];
    }
    firstthree[3] = '\0';

    for(i = 0; i < 3; i++){
        lastthree[i] = last[strlen(last) - 3 + i];
    }
    lastthree[3] = '\0';


    printf("%s%02d%s", firstthree, year % 100, lastthree);
}
/*
Write a function that reads an input file and creates a sorted output file. The function
prototype is void file_sort(char *infile, char *outfile). The
function takes the file names as parameters. The input file contains student information
and has the following format. The first line contains the number of students in the file.
Each subsequent line contains information about one student. Each line contains three
fields namely student id, grade, and gpa in that order separated by blanks. The student id
is a positive integer. The grade is a character. The gpa is a double type value. The
function sorts the student information in the ascending order of student id. The ordered
student information is written to the output file. The output file has the same format as
the input file. The function dynamically allocates three arrays and stores the student
information into the arrays. The three arrays are simultaneously sorted. The sorted array
information is written to the output file. The dynamic arrays are freed when the function
completes its work. Structures should not be used
*/
void file_sort(char *infile, char *outfile)
{
    FILE *fp;
    int students;
    fp = fopen(infile, "r");
    fscanf(fp, "%d", &students);
    fgetc(fp);

    int *student_ids;
    student_ids = (int *)malloc(students * sizeof(int));
    char *student_grades;
    student_grades = (char *)malloc(students * sizeof(char));
    double *student_gpas;
    student_gpas = (double *)malloc(students * sizeof(double));


    int i;
    for(i = 0; i < students; i++){
        fscanf(fp, "%d %c %lf", &student_ids[i], &student_grades[i], &student_gpas[i]);
    }
    fclose(fp);

    int j;
    for (i = 0; i < students; i++){
        for (j = i + 1; j < students; j++)
        {
            if (student_ids[j] < student_ids[i])
            {
                int tempid = student_ids[i];
                student_ids[i] = student_ids[j];
                student_ids[j] = tempid;

                char tempgrade = student_grades[i];
                student_grades[i] = student_grades[j];
                student_grades[j] = tempgrade;

                double tempgpa = student_gpas[i];
                student_gpas[i] = student_gpas[j];
                student_gpas[j] = tempgpa;
            }
        }
    }

    FILE *fwrite;
    fwrite = fopen(outfile,"w");
    fprintf(fwrite, "%d\n", students);
    for (i = 0; i < students; i++){
        fprintf(fp, "%d %c %.2f\n", student_ids[i], student_grades[i], student_gpas[i]);
    }
    fclose(fwrite);

    free(student_ids);
    free(student_grades);
    free(student_gpas);


}
int main(){
    // char first[40];
    // char last[40];
    // int year;
    // printf("Enter first name: ");
    // scanf("%s", first);
    // printf("Enter last name: ");
    // scanf("%s", last);
    // printf("enter birth year: ");
    // scanf("%d", &year);
    // id_password(first, last, year);
    file_sort("case9in.txt", "output.txt");
    return 0;
}