/*
 Exercise 8.13
*/

#include "std_lib_facilities.h"

int get_string_length(const string str)
{
    return narrow_cast<int> (str.size());
}

string find_longest(const vector<string>& str_vec)
{
    int which_longest = 0;
    for (int i = 1; i < str_vec.size(); i++)
    {
        if (str_vec[i].size() > str_vec[which_longest].size())
        {
            which_longest = i;
        }
    }
    return str_vec[which_longest];
}

string find_shortest(const vector<string>& str_vec)
{
    int which_shortest = 0;
    for (int i = 1; i < str_vec.size(); i++)
    {
        if (str_vec[i].size() < str_vec[which_shortest].size())
        {
            which_shortest = i;
        }
    }
    return str_vec[which_shortest];
}

string find_first(const vector<string>& str_vec)
{
    int which_first = 0;
    for (int i = 1; i < str_vec.size(); i++)
    {
        if (str_vec[i] < str_vec[which_first])
        {
            which_first = i;
        }
    }
    return str_vec[which_first];
}

string find_last(const vector<string>& str_vec)
{
    int which_last = 0;
    for (int i = 1; i < str_vec.size(); i++)
    {
        if (str_vec[i] > str_vec[which_last])
        {
            which_last = i;
        }
    }
    return str_vec[which_last];
}

int main()
{
    vector<string> str_seq{
        "hello", "darkness", "my", "old", "friend"
    };
    vector<int> str_len(str_seq.size());
    
    // Get each string length
    for (int i = 0; i < str_seq.size(); i++)
    {
        str_len[i] = get_string_length(str_seq[i]);
        cout << str_len[i] << '\n';
    }
    cout << '\n';
    
    cout << "Longest string is " << find_longest(str_seq) << '\n';
    cout << "Shortest string is " << find_shortest(str_seq) << '\n';
    cout << "Lexicographic first string is " << find_first(str_seq) << '\n';
    cout << "Lexicographic last string is " << find_last(str_seq) << '\n';
    
    return 0;
}
