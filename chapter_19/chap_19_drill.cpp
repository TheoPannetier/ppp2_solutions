/*
 1. Define template<typename T> struct S { T val; };.

 2. Add a constructor, so that you can initialize with a T.
 3. Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with values of your choice.
 4. Read those values and print them.
 5. Add a function template get() that returns a reference to val.
 6. Put the definition of get() outside the class.
 7. Make val private.
 8. Do 4 again using get().
 9. Add a set() function template so that you can change val.
 10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.
 11. Provide const and non-const versions of get().
 12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
 13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.
 14. Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val } format. That will allow read_val() to also handle the S<vector<int>> variable.
 Remember to test after each step.
 */

#include "std_lib_facilities.h"
#include <cmath>

template<typename T> struct S
{
    S(T a_value):val{a_value} {};
    const T& get() const;
    T& get();
    // void set(const T& new_val);
    void operator= (const T&);
private:
    T val;
};

template<typename T> const T& S<T>::get() const
{
    return val;
}

template<typename T> T& S<T>::get()
{
    return val;
}

/*
template<typename T> void S<T>::set(const T& new_val)
{
    val = new_val;
}
 */

template<typename T> void S<T>::operator= (const T& new_val)
{
    val = new_val;
}

template<typename T> void read_val(T& v)
{
    cout << "Please enter a new value:\n";
    if (!(cin >> v))
        throw runtime_error("Wrong input.\n");
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        os << s[i] << '\t';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (!(is >> s[i]))
            throw runtime_error("Wrong input.\n");
    }
    return is;
}

int main()
{
    try {
        S<int> inst_int(5);
        S<double> inst_dbl(5.5);
        S<char> inst_ch('h');
        S<string> inst_str("hey");
        S<vector<int>> inst_vct({5, 9, 6});
        
        cout << inst_int.get()
        << '\n' << inst_dbl.get()
        << '\n' <<  inst_ch.get()
        << '\n' <<  inst_str.get()
        << '\n' <<  inst_vct.get()[0]
        << '\n' <<  inst_vct.get()[1]
        << '\n' <<  inst_vct.get()[2]
        << '\n';
        
        inst_int = 12;
        cout << inst_int.get() << '\n';

        int after = inst_int.get();
        read_val(after);
        cout << "New value is:\t" << after << '\n';
        
        double a_dbl;
        read_val(a_dbl);
        cout << "New value is:\t" << a_dbl << '\n';
        
        char a_ch;
        read_val(a_ch);
        cout << "New value is:\t" << a_ch << '\n';
        
        string a_str;
        read_val(a_str);
        cout << "New value is:\t" << a_str << '\n';
        
        vector<int> a_vec{7, 8};
        read_val(a_vec);
        cout << "New value is:\t" << a_vec << '\n';
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
