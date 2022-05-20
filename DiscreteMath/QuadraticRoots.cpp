/* Find the distinct roots of a second-order homogenous recurrence relation with constant coefficients */

#include <iostream> 
#include <cmath>

// function prototypes
// read in and validate input
double readDoubleVar(const char prompt[]); 
// read in and validate special case B != 0
double readDoubleB(const char prompt[]); 
// function to find root(s) and formula for the sequence
void findSequence(double A, double B, double a0, double a1);
// print result for single root, root1 = root2
void printSingleRoot(double C, double D, double root1); 
// print result for distinct roots
void printDistinctRoots(double C, double D, double root1, double root2); 

using namespace std;

int main()
{
    double A = 0, B = 0, a0 = 0, a1 = 0;

    // run routine 4 times
    for (int i = 0; i < 4; i++)
    {
        // read in integers from the user
        A = readDoubleVar("Please enter a number for A: ");
        cout << endl;
        B = readDoubleB("Please enter a number for B where B != 0: ");
        cout << endl;
        a0 = readDoubleVar("Please enter an initial value for a0 ");
        cout << endl;
        a1 = readDoubleVar("Please enter an initial value for a1 ");
        cout << endl;
        
        // find the root(s) and deterimine the formula for the sequence
        findSequence(A, B, a0, a1);
    }
    
    return 0;
}

// find real root(s), if any, and determine the formula for the sequence from 
//      passed in values
void findSequence(double A, double B, double a0, double a1)
{
    double discriminant = 0; // b^2 -4*a*c
    double root1 = 0, root2 = 0;
    double a = 1, b = -A, c = -B; // quadratic variables
    
    // An = Cr^n + Ds^n where r and s are root1 and root2
    double C = 0; // solve above equation in terms of C, plug in to solve for D  
    double D = 0; 

    /* Characteristic Equation: t^2 - At - B = 0 
        Use quadratic equation to find roots where a = t, b = A, c = B */
    
    // Step1: determine if roots are real or complex
    discriminant = (b*b - (4*a*c)); 

    // Step 2: Find roots if real, notify user if complex
    if (discriminant < 0) // quadratic has complex roots
    {
        cout << "The recurrence relation has complex roots. " << endl;
    }
    else if (discriminant == 0)// quadratic has a single real root
    {
           
         root1 = (-b + sqrt(discriminant)) / (a * 2);
            
        // calculate C and D
        C = a0; //n = 0: a0 = C *1 + D*0*1 
        D = a1 / root1 - a0; //n = 1: a1 = C*(root1)^1 + D*1*(root1)^1
            
        cout << "C = " << C << " and D = " << D << endl;
            
        // step 3:  output formula for sequence
        if (C == 0) // a(n) = D*n*(root1)^n
        {
            cout << "The formula An = "<< D
                << "*n*(" << root1 << ")^n " << endl;
        }
        else
        {
            cout << "The formula An = " << C << "*(" << root1 << ")^n + " 
                << D << "*n*(" << root1 << ")^n " << endl;
        }

        // step 4: output first six terms of the sequence
        printSingleRoot(C, D, root1);
    }
    else if(discriminant > 0) // quadratic has two distinct roots
    {
        // find both distinct roots
        root1 = ((-b) + sqrt(discriminant)) / (a * 2);
        root2 = ((-b) - sqrt(discriminant)) / (a * 2);

        // calculate C and D
        D = (a1 - (a0 * root1))/(-root1 + root2);    
        C = a0 - D;
        
        cout << "C = " << C << " and D = " << D << endl;
      
        // step 3: output formula for the sequence
        cout << "The formula An = " << C << "*(" << root1 << ")^n + " << D
            << "*n(" << root2 << ")^n " << endl;
    
        // step 4: output first six terms of the sequence
        printDistinctRoots(C, D, root1, root2);
    }
}

// print first six terms of sequence when there is one real root
void printSingleRoot(double C, double D, double root1)
{
    cout << "The first six terms of the sequence are: " << endl;
    for (int n = 0; n < 6; n++)
    {
        cout << "a(" << n << ") = " << (C + D*n)*pow(root1, n) << endl;
    }
}

// print first six terms of sequence when there are two real roots
void printDistinctRoots(double C, double D, double root1, double root2)
{
    cout << "The first six terms of the sequence are: " << endl;
    for (int n = 0; n < 6; n++)
    {
        cout << "a(" << n << ") = " << C*pow(root1, n) + D *pow(root2, n) << endl;
    }
}

// verify input is an integer or a double
double readDoubleVar(const char prompt[])
{
    double temp = 0;
    cout << prompt;
    cin >> temp;

    // validate data
    while (!cin) 
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input, please try again!" << endl;
        cin >> temp;
    }
    cin.ignore(100, '\n');
    return temp;
}

/* verify constant B is an integer or a double
        special case: B must not be equal to 0 */
double readDoubleB(const char prompt[])
{
    double temp = 0;
    cout << prompt;
    cin >> temp;

    // validate data
    while (!cin || temp == 0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input, please try again!" << endl;
        cin >> temp;
    }
    cin.ignore(100, '\n');
    return temp;
}
