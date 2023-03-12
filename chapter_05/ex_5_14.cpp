#include "std_lib_facilities.h"
// Exercise 5.14

int day_to_int(string day)
{
    if (day == "Monday" || day ==  "monday" || day ==  "Mon" || day == "mon")
    {
        return 1;
    } else if (day == "Tuesday" || day == "tuesday" || day == "Tue" || day == "tue") {
        return 2;
    } else if (day == "Wednesday" || day == "wednesday" || day == "Wed" || day == "wed") {
        return 3;
    } else if (day == "Thursday" || day == "thursday" || day == "Thu" || day == "thu") {
        return 4;
    } else if (day == "Friday" || day == "friday" || day == "Fri" || day == "fri") {
        return 5;
    } else if (day == "Saturday" || day == "saturday" || day == "Sat" || day == "sat") {
        return 6;
    } else if (day == "Sunday" || day == "sunday" || day == "Sun" || day == "sun") {
        return 7;
    } else {
        return 0; // no match
    }
}

int main()
{
    try {
        int input_val;
        string input_day;
        int which_day;
        int nb_rejected = -1; // escape character is also caught
        vector<int> monday = {0};
        vector<int> tuesday = {0};
        vector<int> wednesday = {0};
        vector<int> thursday = {0};
        vector<int> friday = {0};
        vector<int> saturday = {0};
        vector<int> sunday = {0};

        cout << "Enter day-integer pairs:";
        
        while (cin) {
            cin >> input_day >> input_val;
            which_day = day_to_int(input_day);
            switch (which_day) {
                case 1:
                    monday.push_back(input_val);
                    break;
                case 2:
                    tuesday.push_back(input_val);
                    break;
                case 3:
                    wednesday.push_back(input_val);
                    break;
                case 4:
                    thursday.push_back(input_val);
                    break;
                case 5:
                    friday.push_back(input_val);
                    break;
                case 6:
                    saturday.push_back(input_val);
                    break;
                case 7:
                    sunday.push_back(input_val);
                    break;
                case 0:
                    ++nb_rejected;
                    break;
                default:
                    throw runtime_error("unmatched day value.\n");
                    break;
            }
        }
        
        int sum_monday = 0;
        int sum_tuesday = 0;
        int sum_wednesday = 0;
        int sum_thursday = 0;
        int sum_friday = 0;
        int sum_saturday = 0;
        int sum_sunday = 0;
        
        for (int i = 0; i < monday.size(); ++i)
        {
            sum_monday += monday[i];
        }
        cout << "Sum for monday:\t" << sum_monday;
        for (int i = 0; i < tuesday.size(); ++i)
        {
            sum_tuesday += tuesday[i];
        }
        cout << "\nSum for tuesday:\t" << sum_tuesday;
        for (int i = 0; i < wednesday.size(); ++i)
        {
            sum_wednesday += wednesday[i];
        }
        cout << "\nSum for wednesday:\t" << sum_wednesday;
        for (int i = 0; i < thursday.size(); ++i)
        {
            sum_thursday += thursday[i];
        }
        cout << "\nSum for thursday:\t" << sum_thursday;
        for (int i = 0; i < friday.size(); ++i)
        {
            sum_friday += friday[i];
        }
        cout << "\nSum for friday:\t" << sum_friday;
        for (int i = 0; i < saturday.size(); ++i)
        {
            sum_saturday += saturday[i];
        }
        cout << "\nSum for saturday:\t" << sum_saturday;
        for (int i = 0; i < sunday.size(); ++i)
        {
            sum_sunday += sunday[i];
        }
        cout << "\nSum for sunday:\t" << sum_sunday;
        cout << "\n" << nb_rejected << " entries have been ignored.\n";
    }
    catch (logic_error& e) {
        cout << "Logic error: " << e.what();
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
}
