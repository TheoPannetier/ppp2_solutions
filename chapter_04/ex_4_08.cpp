// Exercise 4.8
#include "std_lib_facilities.h"

int main()
{
    int nb_rice_grains{1};
    int nb_squares{1};
    bool reached_one_thousand{false};
    bool reached_one_million{false};
    bool reached_one_billion{false};
    
    while (!reached_one_billion)
    {
        ++nb_squares;
        nb_rice_grains *= 2;
        cout << "By square " << nb_squares << " we have " << nb_rice_grains << " rice grains.\n";
        
        if (nb_rice_grains > 1000 && !reached_one_thousand)
        {
            reached_one_thousand = true;
            cout << nb_squares << " squares were necessary to reach 1,000 rice grains.\n";
        } else if (nb_rice_grains > 1000000 && !reached_one_million) {
            reached_one_million = true;
            cout << nb_squares << " squares were necessary to reach 1,000,000 rice grains.\n";
        } else if (nb_rice_grains > 1000000000 && !reached_one_billion) {
            reached_one_billion = true;
            cout << nb_squares << " squares were necessary to reach 1,000,000,000 rice grains.\n";
        }
    }
    return 0;
}
