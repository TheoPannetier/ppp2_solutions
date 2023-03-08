#include "std_lib_facilities.h"
// Exercise 5.2
double ctok(double c)   // converts Celsius to Kelvin
{
    double k = c + 273.15; // k should be a double
    return k; // k not int
}

int main()
{
    double c = 0;
    cin >> c;   // d not c
    double k = ctok(c); // c as a string
    cout << k << "\n" ; // Cout with cap + line break as char + \ not /
}
