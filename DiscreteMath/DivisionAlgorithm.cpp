/* This program calculates the greatest common denominator of two integers using the division algorithm from the text Discrete Mathematics with Applications */

#include <iostream>

// function prototypes

 // calculates and outputs the gcd of two integers x and y
long long gcdFunction(long long x, long long y);

// calculate the quotient, q, and remainder, r using the division algorithm
void divisionAlgorithm(long long x, long long y);

// input validation helpers
long long readLongX(const char prompt[]); 
long long readLongY(const char prompt[]);

using namespace std;

int main()
{
    long long x = 0;
    long long y = 0; 
    cout << "Serena Seyler " << endl;

    // run routine 4 times
    for (int i = 0; i < 4; i++)
    {
        // read in an integer from the user
        x = readLongX("Please enter an integer x, where x > 1: ");
        y = readLongY("Please enter an integer y, where 1 <= y < x: ");
		
        while (!(y < x)) // y must be less than x
        {
            cout << "Input must be < " << x << ", please try again!" << endl;
            y = readLongY("Please enter an integer y, where 1 <= y < x: ");
        }
        cout << "\n x = " << x << " y = " << y << endl;
        cout << "\nThe greatest common divisor of x and y is: " 
            << "GCD(" << x <<',' <<y <<") = " << gcdFunction(x, y) << endl << endl;

        // Calculate and output the quotient and remainder
        divisionAlgorithm(x, y);
    }

    return 0;
}


/* Function to calculate the greatest common divisor of two integers
       x and y where 1 < x <= 2 ^63 and 1 <= y < x 
	** This function uses the Euclidian algorithm 4.10.1 */
long long gcdFunction(long long x, long long y)
{
    long long r = 0; // remainder
    long long q = 0; // quotient

    
	do
	{
		r = x % y; // calculate remainder
		q = x / y; // calculate quotient
		x = y; // pass in y value as x
		y = r; // pass in remainder as y
	} while (r > 0);
	return x;
	
}

/* Function to calculate the quotient 'q'  and remainder 'r' of two integers
      x and y where 1 < x <= 2^63 and 1 <= y < x 
   ** This function uses the division algorithm: x = yq  + r */
void divisionAlgorithm(long long x, long long y)
{
    long long r = 0;
    long long q = 0;

    r = x;
    while (r >= y)
    {
        r = r - y;
        q++;
    }
    cout << "The quotient and the remainder that satisify x = yq + r are: " 
        << '\n' << "q = " << q << " and r = " << r << endl;
}

// validates that x is an integer > 1
long long readLongX(const char prompt[])
{
    long long input = 0;
    cout << prompt;
    cin >> input;

    // validate input is only an integer greater than 1
    while ((!cin || input <= 1) || cin.peek() == '.')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Input must be an integer > 1, please try again!" << endl;
        cin >> input;
    }
    cin.ignore(100, '\n');

    return input;
}

// validates y is an integer >= 1
long long readLongY(const char prompt[])
{
    long long input = 0;
    cout << prompt;
    cin >> input;

    // validate input is only an integer greater than 1
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
