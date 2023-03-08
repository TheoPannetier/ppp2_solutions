#include "std_lib_facilities.h"
// Exercise 5.7

int main()
{
    double a;
    double b;
    double c;
    
    // Enter input sequence
    cout << "Enter coefficients a, b and c of the quadratic equation: ";
    try {
        cin >> a >> b >> c;
        if (a == 0) throw logic_error("'a' must be different from zero.\n");
        double delta = b * b - 4 * a * c;
        if (delta < 0) throw logic_error("This equation has no real root!\n");
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        
        cout << "The two solutions are " << x1 << " and " << x2 << ".\n";
    }
    catch (logic_error& e) {
        cout << "Logic error: " << e.what();
    }
}

// Pick easy values to check: if c = 0 one of the roots should be 0;
// the other is trivial, especially with a = 0.5!
