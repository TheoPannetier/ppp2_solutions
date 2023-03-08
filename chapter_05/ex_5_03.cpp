#include "std_lib_facilities.h"
// Exercise 5.3
double ctok(double c)   // converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0;
    try {
        cin >> c;
        if (c < -273.15) error("A temperature can't be below -273.15°C.\n");
    }
    catch (runtime_error& e)
    {
        cerr << "runtime error: " << e.what();
        return 1;
    }
    double k = ctok(c);
    cout << k << "\n";
}
