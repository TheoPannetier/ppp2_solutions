#include "std_lib_facilities.h"
// Exercise 5.9

int main()
{
    // Enter input sequence
    int n;
    cout << "Please enter the number of values you want to sum: ";
    try {
        cin >> n;
        if (!cin) throw logic_error("wrong input, please only enter 1 integer.");
        else if (n <= 0) throw logic_error("number of values to sum must be at least 1.\n");
        
        vector<int> inputs;
        int next_input;
        cout << "Please enter some integers: ";
        while (cin >> next_input) {
            if (!cin) throw logic_error("wrong input, please only enter integers.\n");
            inputs.push_back(next_input);
        }
        if (inputs.size() < n) throw logic_error("not enough integers to sum.\n");
        
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += inputs[i];
        }
        int total = narrow_cast<int>(sum);
        
        cout << "The sum of the first " << n << " numbers (";
        for (int i = 0; i < n; i++) {
            cout << inputs[i] << " ";
        }
        cout << ") is " << total << ".\n";
    }
    catch (logic_error& e) {
        cout << "Logic error: " << e.what();
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
}
