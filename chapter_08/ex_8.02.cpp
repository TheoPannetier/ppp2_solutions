/*
 Exercise 8.02
*/

#include "std_lib_facilities.h"

void print(const string& label, const vector<int>& vec)
{
    cout << label << ':' << '\n';
    for (int i:vec)
    {
        cout << i << '\n';
    }
}

int main()
{
    vector<int> nums{3, 8, 3};
    print("sequence", nums);
    return 0;
}
