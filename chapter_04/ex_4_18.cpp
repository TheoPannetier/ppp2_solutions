// Exercise 4.18
#include "std_lib_facilities.h"

int main()
{
    double a;
    double b;
    double c;
    
    // Enter input sequence
    cout << "Enter coefficients a, b and c of the quadratic equation: ";
    cin >> a >> b >> c;
    
    double x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    
    cout << "The two solutions are " << x1 << " and " << x2 << ".\n";
}
