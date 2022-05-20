/*
	Simulates the full-adder circuitry depicted in the text, "Discrete Mathematics with Applications". This program will read in two strings of binary digits and add them bit-by-bit
	using the full-adder function. There are also four logic gate functions to simulate a NOT Gate, AND Gate, OR Gate, and a XOR Gate
	

*/
#include <iostream>
#include <cstring>

const int MAXSIZE = 9; // max size 8 bits and '\n'

struct AddBinary 
{
    char sum = '0';
    char carry = '0';
};

AddBinary fullAdder(char p, char q, char carry); 
// helper functions
void padString(char a[], char b[]); 
void printStrings(char a[], char b[]); 
// Logic Gate Functions
char notGate(char p);
char andGate(char p, char q);
char orGate(char p, char q);
char xorGate(char p, char q);

using namespace std;

int main()
{
    AddBinary result;
    char sum[MAXSIZE];
    char strA[MAXSIZE];
    char strB[MAXSIZE];
    char *checkString;
    char key[] = "01";
    char p = '0', q = '0';
    int lenA = 0, lenB = 0; 

    // call program 4 times
    for (int i = 0; i < 4; ++i)
    {
        // prompt user for binary strings
        cout << "Please enter a binary number, up to 8 bits: " << endl;
        cin.get(strA, '\n');
        cin.ignore(9, '\n');
        // verify input
        checkString = strpbrk(strA, key);
        while (checkString == NULL)
        {
            cout << "Invalid input, string must contain only '0' or '1' "
                 << endl;
            cout << "Please enter a binary number, up to 8 bits: " << endl;
            cin.get(strA, '\n');
            cin.ignore(9, '\n');
            checkString = strpbrk(strA, key);
        }
        
        // prompt for second string
        cout << "Please enter a binary number, up to 8 bits: " << endl;
        cin.get(strB, '\n');
        cin.ignore(9, '\n');
        checkString = strpbrk(strB, key);
        while (checkString == NULL)
        {
            cout << "Invalid input, string must contain only '0' or '1' "
                 << endl;
            cout << "Please enter a binary number, up to 8 bits: " << endl;
            cin.get(strB, '\n');
            cin.ignore(9, '\n');
            checkString = strpbrk(strB, key);
        }
        
        // determine string length
        lenA = strlen(strA);
        lenB = strlen(strB);
        
        // if either string is less than array size, pad strings
        if (lenA < (MAXSIZE - 1) || lenB < (MAXSIZE - 1))
        {
            padString(strA, strB);
            printStrings(strA, strB);
        }
        else
            printStrings(strA, strB);

        // starting from last element, compare strA and strB
        // bit by bit
        for (int i = (MAXSIZE-2); i >= 0; i--)
        {
            p = strA[i];
            q = strB[i];
            
            // save result
            result = fullAdder(p, q, result.carry);
            sum[i] = result.sum;
        }

        // display output, formatted in 4 bits
        cout << "The answer is ";
        for (int i = 0; i < 4; i++)
        {
            cout << sum[i];
        }
        cout << " ";
        for (int j = 4; j < MAXSIZE - 1; j++) 
        {
            cout << sum[j];
        }
        cout << endl;
            
    }
return 0;
}

AddBinary fullAdder(char p, char q, char carry)
{
    char sum1 = '0';
    char sum2 = '0'; 
    char carry1 = '0'; 
    char carry2 = '0';
    char carryOut = '0';
    
    AddBinary result;
    
    sum1 = xorGate(p, q); 
    carry1 = andGate(sum1, carry); 
    
    sum2 = xorGate(sum1, carry); 
    carry2 = andGate(p, q);

    if (orGate(carry1, carry2) == '1')
        carryOut = '1';
    
    // return sum and carry to struct object
    result.carry = carryOut;
    result.sum = sum2;

    // if remainder of string is empty, do not print
    if (p == ' ' && q == ' ')
    {
        return result;
    }
    
    // output data to screen
    cout << "The bits are " << p << " and " << q << ". The carry in is "
        << carry << ". The sum is " << sum2 << ". The carry out is " << carryOut
        << endl;

    return result;
}

void printStrings(char a[], char b[]) 
{
    // display output, formatted in 4 bits
    cout << "The numbers to be added are ";
    
    // string1
    for (int i = 0; i < 4; i++)
    {
        cout << a[i];
    }
    cout << " ";
    for (int j = 4; j < MAXSIZE - 1; j++)
    {
        cout << a[j];
    }

    // string 2
    cout << " and ";
    for (int i = 0; i < 4; i++)
    {
        cout << b[i];
    }
    cout << " ";
    for (int j = 4; j < MAXSIZE - 1; j++)
    {
        cout << b[j];
    }
    cout << endl;
}

void padString(char a[] ,char b[])
{
    char tempA[MAXSIZE];
    char tempB[MAXSIZE];
    int numOfSpaces = 0;
    
    // copy strings
    strcpy(tempA, a);
    strcpy(tempB, b);

    if (a) // stringA
    {
        numOfSpaces = MAXSIZE - strlen(a);
        for (int i = 0; i < numOfSpaces - 1; ++i)
        {
            a[i] = ' ';
        }
        for (int i = numOfSpaces - 1; i < MAXSIZE - 1; ++i)
        {
            a[i] = tempA[i - numOfSpaces + 1];
        }
    }
    
    if (b) // stringB
    {
        numOfSpaces = MAXSIZE - strlen(b);
        for (int i = 0; i < numOfSpaces - 1; ++i)
        {
            b[i] = ' ';
        }
        for (int i = numOfSpaces - 1; i < MAXSIZE - 1; ++i)
        {
            b[i] = tempB[i - numOfSpaces + 1];
        }
    }
}

/* Logic Gate Definitions */

// AND gate returns p AND q
char andGate(char p, char q)
{
    if (p == '1' && q == '1')
        return '1';
    else
        return '0';
}
// OR gate returns p OR q
char orGate(char p, char q)
{
    if (p == '1' || q == '1')
        return '1';
    else
        return '0';
}
// NOT gate returns NOT p
char notGate(char p)
{
    if (p == '1')
        return '0';
    else
        return '1';
}
// XOR gate returns '0' if p == q
char xorGate(char p, char q)
{
    if (p == q)
        return '0';
    else
        return '1';
}
