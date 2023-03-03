// Exercise 4.6
#include "std_lib_facilities.h"

int main()
{
    vector<string> spelled_digits{
        "zero", "one", "two",
        "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    
    int input_digit;
    
    cout << "Enter a digit: ";
    while (cin >> input_digit)
    {
        cout << "\nYou entered the number " << spelled_digits[input_digit] << ". Enter a new digit:";
    }
    return 0;
}

//----- Second part -----------//

// Exercise 4.6
#include "std_lib_facilities.h"

int main()
{
    const vector<string> spelled_digits{
        "zero", "one", "two",
        "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    
    string input_str;
    bool has_matched;
    
    cout << "Enter a spelled out digit: ";
    while (cin >> input_str)
    {
        has_matched = false;
        for (int i = 0; i < spelled_digits.size(); i++)
        {
            if (spelled_digits[i] == input_str)
            {
                cout << "\nYou entered the number " << i << ". Enter a new digit: ";
                has_matched = true;
            }
        }
        if (!has_matched) simple_error("Please only enter spelled out digits in lowercase.\n");
        
    }
    return 0;
}
