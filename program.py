#importing math to use functions
import math
def compute_pi(n):
    #getting sum as we need it for the formula
    sum = 0.0
    #setting pi variable to 1 to switch between negative and positive
    pi = 1
    #going from 0 to user input to get pi amount
    for k in range(0, n, 1):
        #adding fractions to pi
        sum += pi / ((2.0 * k) + 1)
        #reversing sign
        pi = -pi
        #multiplying by 4 to get final answer
    return sum * 4

#defining square root function
def compute_sqrt(x):
    #initializing variables
    nextnum = 1.0
    last = 1.0
    #making 10 guesses to get square root
    for k in range (1, 10, 1):
        #setting last = next to use last and next in equation
        last = nextnum
        #equation for getting square root
        nextnum = 0.5 * (last + x / last)
        #returning the next number
    return nextnum

#function to check if numebr is prime
def is_prime(n):
    #1 and less cant be prime
    if n <= 1:
        #so return false
        return False
    # going from 2 to number user entered and seeing if the number can be modulo'd
    for k in range(2, n, 1):
        if n % k == 0:
            #if can be modulo'd by iteration number, false
            return False
    #if everything else passes, its prime
    return True

def display_primes(n):
    #looping from 2 to n+1 to check all primes in that range
    for k in range(2, n + 1, 1):
        if is_prime(k) == True:
            #printing primes
            print(k)

def process_scores():

    #initializing variables
    min_student = ""
    max_student = ""
    #101 and -1 for impossible scores
    min_score = 101
    max_score = -1
    #total for averaging, score variable for input
    total = 0
    score = 0
    #iteration counter for averaging
    count = 0


    #while true loop for infinite iterations until q
    while True:
        # getting user input
        user_input = input("Enter student name and score, or q to quit: ").strip()
        #if its 1, quit
        if user_input == 'q':
            break
        #splitting name and score into two separate values
        name_score = user_input.split()
        #giving namae and score their own variables
        name = name_score[0]
        score = int(name_score[1])
        #if score is less than min, make it new min and make student new min
        if score < min_score:
            min_student = name
            min_score = score
        #opposite, if score is more than max
        if score > max_score:
            max_student = name
            max_score = score
        #getting total for averaging
        total += score
        #incrementing count in each iteration for averaging
        count = count + 1
    # if statement to check if users entered anything
    if count > 0:
        #getting average score
        avg_score = total / count
        #printing out each thing
        print("Avg score:", avg_score)
        print("Max score:", max_score)
        print("Min score:", min_score)
        print("Max student:", max_student)
        print("Min student:", min_student)
    else:
        #if nothing was entered
        print("No scores entered")

def compute_tax(income, status, state):
    tax_rate = 0.0
    #if user is instate
    if state.lower() == 'i':
        #if user is single
        if status == "single":
            #if income is less than 30000
            if income < 30000:
                #users tax rate is 20%
                tax_rate = 0.2
            #if income is >= 30000
            else:
                #user tax rate is 25%
                tax_rate = 0.25
        #if user is married
        else:
            #if income is less than 50000
            if income < 50000:
                #tax rate is 10%
                tax_rate = 0.10
            #if income > 50000
            else:
                #tax rate is 15%
                tax_rate = 0.15
    #if user is out of state
    else:
        #if user is single
        if status == "single":
            #if income < 30000
            if income < 30000:
                #tax rate is 17%
                tax_rate = 0.17
            #income above 30000
            else:
                #tax rate is 22%
                tax_rate = 0.22
        #if user is married
        else:
            #if income less than 50000
            if income < 50000:
                #tax rate is 17%
                tax_rate = 0.07
            #income above 50000 
            else:
                #tax rate is 12%
                tax_rate = 0.12
    
    #giving user processed income based on income and tax rate
    processed_income = income * tax_rate
    #returning to user
    return processed_income
#defining quadratic solver
def solve_quadratic(a, b, c):
    #if amount is greater than or equal to 0, there are solutions
    if ((b * b) - (4 * a  * c)) >= 0:
        #positive and negative answers to quadratic formula
        solution1 = (-b + math.sqrt((b * b) - (4 * a * c))) / (2 * a)
        solution2 = (-b - math.sqrt((b * b) - (4 * a * c))) / (2 * a)
        #returning solutions
        return solution1, solution2
    #if amount < 0, return two 0's
    return 0,0
#sorting list of user input
def sort(list):
    #initializing iterators
    k = 0
    l = 0
    #k from 0 to length-1
    for k in range(0, len(list), 1):
        #l from k+1 to length-1
        for l in range(k + 1, len(list), 1):
            #if list item at k spot is bigger than l, switch them
            if list[k] > list[l] :
                #temp variable holding list at l
                temp = list[l]
                #list at l now holds item of list at k
                list [l] = list[k]
                #list at k now holds item of list at l held in temp
                list[k] = temp
    #returning sorted list
    return list

def id_password(first, last):
    #setting first and last name to all uppercase
    first = first.upper()
    last = last.upper()
    #user id is first letter of first name plus last name
    user_id = first[0] + last
    #password is first letter, last letter, first three of last, length of last and first name
    password = first[0] + first[len(first) - 1] + last[0:3]  + str(len(first)) + str(len(last))
    #returning id and password to user
    return user_id, password
#defining file sorter
def file_sort(infile, outfile):
    #creating in_file variable that holds file
    in_file = open(infile, 'r')
    #number of students is the first line stripped
    num_students = int(in_file.readline().strip())
    #making arrays for each value in file
    student_ids = []
    student_names = []
    student_gpas = []    
    #for loop that checks each line in the file
    for line in in_file:
        #splitting info into three variables, stripping all whitespace and \n
        student_info = line.strip().split()
        #appending each value to their array
        student_ids.append(int(student_info[0]))     
        student_names.append((student_info[1]))
        student_gpas.append(float(student_info[2]))
    #closing infile since use is done
    in_file.close()

    #selection sorting based on id's
    #k 0 to num_students
    for k in range(0, num_students, 1):
        #k+1 to number of students
        for l in range(k + 1, num_students, 1):
            #if student_id of l is less than k
            if student_ids[l] < student_ids[k]:
                #switch each variable so all student info is switched
                tempid = student_ids[k]
                student_ids[k] = student_ids[l]
                student_ids[l] = tempid

                tempname = student_names[k]
                student_names[k] = student_names[l]
                student_names[l] = tempname

                tempgpa = student_gpas[k]
                student_gpas[k] = student_gpas[l]
                student_gpas[l] = tempgpa
    #making outfile to write to file
    out_file = open(outfile, 'w')
    #writing down number of students plus new line
    out_file.write(str(num_students) + '\n')
    #printing out each students info 
    for k in range(0, num_students, 1):
        out_file.write(str(student_ids[k]) + " " + student_names[k] + " " + str(student_gpas[k]) + "\n")
    #closing outfile
    out_file.close()

#creating class Rectangle    
class Rectangle:
    #defining initiation arguments and values
    def __init__(self, length, width):
        self.length = length
        self.width = width
    #getLength which returns length
    def getLength(self):
        return self.length
    #setLength sets length to what is inputted
    def setLength(self, length):
        self.length = length
    #does the same as previous two with width
    def getWidth(self):
        return self.width
    
    def setWidth(self, width):
        self.width = width
    #returning length * width to get area
    def a(self):
        return self.length * self.width
    #toString function that returns values of properties 
    def __str__(self):
        return str(self.length) + ' ' + str(self.width)
    
#while true for unfinite looping
while True:
    #asking for user input
    print ("\nEnter a number 1-9 to pick a program to run:")
    print("1-computing pi")
    print("2-computing square root")
    print("3-displaying primes")
    print("4-processing scores")
    print("5-computing tax")
    print("6-solving quadratic")
    print("7-number sorter")
    print("8-id and password")
    print("9-sorting file")
    print("10-quit")
    print("")
    #storing input in each option
    option = int(input("Enter choice: "))
    # if user enters 1
    if option == 1:
        #taking user input and getting pi by using formula up to that number
        num = int(input("Enter a number to compute pi with: "))
        #printing approximite pi
        print("Your value of pi using", num, "is", compute_pi(num))
    # if user enters 2
    elif option == 2:
        #taking user input and getting square root of it
        num = float(input("Enter a number to find it square root: "))
        #printing square root
        print("The square root of", num, "is:", compute_sqrt(num))
    # if user enters 3
    elif option == 3:
        #taking user input and getting primes up to that number
        num = int(input("Enter a number to get the primes up to it: "))
        #displaying primes
        display_primes(num)
    # if user enters 4
    elif option == 4:
        #calling process scores function as it doesn't take any input
        process_scores()
    # if user enters 5
    elif option == 5:
        #having user enter income, status, and in or out of state to calculate tax
        income = int(input("Enter your income: "))
        status = input("Enter whether your married or single: ")
        state = input("Enter i for in-state or o for out-of-state: ")
        #printing tax
        print("Your tax amount is: ", compute_tax(income, status, state))
    # if user enters 6
    elif option == 6:
        #getting a, b, and c for quadratic formula
        print("Enter a, b, and c for ax^2 + bx + c = 0")
        a = float(input("Enter a: "))
        b = float(input("enter b: "))
        c = float(input("enter c: "))
        #getting both solutions back in respective variables
        solution1, solution2 = solve_quadratic(a,b,c)
        #printing solutions
        print("The answers are", solution1, "and", solution2)
    # if user enters 7
    elif option == 7:
        #having user enter numbers for sorting
        print("enter numbers to be sorted, enter -1 to end")
        #array to hold numbers
        num_list = []
        num = 0
        #infinite loop to get numbers and appending them to array
        while True:
           num = int(input())
           if num == -1:
               break
           num_list.append(num)
        #sorting list
        sort(num_list)
        #setting i to 0
        i = 0
        #printing list with no newlines
        while i < len(num_list):
            print(num_list[i], ",", end='')
            #incrementing i by 1
            i += 1
    # if user enters 8
    elif option == 8:
        #prompting user for first and last name and storing them in variables
        print ("Enter your first and last name to be given a username and password")
        first = input("first: ")
        last = input ("last: ")
        #putting id and password into variables
        id, password = id_password(first, last)
        #printing them
        print("id:", id)
        print("password:", password)
    # if user enters 9
    elif option == 9:
        #putting name of infile and outfile into variables
        print("Enter the name of your infile and outfile to have students sorted")
        infile = input("infile: ")
        outfile = input("outfile: ")
        #using those variables in file sort
        file_sort(infile,outfile)
    # if user enters 10, break out of loop
    elif option == 10:
        break

#instantiating new rectangle object 
x = Rectangle(5,10)
#printing width and length to show amounts
print("Rectangle width is: ", x.getWidth())
print("Rectangle length is: ", x.getLength())
#printing area to show it works
print("Area is: ", x.a())

#setting new width and lengths
x.setLength(15)
x.setWidth(20)
#reprinting to show changes
print("Rectangle's new width is: ", x.getWidth())
print("Rectangle's new length is: ", x.getLength())
print("new Area is: ", x.a())


    