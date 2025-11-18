#Write a function sort(list) that sorts a given list of numbers. The function returns
#the sorted list as return value. The given input list remains unchanged. Selection sort must
#be used. Built in sort function cannot be used.

def sort(list):
    for k in range(0, len(list), 1):
        for j in range(k + 1, len(list), 1):
            if list[j] < list[k]:
                temp = list[j]
                list[j] = list[k]
                list[k] = temp
#Write a function that automatically generates the user id and the password for the user.
#The user id and the pass words are based on the user’s last name and first name. The user
#id is the first letter of the first name followed by the last name. The password is the first
#letter of the first name followed the last letter of the first name followed by the first three
#letters of the last name followed by the length of the first name followed by the length of
#the last name. The user may enter the first and last names in lower or upper case letters.
#Both the user id and passwords must be in upper case. For example, if the first name is
#John and the last name is Maxwell then the user id is JMAXWELL and the password is
#JNMAX47. The function id_password(first, last) takes first name and last
#name as inputs and returns user id and password as outputs.


def id_password(first, last):
    userid = (first[0] + last).upper()
    userpassword = (first[0] + first[len(first) - 1] + last[0:3] + str(len(first)) + str(len(last))).upper()
    return userid, userpassword

# Write a function that reads an input file and creates a sorted output file. The function is
# file_sort(infile, outfile). The function takes the file names as parameters.
# The input file contains student information and has the following format. The first line
# contains the number of students in the file. Each subsequent line contains information
# about one student. Each line contains three fields namely student id, name, and gpa in
# that order separated by blank. The student id is a positive integer. The name is a single
# word string. The gpa is a double type value. The function sorts the student information in
# the ascending order of student id. The ordered student information is written to the output
# file. The output file has the same format as the input file. Built in sort function cannot be
# used.

def file_sort(infile, outfile):
    in_file = open(infile, 'r')
    students = int(in_file.readline().strip())

    student_id = []
    student_name = []
    student_gpa = []

    for line in in_file:    
        student_info = line.strip().split()

        student_id = student_id + [student_info[0]]
        student_name = student_name + [student_info[1]]
        student_gpa = student_gpa + [student_info[2]]

    in_file.close()       

    for k in range(0, students, 1):
        for j in range(k + 1, students, 1):
            if int(student_id[j]) < int(student_id[k]):
                temp_id = student_id[j]
                student_id[j] = student_id[k]
                student_id[k] = temp_id

                temp_name = student_name[j]
                student_name[j] = student_name[k]
                student_name[k] = temp_name

                temp_gpa = student_gpa[j]
                student_gpa[j] = student_gpa[k]
                student_gpa[k] = temp_gpa
    
    out_file = open(outfile, 'w')
    out_file.write(str(students) + "\n")

    for k in range (0, students, 1):
        out_file.write(str(student_id[k]) + " " + student_name[k] + " " + str(student_gpa[k]) + "\n")
    
    out_file.close()

class rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width
    
    def getLength(self):
        return self.length
    
    def setLength(self, length):
        self.length = length
    
    def getArea(self):
        return self.length * self.width
    
    def __str__(self):
        return str(self.length) + " " + str(self.width)
    




list = [12,6,3,8,9,1]
list2 = list.copy()
sort(list2)
print(list2)

First = input("Enter your first name: ")
Last = input("Enter your last name: ")
id, password = id_password(First, Last)
print(id, password)

