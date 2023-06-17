/*
 1. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.
 */

#include "std_lib_facilities.h"
#include <cmath>

int str_len(const char* c_str) {
    int len = 0;
    while (*c_str) { // while char is not 0
        ++len;
        ++c_str;
    }
    return len;
}

char* strdup(const char* c_str)
{
    const int len = str_len(c_str);
    char* p_str = new char[len];
    char* ip_str = p_str; // iterator copy
    while(*c_str) {
        *ip_str = *c_str;
        ++c_str;
        ++ip_str;
    }
    return p_str;
}


int main()
{
    try {
        char c_str[] = "hello_world";
            // c style string
            // array of chars, compiler adds 0 at the end
        
        cout << str_len(c_str) << '\n';
            // name pc decays into pointer to array on function call
        
        char* pc = strdup(c_str);
        
        // Shorthand print
        cout << pc << '\n';
            // pc decays into the whole array?
        
        // Longhand print
        while (*pc) {
            cout << *pc;
            ++pc;
        }
        cout << '\n';
        // /!\ pc has changed!
        // could avoid by first making a copy
        // then re-assigning copy to original after iterating
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
