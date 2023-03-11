#include "std_lib_facilities.h"
// Exercise 5.10

int main()
{
    // Enter input sequence
    int n;
    cout << "Please enter the number of values you want to sum and diff: ";
    try {
        cin >> n;
        if (!cin) throw logic_error("wrong input, please only enter 1 integer.");
        else if (n <= 1) throw logic_error("need at least two numbers to list a difference.\n");
        
        vector<double> inputs;
        double next_input;
        cout << "Please enter some integers: ";
        while (cin >> next_input) {
            if (!cin) throw logic_error("wrong input, please only enter numbers.\n");
            inputs.push_back(next_input);
        }
        if (inputs.size() < n) throw logic_error("not enough numbers to sum.\n");
        
        cout << "The sum of the first " << n << " numbers (";
        vector<double> differences;
        double diff;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += inputs[i];
            cout << inputs[i] << " ";
            if (i > 0)
            {
                diff = inputs[i - 1] - inputs[i];
                differences.push_back(diff);
            }
        }
        cout << ") is " << sum << ".\n";
        cout << "The differences between numbers are:\n";
        for (int i = 0; i < differences.size(); i++) {
            cout << differences[i] << "\t";
        }
        cout << "\n";
    }
    catch (logic_error& e) {
        cout << "Logic error: " << e.what();
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
}
