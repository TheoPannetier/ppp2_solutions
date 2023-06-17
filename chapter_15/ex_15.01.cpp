/*
 Ex. 15.1
 Here is another way of defining a factorial function:

 int fac(int n) { return n > 1 ? n * fac(n–1) : 1; }    // factorial n!
 
 It will do fac(4) by first deciding that since 4>1 it must be 4*fac(3), and that’s obviously 4*3*fac(2), which again is 4*3*2*fac(1), which is 4*3*2*1. Try to see that it works. A function that calls itself is said to be recursive. The alternative implementation in §15.5 is called iterative because it iterates through the values (using while). Verify that the recursive fac() works and gives the same results as the iterative fac() by calculating the factorial of 0, 1, 2, 3, 4, up until and including 20. Which implementation of fac() do you prefer, and why?
*/

#include "std_lib_facilities.h"

int fac(int n) {
    return n > 1 ? n * fac(n - 1) : 1;
}

int fac2(int n)
{
    int r = 1;
    while (n > 1) {
        r *= n;
        --n;
    }
    return r;
}

int main()
{
    try {
        bool both_equal{false};
        for (int i = 0; i < 5; i++)
        {
            both_equal = fac(i) == fac2(i);
            if(!both_equal)
                error("The two functions yield different results!");
        }
        return 0;
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
