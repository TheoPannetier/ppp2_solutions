/*
 Chapter 11 Exercise 2
 Write a program that given a file name and a word outputs each line that contains that word together with the line number. Hint: getline().
*/

#include "std_lib_facilities.h"

void deal_with_input_fail(ifstream& ifs)
{
    if (ifs.eof())
        return;
    else if (ifs.fail())
    {
        // ifs.clear(); // only to read
        // ... here address issue if possible
        // not possible here, error
        // ifs.clear(ios_base::failbit); // if could not address error
        throw runtime_error("Could not read input in file.\n");
    }
}

int main()
{
    try {
        string chosen_word;
        cout << "Please chose a word: ";
        cin >> chosen_word;
        
        // Open input file
        string ifs_name = "ex_11.02_input.txt";
        ifstream ifs{ifs_name};
        if(!ifs)
            throw logic_error("Input file not found.\n");
        // Throw an exception if file state is bad
        ifs.exceptions(ifs.exceptions() | ios_base::badbit);
        
        // Read input file
        int nb_occur = 0;
        string str_input;
        string str_flush;
        while (ifs >> str_input)
        {
            if (str_input == chosen_word)
            {
                ++nb_occur;
                getline(ifs, str_flush); // flush rest of line
                
            }
        }
        // if ifs.fail() deal with it or error
        deal_with_input_fail(ifs);
        
        // else is eof(); proceed
        cout << "The word " << chosen_word << " occurs on " << nb_occur << " lines.\n";
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c && c != ';');
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin >> c && c != ';');
        return 2;
    }
}
