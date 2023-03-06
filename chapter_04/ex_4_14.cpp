// Exercise 4.14
#include "std_lib_facilities.h"

int main()
{
    int max_val;
        cout << "Please enter a max value to search: ";
    cin >> max_val;
    
    // Fill vector with values from 2 to the value
    vector<int> primes;
    for (int i = 2; i <= max_val; ++i)
    {
        primes.push_back(i);
    }

    int i = 0;
    while (i < primes.size())
    {
        int p = primes[i];
        
        // Find all composites of p in the sequence
        vector<int> composites;
        int max_in_seq = primes.back();
        int max_factor = max_in_seq / p;
        for (int f = 2; f <= max_factor; f++)
        {
            composites.push_back(p * f);
        }
        
        // Re-build vector excluding composites
        vector<int> still_primes;
        for (int j:primes)
        {
            bool is_composite = false;
            for (int c:composites)
            {
                if (j == c) is_composite = true;
            }
            if (!is_composite) still_primes.push_back(j);
        }
        primes = still_primes;
        // next prime
        ++i;
    }
    
    cout << "All primes numbers from 1 to " << max_val << ":\n";
    for (int p:primes)
    {
        cout << p << "\n";
    }
}
