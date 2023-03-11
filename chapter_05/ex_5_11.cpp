#include "std_lib_facilities.h"
// Exercise 5.11

int main()
{
    try {
        int how_many = 45;
        int former = 1;
        cout << former << "\n";
        int current = 1;
        cout << current << "\n";
        int sum;
        for (int i = 0; i < how_many; i++)
        {
            sum = former + current;
            cout << sum << "\n";
            former = current;
            current = sum;
        }
    }
    catch (logic_error& e) {
        cout << "Logic error: " << e.what();
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
}
