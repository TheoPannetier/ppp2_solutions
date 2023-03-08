// Exercise 4.7
#include "std_lib_facilities.h"

double input_to_dbl(const string input)
// double and not int to ensure division is what user might expect
{
    const vector<string> spelled_digits {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    const vector<string> str_digits {
        "0", "1", "2", "3", "4",
        "5", "6", "7", "8", "9"
    };
    for (int i = 0; i < spelled_digits.size(); ++i)
    {
        if (input == spelled_digits[i] || input == str_digits[i])
        {
            return i;
        }
    }
    simple_error("Invalid input. Please only enter a digit spelled out or as a number.");
    return 1; // never used but toggles warning off
};

int main()
{
    string input1;
    string input2;
    char operation;
    
    double result = 0.0; // evade warning for the switch default case
    
    cout << "Please enter two digits and an operation: ";
    cin >> input1 >> input2 >> operation;
    const double operand1 = input_to_dbl(input1);
    const double operand2 = input_to_dbl(input2);
    
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
