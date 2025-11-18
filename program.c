#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

double compute_pi(int n);

double compute_pi(int n)
{
    double sum = 0.0;
    int nume = 1;
    // looping until we get to n value
    for (int i = 0; i < n; i++)

        // adding value of 2 times i + 1 for odd numbers to sum constantly until n is reached
        sum += nume / ((2.0 * i) + 1);
    // making numerator opposite of what it is everytime
    nume = -nume;
    // multiplying sum by 4 to get pi
    return sum * 4;
}

double compute_sqrt(double x)
{
    // initial number is 1
    double next = 1.0;
    double last = 1.0;

    for (int i = 0; i < 10; i++)
    {
        // setting last to next so we can use last in equation
        last = next;
        // setting next equal to equation until we get sqrt
        next = 0.5 * (next + x / last);
    }
    // returning sqrt
    return next;
}

int is_prime(int n)
{
    // if n is less than or equal to 1 its not prime
    if (n <= 1)
        return 0;
    // if n is moduloed by a number to get 0, it has a factor and isn't prime
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    // if it's not caught by previous if's, it's prime
    return 1;
}

void display_primes(int n)
{
    // starting for loop at 2 so 0 and 1 aren't recognized as prime
    for (int i = 2; i <= n; i++)
    {
        // if prime is true, print it out
        if (is_prime(i) == 1)
        {
            printf("%d ", i);
        }
    }
}

void id_password(char first[], char last[], int year)
{
    // initializing the first and last three characters to nothing
    char firstthree[4] = "";
    char lastthree[4] = "";

    // setting firstthree to the first three of the first string array
    for (int i = 0; i < 3; i++)
    {
        firstthree[i] = first[i];
    }
    firstthree[3] = '\0';
    // Manually setting each of the last three characters since my loop wouldn't work.
    int len = strlen(last);
    // Get third to last letter
    lastthree[0] = last[len - 3];
    // Get second to last letter
    lastthree[1] = last[len - 2];
    // Get last letter
    lastthree[2] = last[len - 1];
    // set the last letter to '\0' to end the string
    lastthree[3] = '\0';
    // printing username as first letter, and last name.
    printf("Username is: %c%s\n", first[0], last);
    // printing password as first three letters, year modulo 100, and %02d to always get last two numbers, and ending with last three letters.
    printf("Password is: %s%02d%s\n", firstthree, year % 100, lastthree);
}

void process_scores()
{
    // quit character
    char quit = 'q';
    // user input
    char input[40] = "";
    // initializing min and max student
    char min_student[40] = "";
    char max_student[40] = "";
    // setting min and max score to unobtainable numbers so the loops always work
    int min_score = 101;
    int max_score = -1;
    // total variable to be added every loop
    double total = 0;
    // counter variable
    int count = 0;
    // score variable for user input
    int score = 0;
    while (1)
    {
        // taking in input for name frist
        printf("Enter student name and score, or q to quit: ");
        scanf("%s", input);
        // if they enter q, break out
        if (tolower(input[0]) == 'q')
        {
            break;
        }
        // taking in the score after so it's not taken after q
        scanf("%d", &score);

        // if score is less than min, change min to score, and copy the name of the person who got mine to min_student
        if (score < min_score)
        {
            strcpy(min_student, input);
            min_score = score;
        }
        // if score is greater than max, change max to score, and copy the name of the person who got max to max_student
        if (score > max_score)
        {
            strcpy(max_student, input);
            max_score = score;
        }
        // increasing total score variable to be divided later.
        total += score;
        // increasing count to use as denominator.
        count++;
    }
    // if there was input, give output of each score
    if (count > 0)
    {
        // average score using total scores divided by the count
        double avg_score = total / count;
        // getting avg score up to two decimals
        printf("Avg score: %.02f\n", avg_score);
        printf("Max score: %d\n", max_score);
        printf("Min score: %d\n", min_score);
        printf("Max student: %s\n", max_student);
        printf("Min student: %s\n", min_student);
    }

    // if no scores are entered, tell user.
    else
    {
        printf("No scores entered");
    }
}

double compute_tax(int income, char *status, char state)
{
    // if income is less than 0, impossible, return -1;
    if (income < 0)
    {
        return -1;
    }

    // make status lowercase so no matter how it's typed, if keyword is used, it'll work.
    for (int i = 0; i < strlen(status); i++)
    {
        status[i] = tolower(status[i]);
    }

    // checking if user entered in keywords given, if not return -1.
    if (strcmp(status, "single") != 0 && strcmp(status, "married") != 0)
    {
        return -1;
    }

    // if the user doesn't enter i or o, invalid, return -1.
    if (tolower(state) != 'i' && tolower(state) != 'o')
    {
        return -1;
    }

    // initializing tax rate variable.
    double tax_rate = 0.0;

    // if the user is in state
    if (tolower(state) == 'i')
    {
        // if the user is single
        if (strcmp(status, "single") == 0)
        {
            // if the income is less than 40000
            if (income < 40000)
            {
                // the users tax rate is 30%
                tax_rate = 0.3;
            }
            // if the income is greater than 40000
            else
            {
                // the users tax rate is 35%
                tax_rate = 0.35;
            }
        }
        // if the user is married
        else
        {
            // if the joint income is greater than 60000
            if (income < 60000)
            {
                // tax rate is 20%
                tax_rate = 0.2;
            }
            else
            {
                // tax rate is 25%
                tax_rate = 0.25;
            }
        }
    }
    // if the user is out of state
    else
    {
        // if the user is single
        if (strcmp(status, "single") == 0)
        {
            // if the income is less than 40000
            if (income < 40000)
            {
                // tax rate is 27%
                tax_rate = 0.27;
            }
            // if the income is greater than 40000
            else
            {
                // tax rate is 35%
                tax_rate = 0.33;
            }
        }
        // if the user is married
        else
        {
            // if the joint income is less than 60000
            if (income < 60000)
            {
                // tax rate is 17%
                tax_rate = 0.17;
            }
            else
            {
                // tax rate is 22%
                tax_rate = 0.22;
            }
        }
    }
    // making a processed income variable and returning that to the user.
    double processed_income = income * tax_rate;
    return processed_income;
}

int quadratic(double a, double b, double c, double *solution1, double *solution2)
{

    // if b^2 -4ac is greater than/equal to 0, theres a solution
    if (((b * b) - (4 * a * c)) >= 0)
    {
        // returning both solutions by using their pointers
        *solution1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
        *solution2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
        // returning true since theres answers
        return 1;
    }
    // if its less than 0, return -1 for each.
    *solution1 = -1;
    *solution2 = -1;
    return 0;
}
void file_count(char *file, int *characters, int *blanks, int *lines)
{
    // creating a FILE variable to read files
    FILE *fp = fopen(file, "r");

    // character variable for each character we're on
    int character;
    // saving last character to \n so if a new line is read, we increase the number of lines
    int last_char = '\n';
    // initializing each amount to 0 since file isn't read
    *characters = 0;
    *blanks = 0;
    *lines = 0;

    // while true
    while (1)
    {   
        // character equals get file pointer
        character = fgetc(fp);
        // if we hit end of file, break out of loop
        if (character == EOF)
            break; // EOF reached, exit the loop

        // if file doesn't end, always increase characters
        (*characters)++;

        // if theres a blank space, increase blanks
        if (character == ' ')
        {
            (*blanks)++;
        }

        // if the character is a new line, increase lines
        if (character == '\n')
        {
            (*lines)++;
        }
        // saving last)char for later check
        last_char = character;
    }

    // If the last character isn't a newline, count the last line
    if ((*characters) > 0 && last_char != '\n')
    {
        (*lines)++;
    }
    // closing file pointer
    fclose(fp);
}

void file_sort(char *infile, char *outfile)
{
    // giving a file to read from
    FILE *fp = fopen(infile, "r");
    // initializing students to 0.
    int students = 0;

    // reading amt of students from the file.
    fscanf(fp, "%d", &students);
    // getting to next line.
    fgetc(fp);

    // dynamically allocating memory by giving amount of bytes needed using students * size
    int *student_ids = (int *)malloc(students * sizeof(int));
    char *grades = (char *)malloc(students * sizeof(char));
    double *gpa = (double *)malloc(students * sizeof(double));

    // reading student data from the file
    for (int i = 0; i < students; i++)
    {
        fscanf(fp, "%d %c %lf", &student_ids[i], &grades[i], &gpa[i]);
    }
    // closing file pointer
    fclose(fp);
    // using selection sort to sort based on ids
    for (int i = 0; i < students; i++)
    {
        // j is one ahead of i each time
        for (int j = i + 1; j < students; j++)
        {
            // if j is less than i, switch all student variables
            if (student_ids[j] < student_ids[i])
            {
                int tempid = student_ids[i];
                student_ids[i] = student_ids[j];
                student_ids[j] = tempid;

                char tempgrade = grades[i];
                grades[i] = grades[j];
                grades[j] = tempgrade;

                double temptgpa = gpa[i];
                gpa[i] = gpa[j];
                gpa[j] = temptgpa;
            }
        }
    }
    // creating an output file to write to
    FILE *fwrite = fopen(outfile, "w");
    // printing to file student amt
    fprintf(fwrite, "%d\n", students);
    for (int i = 0; i < students; i++)
    {
        fprintf(fwrite, "%d %c %.2f\n", student_ids[i], grades[i], gpa[i]);
    }
    // closing the write file pointer.
    fclose(fwrite);

    // freeing the dynamic arrays.
    free(student_ids);
    free(grades);
    free(gpa);
}

typedef struct
{
    char name[20];
    int student_id;
    int age;
    double gpa;
} Student;

void file_student(char *infile)
{

    // creating a FILE variable to read files
    FILE *fp = fopen(infile, "r");
    // initializing students to 0.
    int students = 0;

    // reading amt of students from the file.
    fscanf(fp, "%d", &students);
    // getting character from the file
    fgetc(fp);

    //Dynamically allocating array of Student structs
    Student *student_array = (Student *)malloc(students * sizeof(Student));

    //reading student data
     for (int i = 0; i < students; i++)
    {
        //getting values using dot 
        fscanf(fp, "%s %d %d %lf", student_array[i].name, &student_array[i].student_id, 
               &student_array[i].age, &student_array[i].gpa);
    }
    //closing read file pointer
    fclose(fp);

    //initializing sum
    double sum = 0.0;
    //increasing sum of gpas by adding each student gpa
    for (int i = 0; i < students; i++)
    {
        sum = sum + student_array[i].gpa;
    }
    //avg using the total divided by amount
    double avg = (sum / students);
    //printing the average gpa to two decimals
    printf("Average GPA: %.2f\n", avg);

    //printing students with gpa less than 3.0
     printf("Students with GPA <= 3.0:\n");
    for (int i = 0; i < students; i++)
    {
        //if student[i]'s gpa is less than 3
        if (student_array[i].gpa <= 3.0)
        {
            //print out on its own line
            printf("%s\n", student_array[i].name);
        }
    }

    //selection sort to order students by id
    for (int i = 0; i < students; i++)
    {
        for (int j = i + 1; j < students; j++)
        {
            //if student id is less than previous student id, switch palces.
            if (student_array[j].student_id < student_array[i].student_id)
            {
                // Swap students
                Student temp = student_array[i];
                student_array[i] = student_array[j];
                student_array[j] = temp;
            }
        }
    }
     // Printing the sorted list
    printf("Sorted students: \n");
    for (int i = 0; i < students; i++)
    {
        printf("%s %d %d %.2f\n", student_array[i].name, student_array[i].student_id, 
               student_array[i].age, student_array[i].gpa);
    }

    // Freeing the dynamic array
    free(student_array);
}

int main()
{
    while (1)
    {

        printf("\nEnter a number 1-10 to pick a program to run:\n");
        printf("1-computing pi\n");
        printf("2-computing square root\n");
        printf("3-displaying primes\n");
        printf("4-id and password\n");
        printf("5-processing grades\n");
        printf("6-computing tax\n");
        printf("7-solving quadratic\n");
        printf("8-counting file\n");
        printf("9-sorting file\n");
        printf("10-student file\n");
        printf("11-quit");
        printf("\n");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            //creating num variable
            int num;
            printf("Enter a number to compute pi with:");
            //scanning user input
            scanf("%d", &num);
            //giving user pi
            printf("Your value of pi using %d is: %d", num, compute_pi(num));
            break;
        }
        case 2:
        {
            //creating num variable
            double num;
            //asking for user input
            printf("Enter a number to get the square root");
            //storing input in num
            scanf("%f", &num);
            //getting sqrt of num
            printf("The square root of %f is: %f", num, compute_sqrt(num));
            break;
        }
        case 3:
        {
            //creating num variable
            int num;
            //asking for user input
            printf("Enter a number to have all prime numbers up to it shown: ");
            //storing input in num
            scanf("%d", &num);
            //giving primes up to that number
            printf("The prime numbers up to %d is: ", num);
            display_primes(num);
            break;
        }
        case 4:
        {
            //creating variables for user to use.
            char first[40];
            char last[40];
            int year;
            printf("enter first name:");
            //storing first name in first
            scanf("%s", first);
            //storing last name in last
            printf("enter last name:");
            scanf("%s", last);
            //storing year in year
            printf("enter year:");
            scanf("%d", &year);
            //giving username and password based on user input.
            id_password(first, last, year);
            break;
        }
        case 5:
        {
            //calling process scores function.
            process_scores();
            break;
        }
        case 6:
        {
            //creating variables for user.
            int income;
            char status[10];
            char state;
            printf("Enter your income: ");
            //storing income in income
            scanf("%d", &income);
            printf("Enter whether your married or single: ");
            //storing relationship status in stauts.
            scanf("%s", status);
            printf("enter i for in-state or o for out-of-state: ");
            // storing in or out of state in state variable.
            scanf(" %c", &state);
            //giving user their tax amount.
            printf("Your tax amount is: %.2f\n", compute_tax(income, status, state));
            break;
        }
        case 7: // Solve quadratic equation
        {
            // Getting User Input
            int a, b, c;
            double solution1, solution2;
            //storing a in a
            printf("Enter a: ");
            scanf("%d", &a);
            //storing b in b
            printf("Enter b: ");
            scanf("%d", &b);
            //storing c in c
            printf("Enter c: ");
            scanf("%d", &c);
            //using quadraatic function on a,b,c
            quadratic(a, b, c, &solution1, &solution2);
            //outputting solutions
            printf("The answers are: %f and %f\n", solution1, solution2);
            break;
        }
        case 8:
        {
            //creating variables
            int characters, blanks, lines;
            printf("Enter file name: ");
            char filename[50];
            //taking in filename
            scanf("%s", filename);
            //using file count function to get variable amounts
            file_count(filename, &characters, &blanks, &lines);
            //printing amounts
            printf("Characters: %d\n", characters);
            printf("Blanks: %d\n", blanks);
            printf("Lines: %d\n", lines);
            break;
        }
        case 9:
        {
            //creating variables
            char input_file[50];
            char output_file[50];
            //entering name of input file
            printf("Enter the name of the input file: ");
            scanf("%s", input_file);
            printf("Enter the name of the output file: ");
            scanf("%s", output_file);

            //sorrting based on info in input file and outputtimg to output file
            file_sort(input_file, output_file);
            break;
        }
         case 10: 
            {
                //Getting user input
                char input_file[50];
                printf("Enter the name of the input file: ");
                scanf("%s", input_file);
                //function call
                file_student(input_file);
                break;
            }
            case 11:{
                printf("Thank you for using Lukes first C program :) Have a nice day");
                return 0;
                break;
            }
             default:  // Handle invalid menu choices
                printf("Please try again\n");
        }
    }
}