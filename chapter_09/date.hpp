#include "std_lib_facilities.h"

class Year {
public:
    Year(int y) : y{y} {
        if (y < min || y > max) throw runtime_error("Year can only be between 1800 and 2200");
    }
    const int get_y() {return y;};
private:
    int y;
    static const int min = 1800;
    static const int max = 2200;
};

enum class Month {
    jan = 1, feb, mar, apr, may, jun,
    jul, aug, sep, oct, nov, dec
};

class Date {
public:
    Date(int y, Month m, int d);
    Year year() { return m_y;}
    Month month() { return m_m;}
    int day() { return m_d;}
private:
    Year m_y;
    Month m_m;
    int m_d;
};

int last_day_of_month(Month m);
