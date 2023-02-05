// Joshua Baron
// 10/13/2022

// Purpose: The purpose of this program is to calculate certain
// operations using recursion.

#include <iostream>
#include <cmath>

using namespace std;

// Sets up the user interface
int userInterface();

// Switch statement that selects which operation to perform
bool selection(int option); 

// Algorithm to sum up the digits of num
int sumDigits(int num);

// Algorithm that takes the fifth root of num
double root5(double num, double guess);

// Halves an integer (x) wihout divison
int halveInt(int x);

// Doubles an integer (x) without multiplication
int doubleInt(int x);

// Algorithm for egyptian divison
int egyptDivision(int divisor, int dividend);

// Algorithm to calculate ramanujan to a certain depth
double ramanujan(int depth, int end);

int main() {
    bool exit = false; // Exit out of user interface
    int choice; // Choice for which algorithm to do

    // while loop for user interface
    while (exit == false) {
        choice = userInterface();
        exit = selection(choice);
    }

    return 0;
}

int userInterface() {
    int choice;

    cout << "Welcome to the recursion assignment. What would you like to test? " << endl;
    cout << "(1) sumDigits" << endl << "(2) root5" << endl << "(3) egyptDivision" << endl;
    cout << "(4) ramanujan" << endl << "(5) Exit" << endl;

    cin >> choice;

    return choice;
}

bool selection(int option) {
    bool exit = false;
    int num; // holds an integer used for some of the algorithms
    int divisor; // divisor for egyptian divison
    int dividend; // divendend for egyptian divison

    switch(option) {
        case 1:
            cout << "What number would you like to sum the digits of? ";
            cin >> num;
            cout << "The sum of the digits of " << num << " is " << sumDigits(num) << endl << endl;
            break;
        case 2:
            cout << "What number would you like to take the fifth root of? ";
            cin >> num;
            cout << "The fifth root of " << num << " is " << root5(num, 1) << endl << endl;
            break;
        case 3:
            cout << "Divisor: ";
            cin >> divisor;
            cout << "Dividend: ";
            cin >> dividend;
            cout << "Quotient: " << egyptDivision(divisor, dividend) << endl << endl;
            break;
        case 4:
            cout << "Depth: ";
            cin >> num;
            cout << "Ramanujan with depth " << num << " is equal to " << ramanujan(num, 0) << endl;
            cout << "Ramanujan carried out to infinity is " << ramanujan(100, 0) << endl << endl;
            // As the depth goes to infinity it approaches 4.
            break;
        case 5:
            exit = true;
            break;
        default:
            cout << "Error Choose (1-5)" << endl;
    }
    return exit;
}


int sumDigits(int num) {
    // If the number is one digit it will return that
    if (to_string(num).length() == 1) {
        return num;
    }

    // Gets the last digit of num
    int lastDigit = num % 10;

    // Adds the last digit to a recursive call of sumDigits, dividing num
    // by ten to get rid of the last number.
    return lastDigit + sumDigits(num / 10);
}

double root5(double num, double guess) {
    // If the number is 0 or 1 it will return the number
    if (num == 0 || num == 1) {
        return num;
    }
    if (abs(pow(guess, 5) - num) < 0.00001) {
        return guess;
    }
    return root5(num, (4 * guess + (num / pow(guess, 4))) / 5);
}

int doubleInt(int x) {
    // Adds the number to itself to double it
    x += x; 
    return x;
}

int halveInt(int x) {
    // Subtracts 2 from the number until less than or equal to one
    // then adds how many times it did that operation and that is the answer
    if (x <= 1) {
        return 0;
    }
    return 1 + halveInt(x - 2);
}

// column b is the divisor, column c is the dividend
int egyptDivision(int dividend, int divisor) {
    int a = 1; // column A
    while (divisor < dividend) {
        a = doubleInt(a);
        divisor = doubleInt(divisor);
    }
    int d = 0; // column d
    while(a >= 1) {
        if (divisor <= dividend) {
            d += a;
            dividend -= divisor;
            a = halveInt(a);
            divisor = halveInt(divisor);
        } else {
            a = halveInt(a);
            divisor = halveInt(divisor);
        }
    }
    return d;
}

double ramanujan(int depth, int end) {
    if (depth == 0) {
        return sqrt(6);
    }
    if (end == depth) {
        return (1 + end) * sqrt((6 + end));
    }
    return (1 + end) * sqrt((6 + end) + ramanujan(depth, end + 1));
}
