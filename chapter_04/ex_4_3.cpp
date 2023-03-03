// Exercise 4.3
#include "std_lib_facilities.h"

int main()
{
    vector<double> distances;
    double input_distance;
    cout << "Enter a sequence of distances in km: ";
    
    while (cin >> input_distance)
    {
        distances.push_back(input_distance);
    }
    
    double total_distance = 0;
    double min_distance = distances[0];
    double max_distance = distances[0];
    
    for (double dist:distances)
    {
        total_distance += dist;
        if (dist < min_distance)
        {
            min_distance = dist;
        }
        if (dist > max_distance)
        {
            max_distance = dist;
        }
    }
    const double mean_distance{total_distance / distances.size()};
    
    cout << "Total distance = " << total_distance << " km\n" <<
            "Mean distance = " << mean_distance << " km\n" <<
            "Max distance = " << max_distance << " km\n" <<
            "Min distance = " << min_distance << " km\n";
    return 0;
}