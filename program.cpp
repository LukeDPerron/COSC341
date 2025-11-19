#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

double compute_pi(int n)
{
    double sum = 0.0;
    int nume = 1;
    // looping until we get to n value
    for (int i = 0; i < n; i++){
        // adding value of 2 times i + 1 for odd numbers to sum constantly until n is reached
        sum += nume / ((2.0 * i) + 1);
    // making numerator opposite of what it is everytime
    nume = -nume;
    }
    // multiplying sum by 4 to get pi
    return sum * 4;
}

void scores()
{
    string input = "";
    string min_student = "";
    string max_student = "";

    int min_score = 101;
    int max_score = -1;

    double total = 0;

    int count = 0;

    int score = 0;

  

    while(true)
    {
        cout << "Enter student name and score, or -1 to quit: ";

        cin >> input;
        if(input == "-1")
        {
            break;
        }
        cin >> score;
        if(score == -1)
        {
            break;
        }

       // if score is less than min, change min to score, and copy the name of the person who got mine to min_student
        if (score < min_score)
        {
            min_student = input;
            min_score = score;
        }
        // if score is greater than max, change max to score, and copy the name of the person who got max to max_student
        if (score > max_score)
        {
            max_student = input;
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
        cout << "Avg score: " << avg_score << "\n";
        cout << "Max penis score: " << max_score << "\n";
        cout << "Min score: " << min_score << "\n";
    }
    // if no scores are entered, tell user.
    else
    {
        cout << "No scores entered \n";
    }
    
}

void file_sort(char *infile, char *outfile)
{
    ifstream fin(infile);

    int students = 0;

    fin >> students;
    int *student_ids = new int [students];
    char *grades = new char [students];
    double *gpa = new double [students];

    for (int i = 0; i < students; i++)
    {
        fin >> student_ids[i] >> grades[i] >> gpa[i];
    }

    fin.close();

    //sorting based on ids
    for (int i = 0; i < students; i++)
    {
        for(int j = i + 1; j < students; j++)
        {
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
    ofstream fout (outfile);

    fout << students << "\n";

    for(int i = 0; i < students; i++)
    {
        fout << student_ids[i] << " " << grades[i] << " " << gpa[i] << "\n";
    }

    fout.close();

}

int main()
{
    // cout << "Enter a number to compute pi with:";
    // int input;
    // cin >> input;
    // cout << "Your value of pi using " << input << " is " << compute_pi(input);

    // scores();
    string input_file;
    string output_file;
    cout << "Enter name of input file: \n";
    cin >> input_file;
    cout << "Enter name of output file: \n";
    cin >> output_file;
    file_sort(&input_file[0], &output_file[0]);

    return 0;
}




    

