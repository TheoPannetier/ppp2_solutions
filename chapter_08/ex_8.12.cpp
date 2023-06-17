/*
 Exercise 8.12
*/

#include "std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
    for(string s : v) {
        if (s == quit) return;
        cout << s << '\n';
    }
    cout << '\n';
}

void print_until_ss(vector<string> v, string quit)
{
    bool quit_met_once = false;
    for(string s : v) {
        if (s == quit)
        {
            if (quit_met_once)
            {
                return;
            } else {
                quit_met_once = true;
            }
        }
        cout << s << '\n';
    }
    cout << '\n';
}

int main()
{
    vector<string> str_seq{
        "hello", "darkness", "my", "old", "friend",
        "stop right here you criminal scum",
        "i've", "come", "to",
        "see", "you",
        "stop right here you criminal scum",
        "again"
    };
    string quit_str = "stop right here you criminal scum";
    
    print_until_s(str_seq, quit_str);
    cout << '\n';

    // I leave aside cases where input is wrong type, which are caught by compiler
    cout << "quit string is empty\n";
    print_until_s(str_seq, "");
    cout << '\n';

    cout << "str_seq is empty\n";
    print_until_s(vector<string>{}, quit_str);
    cout << '\n';

    cout << "str_seq does not contain the quit string\n";
    vector<string> other_str_seq{"hello", "hello"};
    print_until_s(other_str_seq, quit_str);
    cout << '\n';

    cout << "str_seq starts with the quit string\n";
    vector<string> another_str_seq{"stop right here you criminal scum", "hello"};
    print_until_s(another_str_seq, quit_str);
    cout << '\n';

    print_until_ss(str_seq, quit_str);
    return 0;
}
