// Exercise 6.4
#include "std_lib_facilities.h"

class Name_value {
    public:
        Name_value(string name, int value)
        {
            m_name = name;
            m_value = value;
        };
        string get_name();
        int get_value();
    private:
        string m_name;
        int m_value;
};

string Name_value::get_name()
{
    return m_name;
}

int Name_value::get_value()
{
    return m_value;
}


int main()
{
    vector<Name_value> name_vals;
    string name;
    int score;
    bool must_stop{false};
    
    cout << "Enter pairs of name and age or NoName 0 to end input: ";
    while (!must_stop)
    {
        cin >> name >> score;
        
        for (Name_value nv:name_vals)
        {
            if (name == nv.get_name()) simple_error("This name has already been entered.\n");
        }
        
        if (name != "NoName" && score != 0)
        {
            Name_value name_val(name, score);
            name_vals.push_back(name_val);
        } else {
            must_stop = true;
        }
    }
    
    cout << "Here are the listed names and scores:\n";
    for (int i = 0; i < name_vals.size(); ++i)
    {
        cout << name_vals[i].get_name() << "\t" << name_vals[i].get_value() << "\n";
    }
}
