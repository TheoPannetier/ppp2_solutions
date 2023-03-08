// Exercise 4.2
#include "std_lib_facilities.h"

// compute mean and median temperatures
int main()
{
    cout << "Enter temperatures: ";
    vector<double> temps; // temperatures
    for (double temp; cin>>temp; )  // read into temp
        temps.push_back(temp);  // put temp into vector
    // compute mean temperature:
    double sum = 0;
    for (int x : temps) sum += x;
    cout << "Average temperature: " << sum/temps.size() << '\n';
    
    // compute median temperature:
    sort(temps);
    double median_tmp;
    bool nb_temps_is_even = temps.size() % 2 == 0;
    if (nb_temps_is_even)
    {
        median_tmp = (temps[temps.size() / 2 - 1] + temps[1 + temps.size() / 2]) / 2.0;
    } else {
        median_tmp = temps[temps.size() / 2];
    }
    cout << "Median temperature: " << median_tmp << '\n';
}
