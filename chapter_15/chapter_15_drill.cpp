/*
 Chapter 15 Drill
 Class definition drill:
 1. Define a struct Person containing a string name and an int age.
 2. Define a variable of type Person, initialize it with “Goofy” and 63, and write it to the screen (cout).
 3. Define an input (>>) and an output (<<) operator for Person; read in a Person from the keyboard (cin) and write it out to the screen (cout).
 4. Give Person a constructor initializing name and age.
 5. Make the representation of Person private, and provide const member functions name() and age() to read the name and age.
 6. Modify >> and << to work with the redefined Person.
 7. Modify the constructor to check that age is [0:150) and that name doesn’t contain any of the characters ; : " ' [ ] * & ^ % $ # @ !. Use error() in case of error. Test.
 8. Read a sequence of Persons from input (cin) into a vector<Person>; write them out again to the screen (cout). Test with correct and erroneous input.
 9. Change the representation of Person to have first_name and second_name instead of name. Make it an error not to supply both a first and a second name. Be sure to fix >> and << also. Test.
*/

#include "std_lib_facilities.h"

class Person {
public:
    Person(const string& f_n, const string& l_n, const int& x);
    string get_name() const { return first_name + " " + last_name; }
    int get_age() const { return age; }
private:
    string first_name;
    string last_name;
    int age;
};

void check_name(const string& name)
{
    for (char c : name)
    {
        switch (c)
            case ';': case ':': case '"': case '\'':
            case '[': case ']': case '*': case '&':
            case '^': case '%': case '$': case '#':
            case '@': case '!':
            error("Name contains a special character.\n");
    }
}

Person::Person(const string& f_n, const string& l_n, const int& x)
: first_name{f_n}, last_name{l_n}, age{x}
{
    check_name(f_n);
    check_name(l_n);
    if (x < 0 || x > 150)
        error("Age must be between 0 and 150.\n");
};


istream& operator>> (istream& is, Person& p){
    string i_first_name;
    string i_last_name;
    int i_age;
    if (is >> i_first_name >> i_last_name >> i_age)
    {
        // nothing
    } else {
        return is;
    }
    p = Person(i_first_name, i_last_name, i_age);
    return is;
}

ostream& operator<< (ostream& os, const Person& p){
    return os << p.get_name() << ' ' << p.get_age();
}


int main()
{
    try {
        vector<Person> people;
        Person a_person("", "", 0);
        cout << "Please enter sequence of names and ages: ";
        while (cin >> a_person)
        {
            people.push_back(a_person);
        }
        for (Person p:people){
            cout << p << '\n';
        }
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
