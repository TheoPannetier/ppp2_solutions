/*
 For each exercise, create and test (with output) a couple of objects of the defined classes to demonstrate that your design and implementation actually do what you think they do. Where exceptions are involved, this can require careful thought about where errors can occur.
 1. Write a template function f() that adds the elements of one vector<T> to the elements of another; for example, f(v1,v2) should do v1[i]+=v2[i] for each element of v1.
*/

#include "std_lib_facilities.h"
#include <cmath>

template<typename T> void f(vector<T>& v1, const vector<T>& v2)
{
    int sz = max(v1.size(), v2.size());
    v1.resize(sz);
    for (int i = 0; i < v2.size(); ++i)
    {
        v1[i] += v2[i];
    }
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
        // Case double
        vector<double> d1{0.1, 0.4, 3.2};
        vector<double> d2{-0.3, 0.2};
        vector<double> d3{0.5, 0.1, 1.2, 1.8};
        f(d1, d1);
        cout << d1 << '\n';
        f(d1, d2);
        cout << d1 << '\n';
        f(d1, d3);
        cout << d1 << '\n';
        
        // Case char, why not
        vector<char> c1{'A', '0', 'f'};
        vector<char> c2{'0', '4'};
        f(c1, c2);
        cout << c1 << '\n';
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
