/*
 Ex 17.3
 Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their lowercase equivalents. For example, Hello, World! becomes hello, world!. Do not use any standard library functions. A C-style string is a zero-terminated array of characters, so if you find a char with the value 0 you are at the end.
*/

#include "std_lib_facilities.h"
#include <cmath>

void to_lower(char* s)
{
    constexpr int upper_to_lower_diff = 32;
    int i = 0;
    while(s && s[i] != '0')
    {
        if (s[i] >= 65 && s[i] <= 90) // is uppercase
        {
            s[i] += upper_to_lower_diff;
        }
        ++i;
    }
    return;
}

int main()
{
    try {
        // Initialise pointer to C-style string
        string str = "Hello, World!0";
        char *s = new char[str.size()];
        for (int i = 0; i < str.size(); i++)
        {
            s[i] = str[i];
        }
        cout << "Before: " << s << '\n';
        
        to_lower(s);
        cout << "After: " << s << '\n';
        delete[] s;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        return 2;
    }
}
