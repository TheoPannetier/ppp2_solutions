/*
 Chapter 17 drill
 This drill has two parts. The first exercises/builds your understanding of free-store-allocated arrays and contrasts arrays with vectors:

 1. Allocate an array of ten ints on the free store using new.
 2. Print the values of the ten ints to cout.
 3. Deallocate the array (using delete[]).
 4. Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os.
 5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
 6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
 7. Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os.
 8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
 9. Did you remember to delete the arrays? (If not, do it.)
 10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().
*/

#include "std_lib_facilities.h"
#include <cmath>

ostream& print_array10(ostream& os, int* a)
{
    for (int i = 0; i < 10; ++i)
    {
        os << a[i] << ' ';
    }
    return os;
}

ostream& print_array(ostream& os, int* a, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        os << a[i] << ' ';
    }
    return os;
}

ostream& print_vector(ostream& os, const vector<int> v, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        os << v[i] << ' ';
    }
    return os;
}

int main()
{
    try {
        const int nb_ints = 10;
        int* p_vals = new int[nb_ints] {3, 2, 239, 54, 45, 29, 0, 3, 11, 1111};
        
        // Read values
        for (int i = 0; i < nb_ints; ++i)
        {
            cout << p_vals[i] << ' ';
        }
        cout << '\n';
        print_array10(cout, p_vals);
        cout << '\n';

        // De-allocate
        delete[] p_vals;
        print_array10(cout, p_vals); // out of curiosity
        cout << '\n';

        // New values from 100 to 109
        p_vals = new int[nb_ints];
        for (int i = 0; i < nb_ints; ++i)
        {
           p_vals[i] = 100 + i;
        }
        print_array10(cout, p_vals);
        cout << '\n';
        delete[] p_vals; //% not needed?

        // New values from 100 to 110
        p_vals = new int[nb_ints + 1];
        for (int i = 0; i < nb_ints + 1; ++i)
        {
           p_vals[i] = 100 + i;
        }
        print_array(cout, p_vals, 11);
        cout << '\n';
        delete[] p_vals;
        
        // New values from 100 to 119
        p_vals = new int[20];
        for (int i = 0; i < 20; ++i)
        {
           p_vals[i] = 100 + i;
        }
        print_array(cout, p_vals, 20);
        cout << '\n';
        delete[] p_vals;
        
        // Using vectors
        cout << "With vectors:\n";
        vector<int> vals(nb_ints);
        for (int i = 0; i < nb_ints; ++i)
            vals[i] = 100 + i;
        print_vector(cout, vals, nb_ints);
        cout << '\n';
        
        vals.push_back(110);
        print_vector(cout, vals, 11);
        cout << '\n';

        for (int i = 0; i < nb_ints; ++i)
            vals.push_back(i + 111);
        print_vector(cout, vals, 20);
        cout << '\n';

        
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
