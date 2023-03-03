// Exercise 4.4
#include "std_lib_facilities.h"

int main()
{
    cout << "Think of a number between 1 and 100.";
    int guess = 50;
    int increment = guess / 2;
    int nb_questions = 0;
    char answer{' '};
    
    while (nb_questions < 7) {
        cout << "\nIs your number more than " << guess << "? (y/n):";
        cin >> answer;
        if (answer == 'y')
        {
            guess += increment;
            if (increment > 3)
            {
                increment /= 2;
            } else { // couldn't find a more elegant solution
                increment -= 1;
            }
            ++nb_questions;
        } else if (answer == 'n') {
            guess -= increment;
            if (increment > 3)
            {
                increment /= 2;
            } else {
                increment -= 1;
            }
            ++nb_questions;
        } else {
            cout << "\nPlease only enter y (yes) or n (no).";
        }
    }
    if (answer == 'y')
    {
        cout << "\nThe answer is " << guess + 1 << ".\n";
    } else {
        cout << "\nThe answer is " << guess << ".\n";
    }
    
    return 0;
}
