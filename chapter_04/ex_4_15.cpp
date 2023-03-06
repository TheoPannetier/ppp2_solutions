// Exercise 4.15
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
    int n;
        cout << "Enter the desired number of primes: ";
    cin >> n;
    
    // Find primes
    vector<int> primes;
    int x = 2;
    while (primes.size() < n)
    {
        if (is_prime(x)) primes.push_back(x);
        ++x;
    }
    
    // Print all matches
    for (int p:primes)
    {
        cout << p << "\n";
    }
}
