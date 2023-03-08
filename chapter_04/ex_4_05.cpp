// Exercise 4.5
#include "std_lib_facilities.h"

int main()
{
    double operand1;
    double operand2;
    char operation;
    double result = 0.0; // evade warning for the switch default case
    
    cout << "Please enter two numbers and an operation: ";
    cin >> operand1 >> operand2 >> operation;
        switch (operation) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                simple_error("Invalid input: the allowed operations are: + - * /\n");
        }
        cout << "The result is " << result << ".\n";
    return 0;
}
