/*
 Chapter 11 Drill
*/

#include "std_lib_facilities.h"

int main()
{
    try {
        int birth_year = 1995;
        cout << showbase << birth_year << '\t' << "decimal" << '\n'
             << hex << birth_year << '\t' << "hexadecimal" << '\n'
             << oct << birth_year << '\t' << "octal" << '\n';
        int my_age = 28;
        cout << my_age << '\n';
        cout << dec << my_age << '\n';
        
        /*
        int a; int b; int c; int d;
        cin >> a >> oct >> b >> hex >> c >> d;
        cout << showbase << 1234 << '\t' << oct << 1234 << '\t' << hex << 1234 <<'\t' << 1234 << '\n';
        cout << showbase << dec << a << '\t' << b << '\t' << c <<'\t' << d << '\n';
         */
        
        double x = 1234567.89;
        cout << defaultfloat << x << '\n' << fixed << x << '\n' << scientific << x << '\n';
        
        int field_width_first = 13;
        int field_width_sec = 18;
        int field_width_third = 7;
        int field_width_last = 23;

        cout << '|' << setw(field_width_first) << "First Name" << '|' << setw(field_width_sec) << "Last Name" << '|' << setw(field_width_third) << "Tel Nb" << '|' << setw(field_width_last) << "email" << '|' << '\n'
        << '|' << setw(field_width_first) << "Jean" << '|' << setw(field_width_sec) << "Valjean" << '|' << setw(field_width_third) << "00334" << '|' << setw(field_width_last) << "j.valjean@mis.ca" << '|' << '\n'
        << '|' << setw(field_width_first) << "Cosette" << '|' << setw(field_width_sec) << "Erable" << '|' << setw(field_width_third) << "957389" << '|' << setw(field_width_last) << "cosette@mis.ca" << '|' << '\n'
        << '|' <<  setw(field_width_first) << "Emilio" << '|' <<  setw(field_width_sec) << "Dos Santos" << '|' << setw(field_width_third) << "4953498" << '|' << setw(field_width_last) << "emildossantos@edu.ac.pt" << '|' << '\n'
        << '|' << setw(field_width_first) << "Sriochleiahgh" << '|' << setw(field_width_sec) << "Ui Lihldhghiloeadh" << '|' << setw(field_width_third) << "948392" << '|' << setw(field_width_last) << "stroch@county.ie" << '|' << '\n';
        
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c && c != ';');
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin >> c && c != ';');
        return 2;
    }
}
