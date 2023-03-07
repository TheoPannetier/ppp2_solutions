// Exercise 4.19
#include "std_lib_facilities.h"

int main()
{
    vector<string> names;
    string name;
    vector<int> scores;
    int score;
    bool must_stop{false};
    
    cout << "Enter pairs of name and age or NoName 0 to end input: ";
    while (!must_stop)
    {
        cin >> name >> score;
        for (string n:names) if (name == n) simple_error("This name has already been entered.\n");
        if (name != "NoName" && score != 0)
        {
            names.push_back(name);
            scores.push_back(score);
        } else {
            must_stop = true;
        }
    }
    
    cout << "Here are the listed names and scores:\n";
    for (int i = 0; i < names.size(); ++i)
    {
        cout << names[i] << "\t" << scores[i] << "\n";
    }
}
