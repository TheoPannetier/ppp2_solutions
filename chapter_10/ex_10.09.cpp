/*
 Exercise 10.9
 Write a program that takes two files containing sorted whitespace-separated words and merges them, preserving order.
*/

#include "std_lib_facilities.h"

void fill_words_from_file(vector<string>& str_vec, const string& filename)
{
    ifstream ifs{filename};
    if (!ifs)
        throw runtime_error("Cannot open file " + filename + ".\n");
    string word;
    while (ifs >> word) {
        str_vec.push_back(word);
    }
}

void write_words_to_file(const vector<string>& str_vec, const string& filename)
{
    ofstream ofs{filename};
    if (!ofs)
        throw runtime_error("Cannot open file " + filename + ".\n");
    for (string word:str_vec)
    {
        ofs << word << ' ';
    }
}

int main()
{
    try {
        vector<string> words;
        const string filename_1 = "ex_10_09_data_1.txt";
        fill_words_from_file(words, filename_1);
        
        const string filename_2 = "ex_10_09_data_2.txt";
        fill_words_from_file(words, filename_2);
        
        sort(words);
        const string output_filename = "ex_10_09_output.txt";
        write_words_to_file(words, output_filename);
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
    return 0;
}
