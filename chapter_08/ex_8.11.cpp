/*
 Exercise 8.11
 I prefer using the struct.
 This reduces the argument list size (and hence complexity)
 And changing pre-existing arguments with ref doesn't feel safe;
*/

#include "std_lib_facilities.h"

struct Output {
    double max;
    double min;
    double mean;
    double median;
};

Output summarise_vec_struct(const vector<double>& vec)
{
    Output o;
    o.max = vec[0];
    o.min = vec[0];
    o.mean = 0;
    
    for (double d:vec)
    {
        if (d > o.max)
            o.max = d;
        if (d < o.min)
            o.min = d;
        o.mean += d;
    }
    o.mean /= vec.size();
    
    vector<double> sorted_vec = vec;
    sort(sorted_vec);
    bool vec_size_is_even = sorted_vec.size() % 2 == 0;
    int half_vec_size = narrow_cast<int>(sorted_vec.size() / 2);
    if (vec_size_is_even)
    {
        o.median = (sorted_vec[half_vec_size - 1] + sorted_vec[1 + half_vec_size]) / 2.0;
    } else {
        o.median = sorted_vec[half_vec_size];
    }
    
    return o;
}

void summarise_vec_ref(const vector<double>& vec, double& max, double& min, double& mean, double& median)
{
    max = vec[0];
    min = vec[0];
    mean = 0.0;
    for (double d:vec)
    {
        if (d > max)
            max = d;
        if (d < min)
            min = d;
        mean += d;
    }
    mean /= vec.size();
    
    vector<double> sorted_vec = vec;
    sort(sorted_vec);
    bool vec_size_is_even = sorted_vec.size() % 2 == 0;
    int half_vec_size = narrow_cast<int>(sorted_vec.size() / 2);
    if (vec_size_is_even)
    {
        median = (sorted_vec[half_vec_size - 1] + sorted_vec[1 + half_vec_size]) / 2.0;
    } else {
        median = sorted_vec[half_vec_size];
    }
}

int main()
{
    vector<double> seq{1, 5, 7, 4, 2};
    double max;
    double min;
    double mean;
    double median;
    
    cout << "via ref:" << "\n";
    summarise_vec_ref(seq, max, min, mean, median);
    cout << "Max = " << max << "\n"
        << "Min = " << min << "\n"
        << "Mean = " << mean << "\n"
        << "Median = " << median << "\n";
    
    cout << "via struct:" << "\n";
    Output out = summarise_vec_struct(seq);
    cout << "Max = " << out.max << "\n"
        << "Min = " << out.min << "\n"
        << "Mean = " << out.mean << "\n"
        << "Median = " << out.median << "\n";
    
    return 0;
}
