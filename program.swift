func isPrime(x: Int) -> Bool
{
    //if given number is less than 2, can't be prime
    if (x < 2)
    {
        return false;
    }
    //if it is 2, its prime
    if x == 2 {
        return true;
    }
    //looping from 2 and beyond
    for number in 2...(x - 1) 
    { 
        //if it has a modulo that gives 0, its not prime
        if (x % number == 0)
        {
            return false;
        }
    }
    //if it isn't false, return true
    return true;
}

func displayPrimes(x: Int)
{
    //looping from 1 to number given to only print primes
    for number in 1...(x)
    {
        //if its prime, print it
        if (isPrime(x: number) == true)
        {
            print(number);
        }
    }
}

func tax(income: Int, status: String) -> Double
{
    //defualt tax variable
    var tax_rate = 0.0;
    //if user is single
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
    //if user is married
    else if(status == "married" || status == "MARRIED")
    {
        //and income is less than 50000  
            if(income < 50000)
        {
            //tax rate is 10%
            tax_rate = 0.1;
        }
        else
        {
            //tax rate is 15%
            tax_rate = 0.15;
        }
    }
    //returning the tax rate
    let tax = Double(income) * tax_rate;
    return tax;
}

func quadratic(a: Double, b: Double, c: Double) -> (solution1: Double, solution2: Double)
{
    // if b^2 -4ac is greater than/equal to 0, theres a solution
    if a != 0 && (b * b - 4 * a * c >= 0) 
    {
        // making variables for each solution
        let solution1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
        let solution2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
        // returning answers if there are any
        return (solution1, solution2);
    }
    // if its less than 0, return 0 for each.
    return (0.0, 0.0);
}


//helper charAt function
func charAt(str: String, index: Int) -> Character {
    //creating array of letters
    let letters = Array(str);
    //returning the letter at the index given
    return letters[index];
}

func substring(str: String, start: Int, end: Int) -> String {
    //creating array of letters
    let letters = Array(str);
    //creating empty array of size based on end minus start
    var arr = Array(repeating: Character(" "), count: end - start);
    //looping from 0 to size of end minus start
    var k = 0;
    while (k < (end - start)) {
        //putting the letter at start + k into array
        arr[k] = letters[start + k];
        //incrementing k
        k = k + 1;
    }
    //returning substring
    return String(arr);
}

func createIdPassword(first: String, last: String) -> (String, String)
{
    //creating variable for uppercase of first name
    let firstUpper = first.uppercased();
    //creating variable for uppercase of last name
    let lastUpper = last.uppercased();
    //id is first letter uppercased + uppercase last name
    let id = String(charAt(str: firstUpper, index: 0)) + lastUpper
    //password is first letter of first name uppercase, last letter of first name, first three of last name, and length of names
    let password = String(charAt(str: firstUpper, index: 0)) + String(charAt(str: firstUpper, index: firstUpper.count - 1)) + substring(str: lastUpper, start: 0, end: 3) + String(first.count) + String(last.count)
    //returning both id and password
    return(id, password)
}

func factorial(num: Int) -> Int
{
    //if number is 1 or less, return 1
    if (num <= 1)
    {
        return 1
    }
    else
    {
        //if number > 1, return it times itself - 1 recursively
        return num * factorial(num: num - 1)
    }
}

func sort(nums: [Int]) -> [Int]
{
    //creating temporary array since the original array is immutable
    var tempArr = nums
    //looping from k to length
    var k = 0
    while k < tempArr.count - 1 
    {
        //minimum is number iteration starts on
        var min = k
        var l = k + 1
        //iterator for inner loop
            while l < tempArr.count 
            {
                //if array of l is less than min, min is l
                if tempArr[l] < tempArr[min] 
                {
                    min = l
                }
                //incrementing iterator by 1
                l = l + 1
            }
        //switching values of min and k
        let temp = tempArr[k]
        tempArr[k] = tempArr[min]
        tempArr[min] = temp
        k = k + 1
    }
    return tempArr
}










