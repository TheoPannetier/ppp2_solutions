#include "std_lib_facilities.h"
// Exercise 5.4
double ctok(double c)   // converts Celsius to Kelvin
{
    if (c < -273.15) error("A temperature can't be below -273.15°C.\n");
    double k = c + 273.15;
    return k;
}

int main()
{
    try {
        double c = 0;
        cin >> c;
        double k = ctok(c);
        cout << k << "\n";
    }
    catch (runtime_error& e)
    {
        cerr << "runtime error: " << e.what();
        return 1;
    }
}
