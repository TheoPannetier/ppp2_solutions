/*
 Exercise 8.14
 
 After trying, passing by const-value seems to work as expected: makes an immutable copy.
 Why would we want to do that?
 internet search was not really helpful,
 but I learned that passing by value may be faster than ref for small objects
 so I suppose if we have a small object we don't want to be changed
 might as well pass by const value.
 Also, it may be useful to express intent: "the function won't change this object"
*/

#include "std_lib_facilities.h"

void print(const vector<int> vec)
{
    for (int i:vec)
    {
        cout << i << '\n';
    }
}

void print_i(const int i)
{
    cout << i << '\n';
}


int main()
{
    vector<int> nums{3, 8, 3};
    print(nums);
    print(vector<int> {3, 8, 3});
    
    int a = 3;
    print_i(a);
    print_i(3);
    return 0;
}
