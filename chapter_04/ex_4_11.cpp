// Exercise 4.11
#include "std_lib_facilities.h"

bool is_prime(int x)
{
    int i{2};
    while (i < x) {
        if (x % i == 0) return false;
        ++i;
    }
    return true;
}

int main()
{
    // Find primes
    vector<int> primes;
    for (int i = 1; i <= 100; ++i)
    {
        if (is_prime(i)) primes.push_back(i);
    }
    // Print all matches
    for (int p:primes)
    {
        cout << p << "\t";
    }
    
}
