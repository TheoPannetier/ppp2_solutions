/*
 Chapter 11 Exercise 1
 Write a program that reads a text file and converts its input to all lower case, producing a new file.
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
        // Open input file
        string ifs_name = "ex_11.01_input.txt";
        ifstream ifs{ifs_name};
        if(!ifs)
            throw logic_error("Input file not found.\n");
        // Throw an exception if file state is bad
        ifs.exceptions(ifs.exceptions() | ios_base::badbit);
        // Open output file
        string ofs_name = "ex_11.01_output.txt";
        ofstream ofs{ofs_name};
        if(!ofs)
            throw logic_error("Output file not found.\n");

        // Read input file
        string str_input;
        while (ifs >> str_input)
        {
            cout << str_input << "\n";
            string str_lowercase;
            for (char ch:str_input)
                str_lowercase += tolower(ch);
            ofs << str_lowercase << " ";
        }
        // if ifs.fail() deal with it or error
        deal_with_input_fail(ifs);
        
        // else is eof(); proceed
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
