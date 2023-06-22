/*
 For each exercise, create and test (with output) a couple of objects of the defined classes to demonstrate that your design and implementation actually do what you think they do. Where exceptions are involved, this can require careful thought about where errors can occur.
 5. Define a class Int having a single member of class int. Define constructors, assignment, and operators +, –, *, / for it. Test it, and improve its design as needed (e.g., define operators << and >> for convenient I/O).
*/

#include "std_lib_facilities.h"
#include <cmath>

class Int
{
public:
    Int(const int& input_i): i{input_i}{};
    const int get() const { return i; }
private:
    int i;
};

Int operator+ (const Int& I1, const Int& I2)
{
    return I1.get() + I2.get();
}

Int operator- (const Int& I1, const Int& I2)
{
    return I1.get() - I2.get();
}

Int operator* (const Int& I1, const Int& I2)
{
    return I1.get() * I2.get();
}

Int operator/ (const Int& I1, const Int& I2)
{
    return I1.get() / I2.get();
}

ostream& operator<< (ostream& os, Int I)
{
    os << I.get();
    return os;
}

int main()
{
    try {
        Int i1(4);
        cout << i1 << '\n';
        i1 = 3;
        Int i2(7);
        i1 = i2; // no need for copy assignment??
        cout << i1 << '\n';
        i2 = 2;
        cout << i1 + i2 << '\n';
        cout << i1 - i2 << '\n';
        cout << i1 * i2 << '\n';
        cout << i1 / i2 << '\n';
        
        Int i3 = i1; // no need for copy constructor??
        cout << i3 << '\n';
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
