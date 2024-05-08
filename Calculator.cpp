/*Sahil Sharma
A calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.*/
#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;
    double result;

   
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
        
            if (num2 == 0) {
                cout << "Error: Division by zero!" << endl;
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            cout << "Invalid operation!" << endl;
            return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}