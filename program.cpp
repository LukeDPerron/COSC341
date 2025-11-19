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
    //user input
    string input = "";
    //initializing
    string min_student = "";
    string max_student = "";

    int min_score = 101;
    int max_score = -1;

    double total = 0;

    int count = 0;

    int score = 0;

  

    while(true)
    {
        cout << "Enter score, or -1 to quit: ";

        cin >> score;
        if(score == -1)
        {
            break;
        }

       // if score is less than min, change min to score, and copy the name of the person who got mine to min_student
        if (score < min_score)
        {
            min_score = score;
        }
        // if score is greater than max, change max to score, and copy the name of the person who got max to max_student
        if (score > max_score)
        {
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
        // getting avg score 
        cout << "Avg score: " << avg_score << "\n";
        cout << "Max score: " << max_score << "\n";
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
    //getting infile
    ifstream fin(infile);
    //creating students variable
    int students = 0;
    //getting input from file and putting in amount of students
    fin >> students;
    //dynamically allocating arrays for each variable
    int *student_ids = new int [students];
    char *grades = new char [students];
    double *gpa = new double [students];
    //looping through the file and storing the values in respective arrays
    for (int i = 0; i < students; i++)
    {
        fin >> student_ids[i] >> grades[i] >> gpa[i];
    }
    //closing file pointer
    fin.close();

    //sorting based on ids
    for (int i = 0; i < students; i++)
    {
        for(int j = i + 1; j < students; j++)
        {
            //if one id is less than the other, switch all values
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
    //creating file pointer to output file
    ofstream fout (outfile);
    //printing number of students
    fout << students << "\n";
    //printing each value in ascending order
    for(int i = 0; i < students; i++)
    {
        fout << student_ids[i] << " " << grades[i] << " " << gpa[i] << "\n";
    }
    //closing pointer
    fout.close();

}

//triangle class
class Rectangle
{
    //private variables
    private:
        int width;
        int height;
    //public constructors and methods
    public:
    //creating method declerations
        Rectangle();
        Rectangle(int size);
        Rectangle(int width, int height);

        void setWidth(int width);
        void setHeight(int height);

        int getWidth();
        int getHeight();

        int area();
        void display();
};

//constructor with no args setting both to 0
Rectangle::Rectangle()
{
    width = 0;
    height = 0;
}

//constructor with 1 arg setting both to it
Rectangle::Rectangle(int size)
{
    width = size;
    height = size;
}

//constructor with two args setting to respective value
Rectangle::Rectangle(int width, int height)
{
    this->width = width;
    this->height = height;
}
//setting width
void Rectangle::setWidth(int width)
{
    this->width = width;
}
//setting height
void Rectangle::setHeight(int height)
{
    this->height = height;
}
//getting width
int Rectangle::getWidth()
{
    return width;
}
//getting height
int Rectangle::getHeight()
{
    return height;
}
//returning area
int Rectangle::area()
{
    return (width * height);
}
//printing height and width
void Rectangle::display()
{
    cout << "Height: " << height << "\nWidth: " << width;
}

//score class
class Score
{
    //private variavles
    private:
        double *scores;
        int numStudents;
    //public constructors and methods
    public:
    //method decleration
        Score(double inputScores[], int numStudents);
        ~Score(); 

        double average();

        void display();
        
};

//constuctor that creates array of student scores
Score::Score(double inputScores[], int numStudents)
{
    //setting method variable to input
    this->numStudents = numStudents;
    //allocating scores private variable
    scores = new double[numStudents];
    //looping through the given array and putting into private variable
    for(int i = 0; i < numStudents; i++)
    {
        scores[i] = inputScores[i];
    }
}

//destructor
Score::~Score()
{
    delete [] scores;
}

//average method
double Score::average()
{
    //inital average variable
    double average = 0;
    //adding each number to average
    for (int i = 0; i < numStudents; i++)
    {
        average += scores[i];
    }
    //returning average / numStudents to get real average
    return (average / numStudents);
}

void Score::display()
{
    //printing out each score with a space inbetween
    cout << "Scores: ";
    for(int i = 0; i < numStudents; i++)
    {
        cout << scores[i] << " ";
    }
    //newline for style
    cout << "\n";
    //printing out average
    cout << "Average: " << average();
}

int main()
{
    // cout << "Enter a number to compute pi with:";
    // int input;
    // cin >> input;
    // cout << "Your value of pi using " << input << " is " << compute_pi(input);

    // scores();

    // string input_file;
    // string output_file;
    // cout << "Enter name of input file: \n";
    // cin >> input_file;
    // cout << "Enter name of output file: \n";
    // cin >> output_file;
    // file_sort(&input_file[0], &output_file[0]);

    double arr[] = {85.5, 90.0, 78.5, 92.0};
    Score s(arr, 4);

    s.display();

    return 0;
}




    

