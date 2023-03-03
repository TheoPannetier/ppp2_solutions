// Exercise 4.9
#include "std_lib_facilities.h"


// ----- with an int ------- //
int main()
{
    int nb_rice_grains{1};
   
    for (int nb_squares = 2; nb_squares < 65; ++nb_squares)
    {
        nb_rice_grains *= 2;
        cout << "By square " << nb_squares << " we have " << nb_rice_grains << " rice grains.\n";
    }
    return 0;
}
// overflows at the 32nd square
// corresponds to 2 ^ 31
// suspiciously close to the 32 bits (4 bytes) reserved for ints (on my computer).


// ----- with a double ------- //
int main()
{
    double nb_rice_grains{1.0};
   
    for (int nb_squares = 2; nb_squares < 1025; ++nb_squares)
    {
        nb_rice_grains *= 2.0;
        cout << "By square " << nb_squares << " we have " << nb_rice_grains << " rice grains.\n";
    }
    return 0;
}

// approximated to inf at step 1025 (8.98847e+307 at step 1024)
// 2 ^ 1023 is the max here.
// suggests 1024 bits are used for doubles, that is 128 bytes. That's a lot of memory!
// either that, or the computer uses smart tricks with exponents.
