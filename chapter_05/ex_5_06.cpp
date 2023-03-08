#include "std_lib_facilities.h"
// Exercise 5.6
double ctof(double c)   // converts Celsius to Farenheit
{
    if (c < -273.15) error("A temperature can't be below -273.15°C.\n");
    double f = 9.0 / 5.0 * c + 32.0;
    return f;
}

double ftoc(double f)   // converts Farenheit to Celsius
{
    if (f < -459.67) error("A temperature can't be below -459.67°F.\n");
    double c = (f - 32.0) / 9.0 * 5.0;
    return c;
}

int main()
{
    try {
        cout << "Enter a temperature value and a unit (c or f):";
        double val_in;
        char unit = 'n';
        cin >> val_in >> unit;
        
        double val_out;
        switch (unit) {
            case 'c':
                val_out = ctof(val_in);
                cout << val_out << "°F\n";
                break;
            case 'f':
                val_out = ftoc(val_in);
                cout << val_out << "°C\n";
                break;
            default:
                throw runtime_error("Temperature unit can only be c or f.\n");
                break;
        }
    }
    catch (runtime_error& e)
    {
        cerr << "runtime error: " << e.what();
        return 1;
    }
}

