 function factors(a)
{
    //creating an empty string
    let word = "";
    //looping up to the given number
    for (var i = 1; i <= a; i++)
    {
        //if it's modulo is 0 or itself, its a factor.
        if(a % i == 0 || a % i == a){
            word = word + i + ",";
        }
    }
    //returning the string of each factor
    return word;
}

function tax(income, status)
{
    //creating a tax rate variable
    tax_rate = 0.0;
    //if the user is single
    if(status == "single" || status == "SINGLE")
    {
        //and income is less than 30000
        if(income < 30000)
        {
            //tax rate is 20%
            tax_rate = 0.2;
        }
        else{
            //tax rate is 25%
            tax_rate = 0.25;
        }
    }
    //if the user is married
    else if(status == "married" || status == "MARRIED")
    {
        //and income is less than 50000
            if(income < 50000)
        {
            //tax rate is 10%
            tax_rate = 0.1;
        }
        else{
            //tax rate is 15%
            tax_rate = 0.15;
        }
    }
    //returning the income post tax
    return income * tax_rate;
}
function stdDev(numbers)
{
    //creating a size variable for averaging
    var size = numbers.length;
    var avg = 0;

    for (let i = 0; i < numbers.length; i++)
    {
        // adding up all numbers for averaging
        avg = avg + numbers[i];
    }
    //updating average to get real size
    avg = avg / size;
    //empty standard deviation variable for later use.
    var std = 0;
    //adding standard deviation for later use
    for (let i = 0; i < numbers.length; i++)
    {
        std  = std + Math.pow((numbers[i] - avg), 2);
    }   
    //returning the standard deviation
    return Math.sqrt(std/size);
}
function createIdPassword(first, last)
{
    //id is first character and last name, in uppercase
    id = (first.charAt(0) + last).toUpperCase();
    //password is first letter, last letter, first three of last name, length of both names, all in uppercase
    password = (first.charAt(0) + first.charAt(first.length - 1) + last.substring(0, 3) + first.length + "" + last.length).toUpperCase();
    //returning it as an array
    var idpass = [id, password];
    return idpass;
}

function removeDuplicates(strings)
        {
            //creating empty array of original arrays length
            var noDuplicates = new Array(strings.length)
            //count variable
            var count = 0;
            for(var i = 0; i < strings.length; i++)
            {
               //setting found to false for each outer iteration
               let found = false;
               //going from 0 to i, so that we only check if the current string has already been found
               for(var j = 0; j < i; j++)
               {
                //if the string is found, don't add
                  if (strings[i] == strings[j]){
                    found = true
                  }
               }
               //if not found
               if (found == false)
               {
                //add to beginning of no duplicates array
                noDuplicates[count] = strings[i]
                //incrementing count
                count++
               }
            }
            //returning array with no duplicates
            return noDuplicates
        }

    class Student
    {
        //constructor for student class
        constructor(name, gpa)
        {
            //setting defaults in constructor
            this.name = name;
            this.gpa = gpa;
        }
        //method that returns name
        getName()
        {
            return this.name;
        }
        //method that sets name based on argument passed.
        setName(name)
        {
            this.name = name;
        }
        //method that returns gpa
        getGpa()
        {
            return this.gpa;
        }
        //method that sets gpa based on argument passed
        setGpa(gpa)
        {
            this.gpa = gpa;
        }
        //returns boolean based on gpa to tell if honors
        isHonors()
        {
            if (this.gpa >= 3){
                return true;
            }
            return false;
        }
    }


