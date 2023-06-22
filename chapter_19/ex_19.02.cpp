/*
 For each exercise, create and test (with output) a couple of objects of the defined classes to demonstrate that your design and implementation actually do what you think they do. Where exceptions are involved, this can require careful thought about where errors can occur.
 2. Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all vt[i]*vu[i]
*/

#include "std_lib_facilities.h"
#include <cmath>

template<typename T, typename U> T f(vector<T>& vt, const vector<U>& vu)
{
    if (vt.size() != vu.size())
        // Multiplying with empty element would be NA; forbidden
        throw logic_error("Vectors have different lengths");
    T sum_prods = 0;
    for (int i = 0; i < vt.size(); ++i)
    {
        sum_prods += vt[i] * vu[i];
    }
    return sum_prods;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        os << s[i] << '\t';
    }
    return os;
}

int main()
{
    try {
        // Case ints
        vector<int> i1{1, 2};
        vector<int> i2{6, -2};
        cout << f(i1, i2) << '\n';
        
        vector<double> d1{0.1, -0.5};
        cout << f(i1, d1) << '\n'; // return is an int
        cout << f(d1, i1) << '\n'; // return is a dbl
        
        vector<char> c1{'A', 'B'};
        cout << f(i1, c1) << '\n';
        cout << f(d1, c1) << '\n'; // vile but correct
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
