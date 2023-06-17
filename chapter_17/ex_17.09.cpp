/*
 Ex 17.9
 Which way does the stack grow: up (toward higher addresses) or down (toward lower addresses)? Which way does the free store initially grow (that is, before you use delete)? Write a program to determine the answers.
 
 stack mem grows downwards
 free store grows upwards
*/

#include "std_lib_facilities.h"
#include <cmath>

int main()
{
    try {
        int a = 9;
        int b = 10;
        int c = 11;
        int* pa = &a;
        int* pb = &b;
        int* pc = &c;
        cout << pa << '\n';
        cout << pb << '\n';
        cout << pc << '\n';
        int* pd = new int[1];
        int* pe = new int[1];
        int* pf = new int[1];
        cout << pd << '\n';
        cout << pe << '\n';
        cout << pf << '\n';
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
