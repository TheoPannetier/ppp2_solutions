#include "std_lib_facilities.h"
// Exercise 5.5
double ctok(double c)   // converts Celsius to Kelvin
{
    if (c < -273.15) error("A temperature can't be below -273.15°C.\n");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)   // converts Kelvin to Celsius
{
    if (k < 0) error("A temperature can't be below 0°K.\n");
    double c = k - 273.15;
    return c;
}

int main()
{
    try {
        cout << "Enter a temperature value and a unit (c or k):";
        double val_in;
        char unit = 'n';
        cin >> val_in >> unit;
        
        double val_out;
        switch (unit) {
            case 'c':
                val_out = ctok(val_in);
                cout << val_out << "°K\n";
                break;
            case 'k':
                val_out = ktoc(val_in);
                cout << val_out << "°C\n";
                break;
            default:
                throw runtime_error("Temperature unit can only be c or k.\n");
                break;
        }
    }
    catch (runtime_error& e)
    {
        cerr << "runtime error: " << e.what();
        return 1;
    }
}

