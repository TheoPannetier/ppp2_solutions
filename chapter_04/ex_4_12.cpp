// Exercise 4.12
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
    int max_val;
    cout << "Please enter a max value to search: ";
    cin >> max_val;
    
    // Find primes
    vector<int> primes;
    for (int i = 1; i <= max_val; ++i)
    {
        if (is_prime(i)) primes.push_back(i);
    }
    // Print all matches
    cout << "All primes between 1 and " << max_val << ":\n";
    for (int p:primes)
    {
        cout << p << "\t";
    }
    
}
