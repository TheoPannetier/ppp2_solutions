// Exercise 4.16
#include "std_lib_facilities.h"

int main()
{
    // Enter input sequence
    cout << "Enter a sequence of positive integers:";
    vector<int> numbers;
    int input;
    while (cin >> input) numbers.push_back(input);
    sort(numbers.begin(), numbers.end());
    
    // Count occurrences of each number
    vector<int> occurrences(numbers.size(), 0);
    int to_increment = 0;
    int which_is_mode = 0; // by default
    for (int j = 0; j < numbers.size(); ++j)
    {
       if (j != 0 && numbers[j] != numbers[j - 1])
       {
           to_increment = j;
       }
        ++occurrences[to_increment];
        
        // Update the mode
        if (occurrences[to_increment] > occurrences[which_is_mode])
        {
            which_is_mode = to_increment;
        }
    }
    
    cout << "The mode is " << numbers[which_is_mode] << ".\n";
}
