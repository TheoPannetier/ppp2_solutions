/*
 Chapter 11 Exercise 16
 Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first), one value per line.
 Write a value only once, and if it occurs more than once write the count of its occurrences on its line.
 For example, 7 5 5 7 3 117 5 should give
 3
 5     3
 7     2
 117
*/

#include "std_lib_facilities.h"

void deal_with_input_fail(ifstream& ifs)
{
    if (ifs.eof())
        return;
    else if (ifs.fail())
    {
        ifs.clear(); // so stream can be read again
        ifs.unget(); // put last entry back in stream
        char c;
        ifs >> c;
        if (!isdigit(c) && !isspace(c))
        {
            cout << "An entry containing non-digit character " << c << " was ignored.\n";
        } else {
            ifs.clear(ios_base::failbit);
            throw runtime_error("Could not read input in file.\n");
        }
    }
}

void print_out_values(const vector<double>& values)
{
    int nb_reps = 1;
    for (int i = 0; i < values.size(); ++i)
    {
        if (i < values.size() - 1 && values[i + 1] == values[i])
        {
            ++nb_reps;
        } else {
            // Print number and occurrences
            cout << values[i];
            if (nb_reps > 1)
                cout << '\t' << '\t' << nb_reps;
            nb_reps = 1; // reset
            cout << '\n';
        }
    }
}

int main()
{
    try {
        // Open input file
        string ifs_name = "ex_11.16_input.txt";
        ifstream ifs{ifs_name};
        if(!ifs)
            throw logic_error("Input file not found.\n");
        
        // Throw an exception if file state is bad
        ifs.exceptions(ifs.exceptions() | ios_base::badbit);
        
        // Read input file
        vector<double> values;
        double val;
        while (!ifs.eof())
        {
            while (ifs >> val) // ifs is good
            {
                values.push_back(val);
            }
            // if ifs is fail, deal with it or error
            deal_with_input_fail(ifs);
        }
        
        // else is eof(); proceed
        sort(values);
        print_out_values(values);
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
