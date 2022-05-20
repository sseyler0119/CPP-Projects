/* Convert decimal number to binary using division algorithm
	SOURCES: Textbook examples, "C++ Programming: Convert Decimal to Binary" 
    www.youtube.com/watch?v=yEYltfCLY3c
*/

#include <iostream>

// struct to hold Division variables used to compute binary result
struct Division
{
    long long quotient = 0;
    long long remainder = 0;
};

// function prototypes
// Function to convert a decimal integer to binary
void decimalToBinary(long long a);
// Function using the division algorithm to find quotient and remainder
Division divisionAlgorithm(long long a);
// input validation helpers
long long readLongInt(const char prompt[]); 

using namespace std;

int main()
{
    long long a = 0;
 
    // run routine 4 times
    for (int i = 0; i < 4; i++)
    {
        // read in an integer from the user
        a = readLongInt("Please enter an integer q, where q > 0: ");
        cout << endl;
       
        // Convert decimal integer 'a' to binary integer
        decimalToBinary(a);
    }
    
    return 0;
}


/* Function to convert a decimal integer 'a' into its binary equivelent
   ** This function uses Algorithm 5.1.1 Decimal to Binary Conversion
        Using Repeated Division by 2 */
void decimalToBinary(long long a)
{
    Division result;
    int i = 0; // iterator
    long long q = a; // passed in decimal value to convert
    long long length = 0; // total length of array after conversion
    long long count = 0; // iterate count to determine array length
    
    // array to hold the remainder, initialized to 64
    //    final length will be the length of the binary integer
    long long r[64]; 

    while (i = 0 || q != 0)
    {
        result = divisionAlgorithm(q); // call divisionAlgorithm, return to result
        r[count] =  result.remainder; // assign returned remainder to binary array
        q = result.quotient; // assign returned quotient to q

        i++;
        count++;
    }

    // print result
    cout << "The binary conversion of " << a << " is: " << endl;
    // output result from LSB to MSB
    for (length = count - 1; length >= 0; length--)
    {
        if (length % 4 == 0) // insert space every 4 bits
        {
            cout << r[length] << " ";
        }
        else
        {
            cout << r[length];
        }
    }
    cout << endl;
}

/* Function utilizing the division algorithm where 'a' is the passed
        in decimal value and  d = 2. The function returns an r value of
        either 0 or 1 and q value to the decimalToBinary function. The returned q 
        value is passed back into the division algorithm as the new 'a' parameter */
Division divisionAlgorithm(long long a)
{
    Division result;
    long long r = 0;
    long long q = 0;

    r = a;

    while (r >= 2)
    {
        r = r - 2;
        q++;
    }
    // return r and q back to the calling function  
    result.remainder = r;
    result.quotient = q; 
        
    return result;
}

// validates that input is an integer > 0
long long readLongInt(const char prompt[])
{
    long long input = 0;
    cout << prompt;
    cin >> input;

    // validate input is only an integer greater than 0
    while ((!cin || input < 1) || cin.peek() == '.')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Input must be an integer > 1, please try again!" << endl;
        cin >> input;
    }
    cin.ignore(100, '\n');

    return input;
}
