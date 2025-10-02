import math
def compute_pi(n):
    sum = 0.0
    pi = 1
    for k in range(1, n, 1):
        sum += pi / ((2.0 * k) + 1)
        pi = -pi
    return sum * 4

def compute_sqrt(x):
    nextnum = 1.0
    last = 1.0
    for k in range (1, 10, 1):
        last = nextnum
        nextnum = 0.5 * (last + x / last)
    return nextnum

def is_prime(n):
    if n <= 1:
        return False
    for k in range(2, n, 1):
        if n % k == 0:
            return False
    return True

def display_primes(n):
    for k in range(2, n + 1, 1):
        if is_prime(k) == True:
            print(k)

def process_scores():

    min_student = ""
    max_student = ""

    min_score = 101
    max_score = -1

    total = 0
    score = 0

    count = 0


    while True:
        user_input = input("Enter student name and score, or q to quit: ").strip()

        if user_input == 'q':
            break

        name_score = user_input.split()

        name = name_score[0]
        score = int(name_score[1])

        if score < min_score:
            min_student = name
            min_score = score

        if score > max_score:
            max_student = name
            max_score = score

        total += score
        
        count = count + 1

    if count > 0:
        avg_score = total / count
        print("Avg score:", avg_score)
        print("Max score:", max_score)
        print("Min score:", min_score)
        print("Max student:", max_student)
        print("Min student:", min_student)
    else:
        print("No scores entered")

def compute_tax(income, status, state):
    tax_rate = 0.0

    if state.lower() == 'i':
        if status == "single":
            if income < 30000:
                tax_rate = 0.2
            else:
                tax_rate = 0.25
        else:
            if income < 50000:
                tax_rate = 0.10
            else:
                tax_rate = 0.15
    else:
        if status == "single":
            if income < 30000:
                tax_rate = 0.17
            else:
                tax_rate = 0.22
        else:
            if income < 50000:
                tax_rate = 0.07
            else:
                tax_rate = 0.12
    
    processed_income = income * tax_rate
    return processed_income

def solve_quadratic(a, b, c):

    if ((b * b) - (4 * a  * c)) >= 0:
        solution1 = (-b + math.sqrt((b * b) - (4 * a * c))) / (2 * a)
        solution2 = (-b - math.sqrt((b * b) - (4 * a * c))) / (2 * a)

        return solution1, solution2
    
    return 0,0

def sort(list):
    k = 0
    l = 0
    for k in range(0, len(list), 1):
        for l in range(k + 1, len(list), 1):
            if list[k] > list[l] :
                temp = list[l]
                list [l] = list[k]
                list[k] = temp
    return list

def id_password(first, last):
    first = first.upper()
    last = last.upper()
    user_id = first[0] + last
    password = first[0] + first[len(first) - 1] + last[0:3]  + str(len(first)) + str(len(last))
    return user_id, password

def file_sort(infile, outfile):
    in_file = open(infile, 'r')
    num_students = int(in_file.readline().strip())

    student_ids = []
    student_names = []
    student_gpas = []    

    for line in in_file:
        student_info = line.strip().split()
        student_ids.append(int(student_info[0]))     
        student_names.append((student_info[1]))
        student_gpas.append(float(student_info[2]))
    in_file.close()

    for k in range(0, num_students, 1):
        for l in range(k + 1, num_students, 1):
            if student_ids[l] < student_ids[k]:

                tempid = student_ids[k]
                student_ids[k] = student_ids[l]
                student_ids[l] = tempid

                tempname = student_names[k]
                student_names[k] = student_names[l]
                student_names[l] = tempname

                tempgpa = student_gpas[k]
                student_gpas[k] = student_gpas[l]
                student_gpas[l] = tempgpa

    out_file = open(outfile, 'w')
    out_file.write(str(num_students) + '\n')

    for k in range(0, num_students, 1):
        out_file.write(str(student_ids[k]) + " " + student_names[k] + " " + str(student_gpas[k]) + "\n")
    out_file.close()
    

while True:
    print ("\nEnter a number 1-10 to pick a program to run:")
    print("1-computing pi")
    print("2-computing square root")
    print("3-displaying primes")
    print("4-processing scores")
    print("5-computing tax")
    print("6-solving quadratic")
    print("7-number sorter")
    print("8-id and password")
    print("9-sorting file")
    print("10-student file")
    print("11-quit")
    print("")
    option = int(input("Enter choice: "))
    if option == 1:
        num = int(input("Enter a number to compute pi with: "))
        print("Your value of pi using", num, "is", compute_pi(num))
    elif option == 2:
        num = float(input("Enter a number to find it square root: "))
        print("The square root of", num, "is:", compute_sqrt(num))
    elif option == 3:
        num = int(input("Enter a number to get the primes up to it: "))
        display_primes(num)
    elif option == 4:
        process_scores()
    elif option == 5:
        income = int(input("Enter your income: "))
        status = input("Enter whether your married or single: ")
        state = input("Enter i for in-state or o for out-of-state: ")
        print("Your tax amount is: ", compute_tax(income, status, state))
    elif option == 6:
        print("Enter a, b, and c for ax^2 + bx + c = 0")
        a = float(input("Enter a: "))
        b = float(input("enter b: "))
        c = float(input("enter c: "))
        solution1, solution2 = solve_quadratic(a,b,c)
        print("The answers are", solution1, "and", solution2)
    elif option == 7:
        print("enter numbers to be sorted, enter -1 to end")
        num_list = []
        num = 0
        while True:
           num = int(input())
           if num == -1:
               break
           num_list.append(num)
           sort(num_list)
           i = 0
        while i < len(num_list):
            print(num_list[i], ",", end='')
            i += 1
    elif option == 8:
        print ("Enter your first and last name to be given a username and password")
        first = input("first: ")
        last = input ("last: ")
        id_password(first, last)
    elif option == 9:
        print("Enter the name of your infile and outfile to have students sorted")
        infile = input("infile: ")
        outfile = input("outfile: ")
        file_sort(infile,outfile)
    elif option == 10:
        break

class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width
    
    def getLength(self):
        return self.length
    
    def setLength(self, length):
        self.length = length
    
    def getWidth(self):
        return self.width
    
    def setWidth(self, width):
        self.width = width
    
    def a(self, length, width):
        return self.length * self.width
    
    def __str__(self):
        return str(self.length) + ' ' + str(self.width)

    