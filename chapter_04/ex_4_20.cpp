// Exercise 4.20
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
    
    string candidate_name;
    cout << "Please enter a name in the list:\n";
    cin >> candidate_name;
    bool has_a_match{false};
    
    for (int i = 0; i < names.size(); ++i)
    {
        if (candidate_name == names[i]) {
            cout << scores[i] << "\n";
            has_a_match = true;
        }
    }
    if (!has_a_match) cout << "Name not found\n";
}
