#include "date.hpp"
#include "std_lib_facilities.h"

int last_day_of_month(Month m)
{
    if (m == Month::feb)
        return 28;
    else if (m == Month::jan || m == Month::mar || m == Month::may ||
             m == Month::jul || m == Month::aug || m == Month::aug ||
             m == Month::oct || m == Month::dec) {
        return 31;
        } else {
            return 30;
        }
}

Date::Date(int y, Month m, int d)
: m_y{Year(y)}
{
    if (d < 1) throw runtime_error("Day must be a value above 0.\n");
    if (d > last_day_of_month(m)) throw runtime_error("Day must not exceed nb of days in this month.\n");
    m_m = m;
    m_d = d;
}
