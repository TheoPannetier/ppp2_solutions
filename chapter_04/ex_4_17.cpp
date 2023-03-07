// Exercise 4.17
#include "std_lib_facilities.h"

int main()
{
    // Enter input sequence
    cout << "Enter a sequence of strings:";
    vector<string> words;
    string input;
    while (cin >> input) words.push_back(input);
    sort(words.begin(), words.end());
    
    // Count occurrences of each word
    // while tracking min and max
    vector<int> occurrences(words.size(), 0);
    int to_increment = 0;
    int which_is_mode = 0; // by default
    string max_word = words[0];
    string min_word = words[0];
    
    for (int j = 0; j < words.size(); ++j)
    {
       if (j != 0 && words[j] != words[j - 1])
       {
           to_increment = j;
           if (words[j] > max_word) max_word = words[j];
           if (words[j] < min_word) min_word = words[j];
       }
        ++occurrences[to_increment];
        
        // Update the mode
        if (occurrences[to_increment] > occurrences[which_is_mode])
        {
            which_is_mode = to_increment;
        }
    }
    
    cout << "The mode is \"" << words[which_is_mode] << "\".\n";
    cout << "The max is \"" << max_word << "\".\n";
    cout << "The min is \"" << min_word << "\".\n";
}
