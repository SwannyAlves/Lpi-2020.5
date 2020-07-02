#ifndef W5N_DATE_H
#define W5N_DATE_H

#include <string>

struct Date
{
    Date();
    unsigned day;
    unsigned month;
    unsigned year;

    void set_from_string(const std::string& date);
    std::string to_string();
};
#endif
