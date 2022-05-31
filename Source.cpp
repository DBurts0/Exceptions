#include <iostream>
using namespace std;

// Variables for gathering the user's inputs and calculations.
int num1;
int num2;
float num3;
string userInput;
int err = 0;
// Variable for testing if the user input something other than a number
bool inputFail;

// Function for dividing the two numbers
float Divide(float num, float denom)
{
    // Divide the two numbers the user provided and output the result
    num3 = num / denom;
    cout << "The quotient of the two numbers is: " << num3 << endl;
    return num3;
}

// Function for adding the two numbers together
float Add(float n1, float n2) 
{
    // Add the two numbers the user provided and output the result
    num3 = n1 + n2;
    cout << "The sum of the two numbers is: " << num3 << endl;
    return num3;
}

//function for subtracting the two numbers
float Subtract(float n1, float n2) 
{
    num3 = n1 - n2;
    // Display the difference of the two numbers the user provided
    cout << "The difference of the two numbers is: " << num3 << endl;
    return num3;
}

// function for multplying the two numbers together
float Multiply(float n1, float n2) 
{
    // Multiply the two numbers the user provided and output the result
    num3 = n1 * n2;
    cout << "The product of the two numbers is: " << num3 << endl;
    return num3;
}

int main()
{
    cout << "Welcome! This program will take two numbers that you provide,\n";
    cout << "and produce the sum, product, difference, and quotient of the numbers.\n ";
    // Return point if the user wishes to try another equation
START:
    do 
    {
        // Ask for the first number
        cout << "Enter the first number!\n";
        cin >> num1;

        // check if the user input a non number value
        inputFail = cin.fail();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (inputFail == true) 
        {
            cout << "Invalid input. Please try again.\n";
        }

    } while (inputFail == true);
 
    do 
    {
        // Ask for the second number
        cout << endl << "Enter second number\n";
        cin >> num2;

        // check if the user input a non number value
        inputFail = cin.fail();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (inputFail == true)
        {
            cout << "Invalid input. Please try again.\n";
        }
    } while (inputFail == true);

    // Check if the denominator is 0 before calculating
    try
    {
        if (num2 == 0)
        {
            // Throw the exception 
            throw err;
        }
        // Calculate all four equations if no exception was thrown
        Divide(num1, num2);
        Multiply(num1, num2);
        Add(num1, num2);
        Subtract(num1, num2);
    }
    // If an exception occurs, catch it and inform the use what caused it.
    catch (int errNum)
    {
        cout << "Error! Cannot divide by 0 " << endl;
    }

    // Return point if the user inputs an invalid responce when asked if they want to try a new equation
EQUATION:
    cout << "Would you like to do another equation?\n";
    cout << "Type yes or no.\n";
    cin >> userInput;
    // If the user types yes, return to the beginning of the main function
    if (userInput == "yes") {
        goto START;
    }
    // If the user types no, exit the program
    else if (userInput == "no") {
        cout << "Goodbye.\n";
    }
    // If the user inputs a value other than yes or no, ask them again
    else 
    {
        cout << "Invalid response.\n";
        goto EQUATION;
    }
}