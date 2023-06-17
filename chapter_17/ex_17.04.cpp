/*
 Ex 17.4
 Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. Do not use any standard library functions.
*/

#include "std_lib_facilities.h"
#include <cmath>

int get_cstr_size(const char* s)
{
    int str_size = 0;
    int i = 0;
    while (s) { // not nullptr
        ++str_size;
        if (s[i] == '0') return str_size;
        ++i;
    }
    return -1; // should not reach
}

char* strdup(const char* s)
{
    int s_size = get_cstr_size(s);
    char* dup = new char[s_size];
    for (int i = 0; i < s_size; ++i)
        dup[i] = s[i];
    return dup;
}

int main()
{
    try {
        // Initialise pointer to C-style string
        string str = "Hello, World!0";
        char *s1 = new char[str.size()];
        for (int i = 0; i < str.size(); i++)
        {
            s1[i] = str[i];
        }
        cout << "Original: " << s1 << '\n';

        // Duplicate
        char* s2 = strdup(s1);
        cout << "Duplicate: " << s2 << '\n';
        delete[] s1;
        delete[] s2;
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
